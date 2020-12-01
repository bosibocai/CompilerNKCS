%X IN_COMMENT
%{            //全局声明部分
#include <stdio.h>  
#include <stdlib.h>
#include<string.h>
#include "grammar.tab.h"
extern char *yytext;
extern FILE *yyin;
extern YYSTYPE yylval;
%}
st          [ \t]
ws          {st}+
wrap        {\n}
notwrap     {^\n}
letter      [A-Za-z]
dight       [0-9]
id          ({letter})({letter}|{dight})*
num         ({dight}*?(E[+-]?{dight}*)?)
type        int|void
%%
{ws}             {}
{type}           {yylval.str=strdup(yytext);printf("TYPE, %s\n",yytext);return(TYPE);}
main             {yylval.str=strdup(yytext);printf("MAIN,%s\n",yytext);return(MAIN);}
printf           {printf("PRINTF,%s\n",yytext);return(PRINTF);}
return           {printf("RETURN,%s\n",yytext);return(RETURN);}
if               {printf("IF,%s\n",yytext);return(IF);}
while            {printf("WHILE,%s\n",yytext);return(WHILE);}
for              {printf("FOR,%s\n",yytext);return(FOR);}
{id}             {yylval.str=strdup(yytext);printf("ID,%s\n",yytext);return(ID);}
{num}            {yylval.str=strdup(yytext);printf("INT,%s\n",yytext);return(INT);}
"//".*\n         {printf("linecomment,%s\n",yytext);return(COMMENT);}
"{"              {printf("LBRACE,%s\n",yytext);return(LBRACE);}
"}"              {printf("RBRACE,%s\n",yytext);return(RBRACE);}
"("              {printf("LP,%s\n",yytext);return(LP);}
")"              {printf("RP,%s\n",yytext);return(RP);}
"["              {printf("LB,%s\n",yytext);return(LB);}
"]"              {printf("RB,%s\n",yytext);return(RB);}
","              {printf("COMMA,%s\n",yytext);return(COMMA);}
";"              {printf("SEMICOLEN,%s\n",yytext);return(SEMICOLEN);}
"+"              {printf("ADD,%s\n",yytext);return(ADD);}
"-"              {printf("SUBTRACT,%s\n",yytext);return(SUBTRACT);}
"*"              {printf("MULTIPLY,%s\n",yytext);return(MULTIPLY);}
"/"              {printf("DIVIDE,%s\n",yytext);return(DIVIDE);}
"%"              {printf("MOD,%s\n",yytext);return(MOD);}
"^"              {printf("POW,%s\n",yytext);return(POW);}
"="              {printf("ASSIGN,%s\n",yytext);return(ASSIGN);}
"=="             {yylval.str=strdup(yytext);printf("AA,%s\n",yytext);return(RELOP);}
">"              {yylval.str=strdup(yytext);printf("MORE,%s\n",yytext);return(RELOP);}
"<"              {yylval.str=strdup(yytext);printf("LESS,%s\n",yytext);return(RELOP);}
">="             {yylval.str=strdup(yytext);printf("MA,%s\n",yytext);return(RELOP);}
"<="             {yylval.str=strdup(yytext);printf("LA,%s\n",yytext);return(RELOP);}
"!="             {yylval.str=strdup(yytext);printf("NA,%s\n",yytext);return(RELOP);}
"&&"             {printf("AND,%s\n",yytext);return(AND);}
"||"             {printf("OR,%s\n",yytext);return OR;}
"!"              {printf("NOT:%s\n",yytext);return NOT;}
<INITIAL>{
"/*"             BEGIN(IN_COMMENT);yymore();
}
<IN_COMMENT>{
"*/"             printf("ANNODATE:%s\n",yytext);BEGIN(INITIAL);
[^*\n]           yymore();
"*"              yymore();
wrap               yymore();
}
%%


//以下为函数定义部分
int main(int avgs, char *avgr[]) 
{
    yyin = fopen(avgr[1], "r");
    if (!yyin)
    {
        return 0;
    }
    yylex();
    fclose(yyin);

    return 1;
}
