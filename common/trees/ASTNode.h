#ifndef ASTNODE
#define ASTNODE
#include<iostream>

//节点类型
enum class ASTNodeType
{
    root=1,
    defFunc=2,//声明函数
    callFunc=3,//调用函数
    stmt=4,
    exp=5,//表达式
    op=6,//操作符，包括
    defVar=7,
    assignVar=8,
    loop=9,//循环
    conditional=10,//条件

};

class ASTNode
{
    private:
        ASTNodeType nodeType;
        ASTNode* parent=NULL;
        ASTNode* child=NULL;
        ASTNode* brother=NULL;
    
    protected:
        std::string content;
        //__printTree
    
    public:
        ASTNode(){};
        ASTNode(ASTNodeType type);
        ASTNode(ASTNodeType type,char* content);
        inline ASTNodeType getNodeType() { return this->nodeType; }
        inline AbstractASTNode* getParent() { return this->parent; }
        inline AbstractASTNode* getChild() { return this->child; }
        inline AbstractASTNode* getBrother() { return this->brother; }
        inline std::string getContent() { return this->content; }
        inline void setParent(ASTNode* parentNode){this->parent=parentNode;}
        void addChildNode(ASTNode* childNode);
        void addBrother(ASTNode* brotherNode);
        ASTNode* getLastBrother();
        void printTree();
        virtual void printInfo(int depth) = 0;
};


class RootNode : public ASTNodeType
{
    public:
        RootNode(){this->nodeType=root;this->content="root";};
        void printInfo(int depth);
};
#endif
