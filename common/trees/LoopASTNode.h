#ifndef LOOPASTNODE
#define LOOPASTNODE
#include "ASTNode.h"

//循环类型，for,while
enum class LoopType
{
    FOR,
    WHILE,
};

class LoopASTNode:public ASTNode
{
    private:
        LoopType loopType;
        //for 循环语句包括三部分，初始init、判断条件condition、更新循环控制变量increment
        //while 循环语句只有判断条件
        ASTNode* init;
        ASTNode* condition;
        ASTNode* increment;


        //代码块部分也为该节点的child
    public:
        //FOR 循环节点初始化
        LoopASTNode(char* content,LoopType type,ASTNode *stmts,ASTNode* init,ASTNode* condition,ASTNode* increment);
        //WHILE 循环节点初始化
        LoopASTNode(char* content,LoopType type,ASTNode *stmts,ASTNode* condition);
        inline LoopType getLoopType(){return this->loopType;}
        inline ASTNode* getInit(){return this->init;}
        inline ASTNode* getCondition(){return this->condition;}
        inline ASTNode* getIncrement(){return this->increment;}
        void printInfo(int depth);
}

#endif