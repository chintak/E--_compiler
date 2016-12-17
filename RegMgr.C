#include "RegMgr.h"
#include <stdlib.h>
#include <utility> 
#include <sstream>
#include <iomanip>


RegMgr::RegMgr()
{
	intReg_ = new bool[INT_REG_COUNT];
	floatReg_ = new bool[FLOAT_REG_COUNT];
	floatCount_ = 0;
	intCount_ = 0;
	nextInt_ = 0;
	nextFloat_ = 0;
	for (int i = 0; i < INT_REG_COUNT; i++)
		intReg_[i] = false;
	for (int i = 0; i < FLOAT_REG_COUNT; i++)
		floatReg_[i] = false;
}

string RegMgr::getReg(RegType t, VariableEntry *ve)
{
	int reg = -1;

	if (t == RegMgr::RegType::INT && intCount_ < INT_REG_COUNT)
	{
	
		if ( intReg_[nextInt_] == true)
		{
			while(true)
			{
				if (intReg_[nextInt_] == 0)
					break;
				nextInt_ = (nextInt_ + 1)%INT_REG_COUNT;
			}
		}

		reg = nextInt_;
		intReg_[nextInt_] = 1;
		nextInt_ = (nextInt_ + 1)%INT_REG_COUNT;
		intCount_++;
		
	}
	else if (floatCount_ < FLOAT_REG_COUNT)
	{
	
		if ( floatReg_[nextFloat_] == true)
		{
			while(true)
			{
				if (floatReg_[nextFloat_] == 0)
					break;
				nextFloat_ = (nextFloat_ + 1)%FLOAT_REG_COUNT;
			}
		}

		reg = nextFloat_;
		floatReg_[nextFloat_] = 1;
		nextFloat_ = (nextFloat_ + 1)%FLOAT_REG_COUNT;
		floatCount_++;
	}
	if (reg != -1)
	{		
		regMap_[ve] =reg;
		return RegMgr::getRegName(reg, t);
	}
	return "Err";

}

void RegMgr::freeReg(VariableEntry *ve, RegMgr::RegType t)
{
	int i = regMap_[ve];
	if (t == RegMgr::RegType::INT)
	{
		intCount_--;
		intReg_[i] = 0;
	}
	else
	{
		floatCount_--;
		floatReg_[i] = 0;
	}
}

void RegMgr::freeReg(string regName)
{
	RegMgr::RegType t = getRegType(regName);
	int reg = getRegNumber(regName);

	if (t == RegMgr::RegType::INT)
	{
		intCount_--;
		intReg_[reg] = 0;
	}
	else
	{
		floatCount_--;
		floatReg_[reg] = 0;
	}

}

string RegMgr::getRegName(int reg, RegMgr::RegType t)
{
	ostringstream ss;
	if (t == RegMgr::RegType::INT)
		ss << "R";
	else
		ss << "F";
	ss << setw(3) << setfill('0') << reg;
	return ss.str();
}

RegMgr::RegType RegMgr::getRegType(string regName)
{
	if (regName[0] == 'F')
		return RegMgr::RegType::FLOAT;
	return RegMgr::RegType::INT;
}

int RegMgr::getRegNumber(string regName)
{
	regName.erase(0, 1);
	return atoi(regName.c_str());
}

RegMgr* RegMgr::initRegMgr()
{
	if (regMgr)
		return new RegMgr();
	return NULL;
}

RegMgr::~RegMgr()
{
	delete intReg_;
	delete floatReg_;
}

RegMgr *regMgr = RegMgr::initRegMgr();