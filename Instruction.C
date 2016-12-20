#include "Instruction.h"

void
Instruction::print(ostream& os, int indent) {
    if (lbl_) { lbl_->print(os, 0); os << ' '; }
    os << Instruction::icode[icode_] << ' ';
    arg1_->print(os, 0);
    if (arg2_) {
        os << ' ';
        arg2_->print(os, 0);
    }
    if (res_) {
        os << ' ';
        res_->print(os, 0);
    }
}

const string Instruction::icode[] = {
    "ADD",
    "SUB",
    "DIV",
    "MUL",
    "MOD",
    "NEG",
    "AND",
    "OR",
    "XOR",
    "FADD",
    "FSUB",
    "FDIV",
    "FMUL",
    "FNEG",
    /* TODO not used */
    "GT",
    "GE",
    "UGT",
    "UGE",
    "EQ",
    "NE",
    "FGT",
    "FGE",
    "FEQ",
    "FNE",
    "PRTI",
    "PRTS",
    "PRTF",
    "JMP",
    "JMPC",
    "JMPI",
    "JMPCI",
    "MOVL",
    "MOVS",
    "MOVI",
    "MOVF",
    "MOVIF",
    "MOVFI",
    "LDI",
    "LDF",
    "STI",
    "STF",
    "IN",
    "INI",
    "INF"
};
