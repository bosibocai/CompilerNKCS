#ifndef STMTASTNODE
#define STMTASTNODE
#include "ASTNode.h"

enum class stmtType
{
    //语句类别，包括声明语句，表达式，复合语句，返回语句
    defStmt=1,
    expStmt=2,
    compoundStmt=3,
    returnStmt=4,
    printStmt=5,
};

class StmtASTNode:public ASTNode
{
    private:
        stmtType stmt_type;

    public:
        StmtASTNode(stmtType stmt_type);
        inline stmtType getType(){return this->stmt_type;}
        void printInfo(int depth);
};

#endif