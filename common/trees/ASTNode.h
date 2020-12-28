#ifndef ASTNODE
#define ASTNODE
#include<iostream>
#include "../tables/symbol.h"

//节点类型
enum class ASTNodeType
{
    root=1,
    // defFunc=2,//声明函数，没实现
    // callFunc=3,//调用函数，没实现
    stmt=4, //语句
    exp=5,//表达式
    op=6,//操作符，包括
    defVar=7,//声明变量
    callVar=8,//调用变量
    loop=9,//循环
    conditional=10,//条件
    literal=11,//字面量
    mainnode=12,//main函数节点

};

//   std::ostream& operator<<(std::ostream& os, const ASTNodeType& astnodetype){
//       os << astnodetype;
//         return os;
//   }


/*
    其他节点都继承自该节点，其中声明节点包括声明函数和声明变量需要链接symbol
    nodeType在初始化时赋值，继承ASTNode初始化函数
    父亲节点、兄弟节点、孩子节点只能通过函数获取
*/

class ASTNode
{
    private:
        ASTNodeType nodeType;
        ASTNode* parent=NULL;
        ASTNode* child=NULL;
        ASTNode* brother=NULL;
        SymbolTable* theTable=NULL;
    
    protected:
        std::string content;
        //打印当前节点
        static void printSelf(ASTNode *selfNode,int depth);

    
    public:
        ASTNode();
        ASTNode(ASTNodeType type);
        ASTNode(char* content,ASTNodeType type);
        inline ASTNodeType getNodeType() { return this->nodeType; }
        inline ASTNode* getParent() { return this->parent; }
        inline ASTNode* getChild() { return this->child; }
        inline ASTNode* getBrother() { return this->brother; }
        inline std::string getContent() { return this->content; }
        inline void setParent(ASTNode* parentNode){this->parent=parentNode;}
        inline SymbolTable* getTheTable(){return this->theTable;}
        inline void setTheTable(SymbolTable* theTable){this->theTable=theTable;}
        void addChildNode(ASTNode* childNode);
        void addBrother(ASTNode* brotherNode);
        ASTNode* getLastBrother();
        //打印以当前节点为根节点的抽象语法树
        void printTree();
        virtual void printInfo(int depth) = 0;
};


class RootNode : public ASTNode
{
    public:
        RootNode();
        void printInfo(int depth);
};
#endif
