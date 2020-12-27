/* 第一部分：说明部分 */
/*
  YACC源程序说明部分定义语法规则中要用的终结符号，
  语义动作中使用的数据类型、变量、语义值的联合类型以及语法规则中运算符的优先级等。说明部分可以是空的。
  说明部分通常包含两部分内容：

  C语言代码部分
  Yacc说明部分
  
  这两部分可以拆分成下面四个小部分：
  头文件表
  宏定义
  数据类型定义
  全局变量定义
*/
%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string>
    #include <fstream>
    #include <cstring>
    #include <string.h>
    #include <iostream>
    #include "../in.h"
    #include "../common/util/AsmGenerator.h"
    #include "../common/util/InterMediate.h"
    #include "../common/tools.h"
    class ASTNode; // 数据类型定义：定义语义动作使用到的数据类型
    extern int yylex(); 
    int yyerror(char* s);
    extern char* yytext;// 外部变量和全局变量定义
    extern FILE* yyin;
    ASTNode* root;
%}


/* 第二部分
文法开始符号定义
语义值类型定义
终结符定义
非终结符定义
优先级和结合性定义
*/

/* 语法开始符号定义
上下文无关文法的开始符号是一个特殊的非终结符，所有的推导都从这个非终结符开始
在yacc中，语法开始符定义语句是
% start 非终结符……
如果没有上面的说明，yacc自动将语法规则部分中第一条语法规则左部的非终结符作为语法开始符
*/

/* 
例:
 % union{
int ival
double dval
INTERVAL vval;
}
引用时候的方式
%token <ival> DREG VREG
%token <dval> CONST
%type  <dval>dexp
%type  <vval>vexp
以%token开始的行定义的是终结符的类型
以%type开始的行定义是非终结符的类型
*/
%union{
    ASTNode* astNode;
    char* str;
}

/* 
优先级和结合性定义
%left 左结合
%right 右结合
%nonassoc 无结合性
%prec <终结符> 强制定义优先级
 */
// right：右结合 -> 赋值 or 取非 or 取负数 or 取地址
%right ASSIGN
%right <astNode> NOT
%right UMINUS
%right <astNode> ADDR 

// left：左结合
%left <astNode> ADD SUBTRACT
%left <astNode> MULTIPLY DIVIDE MOD
%left <astNode> POW
%left <astNode> AND OR
%left <str> RELOP //  > ≥ < ≤  !=

%left LBRAKET RBRAKET // [ ]
%left LP RP // ( )
%left LBRACE RBRACE // { }

// nonassoc：不可结合
%nonassoc SEMICOLON COMMA GETMEMBER
%nonassoc RETURN IF ELSE 

/* 
在yacc源程序语法规则部分出现的所有终结符（正文字符“+”，“-”等除外）等必须用%token定义，定义形式：
单一数据类型：
%token 终结符1 终结符2
多数据类型：
%token <类型> 终结符1 终结符2 …
 */
// token：终结符
%token <str> ID
%token <str> INT
%token <str> TYPE
%token MAIN
%token FOR WHILE
%token PRINTF

// type：非终结符
%type <str> specifier //标识符，声明变量类型 specifier -> TYPE 
%type <astNode> stmts stmt //statement
%type <astNode> expr //expression
%type <astNode> compd //compound
%type <astNode> varDec //变量声明
%type <astNode> def dec decList initFor
%type <astNode> extDefList extDef extDecList

%%

/* 
语法规则部分是整个YACC源程序的主体，它是由一组产生式及相应的语义动作组成。
规则部分包括修改的BNF格式的文法规则，
以及将在识别出识别出相关的文法规则时被执行的C代码中的动作
（即根据LALR（1）分析算法，在归约中使用）。
文法规则中使用的元符号惯例如下：
通常，竖线|被用作替换（也可以分别写出替换项），
而用来分隔文法规则的左右两边的箭头符号-〉
在YACC中用冒号表示，最后，必须用分号来结束每个文法规则。

 */


 /* 
 对文法中的产生式
在YACC程序中可表示成
A：  α1  |  {语义动作1}
    | α2 {语义动作2}  
    |
    | αm {语义动作m}   
;
  */

/* 没有默认指定%start，默认使用program为文法开始符号 */
/* 
  YACC中的动作是由在每个文法规则中将其写作真正的C代码（在大括号中）来实现的。
  在书写动作时，可以使用YACC伪变量。当识别一个文法规则时，
  规则中的每个符号都拥有一个值，除非它被参数改变了。
  这些值由YACC保存在一个与分析栈保持平行的值栈（value stack）中，
  每个在栈中的符号值都可以使用以$开始的伪变量来引用。
  $$代表刚才被识别出来的非终结符的值，也就是文法规则左边的符号。
  伪变量$1、$2、$3等代表了文法规则右边的每个连续的符号。
*/
prog:
        extDefList{
            root = new RootNode();
            root -> addChildNode($1);
        }
