#include "Ast.h"
#include "ParserUtil.h"

AstNode::AstNode(NodeType nt, int line, int column, string file):
	ProgramElem(NULL, line, column, file) {
	nodeType_ = nt;
}

AstNode::AstNode(const AstNode& ast): ProgramElem(ast) {
}

/****************************************************************/

ExprNode::ExprNode(ExprNodeType et, const Value* val, int line, int column,
			 string file):
	AstNode(AstNode::NodeType::EXPR_NODE, line, column, file)
{
	exprType_ = et;
	val_ = val;
	/* coercedType_ */
}


ExprNode::ExprNode(const ExprNode& e) : AstNode(e)
{
}

RefExprNode::RefExprNode(string ext, const SymTabEntry* ste,
	int line, int column, string file):
	ExprNode(ExprNode::ExprNodeType::REF_EXPR_NODE, NULL, line, column, file)
{
	ext_ = ext;
	sym_ = ste;
	type((Type *)ste->type());
}

RefExprNode::RefExprNode(const RefExprNode& r): ExprNode(r)
{
}

void RefExprNode::print(ostream& os, int indent) const {
	os << ext_;
}

void RefExprNode::typePrint(ostream& os, int indent) const {
	if (coercedType()) {
		os << '(';
		coercedType()->print(os, indent);
		os << ')';
	}
	type()->print(os, indent);
}

const Type*
RefExprNode::typeCheck() {
	return type();
}

IfNode::IfNode(ExprNode* cond, StmtNode* thenStmt,
	StmtNode* elseStmt, int line, int column, string file):
	StmtNode(StmtNode::StmtNodeKind::IF, line, column, file)
{
	cond_ = cond;
	then_ = thenStmt;
	else_ = elseStmt;
}

void IfNode::print(ostream& os, int indent) const
{
	os << "if";
	os << " (";
	cond_->print(os, indent);
	os << ") ";

	if (then_) {
	if (then_->stmtNodeKind() == StmtNode::StmtNodeKind::IF) {
		then_->print(os, indent);
		endln(os, indent);
	} else {
		then_->print(os, indent);
		if (then_->stmtNodeKind() != StmtNode::StmtNodeKind::COMPOUND)
		endln(os, indent);
	}
	}
	if (else_) {
	os << "else ";
	else_->print(os, indent);
	if (else_->stmtNodeKind() != StmtNode::StmtNodeKind::COMPOUND)
		endln(os, indent);
	}
}

void IfNode::typePrint(ostream& os, int indent) const
{
	os << "if";
	os << " (";
	cond_->typePrint(os, indent);
	os << ") ";

	if (then_) {
		if (then_->stmtNodeKind() == StmtNode::StmtNodeKind::IF) {
			then_->typePrint(os, indent);
			endln(os, indent);
		} else {
			then_->typePrint(os, indent);
			if (then_->stmtNodeKind() != StmtNode::StmtNodeKind::COMPOUND)
				endln(os, indent);
		}
	}
	if (else_) {
		os << "else ";
		else_->typePrint(os, indent);
		if (else_->stmtNodeKind() != StmtNode::StmtNodeKind::COMPOUND)
			endln(os, indent);
	}
}

const Type*
IfNode::typeCheck() {
	bool err = false;
	Type::TypeTag tag = cond_->typeCheck()->tag();
	if (tag != Type::BOOL && tag != Type::ERROR) {
		errMsg(string("Boolean argument expected"),
			line(), 0, file().c_str());
		err = true;
	}
	if (then_) {
		Type::TypeTag thenTag = then_->typeCheck()->tag();
		if (thenTag == Type::ERROR)
			err = true;
	}
	if (else_) {
		Type::TypeTag elseTag = else_->typeCheck()->tag();
		if (elseTag == Type::ERROR)
			err = true;
	}
	if (err)
		return Type::type[Type::ERROR];
	else
		return Type::type[Type::VOID];
}

void ValueNode::print(ostream& os, int indent) const
{
	value()->print(os, indent);
}

void ValueNode::typePrint(ostream& os, int indent) const
{
	if (coercedType()) {
		os << "(";
		coercedType()->print(os, indent);
		os << ")";
	}
	value()->type()->print(os, indent);
}

const Type*
ValueNode::typeCheck() {
	return value()->type();
}

InvocationNode::InvocationNode(const SymTabEntry *ste, vector<ExprNode*>* param,
	int line, int column, string file):
	ExprNode(ExprNode::ExprNodeType::INV_NODE, NULL, line, column, file) {
	params_ = param;
	ste_ = ste;
}

void InvocationNode::print(ostream& os, int indent) const
{
	bool multiParams = false;
	os << ste_->name() << "(";
	if (params_)
	for (unsigned int i = 0; i < params_->size(); i++)
	{
		if (multiParams)
		os << ", ";
		if ((*params_)[i]) {
		(*params_)[i]->print(os, indent);
		multiParams = true;
		}
	}
	os << ")";
}

void InvocationNode::typePrint(ostream& os, int indent) const
{
	bool multiParams = false;
	if (coercedType()) {
		os << '(';
		coercedType()->print(os, indent);
		os << ')';
	}
	os << ste_->name() << "(";
	if (params_)
		for (unsigned int i = 0; i < params_->size(); i++)
		{
			if (multiParams)
				os << ", ";
			if ((*params_)[i]) {
				(*params_)[i]->typePrint(os, indent);
				multiParams = true;
			}
		}
		os << ")";
	}

InvocationNode::InvocationNode(const InvocationNode& i): ExprNode(i)
{
}

