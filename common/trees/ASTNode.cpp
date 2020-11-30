#include<typeinfo>
#include "ASTNode.h"

ASTNode::ASTNode(ASTNodeType type)
{
    this->nodeType=type;
}

ASTNode::ASTNode(ASTNodeType type,char* content)
{
    this->nodeType=type;
    this->content=content;
}

void ASTNode::addChildNode(ASTNode* childNode)
{
    //添加孩子节点，并将该孩子节点包括其兄弟节点的父节点指向该节点
    this->child=childNode;
    if(childNode!=NULL)
    {
        childNode->parent=this;
        ASTNode* brotherNode=childNode->brother;
        while(brotherNode!=NULL)
        {
            brotherNode->parent=this;
            brotherNode=brotherNode->brother;
        }
    }

}

void ASTNode::addBrother(ASTNode* brotherNode)
{
    //添加兄弟节点，并将兄弟的父节点指向该节点的父节点
    this->brother=brotherNode;
    if(brotherNode!=NULL)
    {
        brotherNode->parent=this->parent;
    }

}

ASTNode* ASTNode::getLastBrother()
{
    ASTNode* node = this;
    while(node->brother!=NULL)
    {
        node=node->brother;
    }
    return node;
}

void ASTNode::printTree()
{

}

void RootNode::printInfo(int depth)
{
    std::cout<<this->content<<std::endl;
}