;

/* 
  例：文法规则和动作：
  exp	:	exp '+' term	{ $$ = $1 + $3; }
  含义是：当识别规则exp->exp+term时，
  左边exp值为右边的exp的值与右边的term的值之和，
  其中$$代表规则左部符号exp的值，
  $1代表规则右部第一个符号exp的值
  $3表示规则右部第三个符号term的值。
*/
extDefList: 
        extDef{
            $$ = $1;
        }
        | extDefList extDef{
            if($1==NULL)
                $$ = $2;
            else{
                if($2!=NULL)
                    $1->getLastBrother()->addBrother($2);
                $$ = $1;
            }
        }
;

extDef: 
        specifier extDecList SEMICOLON {
            DefVarASTNode* var = (DefVarASTNode*)$2;
            var->setSymbolType($1);
            $$ = var;
        }
        | specifier SEMICOLON {}
        | specifier MAIN LP RP compd {
            $$ = $5;
        } 
        | error SEMICOLON {
            yyerrok;
            $$ = NULL;
        }
;

extDecList:
        varDec {
            $$ = $1;
        }
        | extDecList COMMA varDec {
            $1->getLastBrother()->addBrother($3);
            $$ = $1;
        } 
;

specifier:
        TYPE{
            $$ = (char*)"integer";
        }
        | TYPE MULTIPLY {
            $$ = (char*)"pointer";
        }
;

varDec:
        ID {
            Symbol* result = tempTable->insertSymbol($1,Type::integer);
            if(result!=NULL){
                $$ = new DefVarASTNode($1);
            } 
            else{
                yyerror((char*)"multi defined");
            } 
        }
        | ID LBRAKET INT RBRAKET {
            ASTNode* node = new DefVarASTNode($1);
            Symbol* result = tempTable->insertArraySymbol(node);
            if(result!=NULL){
                DefVarASTNode* var = (DefVarASTNode*) node;
                var -> setSymbolType((char*)"array",$3);
                $$ = var;
            } 
            else {
                yyerror((char*)"multi defined");
            }
        }
;

// FuncDec VarList ParamDec

compd:
       LBRACE {
            // tempTable: 指向当前符号表
            // flagTable: 找a具体在哪个table 
            tempTable = tempTable->createChildTable(false);
            flagTable = tempTable;
        } 
        stmts RBRACE{
           ASTNode* node = new StmtASTNode(stmtType::compoundStmt);
           node -> addChildNode($3);
           $$ = node;
           tempTable = tempTable->getFather();
           flagTable = tempTable;
        }
       | error RBRACE {
           yyerrok;
       }
;

stmts:
        stmts stmt {
            if($1==NULL)
                $$ = $2;
            else{
                $1 -> getLastBrother() -> addBrother($2);
            }
        }
        | {
            $$ = NULL;
        }
;

initFor:
        def {
            $$ = $1;
        }
        | expr {
            $$ = $1;
        }
;

stmt:
        expr SEMICOLON {
            ASTNode* temp = new StmtASTNode(stmtType::expStmt);
            temp -> addChildNode($1);
            $$ = temp;
        }
        | def SEMICOLON {
            ASTNode* temp = new StmtASTNode(stmtType::defStmt);
            temp -> addChildNode($1);
            $$ = temp;
        }
        | compd {
            $$ = $1;
        }
        | PRINTF LP expr RP SEMICOLON{
            ASTNode* temp = new StmtASTNode(stmtType::printStmt);
            temp->addChildNode($3);
            $$=temp;
        }
        | RETURN SEMICOLON {
            $$ = new StmtASTNode(stmtType::returnStmt);
        }
        | RETURN expr SEMICOLON {
            ASTNode* temp = new StmtASTNode(stmtType::returnStmt);
            temp->addChildNode($2);
            $$ = temp;
        }
        | IF LP expr RP stmt {
            $$ = new ConditionalASTNode((char*)"", conditionalType::IF, $3, $5);
        }
        | IF LP expr RP stmt ELSE stmt {
            $$ = new ConditionalASTNode((char*)"", conditionalType::IF, $3, $5, $7);
        }
        | WHILE LP expr RP stmt {
            $$ = new LoopASTNode((char*)"", LoopType::WHILE, $5, $3);
        }
        | FOR LP SEMICOLON SEMICOLON RP stmt{
            $$ = new LoopASTNode((char*)"", LoopType::FOR, $6, NULL, NULL, NULL);
        }
        | FOR LP initFor SEMICOLON SEMICOLON RP stmt {
            $$ = new LoopASTNode((char*)"", LoopType::FOR, $7, $3, NULL, NULL);
        }
        | FOR LP SEMICOLON expr SEMICOLON RP stmt {
            $$ = new LoopASTNode((char*)"", LoopType::FOR, $7, NULL, $4, NULL);
        }
        | FOR LP SEMICOLON SEMICOLON expr RP stmt {
            $$ = new LoopASTNode((char*)"", LoopType::FOR, $7, NULL, NULL, $5);
        }
        | FOR LP initFor SEMICOLON expr SEMICOLON RP stmt {
            $$ = new LoopASTNode((char*)"", LoopType::FOR, $8, $3, $5, NULL);
        }
        | FOR LP initFor SEMICOLON SEMICOLON expr RP stmt {
            $$ = new LoopASTNode((char*)"", LoopType::FOR, $8, $3, NULL, $6);
        }
        | FOR LP SEMICOLON expr SEMICOLON expr RP stmt {
            $$ = new LoopASTNode((char*)"", LoopType::FOR, $8, NULL, $4, $6);
        }
        | FOR LP initFor SEMICOLON expr SEMICOLON expr RP stmt {
            $$ = new LoopASTNode((char*)"", LoopType::FOR, $9, $3, $5, $7);
        }
        | error SEMICOLON{
            yyerrok;
        }
