# CompilerNKCS
实现一个简单c语言编译器

目标：编译器演示程序，将C语言程序编译为目标代码————汇编程序，用汇编器转换成二进制程序后运行无误

## 基本要求：

    数据类型：int
    
    语句：注释，声明，赋值，循环（while 和 for），判断（if），输入输出 
    
    算术运算：+，-，*，/，%，^ 
    
    关系运算：==，>，<，>=，<=，!=
    
    逻辑运算：&&（与），||（或），!（非）
    

## 完成功能：
    
    词法分析、语法分析、类型检查、代码优化、错误分析、汇编程序

## 加分项：

    支持数组运算 一维数组
    
    支持指针运算 一维指针

## 操作方法：

    make grammar    编译lexxa.l、grammar.y
    
    make parser     生成可执行文件
    
    ./parser xx.c   运行词法分析和语法分析
    
    make clean      删除生成的文件

### 程序解析

    文件阅读顺序：
    
    词法分析： lexxal.l
    语法分析： grammar.y
    其中在grammar.y文件内会调用lexxal进行词法分析，因此词法分析和语法分析的所有的操作都在grammar.y文件内被定义
    tools.h里面的头文件：
``` 
#include "./tables/symbol.h"
#include "./trees/ASTNode.h"
#include "./trees/StmtASTNode.h"
#include "./trees/LiteralASTNode.h"
#include "./trees/OpASTNode.h"
#include "./trees/VarASTNode.h"
#include "./trees/DefVarASTNode.h"
#include "./trees/LoopASTNode.h"
#include "./trees/ConditionalASTNode.h"
```
    symbol.h和symbol.cpp中定义了词法分析生成符号表的主要函数
    在grammar.y文件中会调用词法分析器进行词法分析，然后在grammar.y文件进行语法分析

