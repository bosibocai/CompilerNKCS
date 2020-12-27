#ifndef INTERMEDIATE_H
#define INTERMEDIATE_H

#include "../tools.h"
#include "./Quad.h"
#include "../tables/symbol.h"
// #include "../symbol/FuncSymbol.h"
#include <stack>
#include <list>

// Inter mediate code generator
class InterMediate
{
private:
    RootNode *root;
    std::vector<Quad> quads;
    std::vector<Symbol *> tempVar;
    // FuncTable funcTable;
    SymbolTable *rootTable;

    std::stack<std::list<int>> trueList;
    std::stack<std::list<int>> falseList;
    std::stack<int> signal;
    std::stack<Symbol *> childValue;
    // Function for backpatch.
    std::list<int> *makelist(int index);
    std::list<int> *merge(std::list<int> *list1, std::list<int> *list2);
    void backpatch(std::list<int> *backList, int target);

public:
    inline ASTNode *getRoot() { return this->root; }
    inline SymbolTable *getTable() { return this->rootTable; }
    // inline FuncTable &getFuncTable() { return this->funcTable; }
    inline std::vector<Quad> &getQuads() { return this->quads; }
    inline std::vector<Symbol *> &getTempVars() { return this->tempVar; }
    InterMediate(RootNode *rootNode, SymbolTable *symbolTable);
    void Generate(ASTNode *node, SymbolTable *symbolTable);
    // Create a child symbol table to generate follow code.
    SymbolTable *GenerateStmt(StmtASTNode *node, SymbolTable *symbolTable);
    SymbolTable *GenerateReturn(StmtASTNode *node, SymbolTable *symbolTable);
    Symbol *GenerateOp(OpASTNode *node, SymbolTable *symbolTable);
    Quad *CaculateOp(OpCode op, ASTNode *arg1Node, ASTNode *arg2Node, Symbol *result, SymbolTable *symbalTable);
    void RelopOp(Quad *trueQuad, Quad *falseQuad, OpCode op, ASTNode *arg1Node, ASTNode *arg2Node, SymbolTable *symbolTable);
    void printQuads();
};
#endif
