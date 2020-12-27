#include "MainASTNode.h"
MainASTNode::MainASTNode(char* content,ASTNode* value):ASTNode(content,ASTNodeType::mainnode)
{
    this->addChildNode(value);
}

void MainASTNode::printInfo(int depth)
{
    std::cout<<"Main"<<std::endl;
}