PrimitivePatNode::PrimitivePatNode(EventEntry* ee, vector<VariableEntry*>* params,
	ExprNode* c, int line, int column, string file):
	BasePatNode(BasePatNode::PatNodeKind::PRIMITIVE, line, column, file)
{
	ee_ = ee;
	params_ = params;
	cond_ = c;
}

void
dfs(list<OpNode*>& asgs, ExprNode* c) {
	// Do a DFS search in ExprNode and get the list of Assignment statements
	if (c->exprNodeType() != ExprNode::ExprNodeType::OP_NODE)
		return;
	OpNode* o = (OpNode*) c;
	if (o->opCode() == OpNode::OpCode::ASSIGN)
		asgs.push_back(o);
	dfs(asgs, o->arg(0));
	if (o->arity() == 2)
		dfs(asgs, o->arg(1));
	return;
}

void
PrimitivePatNode::cond(ExprNode* c) {
	if (!c) return;
	cond_ = c;
	dfs(asgs_, c);  // get the assignment statements from cond_
}

void PrimitivePatNode::print(ostream& os, int indent) const
{
	bool multiParams = false;
	vector<Type*> *argTypes;

	if (ee_ && ee_->type())
	argTypes = ee_->type()->argTypes();

	if (argTypes && params_) {
		for (unsigned int i = 0; i < argTypes->size() && (*params_)[i]; i++) {
			(*params_)[i]->type((*argTypes)[i]);
		}
	}
	prtSpace(os, indent);
	os << "(";
	os << ee_->name();
	if (ee_->name() != "any") {
	os << "(";
	if (argTypes && params_) {
		for (unsigned int i = 0; i < argTypes->size() && (*params_)[i]; i++) {
			if (multiParams)
				os << ", ";
			(*params_)[i]->print(os, indent);
			multiParams = true;
		}
	}
	os << ")";
	}
	if (cond_) {
		os << "|";
		cond_->print(os, indent);
	}
	os << ")";
}

void PrimitivePatNode::typePrint(ostream& os, int indent) const
{
	bool multiParams = false;
	vector<Type*> *argTypes;

	if (ee_ && ee_->type())
		argTypes = ee_->type()->argTypes();

	if (argTypes && params_) {
		for (unsigned int i = 0; i < argTypes->size() && (*params_)[i]; i++) {
			(*params_)[i]->type((*argTypes)[i]);
		}
	}
	prtSpace(os, indent);
	os << "(";
	os << ee_->name();
	if (ee_->name() != "any") {
		os << "(";
		if (argTypes && params_) {
			for (unsigned int i = 0; i < argTypes->size() && (*params_)[i]; i++) {
				if (multiParams)
					os << ", ";
				(*params_)[i]->typePrint(os, indent);
				multiParams = true;
			}
		}
		os << ")";
	}
	if (cond_) {
		os << "|";
		cond_->typePrint(os, indent);
	}
	os << ")";
}


bool PrimitivePatNode::hasSeqOps() const
{
	return kind() == PatNodeKind::SEQ || kind() == PatNodeKind::STAR;
}

bool PrimitivePatNode::hasNeg() const
{
	return kind() == PatNodeKind::NEG;
}

bool PrimitivePatNode::hasAnyOrOther() const
{
	return kind() == PatNodeKind::PRIMITIVE || kind() == PatNodeKind::OR;
}

PatNode::PatNode(PatNodeKind pk, BasePatNode *p1, BasePatNode*p2, int line,
	int column, string file): BasePatNode(pk, line, column, file)
{
	pat1_ = p1;
	pat2_ = p2;

}

void PatNode::print(ostream& os, int indent) const {
	PatNodeKind patKind = kind();

	os << "(";
	if (patKind == PatNodeKind::NEG) {
		os << "!";
	}
	pat1_->print(os, indent);
	if (patKind == PatNodeKind::STAR)
		os << "**";
	if (pat2_) {
		if (patKind == PatNodeKind::SEQ)
			os << ":";
		else if (patKind == PatNodeKind::OR)
			os << "\\/";
		pat2_->print(os, indent);
	}
	os << ")";
}

void PatNode::typePrint(ostream& os, int indent) const {
	PatNodeKind patKind = kind();

	os << "(";
	if (patKind == PatNodeKind::NEG) {
		os << "!";
	}
	pat1_->typePrint(os, indent);
	if (patKind == PatNodeKind::STAR)
		os << "**";
	if (pat2_) {
		if (patKind == PatNodeKind::SEQ)
			os << ":";
		else if (patKind == PatNodeKind::OR)
			os << "\\/";
		pat2_->typePrint(os, indent);
	}
	os << ")";
}

bool PatNode::hasSeqOps() const {
		return (kind() == PatNodeKind::SEQ || kind() == PatNodeKind::STAR ||
						(pat1() && pat1()->hasSeqOps()) ||
						(pat2() && pat2()->hasSeqOps()));
}

bool PatNode::hasNeg() const {
	if (pat2() != NULL) {
		return pat1()->hasNeg() || pat2()->hasNeg();
	}
	return false;
}

bool PatNode::hasAnyOrOther() const {
	return kind() == PatNodeKind::PRIMITIVE || kind() == PatNodeKind::OR;
}

