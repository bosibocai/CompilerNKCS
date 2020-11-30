#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

#include <string>
#include <unordered_map> //每个符号表用hash实现
#include <stack> //stack中存不同作用域的符号表



enum class Type{
    unset = -1,
    integer = 0,
    boolean = 1,
    string = 2,
    pointer = 3,
    Array = 4,
    Struct = 5
};

class Symbol{
protected:
    std::string name;
    Type type;
    int  width; //当前type的宽度，未赋值时设为-1，int=4, float=8
    int offset; //Tabel中相对地址
public:
    Symbol();
    Symbol(std::string name, Type type);
    std::string getName;
    int getOffset();
    int getWidth();
    Type &getType();
    void setWidth(int width);
    void setOffset(int offset);
};


class SymbolTable{
private:
    std::unordered_map<std::string, Symbol*> symbolHash;
public:
SymbolTable();
    int insertSymbol();
    Symbol* findSymbol();
};


#endif //!SYMBOL_TABLE