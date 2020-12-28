#include <iostream>
#include "symbol.h"
// #include "../trees/DefVarASTNode.h"
using namespace std;

// --------------------------------------------
// Symbol类：符号，符号表中的每一项
// --------------------------------------------
Symbol::Symbol(){
    this -> name = "";
    this -> type = Type::integer;
    this -> id = -1;
    this -> width = -1;
    this -> offset = -1;
}

Symbol::Symbol(std::string name, Type type){
    this -> name = name;
    this -> type = type;
}

std::string Symbol::getName(){ 
    return this -> name;
}

int Symbol::getOffset(){
    return this -> offset;
}

int Symbol::getWidth(){
    return this -> width;
}

Type &Symbol::getType(){
    return this -> type;
}

void Symbol::setWidth(int width){
    this -> width = width; 
}

void Symbol::setOffset(int offset){
    this -> offset = offset;
}

void Symbol::setId(int id){
    this -> id = id;
}


// --------------------------------------------
// SymbolTable类：符号表，每个作用域都维护自己的符号表
// 不同符号表通过树相连
// --------------------------------------------
SymbolTable::SymbolTable(bool isFun, SymbolTable* father){
    // 未实现函数调用，参数isFun应为false
    this -> father = father;
    this -> child = NULL;
    this -> brother = NULL;
    SymbolTable* temp = this;
    while(temp->father != NULL){
        temp = temp ->father;
    }
    this -> root = temp;
    this -> isFun = isFun;
    this -> totalOffset = 0;
    // offsetFromRoot记录每个符号表相对于rootTable的offset
    if(father!=NULL)
        this -> offsetFromRoot = temp -> getTotalOffsetFromRoot();
    else
        this -> offsetFromRoot = 0;
    // totalOffsetFromRoot记录每个符号表相对于rootTable的下一个可用offset
    // 只有rootTable会不断更新，别的符号表都是0
    this -> totalOffsetFromRoot = 0;
}

// 返回符号表，词法分析要输出的列表里面用的是符号表的地址
SymbolTable* SymbolTable::findSymbolinThisTable(std::string name){
    std::unordered_map<std::string, Symbol*>::iterator it = this->symbolHash.find(name);
    if(it!=this->symbolHash.end())
        return this;
    else
        {
            cout << "findSymbolinThisTable  NULL" << endl;
            return NULL;
        }
        
}

SymbolTable* SymbolTable::findSymbol(std::string name){
    SymbolTable* temp = this;
    while(temp != NULL){
        SymbolTable* flag = temp->findSymbolinThisTable(name);
        if(flag==NULL)
        {
            temp = temp->father;
        }
            
        else
            return flag;
    }
    std::cout<<"variable(findSymbol) "<<name<<" is undefined"<<std::endl;
    return NULL;
}

Symbol* SymbolTable::findSymbolfromRoot(std::string name){
    std::cout<<"find symbol from root"<<std::endl;
    SymbolTable* temp = this;
    while(temp->find_symbol_in_table_return_symbol(name)==NULL){
        if(temp->getFather()==NULL){
            temp = temp->getChild();
        }
        else{
            if (temp->getBrother()!=NULL)
                temp->getBrother();
            else{
                temp  = temp->getFather()->getChild()->getChild();
            }
        }
    }
    Symbol* s = temp->find_symbol_in_table_return_symbol(name);
    return s;
}


SymbolTable* SymbolTable::findSymbolfromRootReturnTable(std::string name){
    SymbolTable* temp = this;
    while(temp->find_symbol_in_table_return_symbol(name)==NULL){
        if(temp->getFather()==NULL){
            temp = temp->getChild();
        }
        else{
            if (temp->getBrother()!=NULL)
                temp->getBrother();
            else{
                temp  = temp->getFather()->getChild()->getChild();
            }
        }
    }
    return temp;
}

