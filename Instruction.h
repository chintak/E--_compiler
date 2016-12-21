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
	Instruction(Icode o, const Arg* a1, const Arg* a2=NULL, const Arg* r=NULL, const Label* l=NULL) :
		icode_(o), arg1_(a1), arg2_(a2), res_(r), lbl_(l) {}
	~Instruction();
	void print(ostream& os, int indent);
	string label() { if (lbl_)
						return lbl_->name(); 
					 else return string(""); 
				}
	string targetLabel() 
	{
		if (res_ && res_->argKind() == Arg::LABEL)
		{
			const Label* l = (Label*) res_;
			return l->name();
		}
		return string("");
	}
	const Arg* arg1() { return arg1_;}
	const Arg* arg2() { return arg2_;}
	const Arg* result() { return res_;}

	static const string icode[];  // contains the mapping from Icode enum to actual instruction name in string

private:
	Icode icode_;
	const Arg* arg1_;
	const Arg* arg2_;
	const Arg* res_;
	const Label* lbl_;
};
#endif
