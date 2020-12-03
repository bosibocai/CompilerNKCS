#include "DefVarASTNode.h"
#include <cstring>

DefVarASTNode::DefVarASTNode(char *content, ASTNode *value):ASTNode(content,ASTNodeType::defVar)
{
    this->symbolType = Type::unset;
    //value节点为孩子节点
    this->addChildNode(value);
    //content中是id
}

void DefVarASTNode::setSymbolType(char* type)
{
    //定义symbol类型,int 和 point
    Type t;
    if(strcmp(type,"integer")==0)
    {
        t=Type::integer;
    }
    else if(strcmp(type,"pointer")==0)
    {
        t=Type::pointer;
    }
    if(this->symbolType==Type::unset)
    {
        this->symbolType=t;
    }
    //同时定义多个变量时
    DefVarASTNode *brotherNode=(DefVarASTNode*)this->getBrother();
    while(brotherNode!=NULL)
    {
        if(brotherNode->symbolType==Type::unset)
        {
            brotherNode->symbolType=t;
        }
        brotherNode=(DefVarASTNode*)brotherNode->getBrother();
    }
}

void DefVarASTNode::setSymbolType(char* type,char *len)
{
    //定义symbol类型，array
    Type t;
    if(strcmp(type,"array")==0)
    {
        t=Type::Array;
    }
    if(this->symbolType==Type::unset)
    {
        this->symbolType=t;
    }
    this->arrayLen=atoi(len);
    //同时定义多个变量时
    DefVarASTNode *brotherNode=(DefVarASTNode*)this->getBrother();
    while(brotherNode!=NULL)
    {
        if(brotherNode->symbolType==Type::unset)
        {
            brotherNode->symbolType=t;
        }
        brotherNode=(DefVarASTNode*)brotherNode->getBrother();
    }
}

void DefVarASTNode::printInfo(int depth)
{
    //变量声明 包括 类型和id
    std::cout<<"Var Declaration. ";
    //id
    std::cout<<this->content;
    //类型
    if(this->symbolType == Type::integer)
        std::cout<<" type: int";
    else if(this->symbolType==Type::pointer)
        std::cout<<" type: pointer";
    else if(this->symbolType==Type::Array)
        std::cout<<" type: array"<<" size: "<<this->arrayLen;
    std::cout<<std::endl;
}