// 返回符号，中间代码生成需要用到符号
Symbol* SymbolTable::find_symbol_in_table_return_symbol(std::string name){
    std::unordered_map<std::string, Symbol*>::iterator it = this->symbolHash.find(name);
    if(it!=this->symbolHash.end())
        {
            cout << "find_symbol_in_table_return_symble"<<it->second->getName()<<endl;
            return it->second;
        }
    else{
        cout << "find_symbol_in_table_return_symble NULL" << endl;
        return NULL;
    }
        
}

Symbol* SymbolTable::find_symbol_return_symble(std::string name){
    SymbolTable* temp = this;
     std::cout <<"find_symbol_return_symble      "<< name << "  "  << std::endl;
     temp->getAllSymbol();
    while(temp != NULL){
        Symbol* flag = temp->find_symbol_in_table_return_symbol(name);
        if(flag==NULL)
        {
            temp->getAllSymbol();
            temp = temp->father;
            cout << "father" << endl;
            
        }
        else
// <<<<<<< HEAD
            return flag;
// =======
//             return flag->find_symbol_in_table_return_symbol(name);
// >>>>>>> 6f2c25dff8bdee9a4a40aad1ac7ed8a286b078c6
    }
    std::cout << "\033[31mError（find_symbol_return_symble）: \033[0m"
              << "value " << name << " is not defined" << std::endl;
    exit(1);
    return NULL;
}


Symbol* SymbolTable::insertSymbol(std::string name, Type type){
    if(this->findSymbolinThisTable(name)!=NULL){
        std::cout << "findSymbolinThisTable insertSymbol \n" ;
        this->findSymbolinThisTable(name)->getAllSymbol();
        return NULL;
    }
        
    std::cout<<"variable(insertSymbol) "<<name<<" is undefined"<<std::endl;
    Symbol* temp = new Symbol(name, type);
    std::cout<< "temp new symbol" << std::endl;
    int width = 4;
    // temp -> setId(this->root->symbolCount++);
    temp -> setWidth(width);
    std::cout<<"set width: "<<width<< std::endl;
    temp -> setOffset(this->totalOffset);
    std::cout<<"set offset: "<<this->totalOffset<<std::endl;
    this -> totalOffset += width;
    std::cout<<"Next offset can be used: "<<this->getTotalOffset()<<std::endl;
    // this->root->symbols->push_back(temp);
    this->symbolHash[name] = temp;
    std::cout<< "symbolHash[name]" << name << this->symbolHash[name]->getName() <<std::endl;
    return temp;
}

// Symbol* SymbolTable::insertArraySymbol(std::string name){
//     if(this->findSymbol(name) != NULL)
//         return NULL;
//     Symbol* temp = new Symbol(name, Type::Array);
//     // Type itemType = arrayNode -> getSymbolType();
//     //int width = arrayNode -> getArrayLen()*type_width.find(itemType)->second;
//     int width = arrayNode -> getArrayLen()*4;
//     // temp -> setId(this->root->symbolCount++);
//     temp -> setWidth(width);
//     std::cout<<"set width: "<<width<< std::endl;
//     temp -> setOffset(this->totalOffset);
//     std::cout<<"set offset: "<<this->totalOffset<<std::endl;
//     this -> totalOffset += width;
//     // this->root->symbols->push_back(temp);
//     this->symbolHash[name] = temp;
//     return temp;
// }

Symbol* SymbolTable::insertArraySymbol(std::string name, int length){
    if(this->findSymbol(name) != NULL)
        return NULL;
    Symbol* temp = new Symbol(name, Type::Array);
    // Type itemType = arrayNode -> getSymbolType();
    //int width = arrayNode -> getArrayLen()*type_width.find(itemType)->second;
    int width = length*4;
    // temp -> setId(this->root->symbolCount++);
    temp -> setWidth(width);
    std::cout<<"set width: "<<width<< std::endl;
    temp -> setOffset(this->totalOffset);
    std::cout<<"set offset: "<<this->totalOffset<<std::endl;
    this -> totalOffset += width;
    std::cout<<"Next offset can be used: "<<this->getTotalOffset()<<std::endl;
    // this->root->symbols->push_back(temp);
    this->symbolHash[name] = temp;
    return temp;
}

