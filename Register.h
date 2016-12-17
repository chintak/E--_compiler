#ifndef REGISTER_H
#define REGISTER_H

#include <cstdio>
#include <string>

using namespace std;

class Register {
public:
    Register(int n) : num_(n) {}
    ~Register();
    virtual string name() const=0;
    virtual void print(ostream& os, int indent) const=0;
    int num() const { return num_; }

private:
    int num_;
};

class IReg : public Register {
public:
    IReg(int n) : Register(n) {}
    ~IReg();
    string name() const {
        char c[5];
        sprintf(c, "R%03d", num());
        return string(c);
    }
    inline void print(ostream& os, int indent) const {
        os << name();
    }
};

class FReg : public Register {
public:
    FReg(int n) : Register(n) {}
    ~FReg();
    string name() const {
        char c[5];
        sprintf(c, "F%03d", num());
        return string(c);
    }
    inline void print(ostream& os, int indent) const {
        os << name();
    }
};

#endif