;

def:
        specifier decList{
            DefVarASTNode* temp = (DefVarASTNode*)$2;
            temp->setSymbolType($1);
            $$ = temp;
        }
        | error SEMICOLON{
            yyerrok;
        }
;

decList: 
        dec {
            $$ = $1;
        }
        | dec COMMA decList {
            $1 -> getLastBrother() -> addBrother($3);
            $$ = $1;
        }
;

dec:
        varDec {
            $$ = $1;
        }
        | varDec ASSIGN expr {
            $1 -> addChildNode($3);
            $$ = $1;
        }
;

expr:
        expr ASSIGN expr{
            ASTNode* temp=NULL;
            if($1->getNodeType()==ASTNodeType::op){
                OpASTNode* left=(OpASTNode*)$1;
                if(left->getType()==opType::getArrayValue){
                    temp = new OpASTNode((char*)"=", opType::assignArrayValue);
                }
                else{
                    temp = new OpASTNode((char*)"=", opType::assign);
                }
            }
            else{
                temp = new OpASTNode((char*)"=", opType::assign);
            }
            temp->addChildNode($1);
            $1->addBrother($3);
            $$=temp;
        }
        | expr AND expr {
            ASTNode* temp = new OpASTNode((char*)"&&",opType::andop);
            temp->addChildNode($1);
            $1->addBrother($3);
            $3->setParent(temp);
            $$=temp;

        }
        | expr OR expr {
            ASTNode* temp = new OpASTNode((char*)"||",opType::orop);
            temp->addChildNode($1);
            $1->addBrother($3);
            $$=temp;
        }
        | expr RELOP expr {
            ASTNode* temp=new OpASTNode($2,opType::relop);
            temp->addChildNode($1);
            $1->addBrother($3);
            $$=temp;
        }
        | expr ADD expr {
            ASTNode* temp = new OpASTNode((char*)"+",opType::add);
            temp->addChildNode($1);
            $1->addBrother($3);
            $$=temp;

        }
        | expr SUBTRACT expr {
            ASTNode* temp = new OpASTNode((char*)"-",opType::subtract);
            temp->addChildNode($1);
            $1->addBrother($3);
            $$=temp;

        }
        | expr MULTIPLY expr {
            ASTNode* temp = new OpASTNode((char*)"*",opType::multiply);
            temp->addChildNode($1);
            $1->addBrother($3);
            $$=temp;

        }
        | expr DIVIDE expr {
            ASTNode* temp = new OpASTNode((char*)"/",opType::divide);
            temp->addChildNode($1);
            $1->addBrother($3);
            $$=temp;
        }
        | expr MOD expr {
            ASTNode* temp = new OpASTNode((char*)"%",opType::mod);
            temp->addChildNode($1);
            $1->addBrother($3);
            $$=temp;
        }
        | expr POW expr {
            ASTNode* temp = new OpASTNode((char*)"^",opType::pow);
            temp->addChildNode($1);
            $1->addBrother($3);
            $$=temp;
        }
        | MULTIPLY expr {
            ASTNode* temp = new OpASTNode((char*)"-",opType::negative);
            temp->addChildNode($2);
            $$=temp;

        }
        | LP expr RP{
            $$=$2;
        }
        | NOT expr {
            ASTNode* temp = new OpASTNode((char*)"!",opType::notop);
            temp->addChildNode($2);
            $$=temp;
        }
        | expr LBRAKET expr RBRAKET{
            $$=NULL;
        }
        | ID LBRAKET expr RBRAKET{
            ASTNode* temp = new OpASTNode((char*)"[]",opType::getArrayValue);
            ASTNode* var = new VarASTNode((char*)$1);
            temp->addChildNode(var);
            var->addBrother($3);
            $$=temp;
        }
        | ADDR ID{
            ASTNode* temp = new OpASTNode((char*)"&", opType::signaland);
            ASTNode* child = new VarASTNode((char*)$2);
            temp -> addChildNode(child);
            $$ = temp;
        }
        | MULTIPLY ID{
            ASTNode* temp = new OpASTNode((char*)"*",opType::getvalue);
            ASTNode* var = new VarASTNode((char*)$2);
            temp->addChildNode(var);
            $$=temp;
        }
        | ID {
            flagTable = tempTable->findSymbol($1);
            if(flagTable!=NULL){
                $$ = new VarASTNode($1);
            }
            else{
                yyerror((char*)"use variable undifined");
            }
        }
        | INT {
            $$ = new LiteralASTNode($1);
        }
        | error RP{
            yyerrok;
        }
