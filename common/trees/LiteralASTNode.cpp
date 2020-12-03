#include "LiteralASTNode.h"

LiteralASTNode::LiteralASTNode(char* content):ASTNode(content,ASTNodeType::literal)
{
    //继承ASTNode初始化
}

void LiteralASTNode::printInfo(int depth)
{
    std::cout<<"Literal "<<std::stoi(this->content)<<std::endl;
}

int LiteralASTNode::getValue()
{
    return std::stoi(this->content);
}
