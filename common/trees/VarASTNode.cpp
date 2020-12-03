#include "VarASTNode.h"
VarASTNode::VarASTNode(char* content,ASTNode* value):ASTNode(content,ASTNodeType::callVar)
{
    this->addChildNode(value);
}

void VarASTNode::printInfo(int depth)
{
    std::cout<<"Var"<<" "<<this->content<<std::endl;
}