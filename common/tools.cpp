#include "./tools.h"
SymbolTable* rootTable = new SymbolTable(false, NULL);
SymbolTable* flagTable = rootTable;
SymbolTable* tempTable = rootTable;