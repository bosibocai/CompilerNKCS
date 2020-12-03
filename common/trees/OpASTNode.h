#ifndef OPASTNODE
#define OPASTNODE
#include "ASTNode.h"

enum class opType
{
    //操作符集
    add=1, // +
    subtract=2, // -
    multiply=3, // *
    divide=4, // /
    mod=5, // %
    pow=6, // ^
    assign=7, // =
    relop=8, // <,>,<=,>=,!=
    andop=9, // &&
    orop=10, //||
    notop=11, // !
    getArrayValue=12, // a[n]
    assignArrayValue=13, // a[n]=
    getvalue = 14, //*a
    negative = 15, //-a
    signaland = 16 //&a
};

class OpASTNode:public ASTNode
{
    private:
        opType op_type;
    
    public:
        OpASTNode(char *content,opType op_type);
        inline opType getType(){return this->op_type;}
        void printInfo(int depth);

};

#endif