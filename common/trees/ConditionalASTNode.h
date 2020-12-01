#ifndef CONDITIONALASTNODE
#define CONDITIONALASTNODE
#include "ASTNode.h"
#include "StmtASTNode.h"

enum class conditionalType
{
    IF=1,
    ELSE=2,
};

class ConditionalASTNode:public ASTNode
{
    private:
        conditionalType condition_type;
        ASTNode* condition;
        ASTNode* body;
        ASTNode* elseBody;
    public:
        ConditionalASTNode(char* content, conditionalType condition_type,ASTNode* condition, ASTNode* body, ASTNode* elseBody=NULL);
        inline ASTNode* getCondition(){return this->condition;}
        inline ASTNode* getBody(){return this->body;}
        inline ASTNode* getElseBody(){return this->elseBody;}
        void printInfo(int depth);
};

#endif