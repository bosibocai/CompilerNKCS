#ifndef LITERALASTNODE
#define LITERALASTNODE
#include "ASTNode.h"
#include "LiteralASTNode.h"

class LiteralASTNode:public ASTNode
{
    public:
        LiteralASTNode(char* content);
        void printInfo(int depth);
        //得到字面量的值--将string转化为int
        int getValue();
};

#endif