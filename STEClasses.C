#include "STEClasses.h"
#include "Value.h"
#include "ParserUtil.h"

void GlobalEntry::print(ostream& out, int indent) const
{
	out << "\n";
	printST(out, indent, ' ', '\0');

	out << "\n";
	for (unsigned int i = 0; i < rules_.size(); i++) {
		rules_[i]->print(out, indent);
	}
	prtSpace(out, indent + STEP_INDENT);
	out << "\n";
}

void GlobalEntry::typePrint(ostream& out, int indent) const
{
	out << "\n";
	typePrintST(out, indent, ' ', '\0');

	out << "\n";
	for (unsigned int i = 0; i < rules_.size(); i++) {
		rules_[i]->typePrint(out, indent);
	}
	prtSpace(out, indent + STEP_INDENT);
	out << "\n";
}

const Type* GlobalEntry::typeCheck()
{
	typeCheckST();

	for (unsigned int i = 0; i < rules_.size(); i++) {
		// cout << "rule: " << rules_[i]->line() << endl;
		rules_[i]->typeCheck();
	}
	return NULL;
}
void ClassEntry::print(ostream& out, int indent) const
{
	prtSpace(out, indent);
	out << "class "<< name();
	out << ";";
}

void ClassEntry::typePrint(ostream& out, int indent) const
{
	out << "class "<< name();
	out << ";";
}

const Type*
ClassEntry::typeCheck() {
	return NULL;
}

void FunctionEntry::print(ostream& out, int indent) const
{
	const vector<const Type*> *argTypes = type()->argTypes();
	int nrLocalVars;

	type()->retType()->print(out, indent);
	out << " " << name();

	if (argTypes) {
		printST(out, indent, '(', ')', false, 0, argTypes->size());
	} else {
		out << "()";
	}
	if (body_) {
		out << " {\n";
		if (symTab()) {
			if (argTypes) {
				nrLocalVars = symTab()->size() - argTypes->size();
			} else {
				nrLocalVars = symTab()->size();
			}
		} else {
			nrLocalVars = 0;
		}
		if (nrLocalVars) {
			prtSpace(out, indent + STEP_INDENT);
			if (argTypes)
				printST(out, indent + STEP_INDENT, '\0', '\0', true,
					argTypes->size(), argTypes->size() + nrLocalVars);
			else
				printST(out, indent + STEP_INDENT, '\0', '\0', true);
		}

		for (list<StmtNode*>::iterator it = body_->stmts()->begin(); it != body_->stmts()->end(); it++)
			if (*it) {
				ostringstream oss;
				(*it)->print(oss, indent);
				if (oss.str().empty())
					continue;
				(*it)->print(out, indent);
				endln(out, indent);
			}
		prtSpace(out, indent);
		out << "}";
	}
	out << ";";
}

void FunctionEntry::typePrint(ostream& out, int indent) const
{
	const vector<const Type*> *argTypes = type()->argTypes();
	int nrLocalVars;

	type()->retType()->print(out, indent);
	out << " " << name();

	if (argTypes) {
		typePrintST(out, indent, '(', ')', false, 0, argTypes->size());
	} else {
		out << "()";
	}
	if (body_) {
		out << " {\n";
		prtSpace(out, indent);
		if (symTab()) {
			if (argTypes) {
				nrLocalVars = symTab()->size() - argTypes->size();
			} else {
				nrLocalVars = symTab()->size();
			}
		} else {
			nrLocalVars = 0;
		}
		if (nrLocalVars) {
			prtSpace(out, indent);
			if (argTypes)
				typePrintST(out, indent + STEP_INDENT, '\0', '\0', true,
					argTypes->size(), argTypes->size() + nrLocalVars);
			else
				typePrintST(out, indent + STEP_INDENT, '\0', '\0', true);
		}

		for (list<StmtNode*>::iterator it = body_->stmts()->begin(); it != body_->stmts()->end(); it++)
			if (*it) {
				ostringstream oss;
				(*it)->typePrint(oss, indent + STEP_INDENT);
				if (oss.str().empty())
					continue;
				prtSpace(out, STEP_INDENT);
				(*it)->typePrint(out, indent + STEP_INDENT);
				endln(out, indent);
			}
		out << '}';
	}
	if (!body_)
		out << ';';
}

