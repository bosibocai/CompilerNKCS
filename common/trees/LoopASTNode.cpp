#include "LoopASTNode.h"

//FOR 循环节点初始化
LoopASTNode::LoopASTNode(char* content,LoopType type,ASTNode *stmts,ASTNode* init,ASTNode* condition,ASTNode* increment):ASTNode(content,ASTNodeType::loop)
{
    this->loopType=type;
    this->addChildNode(stmts);
    this->init=init;
    if(init != NULL)
    {
        init->setParent(this);
    }
    this->condition=condition;
    if(condition!=NULL)
    {
        condition->setParent(this);
    }
    this->increment=increment;
    if(increment!=NULL)
    {
        increment->setParent(this);
    }
}
//WHILE 循环节点初始化
LoopASTNode::LoopASTNode(char* content,LoopType type,ASTNode *stmts,ASTNode* condition):ASTNode(content,ASTNodeType::loop)
{
    this->loopType=type;
    this->addChildNode(stmts);
    this->condition=condition;
    this->init=init;
    if(condition!=NULL)
    {
        condition->setParent(this);
    }
    this->increment=NULL;
}

void LoopASTNode::printInfo(int depth)
{
    //FOR循环打印
    if(this->loopType==LoopType::FOR)
    {
        std::cout<<"FOR"<<std::endl;
        ASTNode::printSelf(this->init,depth+1);
        ASTNode::printSelf(this->condition,depth+1);
        ASTNode::printSelf(this->increment,depth+1);
    }
    //WHILE循环打印
    else
    {
        std::cout<<"WHILE"<<std::endl;
        ASTNode::printSelf(this->condition,depth+1);
    }
    
}