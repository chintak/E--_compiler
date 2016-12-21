#ifndef LABELGENERATOR_H
#define LABELGENERATOR_H


#include <iostream>
#include <string>
#include "Register.h"

class LabelGenerator {
public:
    LabelGenerator() {}
    ~LabelGenerator();
    
    static Label* getLabel();
    static vector<Label*>* getIfLabel();

private:
    static int ifCount;
    static int lableCount;
};

#endif
