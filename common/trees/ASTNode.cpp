#include<typeinfo>
#include "ASTNode.h"

ASTNode::ASTNode() {
    this->child = NULL;
    this->parent = NULL;
    this->brother = NULL;
    this->content = "Initial";
}

ASTNode::ASTNode(ASTNodeType type)
{
    this->nodeType=type;
}

ASTNode::ASTNode(char* content,ASTNodeType type)
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

void ASTNode::printSelf(ASTNode *selfNode,int depth)
{
    //递归
    //深度优先遍历，遇到节点就输出，若节点为空退出
    if(selfNode==NULL) return;
    //打印当前节点深度,及节点深度
    std::cout<<"depth:"<<" "<<depth;
    for(int i = 0;i<depth;i++)
    {
        std::cout<<"--";
    }
    //根据每种节点的特性，打印当前节点Info
    selfNode->printInfo(depth);
    //孩子节点
    ASTNode *childNode=selfNode->child;
    while(childNode!=NULL)
    {
        ASTNode::printSelf(childNode,depth+1);
        childNode=childNode->brother;

    }
}

void ASTNode::printTree()
{
    ASTNode::printSelf(this,0);
}

RootNode::RootNode():ASTNode(ASTNodeType::root)
{
    this->content="Root";
}

void RootNode::printInfo(int depth)
{
    std::cout<<this->content<<std::endl;
}