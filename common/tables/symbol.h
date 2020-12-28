#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

#include <string>
#include <unordered_map> //每个符号表用hash实现
#include <vector> //存所有的symbols

//#include "../trees/ASTNode.h"

enum class Type{
    unset = -1,
    integer = 0,
    boolean = 1,
    string = 2,
    pointer = 3,
    Array = 4, 
    MAIN = 5, 
    RETURN = 6
// >>>>>>> 9e09d97804f67bd7667174bc856b2816771ef11b
};

// std::unordered_map<Type, int> type_width{
//     {Type::unset, 0},
//     {Type::integer, 4},
//     {Type::boolean, 1},
//     {Type::pointer, 16},
// };

// --------------------------------------------
// Symbol类：符号，符号表中的每一项
// --------------------------------------------
class Symbol{
protected:
    std::string name;
    Type type;
    int id; //这个Symbol存在vector中第几个位置
    int  width; //当前type的宽度，未赋值时设为-1，int=4, float=8
    int offset; //Table中相对地址
public:
    Symbol();
    Symbol(std::string name, Type type);
    std::string getName();
    int getOffset();
    int getWidth();
    Type &getType();
    // 传参的时候，若type为Array,width应设置为（个数*类型宽度）
    void setWidth(int width);
    void setOffset(int offset);
    void setId(int id);
};




// --------------------------------------------
// SymbolTable类：符号表，每个作用域都维护自己的符号表
// 不同符号表通过树相连
// --------------------------------------------
class SymbolTable{
protected:
    // 用名字当作Symbol地址
    std::unordered_map<std::string, Symbol*> symbolHash;
    SymbolTable* father;
    SymbolTable* child;
    SymbolTable* brother;
    SymbolTable* root;
    // 未实现函数调用，此处isFun应为False
    bool isFun;
    int totalOffset;
    int offsetFromRoot;
    // totalOffsetFromRoot记录下一个符号表相对于rootTable的offset，初始化为0，只有rootTable维护这个值。
    int totalOffsetFromRoot;
    
public:
    inline SymbolTable() {};
    SymbolTable(bool isFun, SymbolTable* father);
    Symbol* insertSymbol(std::string name, Type type);
    // 如果符号表项是一个数组：传参直接是结点的指针
    // Symbol* insertArraySymbol(std::string name);
    Symbol* insertArraySymbol(std::string name, int length);
    SymbolTable* findSymbol(std::string name);
    SymbolTable* findSymbolinThisTable(std::string name);
    Symbol* find_symbol_return_symble(std::string name);
    Symbol* find_symbol_in_table_return_symbol(std::string name);
    Symbol* findSymbolfromRoot(std::string name);
    SymbolTable* findSymbolfromRootReturnTable(std::string name);
    void setFather(SymbolTable* f);
    void setChild(SymbolTable* c);
    void setBrother(SymbolTable* b);
    void setOffsetFromRoot(int offset);
    void setTotalOffsetFromRoot(int new_offset);
    inline void getAllSymbol(){ 
        std::unordered_map<std::string, Symbol*>::iterator it = this->symbolHash.begin();
	while(it != symbolHash.end()) {
		std::cout<<it->first<<" "<<it->second->getName()<< std::endl;
		it++;
	}
    }
    SymbolTable* getFather();
    SymbolTable* getChild();
    SymbolTable* getBrother();
    SymbolTable* getThisTable();
    SymbolTable *createChildTable(bool isFun);
    // 返回每个符号表内部的总偏移量
    int getTotalOffset();
    // 返回相对于根符号表的下一个可用偏移量
    int getTotalOffsetFromRoot();
    // 返回每个符号表相对于根符号表的偏移量
    int getOffsetFromRoot();
};

// --------------------------------------------
// Root类：根符号表，树中根节点
// 对应main()函数
// 除符号表功能外，根符号表维护所有符号的vector
// 所有符号的vector功能未知……先跟着学长写吧，说不定后面会用到
// --------------------------------------------
class RootTable: public SymbolTable{
public:
    int symbolCount;
    int tatalOffset;
    std::vector<Symbol*> *symbols;
    RootTable();
    inline Symbol* fine_symbol_in_root( std::string name){
    SymbolTable* t = this;
   
    while(t->getChild()!=NULL){
        t->getAllSymbol();
        if (t->find_symbol_in_table_return_symbol(name)!= NULL){
            return t->find_symbol_in_table_return_symbol(name);
        }else{
            t = t-> getChild();
        }
    }
     if (t->find_symbol_in_table_return_symbol(name)!= NULL){
            return t->find_symbol_in_table_return_symbol(name);
    }else{
        std::cout << "fine_symbol_in_root is NULL" << std::endl;
        return NULL;
    }

    }
};

#endif //!SYMBOL_TABLE