#ifndef MEMALLOC_H
#define MEMALLOC_H

#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include "Register.h"
#include "Type.h"

/*
R000 BP
ROO1 SP
*/

#define IREG_MAX_NUM 999
#define FREG_MAX_NUM 999
#define GLOBAL_OFFSET_LOC 0

using namespace std;

const Register* BP();
const Register* SP();

class MemAlloc {
public:
    MemAlloc() {}
    ~MemAlloc();
    // Get the next register
    static Register* get_next_reg(string vName, const Type* t);
    static Register* get_next_temp_reg(const Type* t);

    static map<Register*, string> regToVarMap;
    static map<string, Register*> varToRegMap;
    static Register* BP_;
    static Register* SP_;

private:
    static Register* get_next_ireg();
    static Register* get_next_freg();


    static int iRegNum;
    static int fRegNum;
    static int tempNum;
    static int globalOffset;
};

#endif
