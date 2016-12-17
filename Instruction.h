#ifndef INSTRUCTION_H 
#define INSTRUCTION_H

#include "Register.h"

template <class a1, class a2, class r>
class Instruction {

	public:
		enum Icode {
			ADD,
			SUB,
			DIV,
			MUL,
			MOD,
			NEG,
			AND,
			OR,
			XOR,
			FADD,
			FSUB,
			FDIV,
			FMUL,
			FNEG,
			/* TODO not used */
			GT,
			GE,
			UGT,
			UGE,
			EQ,
			NE,
			FGT,
			FGE,
			FEQ,
			FNE,
			PRTI,
			PRTS,
			PRTF,
			JMP,
			JMPC,
			JMPI,
			JMPCI,
			MOVL,
			MOVS,
			MOVI,
			MOVF,
			MOVIF,
			MOVFI,
			LDI,
			LDF,
			STI,
			STF,
			IN,
			INI,
			INF
		};

private:
		Icode icode_;
		a1 *arg1_;
		a2 *arg2_;
		r *result_;
		// TODO label
};
#endif