;

%%

int yyerror(char* s){
    printf("Syntax error: %s\n", s);
    exit(1);
}

std::string replaceExtName(char* fileName) {
    int dotIndex = 0;
    int nameLength = strlen(fileName);
    for (int i = nameLength - 1; i >= 0; i--) {
        if (fileName[i] == '.') {
            dotIndex = i;
            break;
        }
    }
    char* buf = new char[dotIndex];
    strncpy(buf, fileName, dotIndex);
    std::string rev(buf);
    rev += ".asm";
    return rev;
}
/* 
YACC源程序的程序部分包括：
主程序 main()
错误信息执行程序 yyerror(s)
词法分析程序yylex(),可以与LEX进行整合
用户在语义动作中用到的子程序
YACC约定：
传递词法分析程序token属性值的全程变量名：yylval
生成的语法分析程序名为：yyparse();
 */

// 暂时没有那么多可选参数，只能从头开始运行
int main(int argc, char* argv[]){
    char* filename = NULL;
    InterMediate* im;
    /* printf(argv[1]); */
    if(argc>=2){
        printf(argv[1]);
        filename = argv[1];
    }
    printf("%s\n",filename);
    printf("begin1.\n");
    FILE* file = fopen(filename, "r");
    printf("begin2.\n");
    yyin = file;
    printf("begin3.\n");
    while(!feof(yyin))
    {
        yyparse();
    }
    root->printTree();
    std::cout << "root->printTree();" << std::endl;
/* <<<<<<< HEAD
    
======= */
    im = new InterMediate((RootNode *)root);
    //-----------------------------------------------------
    //从rootTable开始遍历符号表，rootTable定义在tools中
    //-----------------------------------------------------
    SymbolTable* t = rootTable;
    while(t->getChild()!=NULL){
        t->getAllSymbol();
        t = t-> getChild();
        printf("1.\n");
    }

    /* im = new InterMediate((RootNode *)root); */
/* >>>>>>> 6f2c25dff8bdee9a4a40aad1ac7ed8a286b078c6 */
    std::cout << "new InterMediate((RootNode *)root);" << std::endl;
    im->Generate(im->getRoot(), im->getTable());
    std::cout << " !!!!!!!!!!!!!!!! im->Generate(im->getRoot(), im->getTable());" << std::endl;
    im->printQuads();
    std::cout << "im->printQuads();" << std::endl;
    AsmGenerator * asmgenera ;
    std::cout << " AsmGenerator * asmgenera ;" << std::endl;
    asmgenera =  new AsmGenerator(im->getQuads(), im->getTempVars(), im->getTable());
    std::cout << "new AsmGenerator(im->getQuads(), im->getTempVars(), im->getTable());" << std::endl;
    asmgenera->generate();
    std::cout <<"generate!!!!!!!!!!!!!!" <<std::endl;
    std::cout << asmgenera->getAsmCode();
    std::cout << "asmgenera->getAsmCode();" << std::endl;
    std::string outFileName = replaceExtName(filename);
    std::cout << "replaceExtName(filename);" << std::endl;
    std::ofstream outasm(outFileName);
    std::cout << "new InterMediate((RootNode *)root);" << std::endl;
    outasm << asmgenera->getAsmCode();
    std::cout << "new InterMediate((RootNode *)root);" << std::endl;
    return 0;
}