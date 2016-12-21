#include "MemAlloc.h"

map<Register*, string> MemAlloc::regToVarMap;
map<string, Register*> MemAlloc::varToRegMap;

int MemAlloc::iRegNum(0),
	MemAlloc::fRegNum(0),
	MemAlloc::tempNum(0),
	MemAlloc::globalOffset(GLOBAL_OFFSET_LOC);

static const Register* BP_ = MemAlloc::get_next_reg(
	string("BP"), Type::type[Type::INT]);
static const Register* SP_ = MemAlloc::get_next_reg(
	"SP", Type::type[Type::INT]);

const Register* BP() { return BP_; }
const Register* SP() { return SP_; }

Register* MemAlloc::get_next_reg(string vName, const Type* t) {
	Register* r = NULL;
	if (Type::isIntegral(t->tag()))
		r = get_next_ireg();
	else if (Type::isFloat(t->tag()))
		r = get_next_freg();
	if (r) {
		varToRegMap[vName] = r;
		regToVarMap[r] = vName;
		r->varName(vName);
	}
	return r;
}

Register* MemAlloc::get_next_temp_reg(const Type* t) {
	string tName = "T" + to_string(tempNum++);
	return get_next_reg(tName, t);
}

Register* MemAlloc::get_next_ireg() {
	// TODO: check overflow conditions
	if (iRegNum > IREG_MAX_NUM) {
		cout << "Int register count overflow" << endl;
	}
	return new IReg(iRegNum++);
}

Register* MemAlloc::get_next_freg() {
	// TODO: check overflow conditions
	if (fRegNum > FREG_MAX_NUM) {
		cout << "Float register count overflow" << endl;
	}
	return new FReg(fRegNum++);
}

