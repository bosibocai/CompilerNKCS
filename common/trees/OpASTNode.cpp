#include "OpASTNode.h"

OpASTNode::OpASTNode(char *content,opType op_type):ASTNode(content,ASTNodeType::op)
{
    this->op_type=op_type;
}

void OpASTNode::printInfo(int depth)
{
    std::cout<<"op:"<<this->content<<std::endl;
}