void CompoundStmtNode::print(ostream& os, int indent) const
{
	list <StmtNode*> *stmtList = stmts_;
	bool first = true;

	os << "{";
	for (list<StmtNode*>::iterator it = stmtList->begin(); it != stmtList->end(); it++) {
	ostringstream oss;
	if (*it) {
		(*it)->print(oss, indent);
		if (oss.str().empty()) {
		continue;
		}

		if (first) {
		prtln(os, indent);
		first = false;
		}
		(*it)->print(os, indent);
		if ((*it)->stmtNodeKind() != StmtNode::StmtNodeKind::IF &&
		(*it)->stmtNodeKind() != StmtNode::StmtNodeKind::COMPOUND)
		{
		endln(os, indent);
		}
	}
	}
	os << "};";
	prtln(os, indent);
}

void CompoundStmtNode::typePrint(ostream& os, int indent) const
{
	list <StmtNode*> *stmtList = stmts_;
	bool first = true;

	os << "{";
	for (list<StmtNode*>::iterator it = stmtList->begin(); it != stmtList->end(); it++) {
		ostringstream oss;
		if (*it) {
			(*it)->typePrint(oss, indent);
			if (oss.str().empty()) {
				continue;
			}

			if (first) {
				prtln(os, indent + STEP_INDENT);
				first = false;
			} else prtSpace(os, STEP_INDENT);
			(*it)->typePrint(os, indent + STEP_INDENT);
			if ((*it)->stmtNodeKind() != StmtNode::StmtNodeKind::IF &&
				(*it)->stmtNodeKind() != StmtNode::StmtNodeKind::COMPOUND)
			{
				endln(os, indent);
			}
		}
	}
	os << "};";
	prtln(os, indent);
}

void CompoundStmtNode::printWithoutBraces(ostream& os, int indent) const
{
}

const Type*
CompoundStmtNode::typeCheck() {
	// just call typeCheck for all the StmtNode's in the Compound statement
	list<StmtNode*>* stmtList = stmts();
	list<StmtNode*>::iterator it = stmtList->begin();
	Type::TypeTag res;
	bool err = false;
	while(it != stmtList->end()) {
		if ((*it) == nullptr) {
			++it; continue;  // handle the empty statement (just ;) (stored as NULL)
		}
		res = (*it)->typeCheck()->tag();
		if (res == Type::ERROR)
			err = true;
		++it;
	}
	if (err)
		return Type::type[Type::ERROR];
	else
		return Type::type[Type::VOID];
}

const Type*
ReturnStmtNode::typeCheck() {
	Type::TypeTag retTag = fun_->type()->retType()->tag();
	Type::TypeTag expTag = expr_->typeCheck()->tag();
	if (Type::isSubType(expTag, retTag)) {
		if (retTag != expTag)
			expr_->coercedType(Type::type[retTag]);
	}
	else {
		if (retTag == Type::VOID)
			errMsg(string("No return value expected for a void function"),
				line(), 0, file().c_str());
		else
			errMsg(string("Return value incompatible with current function's type"),
					line(), 0, file().c_str());
		return Type::type[Type::ERROR];
	}
	return Type::type[retTag];
}

RuleNode::RuleNode(BlockEntry *re, BasePatNode* pat, StmtNode* reaction,
	int line, int column, string file): AstNode(AstNode::NodeType::RULE_NODE, line, column, file)
{
	rste_ = re;
	pat_ = pat;
	reaction_ = reaction;
}

void RuleNode::print(ostream& os, int indent) const
{
	prtSpace(os, STEP_INDENT);
	pat_->print(os, indent);
	os << "-->";
	prtSpace(os, STEP_INDENT);
	reaction_->print(os, indent + STEP_INDENT);
	os << ";;\n";
}

void RuleNode::typePrint(ostream& os, int indent) const
{
	prtSpace(os, STEP_INDENT);
	pat_->typePrint(os, indent);
	os << "-->";
	prtSpace(os, STEP_INDENT);
	reaction_->typePrint(os, indent + STEP_INDENT);
	os << ";;\n";
}

