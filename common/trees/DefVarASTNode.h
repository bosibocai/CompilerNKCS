#ifndef DEFVARASTNODE
#define DEFVARASTNODE
#include "ASTNode.h"
#include "../tables/symbol.h"

class DefVarASTNode:public ASTNode
{
    private:
        Type symbolType;
        //实现一维数组,保存长度
        int arrayLen;

    public:
        //声明变量，value指向数据节点，如果是数组则指向的是第一个,初始化该节点时只能声明该节点是初始化变量的节点不能设置变量类型？？
        DefVarASTNode(char *content, ASTNode *value = NULL);
        void printInfo(int depth);
        inline Type getSymbolType(){return this->symbolType;}
        inline int getArrayLen(){return this->arrayLen;}
        //设置变量类型
        void setSymbolType(char *type);
        //如果一维数组，输入type和长度
        void setSymbolType(char *type, char *len);
};

#endif