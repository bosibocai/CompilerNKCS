#include "ConditionalASTNode.h"

ConditionalASTNode::ConditionalASTNode(char* content, conditionalType condition_type,ASTNode* condition, ASTNode* body, ASTNode* elseBody):ASTNode(content,ASTNodeType::conditional)
{
    this->condition_type=condition_type;
    this->condition=condition;
    this->body=body;
    this->elseBody=elseBody;
    //body、if条件、else body部分是条件判断节点的孩子节点，通过指针可访问，还要添加孩子节点向上的指针
    this->body->setParent(this);
    this->condition->setParent(this);
    //如果 else body 部分非空
    if(elseBody)
    {
        this->elseBody->setParent(this);
    }
}

void ConditionalASTNode::printInfo(int depth)
{
    if(this->condition_type==conditionalType::IF)
    {
        std::cout<<"IF"<<std::endl;
        ASTNode::printSelf(this->condition,depth+1);
        ASTNode::printSelf(this->body,depth+1);
        //如果有else语句
        if(this->elseBody)
        {
            for (int i=0;i<depth;i++)
            {
                std::cout<<"--";
            }
            std::cout<<"ELSE"<<std::endl;
            ASTNode::printSelf(this->elseBody,depth+1);
        }
    }
}