/****************************************************************/
extern const OpNode::OpInfo opInfo[] = {
	// print name, arity, paren_flag, fixity, arg types, out type, constraints
	//
	// Paren_flag -- opnode->print() outputs is surrounded by parenthesis if
	// this flag is set. As set below, the expression may not print correctly
	// in some rare cases, e.g., ~(b * c) will get printed as ~b * c,
	// which actually corresponds to (~b)*c. To ensure that things get printed
	// correctly all the time, more paren_flags should be set to 1, but this
	// will lead to more clutter in printed output. Basically, what we have done
	// here is to look are expressions by type -- arithmetic, relational,
	// boolean, bit operations, etc. Within each type, the highest priority
	// operator is printed without paren. This will work correctly, as long
	// as the language doesn't permit mixing of different types of expressions.
	// But this assumption doesn't always hold, as in the example above. Also,
	// there is an exception to this general approach in the case of unary minus
	// and * -- since (-a)*b and -(a*b) have the same meaning, we can exclude
	// paren for * without an error.
	//
	// Codes for constraints:
	// first character:
	//    N: No additional constraint over what is given by argTypes
	//    I: all arguments must have identical type
	//    S: one of the arguments must have a type that is a supertype of
	//        of all other arguments. All other arguments require a coercion
	//        operation to be introduced so as to convert their type to S.
	//    s: one of the arguments must have a type that is a subtype of
	//        of all other arguments.
	//    L: all list arguments (and list output) must have same type. In
	//        addition, all non-list arguments (and output) must have same
	//        type as that of elements in these lists
	//    T: all tuple arguments to the function must have same type.
	//    A: (assignment). Type of second argument must be a subtype of
	//       the first argument
	//
	// second character:
	//    O: output type is the same as out type. (In the following cases,
	//        the output type need not be equal to out type, but a subtype
	//        of it.) Since a TypeTag provides complete type information only
	//        for primitive types, `O' is applicable only in this case.
	//    digit: output type is the same as that of the digit'th argument
	//       In this case, a third character may be used, the code for
	//       which is as follows:
	//         'e' denotes that the output is of type alpha, where
	//             the type of digit'th argument is list(alpha)
	//         'l' denotes that the output is of type list(alpha), where
	//             alpha is the type of the digit'th argument.
	//    S: The output type is the same as that of the argument with the
	//        most general type. (Typically used with first character 'S')
	//    s: The output type is the same as that of the argument with the
	//        least general type. (Typically used with first character 'S')
	//    P: The output type is the product of the types of all arguments
	//    p: The output type is a component of the input tuple type. The
	//        following character specifies the component. A digit k specifies
	//        that the component number as k. The character 'a' indicates that
	//        the component number is given by an integer argument to the
	//        operator. The argument number is given by the following digit.
	//        'p' can be used only in conjunction with first character 'P'.
	//    L: Output type is the same as type of list arguments. Can be used
	//        only in conjunction with first character L.
	//    e: Output type is the same as type of element of list arguments.
	//        Can be used only in conjunction with first character L.
	//
	{OpNode::OpCode::UMINUS, "-",  1, 0, OpNode::OpPrintType::PREFIX, {Type::SIGNED}, Type::SIGNED, "N1"},
	{OpNode::OpCode::PLUS, "+",  2, 1, OpNode::OpPrintType::INFIX, {Type::NUMERIC, Type::NUMERIC}, Type::NUMERIC, "SS"},
	{OpNode::OpCode::MINUS, "-",  2, 1, OpNode::OpPrintType::INFIX, {Type::NUMERIC, Type::NUMERIC}, Type::NUMERIC, "SS"},
	{OpNode::OpCode::MULT, "*",  2, 0, OpNode::OpPrintType::INFIX, {Type::NUMERIC, Type::NUMERIC}, Type::NUMERIC, "SS"},
	{OpNode::OpCode::DIV, "/",  2, 1, OpNode::OpPrintType::INFIX, {Type::NUMERIC, Type::NUMERIC}, Type::NUMERIC, "SS"},
	{OpNode::OpCode::MOD, "%",  2, 1, OpNode::OpPrintType::INFIX, {Type::INTEGRAL, Type::INTEGRAL}, Type::INTEGRAL, "S2"},
	{OpNode::OpCode::EQ, "==", 2, 0, OpNode::OpPrintType::INFIX, {Type::PRIMITIVE, Type::PRIMITIVE}, Type::BOOL, "SO"},
	{OpNode::OpCode::NE, "!=", 2, 0, OpNode::OpPrintType::INFIX, {Type::PRIMITIVE, Type::PRIMITIVE}, Type::BOOL, "SO"},
	{OpNode::OpCode::GT, ">",  2, 0, OpNode::OpPrintType::INFIX, {Type::SCALAR, Type::SCALAR}, Type::BOOL, "SO"},
	{OpNode::OpCode::LT, "<",  2, 0, OpNode::OpPrintType::INFIX, {Type::SCALAR, Type::SCALAR}, Type::BOOL, "SO"},
	{OpNode::OpCode::GE, ">=", 2, 0, OpNode::OpPrintType::INFIX, {Type::SCALAR, Type::SCALAR}, Type::BOOL, "SO"},
	{OpNode::OpCode::LE, "<=", 2, 0, OpNode::OpPrintType::INFIX, {Type::SCALAR, Type::SCALAR}, Type::BOOL, "SO"},
	{OpNode::OpCode::AND, "&&",  2, 1, OpNode::OpPrintType::INFIX, {Type::BOOL, Type::BOOL}, Type::BOOL, "NO"},
	{OpNode::OpCode::OR, "||",  2, 1, OpNode::OpPrintType::INFIX, {Type::BOOL, Type::BOOL}, Type::BOOL, "NO"},
	{OpNode::OpCode::NOT, "!",  1, 0, OpNode::OpPrintType::PREFIX, {Type::BOOL}, Type::BOOL, "NO"},
	{OpNode::OpCode::BITNOT, "~",  1, 0, OpNode::OpPrintType::PREFIX, {Type::INTEGRAL}, Type::INTEGRAL, "N1"},
	{OpNode::OpCode::BITAND, "&",  2, 1, OpNode::OpPrintType::INFIX, {Type::INTEGRAL, Type::INTEGRAL}, Type::INTEGRAL, "Ss"},
	{OpNode::OpCode::BITOR, "|",  2, 1, OpNode::OpPrintType::INFIX, {Type::INTEGRAL, Type::INTEGRAL}, Type::INTEGRAL, "SS"},
	{OpNode::OpCode::BITXOR, "^",  2, 0, OpNode::OpPrintType::INFIX, {Type::INTEGRAL, Type::INTEGRAL}, Type::INTEGRAL, "SS"},
	{OpNode::OpCode::SHL, "<<", 2, 1, OpNode::OpPrintType::INFIX, {Type::INTEGRAL, Type::INTEGRAL}, Type::INTEGRAL, "N1"},
	{OpNode::OpCode::SHR, ">>", 2, 1, OpNode::OpPrintType::INFIX, {Type::INTEGRAL, Type::INTEGRAL}, Type::INTEGRAL, "N1"},
	{OpNode::OpCode::ASSIGN, "=",  2, 0, OpNode::OpPrintType::INFIX, {Type::NATIVE, Type::NATIVE}, Type::VOID, "AO"},
	{OpNode::OpCode::PRINT, "print", OpNode::VARIABLE, 1, OpNode::OpPrintType::PREFIX, {Type::NATIVE}, Type::VOID, "NO"},
	{OpNode::OpCode::INVALID, "invalid",            0, 0, OpNode::OpPrintType::PREFIX, {}, Type::ERROR, "NO"}
};

