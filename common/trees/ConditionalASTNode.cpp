#include "ConditionalASTNode.h"

ConditionalASTNode::ConditionalASTNode(char* content, conditionalType condition_type,ASTNode* condition, ASTNode* body, ASTNode* elseBody):ASTNode(content,ASTNodeType::conditional)
{
    this->condition_type=condition_type;
    this->condition=condition;
    this->body=body;
    this->elseBody=elseBody;
    this->body->setParent(this);
    this->condition->setParent(this);
    if(else)
    this->elseBody->setParent(this);
}