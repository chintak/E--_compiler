#include "MemAlloc.h"

int MemAlloc::iRegNum(0),
    MemAlloc::fRegNum(0),
    MemAlloc::globalOffset(GLOBAL_OFFSET_LOC);


Register* MemAlloc::get_next_reg(const Type* t) {
    Register* r = NULL;
    if (Type::isIntegral(t->tag()))
        r = get_next_ireg();
    else if (Type::isFloat(t->tag()))
        r = get_next_freg();
    cout << r->name() << endl;
    return r;
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
