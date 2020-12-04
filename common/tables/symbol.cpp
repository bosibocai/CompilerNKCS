#include <iostream>
#include "symbol.h"
#include "../trees/DefVarASTNode.h"


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
    while(temp->isFun)
        temp = temp -> father;
    this -> root = temp;
    this -> isFun = isFun;
}

Symbol* SymbolTable::findSymbolinThisTable(std::string name){
    std::unordered_map<std::string, Symbol*>::iterator it = this->symbolHash.find(name);
    if(it!=this->symbolHash.end())
        return it->second;
    else
        return NULL;
}

Symbol* SymbolTable::findSymbol(std::string name){
    SymbolTable* temp = this;
    while(temp != NULL){
        Symbol* flag = temp->findSymbolinThisTable(name);
        if(flag==NULL)
            temp = temp->father;
        else
            return flag;
    }
    std::cout<<"variable "<<name<<" is undefined"<<std::endl;
    return NULL;
}

Symbol* SymbolTable::insertSymbol(std::string name, Type type){
    if(this->findSymbol(name)!=NULL)
        return NULL;
    Symbol* temp = new Symbol(name, type);
    int width = 4;
    // temp -> setId(this->root->symbolCount++);
    temp -> setWidth(width);
    // temp -> setOffset(this->root->tatalOffset);
    // this->root->tatalOffset += width;
    // this->root->symbols->push_back(temp);
    this->symbolHash[name] = temp;
    return temp;
}

Symbol* SymbolTable::insertArraySymbol(ASTNode* node){
    DefVarASTNode* arrayNode = (DefVarASTNode*) node;
    std::string name = arrayNode -> getContent();
    if(this->findSymbol(name) != NULL)
        return NULL;
    Symbol* temp = new Symbol(name, Type::Array);
    Type itemType = arrayNode -> getSymbolType();
    //int width = arrayNode -> getArrayLen()*type_width.find(itemType)->second;
    int width = arrayNode -> getArrayLen()*4;
    // temp -> setId(this->root->symbolCount++);
    temp -> setWidth(width);
    // temp ->setOffset(this->root->tatalOffset);
    // this->root->tatalOffset += width;
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

SymbolTable* SymbolTable::getFather(){
    return this->father;
}

SymbolTable* SymbolTable::getChild(){
    return this->child;
}

SymbolTable* SymbolTable::getBrother(){
    return this->brother;
}

// --------------------------------------------
// Root类：根符号表，树中根节点
// 对应main()函数
// 除符号表功能外，根符号表维护所有符号的vector
// 所有符号的vector功能未知……先跟着学长写吧，说不定后面会用到
// --------------------------------------------
// Root::Root(){
//     this -> father = NULL;
//     this -> root = this;
//     this -> child = NULL;
//     this -> brother = NULL;
//     // Root为main函数，此时isFun为true
//     this -> isFun = true;
//     this -> symbols = new std::vector<Symbol*>();
// }