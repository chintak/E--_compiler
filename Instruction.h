#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Register.h"
#include "Value.h"


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
	Instruction() {}
	Instruction(Icode o, Arg* a1, Arg* a2=NULL, Arg* r=NULL, Label* l=NULL) :
		icode_(o), arg1_(a1), arg2_(a2), res_(r), lbl_(l) {}
	~Instruction();
	void print(ostream& os, int indent);

	static const string icode[];  // contains the mapping from Icode enum to actual instruction name in string

private:
	Icode icode_;
	Arg* arg1_;
	Arg* arg2_;
	Arg* res_;
	Label* lbl_;
};
#endif