const Type* FunctionEntry::typeCheck()
{
	typeCheckST();
	if (body_) {
		for (list<StmtNode*>::iterator it = body_->stmts()->begin();
				it != body_->stmts()->end(); it++) {
			if (*it) {
				(*it)->typeCheck();
			}
		}
	}
	return Type::type[Type::VOID];
}

void EventEntry::print(ostream& out, int indent) const
{
	out << "event "<< name();
	printST(out, indent, '(', ')', false);
	out << ";";
}

void EventEntry::typePrint(ostream& out, int indent) const
{
	out << "event "<< name();
	typePrintST(out, indent, '(', ')', false);
	out << ";";
}

void VariableEntry::print(ostream& out, int indent) const
{
	type()->print(out, indent);
	out << " " << name();
	if (initVal_) {
		out << " = ";
		initVal_->print(out, indent);
	}
	if (vkind_ == GLOBAL_VAR || vkind_ == LOCAL_VAR)
		out << ";";
}

void VariableEntry::typePrint(ostream& out, int indent) const
{
	type()->print(out, indent);
	out << " " << name();
	if (initVal_) {
		out << " = ";
		initVal_->typePrint(out, indent);
	}
}

const Type*
VariableEntry::typeCheck()
{
	if (initVal_) {
		const Type* retType = initVal_->typeCheck();
		Type::TypeTag l, r;
		r = retType->tag();
		l = typeTag();
		if (((Type::isPrimitive(l) && Type::isSubType(r, l)) ||
				 (retType == type()))) {
			return type();  // no need to perform coersion here
		} else {
			errMsg("Assignment between incompatible types",
					line(), 0, file().c_str());
			kind(SymTabEntry::Kind::ERROR_KIND);
			return Type::type[Type::ERROR];
		}
	}
	return type();
}

void BlockEntry::print(ostream& out, int indent) const
{

}

/************** Mem Alloc *******************/

void
GlobalEntry::memAlloc() {
	int staticAreaLoc = 0;
	SymTab* st = symTab();
	VariableEntry* ve;
	SymTab::iterator it = NULL;

	for (it = st->begin(); it != st->end(); ++it)  {
		if ((*it)->kind() == SymTabEntry::Kind::VARIABLE_KIND) {
			ve = (VariableEntry *)(*it);
			if (ve->varKind() == VariableEntry::GLOBAL_VAR) {
				ve->offSet(staticAreaLoc);
				staticAreaLoc++;
				ve->memAlloc();
			}
		} else if ((*it)->kind() == SymTabEntry::Kind::FUNCTION_KIND) {
			(*it)->memAlloc();
		}
	}
}

void
VariableEntry::memAlloc() {
	if (initVal()) {
		initVal()->memAlloc();  // allocate regs for computing rhs
	}
	if (vkind_ == VariableEntry::LOCAL_VAR) {
		lVal(MemAlloc::get_next_reg(name(), type()));
	} else if (vkind_ == VariableEntry::GLOBAL_VAR) {
		const Value* o = new Value(offSet_, Type::UINT);
		const Constant* c = new Constant(o);
		lVal(c);
	} // TODO write condition for PARAM_VAR
}

void
FunctionEntry::memAlloc() {
	// store local variables at an offset of BP-- & param vars at BP++
	int locVarOffset = 0;
	int paramVarOffset = 1;
	SymTab* st = symTab();
	VariableEntry* ve;
	SymTab::iterator it = NULL;

	if (!st) return;

	for (it = st->begin(); it != st->end(); ++it)  {
		if ((*it)->kind() == SymTabEntry::Kind::VARIABLE_KIND) {
			ve = (VariableEntry *)(*it);
			if (ve->varKind() == VariableEntry::LOCAL_VAR) {
				ve->offSet(locVarOffset);
				locVarOffset--;
				if (ve->initVal()) ve->memAlloc();
			} else if (ve->varKind() == VariableEntry::PARAM_VAR) {
				ve->offSet(paramVarOffset);
				paramVarOffset++;
			}
		}
	}
}

/************** Code Gen *******************/