OpNode::OpNode(OpCode op, ExprNode* a1, ExprNode* a2,
		 int ln, int col, string file):
	ExprNode(ExprNode::ExprNodeType::OP_NODE, NULL, ln,col,file) {
	opCode_ = op;
	if (a1 != NULL) {
	arity_ = 1;
	arg_.push_back(a1);
	if (a2 != NULL) {
	arity_++;
	arg_.push_back(a2);
	}
	}
}

OpNode::OpNode(const OpNode &other):
	ExprNode(other) {
	arity_ = other.arity();
	opCode_ = other.opCode();
	for (unsigned int i=0; (i < other.arity()); i++) {
	if (other.arg_[i]) {
		arg_.push_back((other.arg_[i])->clone());
	}
	else {
		arg_.push_back(NULL);
	}
	}
}

void
OpNode::print(ostream& os, int indent) const {
	int iopcode = static_cast<int>(opCode_);
	if (opInfo[iopcode].prtType_ == OpNode::OpPrintType::PREFIX) {
		os << opInfo[iopcode].name_;
		if (arity_ > 0) {
			if (opInfo[iopcode].needParen_)
				os << '(';
			for (unsigned i=0; i < arity_-1; i++) {
				if (arg_[i])
					arg_[i]->print(os, indent);
				else os << "NULL";
				os << ", ";
			}
			if (arg_[arity_-1])
				arg_[arity_-1]->print(os, indent);
			else os << "NULL";
			if (opInfo[iopcode].needParen_)
				os << ") ";
		}
	}
	else if ((opInfo[iopcode].prtType_ == OpNode::OpPrintType::INFIX) && (arity_ == 2)) {
		if (opInfo[iopcode].needParen_)
			os << "(";
		if(arg_[0])
			arg_[0]->print(os, indent);
		else os << "NULL";
		os << opInfo[iopcode].name_;
		if(arg_[1])
			arg_[1]->print(os, indent);
		else os << "NULL";
		if (opInfo[iopcode].needParen_)
			os << ")";
	}
	else internalErr("Unhandled case in OpNode::print");
}

void
OpNode::typePrint(ostream& os, int indent) const {
	int iopcode = static_cast<int>(opCode_);
	if (coercedType()) {
		os << "(";
		coercedType()->print(os, indent);
		os << ")";
	}
	if (opInfo[iopcode].prtType_ == OpNode::OpPrintType::PREFIX) {
		os << opInfo[iopcode].name_;
		if (arity_ > 0) {
			if (opInfo[iopcode].needParen_)
				os << '(';
			for (unsigned i=0; i < arity_-1; i++) {
				if (arg_[i])
					arg_[i]->typePrint(os, indent);
				else os << "NULL";
				os << ", ";
			}
			if (arg_[arity_-1])
				arg_[arity_-1]->typePrint(os, indent);
			else os << "NULL";
			if (opInfo[iopcode].needParen_)
				os << ") ";
		}
	}
	else if ((opInfo[iopcode].prtType_ == OpNode::OpPrintType::INFIX) && (arity_ == 2)) {
		if (opInfo[iopcode].needParen_)
			os << "(";
		if(arg_[0])
			arg_[0]->typePrint(os, indent);
		else os << "NULL";
		os << opInfo[iopcode].name_;
		if(arg_[1])
			arg_[1]->typePrint(os, indent);
		else os << "NULL";
		if (opInfo[iopcode].needParen_)
			os << ")";
	}
	else internalErr("Unhandled case in OpNode::print");
}

Type*
OpNode::opTypeCheck(ExprNode* t1, ExprNode* t2,
										Type::TypeTag lFormType, Type::TypeTag rFormType,
										Type::TypeTag retTag, bool coerce) {
	Type::TypeTag lType = t1->typeCheck()->tag();
	Type::TypeTag rType = t2->typeCheck()->tag();
	Type::TypeTag out = Type::ERROR;
	bool lVal = Type::isSubType(lType, lFormType);
	bool rVal = Type::isSubType(rType, rFormType);
	bool lRet = Type::isSubType(lType, retTag);
	bool rRet = Type::isSubType(rType, retTag);
	bool err = false;
	bool force_coerce = ((opCode_ == OpNode::OpCode::PLUS) ||
		(opCode_ == OpNode::OpCode::MINUS) ||
		(opCode_ == OpNode::OpCode::MULT) ||
		(opCode_ == OpNode::OpCode::DIV));

	if (!lVal && (lType != Type::ERROR)) {
		if (rRet) {
			out = rType;
			if (coerce && (force_coerce || Type::isSubType(lType, out)))
				t1->coercedType(Type::type[out]);
		} else out = Type::ERROR;
		err = true;
		errMsg(string("Incompatible type for argument 1 for operator `") +
				opInfo[(int) opCode_].name_ + string("`"), line(), 0, file().c_str());
	}
	if (!rVal && (rType != Type::ERROR)) {
		if (lRet) {
			out = lType;
			if (coerce && (force_coerce || Type::isSubType(rType, out)))
				t2->coercedType(Type::type[out]);
		} else out = Type::ERROR;
		err = true;
		errMsg(string("Incompatible type for argument 2 for operator `") +
				opInfo[(int) opCode_].name_ + string("`"), line(), 0, file().c_str());
	}
	if (err && (lRet || rRet)) return (Type*) Type::type[out];
	// now we are dealing with valid argument types
	if (lType == rType) {
		out = lType;
	} else if (Type::isSubType(rType, lType)) {
		out = lType;
		if (coerce) t2->coercedType(Type::type[out]);
	} else if (Type::isSubType(lType, rType)) {
		out = rType;
		if (coerce) t1->coercedType(Type::type[out]);
	}
	if (!lRet && !rRet)
		out = retTag;
	return (Type*) Type::type[out];
}

