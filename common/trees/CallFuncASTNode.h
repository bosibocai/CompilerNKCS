#ifndef CALLFUNCASTNODE
#define CALLFUNCASTNODE
#include "ASTNode.h"

class CallFuncASTNode:public ASTNode
{
    private:
        //参数列表
        ASTNode* parameters;
    public:
        CallFuncASTNode(char* content,ASTNode* parameters);
        inline ASTNode* getParameters(){return this->parameters;}
        void printInfo(int depth);
}

#endif