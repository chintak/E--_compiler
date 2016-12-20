#ifndef REGISTER_H
#define REGISTER_H

#include <cstdio>
#include <string>
#include "Value.h"

using namespace std;

class Arg {
public:
    enum ArgKind {
        REGISTER,
        CONSTANT,
        LABEL
    };

    Arg() {}
    Arg(ArgKind a) { argKind_ = a; }
    ~Arg() {}
    ArgKind argKind() { return argKind_; }
    void argKind(ArgKind a) { argKind_ = a; }

private:
    ArgKind argKind_;
};


class Register : public Arg {
public:
    Register(int n) : Arg(Arg::REGISTER) { num_ = n; }
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

class Constant : public Arg {
public:
    Constant(Value* v) : Arg(Arg::CONSTANT) { val_ = v; }
private:
    Value* val_;
};

class Label : public Arg {
public:
    Label(string l) : Arg(Arg::LABEL), lab_(l) {}
    ~Label();
    string name() const { return lab_; }
    void print(ostream& os, int indent) const {
        os << name() + string(":");
    }

private:
    string lab_;
};

#endif