const Type*
OpNode::typeCheck() {
	bool err = false;
	Type::TypeTag actLType, actRType, outType;
	int iopcode = (int) opCode_;
	Type* res = NULL;

	if (arity_ == 2) {
		actLType = opInfo[iopcode].argType_[0];
		actRType = opInfo[iopcode].argType_[1];
		outType = opInfo[iopcode].outType_;

		switch (opCode_) {
			case OpNode::OpCode::ASSIGN:
				Type::TypeTag lType, rType;
				lType = arg_[0]->typeCheck()->tag();
				rType = arg_[1]->typeCheck()->tag();
				if (Type::isSubType(rType, lType)) {
					/* For assignment operator, rhs should be subtype of lhs.
						 rhs type is coerced to lhs' type */
					if (lType != rType)
						arg_[1]->coercedType(Type::type[lType]);
					res = (Type*) Type::type[Type::BOOL];
					type((Type*) res);
					return res;
				} else {
					errMsg(string("Assignment between incompatible types"),
						line(), 0, file().c_str());
					res = (Type*) Type::type[Type::ERROR];
				}
				break;
			case OpNode::OpCode::PLUS:
			case OpNode::OpCode::MINUS:
			case OpNode::OpCode::MULT:
			case OpNode::OpCode::DIV:
			case OpNode::OpCode::MOD:
			case OpNode::OpCode::BITNOT:
			case OpNode::OpCode::BITAND:
			case OpNode::OpCode::BITOR:
			case OpNode::OpCode::BITXOR:
				res = opTypeCheck(arg_[0], arg_[1], actLType, actRType, outType, true);
				break;
			case OpNode::OpCode::SHL:
			case OpNode::OpCode::SHR:
				res = opTypeCheck(arg_[0], arg_[1], actLType, actRType, outType, false);
				break;
			case OpNode::OpCode::EQ:
			case OpNode::OpCode::NE:
			case OpNode::OpCode::GT:
			case OpNode::OpCode::LT:
			case OpNode::OpCode::GE:
			case OpNode::OpCode::LE:
			case OpNode::OpCode::AND:
			case OpNode::OpCode::OR:
				res = opTypeCheck(arg_[0], arg_[1], actLType, actRType, outType, false);
				if (res->tag() != Type::ERROR)
					res = (Type*) Type::type[Type::BOOL];
			default:;
		}

	} else if (arity_ == 1) {
		Type::TypeTag lType;
		lType = arg_[0]->typeCheck()->tag();
		actLType = opInfo[iopcode].argType_[0];
		switch(opCode_) {
			case OpNode::OpCode::UMINUS:
				if (Type::isUnsigned(lType)) {
					arg_[0]->coercedType(Type::type[Type::INT]);
					res = (Type*) Type::type[Type::INT];
				} else if (!Type::isIntegral(lType))
					err = true;
				break;
			case OpNode::OpCode::NOT:
				if (!Type::isBool(lType)) err = true;
				break;
			case OpNode::OpCode::BITNOT:
				if (!Type::isIntegral(lType)) {
					err = true;
					errMsg(string("Incompatible type for argument 1 for operator `") +
						opInfo[iopcode].name_ + string("`"), line(), 0, file().c_str());
				}
				if (!Type::isUnsigned(lType))
					arg_[0]->coercedType(Type::type[Type::UINT]);
				res = (Type*) Type::type[Type::UINT];
				type((Type*) res);
				return res;
			default:;
		}
		if (!err)
			res = (Type*) Type::type[lType];
		else {
			errMsg(string("Incompatible type for argument 1 for operator `") +
				opInfo[iopcode].name_ + string("`"), line(), 0, file().c_str());
			res = (Type*) Type::type[Type::ERROR];
		}
	}
	type((Type*) res);
	return res;
}

const Type*
InvocationNode::typeCheck() {
	FunctionEntry *fe = (FunctionEntry*) symTabEntry();
	vector<Type*>* formParamTypes = fe->type()->argTypes();
	vector<ExprNode*>* actParams = params();
	int num_form_param = formParamTypes ? formParamTypes->size() : 0;
	int num_act_param = actParams ? actParams->size() : 0;
	if (num_form_param != num_act_param) {
		errMsg(to_string(num_form_param) + string(" arguments expected for ") +
					 ste_->name(), line(), 0, file().c_str());
		return ste_->type()->retType();
	}
	// equal number of formal and actual arguments, check their types
	vector<Type*>::iterator itf;
	vector<ExprNode*>::iterator ita;
	Type::TypeTag actualTypeTag, formalTypeTag;
	const Type* actualParam;
	int i = 1;
	bool failed = false;

	for (itf = formParamTypes->begin(), ita = actParams->begin();
			 itf != formParamTypes->end() && ita != actParams->end();
			 ++itf, ++ita, i++) {
		actualParam = (*ita)->typeCheck();
		actualTypeTag = actualParam->tag();
		formalTypeTag = (*itf)->tag();

		if(Type::isSubType(actualTypeTag, formalTypeTag)) {
			if (actualTypeTag != formalTypeTag)
				(*ita)->coercedType(Type::type[formalTypeTag]);
		} else if ((formalTypeTag == Type::CLASS && actualTypeTag == Type::CLASS &&
				(actualParam->typeDesc()->name() == (*itf)->typeDesc()->name()))) {
			// type checking for class
		} else {
			failed = true;
			errMsg(string("Type mismatch for argument ") +
				to_string(i) + string(" to ") + ste_->name(),
				line(), 0, file().c_str());
		}
	}
	if(failed) return Type::type[Type::ERROR];
	return ste_->type()->retType();
}

