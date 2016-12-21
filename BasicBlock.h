#include "Instruction.h"
#include <map>
#include <set>

class BasicBlock {
public:
    BasicBlock(Instruction* is);
    vector<BasicBlock*>* getSucc() { return succ_; }
    vector<BasicBlock*>* getPred() { return pred_; }
    void add_succ(BasicBlock* b) { succ_->push_back(b); }
    void add_pred(BasicBlock* b) { pred_->push_back(b); }
    static map<string, BasicBlock*> labelToBlockMap;
    set<std::string> gen;
    set<std::string> kill;
    set<std::string> In;
    set<std::string> Out;
private:
    vector<BasicBlock*>* succ_ = NULL;
    vector<BasicBlock*>* pred_ = NULL;
    Instruction *is_;
};

vector<BasicBlock*>* createBlocks(vector<Instruction*>* iVec);
void liveVarAnalysis(vector<BasicBlock*>* blocks);
void printBlock(BasicBlock* b);