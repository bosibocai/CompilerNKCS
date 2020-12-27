#ifndef TOOLS
#define TOOLS
#include "./trees/ASTNode.h"
#include "./tables/symbol.h"
#include "./trees/StmtASTNode.h"
#include "./trees/LiteralASTNode.h"
#include "./trees/OpASTNode.h"
#include "./trees/VarASTNode.h"
#include "./trees/DefVarASTNode.h"
#include "./trees/LoopASTNode.h"
#include "./trees/MainASTNode.h"
#include "./trees/ConditionalASTNode.h"
extern SymbolTable* rootTable;
extern SymbolTable* flagTable;
extern SymbolTable* tempTable;
#endif 