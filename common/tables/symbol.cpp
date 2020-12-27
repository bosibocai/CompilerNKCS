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

// 返回符号表，词法分析要输出的列表里面用的是符号表的地址
SymbolTable* SymbolTable::findSymbolinThisTable(std::string name){
    std::unordered_map<std::string, Symbol*>::iterator it = this->symbolHash.find(name);
    if(it!=this->symbolHash.end())
        return this;
    else
        return NULL;
}

SymbolTable* SymbolTable::findSymbol(std::string name){
    SymbolTable* temp = this;
    while(temp != NULL){
        SymbolTable* flag = temp->findSymbolinThisTable(name);
        if(flag==NULL)
            temp = temp->father;
        else
            return flag;
    }
    std::cout<<"variable(findSymbol) "<<name<<" is undefined"<<std::endl;
    return NULL;
}

// 返回符号，中间代码生成需要用到符号
Symbol* SymbolTable::find_symbol_in_table_return_symbol(std::string name){
    std::unordered_map<std::string, Symbol*>::iterator it = this->symbolHash.find(name);
    if(it!=this->symbolHash.end())
        return it->second;
    else
        return NULL;
}

Symbol* SymbolTable::find_symbol_return_symbol(std::string name){
    SymbolTable* temp = this;
    while(temp != NULL){
        SymbolTable* flag = temp->findSymbolinThisTable(name);
        if(flag==NULL)
            temp = temp->father;
        else
            return flag->find_symbol_in_table_return_symbol(name);
    }
    std::cout<<"variable(find_symbol_return_symble) "<<name<<" is undefined"<<std::endl;
    return NULL;
}


Symbol* SymbolTable::insertSymbol(std::string name, Type type){
    if(this->findSymbolinThisTable(name)!=NULL)
        return NULL;
    std::cout<<"variable(insertSymbol) "<<name<<" is undefined"<<std::endl;
    Symbol* temp = new Symbol(name, type);
    std::cout<< "temp new symbol" << std::endl;
    int width = 4;
    // temp -> setId(this->root->symbolCount++);
    temp -> setWidth(width);
    std::cout<< "setWidth(width);" << std::endl;
    // temp -> setOffset(this->root->tatalOffset);
    // this->root->tatalOffset += width;
    // this->root->symbols->push_back(temp);
    this->symbolHash[name] = temp;
    std::cout<< "symbolHash[name]" << std::endl;
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

void SymbolTable::setBrother(SymbolTable* b){
    this->brother = b;
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

SymbolTable *SymbolTable::createChildTable(bool isFun){
    SymbolTable* childTable = new SymbolTable(isFun, this);
    std::cout<<"new a child symbol table"<<std::endl;
    if(this->getChild()!=NULL){
        std::cout<<"first child not NULL, now finding brother teble"<<std::endl;
        if(this->getChild()->getBrother()!=NULL){
            SymbolTable* brotherTable = this->getChild()->getBrother();
            while(brotherTable!=NULL)
                brotherTable = brotherTable->getBrother();
            brotherTable->setBrother(childTable);
        }
        else{
            this->getChild()->getBrother()->setBrother(childTable);
        }
    }
    else{
        std::cout<<"first child is NULL"<<std::endl;
        this->setChild(childTable);
    }
    return childTable;
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