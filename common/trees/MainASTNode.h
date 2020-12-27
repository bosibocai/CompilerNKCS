#ifndef MAINASTNODE
#define MAINASTNODE
#include "ASTNode.h"

class MainASTNode:public ASTNode
{
    public:
        MainASTNode(char* content,ASTNode* value=NULL);
        void printInfo(int depth);

};

#endif