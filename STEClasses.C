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
        if (ve->initVal()) ve->initVal()->memAlloc();
      }
    } else if ((*it)->kind() == SymTabEntry::Kind::FUNCTION_KIND) {
      (*it)->memAlloc();
    }
  }
}

void
FunctionEntry::memAlloc() {
  int locVarOffset = 0;
  int paramVarOffset = 1;
  SymTab* st = symTab();
  VariableEntry* ve;
  SymTab::iterator it = NULL;

  for (it = st->begin(); it != st->end(); ++it)  {
    if ((*it)->kind() == SymTabEntry::Kind::VARIABLE_KIND) {
      ve = (VariableEntry *)(*it);
      if (ve->varKind() == VariableEntry::LOCAL_VAR) {
        ve->offSet(locVarOffset);
        locVarOffset--;
        if (ve->initVal()) ve->initVal()->memAlloc();
      } else if (ve->varKind() == VariableEntry::PARAM_VAR) {
        ve->offSet(paramVarOffset);
        paramVarOffset++;
      }
    }
  }
}