vector<Instruction*>*
GlobalEntry::codeGen() {
	SymTab* st = symTab();
	VariableEntry* ve;
	SymTab::iterator it = NULL;
	vector<Instruction*>* ics = NULL, *instr_set = NULL;

	for (it = st->begin(); it != st->end(); ++it)  {
		if ((*it)->kind() == SymTabEntry::Kind::VARIABLE_KIND) {
			ve = (VariableEntry *)(*it);
			if (ve->varKind() == VariableEntry::GLOBAL_VAR) {
				ics = ve->codeGen();
				if (ics) {
					if (instr_set)
						instr_set->insert(instr_set->end(), ics->begin(), ics->end());
					else instr_set = ics;
				}
			}
		}
	}
	if (instr_set)
			for (unsigned int i = 0; i < instr_set->size(); i++) {
					(*instr_set)[i]->print(cout, 0);
					cout << "\n";
			}
	return instr_set;
}

vector<Instruction*>*
VariableEntry::codeGen() {
	// move the variable offset into a register
	if (initVal() == NULL)
		return NULL;

	// do code gen for RHS
	ExprNode* rhs = initVal();
	vector<Instruction*>* instr_set = rhs->codeGen();
	if (!instr_set) instr_set = new vector<Instruction*>;
	const Arg* r = rhs->rVal();

	// do rval computation
	if (vkind_ == VariableEntry::GLOBAL_VAR) {
		const Arg* l = lVal();

		// store the value
		Instruction::Icode i_code = Instruction::Icode::STI;
		i_code = ((type()->tag() == Type::TypeTag::DOUBLE) ?
			Instruction::Icode::STF : i_code);
		instr_set->push_back(new Instruction(i_code, r, NULL, l, NULL));
	} else if (vkind_ == VariableEntry::LOCAL_VAR) {
		// do lval computation
		const Value* o = new Value(offSet_, Type::UINT);
		const Arg* off = new Constant(o);
		const Arg* l = lVal();
		instr_set->push_back(
			new Instruction(Instruction::Icode::MOVI, off, NULL, l, NULL));
		instr_set->push_back(
			new Instruction(Instruction::Icode::ADD, BP(), l, l, NULL));

		// store the value
		Instruction::Icode i_code = Instruction::Icode::STI;
		i_code = ((type()->tag() == Type::TypeTag::DOUBLE) ?
			Instruction::Icode::STF : i_code);
		instr_set->push_back(new Instruction(i_code, r, NULL, l, NULL));
	}
	// Register* r = NULL;


	// Instruction::Icode i_code1 = Instruction::Icode::MOVI;
	// Instruction::Icode i_code2 = Instruction::Icode::STI;
	// if (type()->tag() == Type::TypeTag::DOUBLE)
	// {
	// 	i_code1 = Instruction::Icode::MOVF;
	// 	i_code2 = Instruction::Icode::STF;
	// }
	// if (i_code1 == Instruction::Icode::MOVI)
	// 	r  = MemAlloc::get_next_ireg();
	// else
	// 	r  = MemAlloc::get_next_freg();

	// instr_set->push_back(new Instruction(i_code1, new Constant(initVal()->value()), NULL, r, NULL)); // stores initval into a  reg.
	// if (varKind() != VariableEntry::VarKind::GLOBAL_VAR)
	// {
	// 	Register* r1 = MemAlloc::get_next_ireg();
	// 	instr_set->push_back(new Instruction(Instruction::Icode::MOVI, off, NULL, r1, NULL)); // move offset into r1
	// 	Register* r2 = MemAlloc::get_next_ireg();
	// 	if (varKind() == VariableEntry::VarKind::LOCAL_VAR)
	// 		instr_set->push_back(new Instruction(Instruction::Icode::ADD, r1, IReg::BP(), r2, NULL)); // store final offset in r2
	// 	else if (varKind() == VariableEntry::VarKind::PARAM_VAR)
	// 		instr_set->push_back(new Instruction(Instruction::Icode::ADD, r1, IReg::SP(), r2, NULL)); // store final offset in r2

	// 	instr_set->push_back(new Instruction(i_code2,r,r2)); // updates value stored in mem.

	// }
	// instr_set->push_back(new Instruction(i_code2,r,off)); // updates value stored in mem.

	return instr_set;
}


