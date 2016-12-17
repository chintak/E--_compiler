#ifndef MEMALLOC_H
#define MEMALLOC_H

#include <cstdio>
#include <iostream>
#include <string>
#include "Register.h"
#include "Type.h"

#define IREG_MAX_NUM 999
#define FREG_MAX_NUM 999
#define GLOBAL_OFFSET_LOC 0

using namespace std;

class MemAlloc {
public:
    MemAlloc() {}
    ~MemAlloc();

    // Get the next register
    static Register* get_next_ireg();
    static Register* get_next_freg();
    static Register* get_next_reg(const Type* t);
    // TODO: stack get next offset allocator method
    // TODO: global next offset allocator method

private:
    static int iRegNum;
    static int fRegNum;
    static int globalOffset;
};

#endif
