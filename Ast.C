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

void RefExprNode::print(ostream& os, int indent) const
{
	os << ext_;
}


void RefExprNode::typePrint(ostream& os, int indent) const
{
	type()->print(os, indent);
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

void ValueNode::print(ostream& os, int indent) const
{
	value()->print(os, indent);
}

void ValueNode::typePrint(ostream& os, int indent) const
{
	value()->type()->print(os, indent);
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
	return kind() == PatNodeKind::SEQ;
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

void PatNode::print(ostream& os, int indent) const
{
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

void PatNode::typePrint(ostream& os, int indent) const
{
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

bool PatNode::hasSeqOps() const
{
	return kind() == PatNodeKind::SEQ;
}

bool PatNode::hasNeg() const
{
	return kind() == PatNodeKind::NEG;
}

bool PatNode::hasAnyOrOther() const
{
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
				prtln(os, indent);
				first = false;
			}
			(*it)->typePrint(os, indent);
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
