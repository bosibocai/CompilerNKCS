#ifndef VARASTNODE
#define VARASTNODE
#include "ASTNode.h"

class VarASTNode:public ASTNode
{
    public:
        VarASTNode(char* content,ASTNode* value=NULL);
        void printInfo(int depth);
};

#endif