const Type*
ExprStmtNode::typeCheck() {
	if (expr_->typeCheck()->tag() == Type::ERROR) {
		return Type::type[Type::ERROR];
	}
	else
		return Type::type[Type::VOID];
}

const Type*
PrimitivePatNode::typeCheck() {
	bool err = false;
	EventEntry *ee = event();
	vector<Type*>* argTypes = ee->type()->argTypes();
	vector<VariableEntry*>* args = params();
	int num_act_param = args ? args->size() : 0;
	int num_form_param = argTypes ? argTypes->size() : 0;
	if (num_form_param == num_act_param) {
		/* type for arguments is inferred from events, so doesn't make sense
		 * performing type checks */

		// for (it = argTypes->begin(), it_a = args->begin(); it != argTypes->end(); ++it, ++it_a)
		// {
		//   if ((*it)->tag() != (*it_a)->type()->tag())
		//   {
		//     if (!Type::isSubType((*it_a)->type()->tag(), (*it)->tag()))
		//       errMsg(string("Incompatible Type for Argument #") + to_string(i) + string(" Expected: ") + string((*it)->name()) + string(" Received: ") + string((*it_a)->type()->name()), line(), 0, file().c_str());
		//       err = true;
		//   }
		// }
	}
	else {
		errMsg(string("Event ") + ee->name() + string(" requires ") +
					 to_string(num_form_param) + string(" arguments"),
					 line(), 0, file().c_str());
		err = true;
	}

	list<OpNode*>* asign_stmts = &this->asgs();
	ExprNode* r;
	VariableEntry* v;
	if (asign_stmts) {
		for (list<OpNode*>::iterator itr = asign_stmts->begin();
				 itr != asign_stmts->end(); ++itr) {
			r = (*itr)->arg(0);
			if (r->exprNodeType() == ExprNode::ExprNodeType::REF_EXPR_NODE) {
				v = (VariableEntry*) ((RefExprNode*) r)->symTabEntry();
				if (v && v->varKind() == VariableEntry::VarKind::PARAM_VAR) {
					errMsg(string("Assignment Statements only for Globals are allowed inside rule"), line(), 0, file().c_str());
					err = true;
				}
			}
			(*itr)->arg(1)->typeCheck();
		}
	}
	if (err)
		return Type::type[Type::ERROR];
	else
		return Type::type[Type::VOID];
}

const Type*
PatNode::typeCheck() {
	bool err = false;
	const Type *p1;
	const Type *p2;

	if (kind() == PatNodeKind::NEG && hasSeqOps()) {
		errMsg(string("Only simple patterns without `.', `*', and `!' operators can be negated"), line(), 0, file().c_str());
	}
	if (pat1()) {
		p1 = pat1()->typeCheck();
		if (p1->tag() == Type::ERROR)
			err = true;
	}
	if (pat2()) {
		p2 = pat2()->typeCheck();
		if (p2->tag() == Type::ERROR)
			err = true;
	}

	if (err) {
		return Type::type[Type::ERROR];
	}
	return Type::type[Type::VOID];
}

const Type*
RuleNode::typeCheck() {
	if (pat()->typeCheck()->tag() == Type::ERROR ||
			reaction()->typeCheck()->tag() == Type::ERROR)
		return Type::type[Type::ERROR];
	else
		return Type::type[Type::VOID];
}


WhileStmtNode::WhileStmtNode(ExprNode* cond, StmtNode* body, int nesting, int line, int column, string file):
	StmtNode(StmtNode::StmtNodeKind::WHILE, line, column, file)
{
	cond_ = cond;
	body_ = body;
	nestingLevel = nesting;
}

void WhileStmtNode::print(ostream& os, int indent) const
{
	os << "while";
	os << " (";
	cond_->print(os, indent);
	os << ") ";

	if (body_) {
		body_->print(os, indent);
		if (body_->stmtNodeKind() != StmtNode::StmtNodeKind::COMPOUND)
			endln(os, indent);
	}
}

void WhileStmtNode::typePrint(ostream& os, int indent) const
{
	os << "while";
	os << " (";
	cond_->typePrint(os, indent);
	os << ") ";

	if (body_) {
		body_->typePrint(os, indent);
		if (body_->stmtNodeKind() != StmtNode::StmtNodeKind::COMPOUND)
				endln(os, indent);
		}
}

const Type*
WhileStmtNode::typeCheck() {
	Type::TypeTag tag;
	if (cond_) {
		tag = cond_->typeCheck()->tag();
		if (tag != Type::BOOL && tag != Type::ERROR) {
			errMsg(string("Boolean expression required for condition in while"),
				line(), 0, file().c_str());
			return Type::type[Type::ERROR];
		}
	}
	if (body_) {
		tag = body_->typeCheck()->tag();
		if (tag == Type::ERROR)
			return Type::type[Type::ERROR];
	}
	return Type::type[Type::VOID];
}

/************** Mem Alloc *******************/

