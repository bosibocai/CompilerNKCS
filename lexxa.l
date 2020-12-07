%X IN_COMMENT
%{            //全局声明部分
#include <stdio.h>  
#include <stdlib.h>
#include<string.h>
#include "grammar.tab.h"

extern char *yytext;
extern FILE *yyin;
extern YYSTYPE yylval;
extern int yyerror(char* s);
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
{type}           {printf("TYPE           %s\n",yytext);return(TYPE);}
main             {printf("MAIN           %s\n",yytext);return(MAIN);}
printf           {printf("PRINTF         %s\n",yytext);return(PRINTF);}
return           {printf("RETURN         %s\n",yytext);return(RETURN);}
if               {printf("IF             %s\n",yytext);return(IF);}
else             {printf("ELSE           %s\n",yytext);return(ELSE);}
while            {printf("WHILE          %s\n",yytext);return(WHILE);}
for              {printf("FOR            %s\n",yytext);return(FOR);}
{id}             {yylval.str=strdup(yytext);
                  printf("ID             %s           %ld\n",yytext,flagTable);
                  return(ID);
                 }
{num}            {yylval.str=strdup(yytext);printf("INT            %s           %s\n",yytext,yylval.str);return(INT);}
"//".*\n         {printf("linecomment    %s\n",yytext);}
"{"              {printf("LBRACE         %s\n",yytext);return(LBRACE);}
"}"              {printf("RBRACE         %s\n",yytext);return(RBRACE);}
"("              {printf("LP             %s\n",yytext);return(LP);}
")"              {printf("RP             %s\n",yytext);return(RP);}
"["              {printf("LB             %s\n",yytext);return(LBRAKET);}
"]"              {printf("RB             %s\n",yytext);return(RBRAKET);}
","              {printf("COMMA          %s\n",yytext);return(COMMA);}
";"              {printf("SEMICOLON      %s\n",yytext);return(SEMICOLON);}
"+"              {printf("ADD            %s\n",yytext);return(ADD);}
"-"              {printf("SUBTRACT       %s\n",yytext);return(SUBTRACT);}
"*"              {printf("MULTIPLY       %s\n",yytext);return(MULTIPLY);}
"/"              {printf("DIVIDE         %s\n",yytext);return(DIVIDE);}
"%"              {printf("MOD            %s\n",yytext);return(MOD);}
"^"              {printf("POW            %s\n",yytext);return(POW);}
"="              {printf("ASSIGN         %s\n","=");return(ASSIGN);}
"=="             {printf("AA             %s\n",yytext);yylval.str=strdup(yytext);return(RELOP);}
">"              {printf("MORE           %s\n",yytext);yylval.str=strdup(yytext);return(RELOP);}
"<"              {printf("LESS           %s\n",yytext);yylval.str=strdup(yytext);return(RELOP);}
">="             {printf("MA             %s\n",yytext);yylval.str=strdup(yytext);return(RELOP);}
"<="             {printf("LA             %s\n",yytext);yylval.str=strdup(yytext);return(RELOP);}
"!="             {printf("NA             %s\n",yytext);yylval.str=strdup(yytext);return(RELOP);}
"&&"             {printf("AND            %s\n",yytext);return(AND);}
"&"              {printf("ADDR           %s\n",yytext);return(ADDR);}
"||"             {printf("OR             %s\n",yytext);return OR;}
"!"              {printf("NOT            %s\n",yytext);return NOT;}
<INITIAL>{
"/*"             BEGIN(IN_COMMENT);
}
<IN_COMMENT>{
"*/"             printf("ANNODATE       %s\n",yytext);BEGIN(INITIAL);
[^*\n]           yymore();
"*"              yymore();
wrap               yymore();
}
%%

int yywrap()
{return 1;}


// //以下为函数定义部分
// int main(int avgs, char *avgr[]) 
// {
//     yyin = fopen(avgr[1], "r");
//     if (!yyin)
//     {
//         return 0;
//     }
//     yylex();
//     fclose(yyin);

//     return 1;
// }
