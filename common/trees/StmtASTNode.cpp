#include "StmtASTNode.h"

StmtASTNode::StmtASTNode(stmtType stmt_type):ASTNode(ASTNodeType::stmt)
{
    this->stmt_type=stmt_type;
}

void StmtASTNode::printInfo(int depth)
{
    if(this->stmt_type==stmtType::defStmt)
    {
        std::cout<<"Def statement."<<std::endl;
    }
    else if(this->stmt_type==stmtType::expStmt)
    {
        std::cout<<"Exp statement."<<std::endl;
    }
    else if(this->stmt_type==stmtType::compoundStmt)
    {
        std::cout<<"Compound statement."<<std::endl;
    }
    else if(this->stmt_type==stmtType::returnStmt)
    {
        std::cout<<"Return statement."<<std::endl;
    }
    else if(this->stmt_type==stmtType::printStmt)
    {
        std::cout<<"Print statement."<<std::endl;
    }

}