%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string>
    #include <fstream>
    #include "../common/tools.h"
    
    extern int yylex();
    int yyerror(char* s);

    extern char* yytext;
    extern FILE* yyin;
    ASTNode* root;
%}

%union{
    ASTNode* astNode;
    char* str;
}

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
%left <str> RELOP //  > ≥ < ≤ 
%left LBRACE RBRACE // { }
%left LBRAKET RBRAKET // [ ]
%left LP RP // ( )

// nonassoc：不可结合
%nonassoc SEMICOLON COMMA GETMEMBER
%nonassoc RETURN IF ELSE 

// token：终结符
%token <str> ID
%token <str> INT
%token <str> TYPE
%token MAIN
%token FOR WHILE



// type：非终结符
%type <str> specifier //标识符，声明变量类型 specifier -> TYPE 
%type <ast> stmts stmt //statement
%type <ast> expr //expression
%type <ast> compd //compound
%type <ast> varDec //变量声明
%type <ast> def dec decList initFor
%type <ast> extDefList extDef extDecList

%%

prog:
        extDefList{
            root = new RootNode();
            root -> addChildNode($1);
        }
;

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
        | error SEMICOLON {
            yyerrork;
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
            $$ = strcpy($1);
        }
        | TYPE MULTIPLY {
            $$ = (char*)("integer point");
        }
;

varDec:
        ID {
            $$ = new DefVarASTNode($1);
        }
        | ID LBRAKET INT RBRAKET {
            DefVarASTNode* var = new DefVarASTNode($1);
            var -> setSymbolType((char*)("array"),$3);
            $$ = var;
        }
;

// FuncDec VarList ParamDec

compd:
       LBRACE stmts RBRACE {
           ASTNode* node = new StmtASTNode(stmtType::compoundStmt);
           node -> addChildNode($2);
           $$ = node;
       } 
       | error RBRACE {
           yyerrork;
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
            $$ = NULL
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
        | RETURN expr SEMICOLON {
            $$ = new StmtASTNode(stmtType::returnStmt);
        }
        | IF LP expr RP stmt {
            $$ = new ConditionASTNode((char*)"", conditionalType::IF, $3, $5);
        }
        | IF LP expr RP stmt ELSE stmt {
            $$ = new ConditionASTNode((char*)"", conditionalType::IF, $3, $5, $7);
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
            yyerrork;
        }
;

def:
        specifier decList{
            DefVarASTNode* temp = (DefVarASTNode*)$2;
            temp->setSymbolType($1);
            $$ = temp;
        }
        | error SEMICOLON{
            yyerrork;
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
            temp -> addChildNode(new VarASTNode(char*)$2);
            $$ = temp;
        }
        | MULTIPLY ID{
            ASTNode* temp = new OpASTNode((char*)"*",opType::getValue);
            ASTNode* var = new VarASTNode((char*)$2);
            temp->addChildNode(var);
            $$=temp;
        }
        | ID {
            $$ = new VarASTNode($1);
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
    fprintf("Syntax error on line %s\n", s);
    return 1;
}


// 暂时没有那么多可选参数，只能从头开始运行
int main(int args, char* argv){
    char* filename = NULL;
    if(argc>=2){
        filename == argv[2];
    }
    FILE* file = fopen(filename, "r");
    yyin = file;
    while(!feof(yyin)){
        yyparse();
    }

    return 0;
}

%%