void SymbolTable::setFather(SymbolTable* f){
    this->father = f;
}

void SymbolTable::setChild(SymbolTable* c){
    this->child = c;
}

void SymbolTable::setBrother(SymbolTable* b){
    this->brother = b;
}

void SymbolTable::setOffsetFromRoot(int offset){
    this ->offsetFromRoot = offset;
}

void SymbolTable::setTotalOffsetFromRoot(int new_offset){
    this -> root -> totalOffsetFromRoot += new_offset;
}

SymbolTable* SymbolTable::getFather(){
    return this->father;
}

SymbolTable* SymbolTable::getChild(){
    return this->child;
}

SymbolTable* SymbolTable::getBrother(){
    return this->brother;
}

SymbolTable* SymbolTable::getThisTable(){
    return this;
}

// 返回相对于根符号表的下一个可用偏移量
int SymbolTable::getTotalOffsetFromRoot(){
    return this->root->totalOffsetFromRoot;
}

// 返回每个符号表相对于根符号表的偏移量
int SymbolTable::getOffsetFromRoot(){
    return this -> offsetFromRoot;
}

// <<<<<<< HEAD
// SymbolTable *SymbolTable::createChildTable(bool isFun)
// {

//     SymbolTable *child = new SymbolTable(isFun,this);
//     cout << "createChildTable" << endl;
//     if (this->getChild() == NULL)
//     {
//          cout << "this->getChild() == NULL" << endl;
//          this->setChild(child);
//     }
//     else if (this->getChild()->getBrother() == NULL)
//     {
//         // ????
//         cout << "this->getChild()->getBrother()" << endl;
//         this->getChild()->setBrother(child);
//         cout << "this->getChild()->getBrother(1)" << endl;
//     }
//     else
//     {
//         // SymbolTable *brother = this->getChild()->getBrother();
//         SymbolTable *brother = this->getChild()->getBrother();
//         cout << "this->getChild()->getBrother();" << endl;
//         while (brother != NULL)
//         {
//             if (brother->getBrother() == NULL)
//                 break;
//             brother = brother->getBrother();
//         }
//         cout << " while (brother != NULL)" << endl;
//         brother->setBrother(child);
// =======
SymbolTable *SymbolTable::createChildTable(bool isFun){
    SymbolTable* childTable = new SymbolTable(isFun, this);
    std::cout<<"new a child symbol table"<<std::endl;
    if(this->getChild()!=NULL){
        std::cout<<"first child not NULL, now finding brother teble"<<std::endl;
        if(this->getChild()->getBrother()!=NULL){
            SymbolTable* brotherTable = this->getChild()->getBrother();
            while(brotherTable->getBrother()!=NULL)
                brotherTable = brotherTable->getBrother();
            brotherTable->setBrother(childTable);
        }
        else{
            this->getChild()->setBrother(childTable);
        }
    }
    else{
        std::cout<<"first child is NULL"<<std::endl;
        this->setChild(childTable);
// >>>>>>> 6f2c25dff8bdee9a4a40aad1ac7ed8a286b078c6
    }
    return childTable;
}

int SymbolTable::getTotalOffset(){
    return this->totalOffset;
}


// --------------------------------------------
// Root类：根符号表，树中根节点
// 对应main()函数
// 除符号表功能外，根符号表维护所有符号的vector
// 所有符号的vector功能未知……先跟着学长写吧，说不定后面会用到
// --------------------------------------------
RootTable::RootTable(){
    this -> father = NULL;
    this -> root = this;
    this -> child = NULL;
    this -> brother = NULL;
    // Root为main函数，此时isFun为true
    this -> isFun = true;
    this -> symbols = new std::vector<Symbol*>();
}