#include "BasicBlock.h"
#include <iterator>
#include <algorithm>  
map<string, BasicBlock*> BasicBlock::labelToBlockMap;

vector<BasicBlock*>* createBlocks(vector<Instruction*>* iVec) {
    vector<BasicBlock*>* blocks = new vector<BasicBlock*>();
    BasicBlock *bl = NULL;
    string s;
    blocks->reserve(iVec->size());
    for (unsigned int i=0; i<iVec->size(); i++) {
        bl = new BasicBlock((*iVec)[i]);    
        s = (*iVec)[i]->label();
        if (s != "") {
         BasicBlock::labelToBlockMap[(*iVec)[i]->label()] = bl;
        }
        blocks->push_back(bl);
    }
    for (unsigned int i=0; i < iVec->size(); i++) {
        if (i > 0) (*blocks)[i]->add_pred((*blocks)[i-1]);
        if (i < iVec->size()-1) (*blocks)[i]->add_succ((*blocks)[i+1]);
        if ((*iVec)[i]->targetLabel() != "") {
            bl = BasicBlock::labelToBlockMap[(*iVec)[i]->label()];
            (*blocks)[i]->add_succ(bl);
            bl->add_pred((*blocks)[i]);
        }
     }
    return blocks;
}

BasicBlock::BasicBlock(Instruction* is) {
    is_ = is;
    Register *r;
    succ_ = new vector<BasicBlock*>();
    pred_ = new vector<BasicBlock*>();
    if (is_->arg1() && is_->arg1()->argKind() == Arg::REGISTER) {
        r = (Register*)(is_->arg1());
        gen.insert(r->varName());
    }
    if (is_->arg2() && is_->arg2()->argKind() == Arg::REGISTER) { 
        r = (Register*)(is_->arg2());
        gen.insert(r->varName());
    }
    if (is_->result() && is_->result()->argKind() == Arg::REGISTER) {
        r = (Register*)(is_->result()); 
        kill.insert(r->varName());
    }
}
void printBlock (BasicBlock *b) {
    set<std::string> temp;
    set<std::string>::iterator iter;
    if (b) {
        temp = b->gen;
        cout <<":: Gen"<<endl;
        for(iter=temp.begin(); iter!=temp.end();++iter) cout << (*iter) <<endl;

        temp = b->kill;
        cout <<":: Kill"<<endl;
        for(iter=temp.begin(); iter!=temp.end();++iter) cout << (*iter) <<endl;
        
        temp = b->In;
        cout <<":: In"<<endl;
        for(iter=temp.begin(); iter!=temp.end();++iter) cout << (*iter) <<endl;

        temp = b->Out;
        cout <<":: Out"<<endl;
        for(iter=temp.begin(); iter!=temp.end();++iter) cout << (*iter) <<endl;
    }
}

void liveVarAnalysis(vector<BasicBlock*>* blocks) {
    vector<BasicBlock*>* succ;
    set<std::string> temp;
    set<std::string>::iterator iter;
    bool sameIn = false;
    bool sameOut = false;
    for (unsigned int i=0; i<blocks->size(); i++) {
        (*blocks)[i]->In = (*blocks)[i]->gen;
    }
    while(sameIn==false && sameOut == false) {
    for (unsigned int i=0; i<blocks->size(); i++) {
        succ = (*blocks)[i]->getSucc();
        if (succ) {
            for (unsigned int j=0; j<succ->size(); j++) {
                temp.insert((*succ)[j]->In.begin(), (*succ)[j]->In.end());
            }
        }
        if ((*blocks)[i]->Out == temp) sameOut=true;
        (*blocks)[i]->Out = temp;
        temp.clear();
        set_difference( (*blocks)[i]->Out.begin(), (*blocks)[i]->Out.end(), (*blocks)[i]->kill.begin(), (*blocks)[i]->kill.end(), inserter(temp, temp.begin()));
        if (succ)
        {  for (unsigned int k=0; k<succ->size(); k++) {
                temp.insert((*succ)[k]->gen.begin(), (*succ)[k]->gen.end());
            }
        }
        if ((*blocks)[i]->In == temp) sameIn = true;
        (*blocks)[i]->In = temp;
        temp.clear();
        cout <<"Block"<<i<<endl;
        printBlock((*blocks)[i]);
    }
}
}