#ifndef REGMGR_H
#define REGMGR_H

#include <map>
#include <string>

#define SP "R000" 
#define BP "R001" 
#define RET_I "R002" 
#define RET_ADDR "R003"
#define RET_F "F000"
#define TOTAL_REG "1000" 
#define INT_REG_COUNT 994
#define FLOAT_REG_COUNT 999

using namespace std;

class VariableEntry;

class RegMgr {

	enum class RegType {
		INT, FLOAT
	};
	private:
		static string getRegName(int reg, RegType t);
		static RegType getRegType(string regName);
		static int getRegNumber(string regName);
		bool *intReg_, *floatReg_;
		int floatCount_, intCount_, nextInt_, nextFloat_;
		map<VariableEntry*,int> regMap_;

	public:
		string getReg(RegType t, VariableEntry *ve);
		void freeReg(VariableEntry *ve, RegMgr::RegType t);
		void freeReg(string regName);
		static RegMgr* initRegMgr();
		RegMgr();
		~RegMgr();

};

extern RegMgr *regMgr;

#endif