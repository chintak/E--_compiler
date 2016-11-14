#include "STEClasses.h"
#include "Value.h"
#include "ParserUtil.h"

void GlobalEntry::print(ostream& out, int indent) const
{
	out << "\n";
	printST(out, indent, '\0', '\0');

	out << "\n";
	for (unsigned int i = 0; i < rules_.size(); i++) {
		rules_[i]->print(out, indent);
	}
	prtSpace(out, indent + STEP_INDENT);
	out << "\n";
}

void ClassEntry::print(ostream& out, int indent) const
{
	prtSpace(out, indent);
	out << "class "<< name();
	out << ";";
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

void EventEntry::print(ostream& out, int indent) const
{
	prtSpace(out, indent);
	out << "event "<< name();
	printST(out, indent, '(', ')', false);
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

void BlockEntry::print(ostream& out, int indent) const
{

}
