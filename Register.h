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
    virtual Type::TypeTag typeTag() const { return Type::VOID; }
    ArgKind argKind() { return argKind_; }
    void argKind(ArgKind a) { argKind_ = a; }
    virtual void print(ostream& os, int indent) const=0;

private:
    ArgKind argKind_;
};


class Register : public Arg {
public:
    enum RegKind {
        INT,
        FLOAT
    };
    Register(RegKind k, string vName, int n) : Arg(Arg::REGISTER)
        { num_ = n; regKind_ = k; varName_ = vName; }
    Register(RegKind k, int n) : Arg(Arg::REGISTER)
        { num_ = n; regKind_ = k; }
    ~Register();

    virtual string name() const=0;
    int num() const { return num_; }
    RegKind regKind() { return regKind_; }
    RegKind regKind() const { return regKind_; }
    string varName() { return varName_; }
    string varName() const { return varName_; }
    void varName(string vName) { varName_ = vName; }
    // void varName(string vName) const { varName_ = vName; }

    Type::TypeTag typeTag() const {
        if (regKind() == Register::INT) return Type::INT;
        else return Type::DOUBLE;
    }

private:
    int num_;
    string varName_;
    enum RegKind regKind_;
};

class IReg : public Register {
public:
    IReg(int n) : Register(INT, n) {}
    IReg(string vName, int n) : Register(INT, vName, n) {}
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
    FReg(int n) : Register(FLOAT, n) {}
    FReg(string vName, int n) : Register(FLOAT, vName, n) {}
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
    Constant(const Value* v) : Arg(Arg::CONSTANT) { val_ = v; }
    const Value* val() { return val_; }
    Type::TypeTag typeTag() const {
        return val_->type()->tag();
    }

private:
    void print(ostream& os, int indent) const {
        val_->print(os, indent);
    }
    const Value* val_;
};

class Label : public Arg {
public:
    Label(string l) : Arg(Arg::LABEL), lab_(l) {}
    ~Label();
    string name() const { return lab_; }
    void print(ostream& os, int indent) const {
        os << name();
    }

private:
    string lab_;
};

#endif