void
RefExprNode::memAlloc() {
	const Type* rT = type();
	const Type* cT = coercedType();

	unCoercedVal(MemAlloc::get_next_temp_reg(rT));
	rVal(unCoercedVal());
	if (cT && Type::isCoerce(rT->tag(), cT->tag())) {
		unCoercedVal(MemAlloc::get_next_temp_reg(rT));
		rVal(MemAlloc::get_next_temp_reg(cT));
	}
}

void
ValueNode::memAlloc() {
	rVal(MemAlloc::get_next_temp_reg(type()));
}

void
OpNode::memAlloc() {
	const Type* cT = coercedType();
	const Type* t = type();

	arg_[0]->memAlloc();
	if (opCode_ == OpCode::UMINUS)
		return;

	if (arity_ == 2)
		arg_[1]->memAlloc();

	// allocate register for result
	if (cT && Type::isCoerce(t->tag(), cT->tag())) {
		unCoercedVal(MemAlloc::get_next_temp_reg(t));
		rVal(MemAlloc::get_next_temp_reg(cT));
		// cout << "malloc: OP: " << rVal()->name() << endl;
		// cout << "malloc: OP: " << unCoercedVal()->name() << endl;
	} else {
		unCoercedVal(MemAlloc::get_next_temp_reg(t));
		rVal(unCoercedVal());
		// cout << "malloc: OP: " << unCoercedVal()->name() << endl;
	}
}

/************** Code Gen *******************/

vector<Instruction*>*
ValueNode::codeGen() {
		vector<Instruction*>* ics = icode();
		const Constant* v = new Constant(value());
		const Register* r = (const Register*) rVal();
		Instruction::Icode i_code;
		if (r->regKind() == Register::RegKind::INT)
				i_code = Instruction::Icode::MOVI;
		else
				i_code = Instruction::Icode::MOVF;
		ics->push_back(new Instruction(i_code, v, NULL, r, NULL));
		return ics;
}

vector<Instruction*>*
RefExprNode::codeGen() {
	const Type* cT = coercedType();
	const Type* rT = type();
	vector<Instruction*>* ics = icode();
	VariableEntry* ve = (VariableEntry*) symTabEntry();
	const Arg* l = ve->lVal();
	const Arg* u = unCoercedVal();
	const Arg* r = rVal();
	Instruction::Icode ic = (Type::isFloat(l->typeTag()) ? Instruction::Icode::LDF : Instruction::Icode::LDI);
	ics->push_back(new Instruction(ic, l, NULL, u, NULL));

	if (cT && Type::isCoerce(rT->tag(), cT->tag())) {
		ic = (Type::isFloat(cT->tag())) ? Instruction::MOVIF : Instruction::MOVFI;
		ics->push_back(new Instruction(ic, u, NULL, r, NULL));
	}
	return ics;
}


vector<Instruction*>*
OpNode::codeGen() {
	vector<Instruction*>* ics = NULL, *ics1 = NULL;
	ics = arg_[0]->codeGen();
	const Arg* a1 = arg_[0]->rVal();
	const Arg* a2 = NULL;
	if (arity_ == 2) {
		ics1 = arg_[1]->codeGen();
		a2 = arg_[1]->rVal();
		if (ics && ics1) ics->insert(ics->end(), ics1->begin(), ics1->end());
		else if (ics1) ics = ics1;
	}
	// perform the actual operation
	if (!ics) ics = new vector<Instruction*>;
	const Arg* u = unCoercedVal();
	const Arg* r = rVal();
	Type::TypeTag rT = type()->tag();
	Type::TypeTag cT = coercedType() ? coercedType()->tag() : Type::VOID;
	Instruction::Icode ic;
	switch (opCode_) {
			case OpCode::PLUS:
				ic = (Type::isIntegral(rT)) ? Instruction::ADD : Instruction::FADD;
				ics->push_back(new Instruction(ic, a1, a2, u, NULL));
				break;
			case OpCode::MINUS:
				ic = (Type::isIntegral(rT)) ? Instruction::SUB: Instruction::FSUB;
				ics->push_back(new Instruction(ic, a1, a2, u, NULL));
				break;
			case OpCode::MULT:
				ic = (Type::isIntegral(rT)) ? Instruction::MUL: Instruction::FMUL;
				ics->push_back(new Instruction(ic, a1, a2, u, NULL));
				break;
			case OpCode::DIV:
				ic = (Type::isIntegral(rT)) ? Instruction::DIV: Instruction::FDIV;
				ics->push_back(new Instruction(ic, a1, a2, u, NULL));
				break;
			case OpCode::UMINUS:
				//arg_[0]->rVal(a1);
				rVal(a1);
				ic = (Type::isIntegral(rT)) ? Instruction::NEG: Instruction::FNEG;
				ics->push_back(new Instruction(ic, a1, a2, a1, NULL));
				break;
			case OpCode::MOD:
				ics->push_back(new Instruction(Instruction::MOD, a1, a2, u, NULL));
				break;
			case OpCode::BITAND:
				ics->push_back(new Instruction(Instruction::AND, a1, a2, u, NULL));
				break;
			case OpCode::BITOR:
				ics->push_back(new Instruction(Instruction::OR, a1, a2, u, NULL));
				break;
			case OpCode::BITXOR:
				ics->push_back(new Instruction(Instruction::XOR, a1, a2, u, NULL));
				break;
			default:;
	}
	if (Type::isCoerce(rT, cT)) {
			ic = (Type::isFloat(cT)) ? Instruction::MOVIF : Instruction::MOVFI;
			ics->push_back(new Instruction(ic, u, NULL, r, NULL));
	}
	icode(ics);
	return ics;
}

