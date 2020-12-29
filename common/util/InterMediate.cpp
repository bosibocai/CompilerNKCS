#include "InterMediate.h"
#include <typeinfo>
#include <cstdio>
using namespace std;
InterMediate::InterMediate(RootNode *rootNode, SymbolTable* symbolTable)
{
    // 这个存放符号表的数组
    // std::vector<Symbol *> tempVar;
    // 翻转符号变量？
    tempVar.reserve(100);
    this->root = rootNode;
    this->rootTable = symbolTable;
}

void InterMediate::Generate(ASTNode *node, SymbolTable *symbolTable)
{
    if (node == NULL)
    {
        std::cout << "NULL" << std::endl;
        return;
    }
       
    ASTNode *p = node->getChild();
    std::cout <<"identifier node type ~!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<  (int)node->getNodeType() << std::endl;
    //  root=1,
    // // defFunc=2,//声明函数，没实现
    // // callFunc=3,//调用函数，没实现
    // stmt=4, //语句
    // exp=5,//表达式
    // op=6,//操作符，包括
    // defVar=7,//声明变量
    // callVar=8,//调用变量
    // loop=9,//循环
    // conditional=10,//条件
    // literal=11,//字面量
    switch (node->getNodeType())
    {
    // case ASTNodeType::defFunc:
    // {
    //     // 如果是函数
    //     FuncSymbol *func = new FuncSymbol(node);
    //     this->funcTable.addFunction(func);
    //     Quad *temp;
    //     // Symbol *tempSym = new Symbol(func->getKeyName(), Type::Void);
    //     temp = new Quad(OpCode::FUNC_DEF, tempSym, (Symbol *)NULL);
    //     this->quads.push_back(*temp);
    //     while (p != NULL)
    //     {
    //         SymbolTable *childTable = symbolTable->createChildTable(true);
    //         childTable->addFromFunctionArgs(node);
    //         Generate(p, childTable);
    //         p = p->getBrother();
    //     }
    //     temp = new Quad(OpCode::END_FUNCTION, (Symbol *)NULL, (Symbol *)NULL);
    //     this->quads.push_back(*temp);
    //     break;
    // }
    // case ASTNodeType::callFunc:
    // {
    //     // 函数调用语句
    //     int count = 0;
    //     ASTNode *var = ((CallFunASTNode *)node)->getVarList();
    //     std::string addOn = "";
    //     while (var != NULL)
    //     {
    //         count = count + 1;
    //         Quad *temp;
    //         if (var->getNodeType() == ASTNodeType::callVar)
    //         {
    //             // 通过符号表找到内容
    //             Symbol *arg1 = symbolTable->findSymbolfromRoot(var->getContent());
    //             temp = new Quad(OpCode::PARAM, arg1, (Symbol *)NULL);
    //             switch (arg1->getIdType())
    //             {

    //             case Type::integer:
    //                 addOn = addOn + "_i";
    //                 break;
    //             case Type::pointer:
    //                 addOn = addOn + "_p";
    //                 break;
    //             default:
    //                 break;
    //             }
    //         }
    //         else if (var->getNodeType() == ASTNodeType::literal)
    //         {
    //             // 字面量
    //             // stoi：string to int函数
    //             int arg1 = std::stoi(var->getContent());
    //             temp = new Quad(OpCode::PARAM, arg1, (Symbol *)NULL);
    //             addOn = addOn + "_i";
    //         }
    //         else if (var->getNodeType() == ASTNodeType::op)
    //         {

    //             Symbol *arg1 = GenerateOp((OpASTNode *)var, symbolTable);
    //             temp = new Quad(OpCode::PARAM, arg1, (Symbol *)NULL);
    //             switch (arg1->getIdType())
    //             {
    //             case Type::integer:
    //                 addOn = addOn + "_i";
    //                 break;
    //             case Type::pointer:
    //                 addOn = addOn + "_p";
    //                 break;
    //             default:
    //                 break;
    //             }
    //         }
    //         this->quads.push_back(*temp);
    //         var = var->getBrother();
    //     }
    //     FuncSymbol *funSym = this->funcTable.findFunction(node->getContent() + addOn);
    //     if (funSym == NULL)
    //     {
    //         std::cout << "\033[31mError: \033[0m"
    //                   << " function is not decleared." << std::endl;
    //         exit(1);
    //     }
    //     Symbol *funcSymbol = new symbol(funSym->getKeyName(), Type::Void);
    //     // Symbol *funcSymbol = new symbol(funSym->getFunName(), Type::Void);
    //     Symbol *tempV = NULL;

    //     if (node->getParent()->getNodeType() == ASTNodeType::stmt)
    //     {
    //         StmtASTNode *stmt = (StmtASTNode *)node->getParent();
    //         if (stmt->getStmtType() == StmtType::expStmt)
    //         {
    //             tempV = NULL;
    //         }
    //         else
    //         {
    //             tempV = new symbol("Temp" + std::to_string(tempVar.size()), Type::integer);
    //             tempVar.push_back(tempV);
    //         }
    //     }
    //     else
    //     {
    //         tempV = new symbol("Temp" + std::to_string(tempVar.size()), Type::integer);
    //         tempVar.push_back(tempV);
    //     }

    //     Quad *temp = new Quad(OpCode::CALL, funcSymbol, count, tempV);
    //     this->quads.push_back(*temp);
    // }

    case ASTNodeType::mainnode:{
        // case ASTNodeType::defFunc:
        // {
        // 如果是函数
        // FuncSymbol *func = new FuncSymbol(node);
        // this->funcTable.addFunction(func);
        Quad *temp;
        Symbol *tempSym = symbolTable->findSymbolfromRoot(std::string("MAIN"));
        cout << "main !!!!!!!symbol "<< tempSym->getName() << endl;
        temp = new Quad(OpCode::MAIN, tempSym, (Symbol *)NULL);
        this->quads.push_back(*temp);
        while (p != NULL)
        {
            // SymbolTable *childTable = symbolTable->createChildTable(true);
            // childTable->addFromFunctionArgs(node);
            Generate(p, symbolTable);
            p = p->getBrother();
        }
        // temp = new Quad(OpCode::END_FUNCTION, (Symbol *)NULL, (Symbol *)NULL);
        // this->quads.push_back(*temp);
        break;
    // }
        // Quad *temp = new Quad(OpCode::MAIN, NULL);
        // this->quads.push_back(*temp);
        // break;
    }

    case ASTNodeType::literal:
    {
        if (node->getParent()->getNodeType() == ASTNodeType::op)
        {
            OpASTNode *par = (OpASTNode *)node->getParent();
            if (par->getType() == opType::andop || par->getType() == opType::orop || par->getType() == opType::notop)
            {
                Quad *trueQuad = new Quad(OpCode::JUMP_GREAT, std::stoi(node->getContent()), 0, (int)NULL);
                Quad *falseQuad = new Quad(OpCode::JUMP, (int)NULL);
                std::list<int> trueL;
                trueL.push_back(quads.size());
                this->quads.push_back(*trueQuad);
                std::list<int> falseL;
                falseL.push_back(quads.size());
                this->quads.push_back(*falseQuad);
                trueList.push(trueL);
                falseList.push(falseL);
            }
        }
        break;
    }
    
    case ASTNodeType::op:
    {
        cout << "((OpASTNode *)node)->getType()" << (int)((OpASTNode *)node)->getType()  << endl;
    // optype   //操作符集
    // add=1, // +
    // subtract=2, // -
    // multiply=3, // *
    // divide=4, // /
    // mod=5, // %
    // pow=6, // ^
    // assign=7, // =
    // relop=8, // <,>,<=,>=,!=
    // andop=9, // &&
    // orop=10, //||
    // notop=11, // !
    // getArrayValue=12, // a[n]
    // assignArrayValue=13, // a[n]=
    // getvalue = 14, //*a
    // negative = 15, //-a
    // signaland = 16 //&a
        if (((OpASTNode *)node)->getType() == opType::andop || ((OpASTNode *)node)->getType() == opType::orop)
        {
            
            Generate(p, symbolTable);
            cout << "Generate(p, symbolTable);" << endl;
            signal.push(quads.size());
            cout << "signal.push(quads.size());" << endl;
            Generate(p->getBrother(), symbolTable);
             cout << "Generate(p->getBrother(), symbolTable);" << endl;
        }
        else if (((OpASTNode *)node)->getType() == opType::notop || ((OpASTNode *)node)->getType() == opType::relop)
        {
            while (p != NULL)
            {
                Generate(p, symbolTable);
                 cout << "while (p != NULL)\
                Generate(p, symbolTable);" << endl;
                p = p->getBrother();
            }
        }
        this->GenerateOp((OpASTNode *)node, symbolTable);
         cout << "this->GenerateOp((OpASTNode *)node, symbolTable);" << endl;
        break;
    }
    
    case ASTNodeType::stmt:
    {
        StmtASTNode *ret = (StmtASTNode *)node;
        if (ret->getType() == stmtType::returnStmt)
        {
            GenerateReturn((StmtASTNode *)node, symbolTable);
        }
        else
        {
            while (p != NULL)
            {
                // 又来递归
                Generate(p, this->GenerateStmt((StmtASTNode *)node, symbolTable));
                cout << "ASTNodeType::stmt:递归结束" << endl;
                p = p->getBrother();
            }
        }
        break;
    }
    
    case ASTNodeType::defVar:
    {
        DefVarASTNode *tempNode = (DefVarASTNode *)node;
        // if (tempNode->getSymbolType() == stmtType::Struct)
        // {
        //     symbolTable->addStructSymbol(tempNode->getStructType(), tempNode->getContent());
        // }
        // else 
        if (tempNode->getSymbolType() == Type::Array)
        {
            std::cout<<"define array in intermedia" << std::endl;
            // symbolTable->insertArraySymbol(tempNode);
        }
        else
        {
            symbolTable->insertSymbol(tempNode->getContent(), tempNode->getSymbolType());
        }
        Symbol *varSymbol = symbolTable->findSymbolfromRoot(node->getContent());
        if (p != NULL)
        {
            
            Quad *temp;
            std::cout << "p ! = null, p =====" << (int)p->getNodeType() << endl;
                //          root=1,
                // // defFunc=2,//声明函数，没实现
                // // callFunc=3,//调用函数，没实现
                // stmt=4, //语句
                // exp=5,//表达式
                // op=6,//操作符，包括
                // defVar=7,//声明变量
                // callVar=8,//调用变量
                // loop=9,//循环
                // conditional=10,//条件
                // literal=11,//字面量
            if (p->getNodeType() == ASTNodeType::literal)
            {
                int arg1 = std::stoi(p->getContent());
                std::cout << "stoi" << endl; 
                temp = new Quad(OpCode::ASSIGN, arg1, varSymbol);
                std::cout <<"temp new Quad" << endl;
            }
            else if (p->getNodeType() == ASTNodeType::callVar)
            {
                Symbol *arg1 = symbolTable->findSymbolfromRoot(p->getContent());
                temp = new Quad(OpCode::ASSIGN, arg1, varSymbol);
            }
            else if (p->getNodeType() == ASTNodeType::op)
            {
               
                Symbol *arg1 = this->GenerateOp((OpASTNode *)p, symbolTable);
                cout << "this->GenerateOp((OpASTNode *)p" << endl;
                temp = new Quad(OpCode::ASSIGN, arg1, varSymbol);
             cout << "new Quad(OpCode::ASSIGN, arg1, varSymbol);" << endl;
             
            }
            // else if (p->getNodeType() == ASTNodeType::callFunc)
            // {
            //     Generate(p, symbolTable);
            //     Symbol *arg1 = tempVar.back();
            //     temp = new Quad(OpCode::ASSIGN, arg1, varSymbol);
            // }
            else
            {
                std::cout << "\033[31mError: \033[0m"
                          << "Type error" << std::endl;
                exit(1);
            }

            this->quads.push_back(*temp);
            std::cout <<"this->quads.push_back(*temp);" <<endl;
        }
        std::cout << "break" << endl;
        break;
    }
    
    case ASTNodeType::callVar:
    {
        if (node->getParent()->getNodeType() == ASTNodeType::op)
        {
            OpASTNode *par = (OpASTNode *)node->getParent();
            if (par->getType() == opType::andop || par->getType() == opType::orop || par->getType() == opType::notop)
            {
                Symbol *arg1 = symbolTable->findSymbolfromRoot(node->getContent());
                Quad *trueQuad = new Quad(OpCode::JUMP_GREAT, arg1, 0, (int)NULL);
                Quad *falseQuad = new Quad(OpCode::JUMP, (int)NULL);
                std::list<int> trueL;
                trueL.push_back(quads.size());
                this->quads.push_back(*trueQuad);
                std::list<int> falseL;
                falseL.push_back(quads.size());
                this->quads.push_back(*falseQuad);
                trueList.push(trueL);
                falseList.push(falseL);
            }
        }
        break;
    }
    
    case ASTNodeType::loop: // for(1.DefASTNODE, 2.OperatorASTNODE, 3.OperatorASTNODE, 4.StmtASTNODE)
    {
        LoopASTNode *loop = (LoopASTNode *)node;
        if (loop->getType() == LoopType::FOR)
        {
            // SymbolTable *childTable = symbolTable->findSymbolfromRootReturnTable();
            Generate(((LoopASTNode *)node)->getInit(), symbolTable);
            int start = quads.size();
            Generate(((LoopASTNode *)node)->getCondition(), symbolTable);
            std::list<int> JudgeTrue = trueList.top();
            std::list<int> JudgeFalse = falseList.top();
            trueList.pop();
            falseList.pop();
            backpatch(&JudgeTrue, JudgeTrue.back() + 2);
            while (p != NULL)
            {
                Generate(p, symbolTable);
                p = p->getBrother();
            }
            Generate(((LoopASTNode *)node)->getIncrement(), symbolTable);

            Quad *temp = new Quad(OpCode::JUMP, start);
            this->quads.push_back(*temp);
            int end = quads.size();
            backpatch(&JudgeFalse, end);
        }
        else if (loop->getType() == LoopType::WHILE)
        {
            int start = quads.size();
            Generate(((LoopASTNode *)node)->getCondition(), symbolTable);
            std::list<int> JudgeTrue = trueList.top();
            std::list<int> JudgeFalse = falseList.top();
            trueList.pop();
            falseList.pop();
            backpatch(&JudgeTrue, JudgeTrue.back() + 2);
            while (p != NULL)
            {
                Generate(p, symbolTable);
                p = p->getBrother();
            }

            Quad *temp = new Quad(OpCode::JUMP, start);
            this->quads.push_back(*temp);
            int end = quads.size();
            backpatch(&JudgeFalse, end);
        }
        break;
    }
    
    case ASTNodeType::conditional: // Just IF and ELSE.
    {
        ConditionalASTNode *select = (ConditionalASTNode *)node;
        Generate(select->getCondition(), symbolTable);
        int start = quads.size();
        std::list<int> JudgeTrue = trueList.top();
        std::list<int> JudgeFalse = falseList.top();
        trueList.pop();
        falseList.pop();

        backpatch(&JudgeTrue, start);
        Generate(select->getBody(), symbolTable);
        if (select->getElseBody() != NULL)
        {
            Quad *temp = new Quad(OpCode::JUMP, (int)NULL);
            this->quads.push_back(*temp);
            temp = &quads.back();
            int elseStart = quads.size();
            Generate(select->getElseBody(), symbolTable);
            backpatch(&JudgeFalse, elseStart);
            int end = quads.size();
            temp->backpatch(end);
        }
        else
        {
            int end = quads.size();
            backpatch(&JudgeFalse, end);
        }
        break;
    }
    // 这个很重要。一开始进入是root，然后进行递归
    case ASTNodeType::root:
    {
        int i = 0;
        while (p != NULL)
        {
            std::cout << "递归" << i << endl;
            Generate(p, symbolTable);
            std::cout << "递归" << i << endl;
            p = p->getBrother();
            // std::cout <<
            // std::cout <<"p_note" << (int) p->getNodeType() << endl;
        }
        break;
    }

    default:
        std::cout << "Hello! Something Wrong happened!\n";
        break;
    }



}

SymbolTable *InterMediate::GenerateStmt(StmtASTNode *node, SymbolTable *symbolTable)
{
    std::cout << "GenerateStmt" << (int) node->getType() << endl; //compoundStmt=3,
    // //语句类别，包括声明语句，表达式，复合语句，返回语句
    // defStmt=1,
    // expStmt=2,
    // compoundStmt=3,
    // returnStmt=4,
    // printStmt=5,
    switch (node->getType())
    {
    case stmtType::compoundStmt:
    {

        if (node->getParent()->getNodeType() == ASTNodeType::loop)
            return symbolTable;
        // if (node->getParent()->getNodeType() == ASTNodeType::defFunc)
        //     return symbolTable;
        std::cout <<"(int)node->getParent()->getNodeType()"<< (int)node->getParent()->getNodeType() << endl; 
        return symbolTable;
    }
    break;
    case stmtType::printStmt:
    {
    ASTNode *p = node->getChild();
    Quad *temp;
    Symbol *result = new Symbol("Temp" + std::to_string(tempVar.size()), Type::integer);
    tempVar.push_back(result);
    // std::cout << "generate print   " <<  (int)p->getNodeType() << endl;
    if (p == NULL)
    {
        temp = new Quad(OpCode::PRINT, (Symbol *)NULL, (Symbol *)NULL, (Symbol *)NULL);
    }
    else if (p->getNodeType() == ASTNodeType::literal)
    {
        int arg1 = std::stoi(p->getContent());
        temp = new Quad(OpCode::PRINT, arg1, result);
    }
    else if (p->getNodeType() == ASTNodeType::callVar)
    {
        Symbol *arg1 = symbolTable->findSymbolfromRoot(p->getContent());
        temp = new Quad(OpCode::PRINT, arg1, result);
        //std::cout<< arg1.
        //std::cout<<"这里是bug点"<<std::endl;
    }
    else if (p->getNodeType() == ASTNodeType::op)
    {
        Symbol *arg1 = this->GenerateOp((OpASTNode *)p, symbolTable);
        temp = new Quad(OpCode::PRINT, arg1, result);
    }
    else
    {
        std::cout << "\033[31mError: \033[0m"
                  << "Type error" << std::endl;
        exit(1);
    }


    quads.push_back(*temp);

    }
    break;



    // case stmtType::returnStmt:
    // {
    //     ASTNode *p = node->getChild();
    //     Quad *temp;
    //     Symbol *result = new Symbol("Temp" + std::to_string(tempVar.size()), Type::integer);
    //     tempVar.push_back(result);
    //     if (p == NULL)
    //     {
    //         temp = new Quad(OpCode::RETURN, (Symbol *)NULL, (Symbol *)NULL, (Symbol *)NULL);
    //     }
    //     else if (p->getNodeType() == ASTNodeType::literal)
    //     {
    //         int arg1 = std::stoi(p->getContent());
    //         temp = new Quad(OpCode::RETURN, arg1, result);
    //     }
    //     else if (p->getNodeType() == ASTNodeType::callVar)
    //     {
    //         Symbol *arg1 = symbolTable->findSymbolfromRoot(p->getContent());
    //         temp = new Quad(OpCode::RETURN, arg1, result);
    //     }
    //     else if (p->getNodeType() == ASTNodeType::op)
    //     {
    //         Symbol *arg1 = this->GenerateOp((OpASTNode *)p, symbolTable);
    //         temp = new Quad(OpCode::RETURN, arg1, result);
    //     }
    //     quads.push_back(*temp);
    // }
    // break;
    default:
        break;
    }
    return symbolTable;
}

SymbolTable *InterMediate::GenerateReturn(StmtASTNode *node, SymbolTable *symbolTable)
{

    ASTNode *p = node->getChild();
    Quad *temp;
    Symbol *result = new Symbol("Temp" + std::to_string(tempVar.size()), Type::integer);
    tempVar.push_back(result);
    std::cout << "GenerateReturn   " <<  (int)p->getNodeType() << endl;
    if (p == NULL)
    {
        temp = new Quad(OpCode::RETURN, (Symbol *)NULL, (Symbol *)NULL, (Symbol *)NULL);
    }
    else if (p->getNodeType() == ASTNodeType::literal)
    {
        int arg1 = std::stoi(p->getContent());
        temp = new Quad(OpCode::RETURN, arg1, result);
    }
    else if (p->getNodeType() == ASTNodeType::callVar)
    {
        Symbol *arg1 = symbolTable->findSymbolfromRoot(p->getContent());
        temp = new Quad(OpCode::RETURN, arg1, result);
    }
    else if (p->getNodeType() == ASTNodeType::op)
    {
        Symbol *arg1 = this->GenerateOp((OpASTNode *)p, symbolTable);
        temp = new Quad(OpCode::RETURN, arg1, result);
    }
    // else if (p->getNodeType() == ASTNodeType::callFunc)
    // {
    //     Generate(p, symbolTable);
    //     Symbol *arg1 = tempVar.back();
    //     temp = new Quad(OpCode::RETURN, arg1, (Symbol *)NULL);
    // }
    else
    {
        std::cout << "\033[31mError: \033[0m"
                  << "Type error" << std::endl;
        exit(1);
    }


    quads.push_back(*temp);
}

// 生成运算符
Symbol *InterMediate::GenerateOp(OpASTNode *node, SymbolTable *symbolTable)
{
    Quad *temp;
    ASTNode *arg1Node, *arg2Node;
    cout << "GenerateOp" << (int)node->getType() <<endl;

    // //操作符集
    // add=1, // +
    // subtract=2, // -
    // multiply=3, // *
    // divide=4, // /
    // mod=5, // %
    // pow=6, // ^
    // assign=7, // =
    // relop=8, // <,>,<=,>=,!=
    // andop=9, // &&
    // orop=10, //||
    // notop=11, // !
    // getArrayValue=12, // a[n]
    // assignArrayValue=13, // a[n]=
    // getvalue = 14, //*a
    // negative = 15, //-a
    // signaland = 16 //&a



    switch (node->getType())
    {
        // 节点的类型如果是赋值
    case opType::assign:
    {
        Symbol *result;
        OpCode op;
        // 给指针赋值

        cout << "node->getChild()->getNodeType()" << (int)node->getChild()->getNodeType()<<endl;


        if (node->getChild()->getNodeType() == ASTNodeType::op && ((OpASTNode *)node->getChild())->getType() == opType::getvalue)
        {
            op = OpCode::ASSIGN_POINTER;
            cout << "node->getChild()->getChild()->getContent()" <<endl;
            cout <<  node->getChild()->getChild()->getContent() << endl;
            result = symbolTable->findSymbolfromRoot(node->getChild()->getChild()->getContent());

        }
        else
        // 普通赋值
        {
            
            op = OpCode::ASSIGN;
            if (node->getChild()->getNodeType() != ASTNodeType::callVar)
            {
                std::cout << "\033[31mError:(GenerateOp) \033[0m"
                          << node->getChild()->getContent() << " is not a variable. What are u doing?" << std::endl;
                exit(1);
            }
             std::cout 
                          << node->getChild()->getContent() << " node->getChild()->getContent()" << std::endl;
        
            result = symbolTable->findSymbolfromRoot(node->getChild()->getContent());
            std::cout 
                          << node->getChild()->getContent() << " findSymbolfromRoot(node->getChild()->getContent());" << std::endl;
        
        }

        ASTNode *arg1Node = node->getChild()->getBrother();
        if (arg1Node->getNodeType() == ASTNodeType::callVar)
        // 变量给变量赋值
        {
            Symbol* arg1 = symbolTable->findSymbolfromRoot(arg1Node->getContent());
        
            if (result->getType() == Type::integer && arg1->getType() == Type::pointer)
            {
                std::cout << "\033[31mError: \033[0m"
                          << "Syntax error, maybe you have used the wrong type: " << (int)arg1Node->getNodeType() << "  Content:" << arg1Node->getContent() << std::endl;
                exit(1);
            }
            temp = new Quad(op, arg1, result);
        }
        else if (arg1Node->getNodeType() == ASTNodeType::op)
        {
            Symbol *arg1 = GenerateOp((OpASTNode *)arg1Node, symbolTable);
            temp = new Quad(op, arg1, result);
        }
        else if (arg1Node->getNodeType() == ASTNodeType::literal)
        {
            int arg1 = std::stoi(arg1Node->getContent());
            temp = new Quad(op, arg1, result);
        }
        // else if (arg1Node->getNodeType() == ASTNodeType::callFunc)
        // {
        //     Generate(arg1Node, symbolTable);
        //     Symbol *arg1 = tempVar.back();
        //     temp = new Quad(op, arg1, result);
        // }
        else
        {
            std::cout << "\033[31mError: \033[0m"
                      << "No match type of" << (int)arg1Node->getNodeType() << "  Content:" << arg1Node->getContent() << std::endl;
            exit(1);
        }
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case opType::assignArrayValue:
    // 给数组赋值
    {
        Symbol *result;
        if (node->getChild()->getNodeType() != ASTNodeType::op)
        {
            std::cout << "\033[31mError: \033[0m"
                      << node->getContent() << " syntax error. What are u doing?" << std::endl;
        }
        result = GenerateOp((OpASTNode *)node->getChild(), symbolTable);

        ASTNode *arg1Node = node->getChild()->getBrother();
        Symbol *arg2 = this->childValue.top();
        this->childValue.pop();

        if (arg1Node->getNodeType() == ASTNodeType::callVar)
        {
            Symbol *arg1 = symbolTable->findSymbolfromRoot(arg1Node->getContent());
            temp = new Quad(OpCode::ASSIGN_ARRAY, arg1, arg2, result);
        }
        else if (arg1Node->getNodeType() == ASTNodeType::op)
        {
            Symbol *arg1 = GenerateOp((OpASTNode *)arg1Node, symbolTable);
            temp = new Quad(OpCode::ASSIGN_ARRAY, arg1, arg2, result);
        }
        else if (arg1Node->getNodeType() == ASTNodeType::literal)
        {
            int arg1 = std::stoi(arg1Node->getContent());
            temp = new Quad(OpCode::ASSIGN_ARRAY, arg1, arg2, result);
        }
        // else if (arg1Node->getNodeType() == ASTNodeType::callFunc)
        // {
        //     Generate(arg1Node, symbolTable);
        //     Symbol *arg1 = tempVar.back();
        //     temp = new Quad(OpCode::ASSIGN_ARRAY, arg1, arg2, result);
        // }
        else
        {
            std::cout << "\033[31mError: \033[0m"
                      << "No match type of" << (int)arg1Node->getNodeType() << "  Content:" << arg1Node->getContent() << std::endl;
            exit(1);
        }
        this->quads.push_back(*temp);

        return result;
        break;
    }
    // case opType::AssignMember:
    // {
    //     Symbol *result;
    //     if (node->getChild()->getNodeType() != ASTNodeType::op)
    //     {
    //         std::cout << "\033[31mError: \033[0m"
    //                   << node->getContent() << " syntax error. What are u doing?" << std::endl;
    //     }

    //     result = GenerateOp((OpASTNode *)node->getChild(), symbolTable);
    //     ASTNode *arg1Node = node->getChild()->getBrother();
    //     Symbol *arg2 = this->childValue.top();
    //     this->childValue.pop();

    //     if (arg1Node->getNodeType() == ASTNodeType::callVar)
    //     {
    //         Symbol *arg1 = symbolTable->findSymbolfromRoot(arg1Node->getContent());
    //         temp = new Quad(OpCode::ASSIGN_STRUCT, arg1, arg2, result);
    //     }
    //     else if (arg1Node->getNodeType() == ASTNodeType::op)
    //     {
    //         Symbol *arg1 = GenerateOp((OpASTNode *)arg1Node, symbolTable);
    //         temp = new Quad(OpCode::ASSIGN_STRUCT, arg1, arg2, result);
    //     }
    //     else if (arg1Node->getNodeType() == ASTNodeType::literal)
    //     {
    //         int arg1 = std::stoi(arg1Node->getContent());
    //         temp = new Quad(OpCode::ASSIGN_STRUCT, arg1, arg2, result);
    //     }
    //     else if (arg1Node->getNodeType() == ASTNodeType::callFunc)
    //     {
    //         Generate(arg1Node, symbolTable);
    //         Symbol *arg1 = tempVar.back();
    //         temp = new Quad(OpCode::ASSIGN_STRUCT, arg1, arg2, result);
    //     }
    //     else
    //     {
    //         std::cout << "\033[31mError: \033[0m"
    //                   << "No match type of" << (int)arg1Node->getNodeType() << "  Content:" << arg1Node->getContent() << std::endl;
    //         exit(1);
    //     }
    //     this->quads.push_back(*temp);

    //     break;
    // }
    case opType::relop:
     // <,>,<=,>=,!=
    {
        Quad *tempTrue, *tempFalse;
        arg1Node = node->getChild();
        arg2Node = arg1Node->getBrother();
        if (node->getContent() == ">")
        {
            RelopOp(tempTrue, tempFalse, OpCode::JUMP_GREAT, arg1Node, arg2Node, symbolTable);
        }
        else if (node->getContent() == ">=")
        {
            RelopOp(tempTrue, tempFalse, OpCode::JUMP_EQ_GREAT, arg1Node, arg2Node, symbolTable);
        }
        else if (node->getContent() == "<")
        {
            RelopOp(tempTrue, tempFalse, OpCode::JUMP_SMALL, arg1Node, arg2Node, symbolTable);
        }
        else if (node->getContent() == "<=")
        {
            RelopOp(tempTrue, tempFalse, OpCode::JUMP_EQ_SMALL, arg1Node, arg2Node, symbolTable);
        }
        else if (node->getContent() == "!=")
        {
            RelopOp(tempTrue, tempFalse, OpCode::JUMP_NOT_EQUAL, arg1Node, arg2Node, symbolTable);
        }
        else if (node->getContent() == "==")
        {
            RelopOp(tempTrue, tempFalse, OpCode::JUMP_EQUAL, arg1Node, arg2Node, symbolTable);
        }

        break;
    }
    case opType::add: // 可能需要重构一下，方便看
    // 加？
    {
        Symbol *result = new Symbol("Temp" + std::to_string(tempVar.size()), Type::integer);
        arg1Node = node->getChild();
        arg2Node = arg1Node->getBrother();
        tempVar.push_back(result);
        result = tempVar.back();
        // 计算运算符？
        temp = this->CaculateOp(OpCode::PLUS, arg1Node, arg2Node, result, symbolTable);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case opType::subtract:
    // 减法？
    {
        Symbol *result = new Symbol("Temp" + std::to_string(tempVar.size()), Type::integer);
        arg1Node = node->getChild();
        arg2Node = arg1Node->getBrother();
        // push到存放符号表的数组tempVar
        tempVar.push_back(result);
        // 返回最后一个：
        result = tempVar.back();
        // 生成四元式
        temp = this->CaculateOp(OpCode::MINUS, arg1Node, arg2Node, result, symbolTable);
        // 推到数组里面
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case opType::multiply:
    // 乘法
    {
        Symbol *result = new Symbol("Temp" + std::to_string(tempVar.size()), Type::integer);
        arg1Node = node->getChild();
        arg2Node = arg1Node->getBrother();
        tempVar.push_back(result);
        result = tempVar.back();
        temp = this->CaculateOp(OpCode::TIMES, arg1Node, arg2Node, result, symbolTable);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case opType::divide:
    // 除法
    {
        Symbol *result = new Symbol("Temp" + std::to_string(tempVar.size()), Type::integer);
        arg1Node = node->getChild();
        arg2Node = arg1Node->getBrother();
        tempVar.push_back(result);
        result = tempVar.back();
        temp = this->CaculateOp(OpCode::DIV, arg1Node, arg2Node, result, symbolTable);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case opType::mod:
    // 取模：%
    {
        Symbol *result = new Symbol("Temp" + std::to_string(tempVar.size()), Type::integer);
        arg1Node = node->getChild();
        arg2Node = arg1Node->getBrother();
        tempVar.push_back(result);
        result = tempVar.back();
        temp = this->CaculateOp(OpCode::MOD, arg1Node, arg2Node, result, symbolTable);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case opType::pow:
    // 乘方
    {
        Symbol *result = new Symbol("Temp" + std::to_string(tempVar.size()), Type::integer);
        arg1Node = node->getChild();
        arg2Node = arg1Node->getBrother();
        tempVar.push_back(result);
        result = tempVar.back();
        temp = this->CaculateOp(OpCode::POWER, arg1Node, arg2Node, result, symbolTable);
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case opType::negative:
    // 负数
    {
        Symbol *result = new Symbol("Temp" + std::to_string(tempVar.size()), Type::integer);
        arg1Node = node->getChild();
        tempVar.push_back(result);
        result = tempVar.back();
        if (arg1Node->getNodeType() == ASTNodeType::callVar)
        {
            Symbol *arg1 = symbolTable->findSymbolfromRoot(arg1Node->getContent());
            temp = new Quad(OpCode::NEGATIVE, arg1, result);
        }
        else if (arg1Node->getNodeType() == ASTNodeType::literal)
        {
            int arg1 = std::stoi(arg1Node->getContent());
            temp = new Quad(OpCode::NEGATIVE, arg1, result);
        }
        else if (arg1Node->getNodeType() == ASTNodeType::op)
        {
            Symbol *arg1 = GenerateOp((OpASTNode *)arg1Node, symbolTable);
            temp = new Quad(OpCode::NEGATIVE, arg1, result);
        }
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case opType::signaland:
    // 单个与运算符：&
    {
        Symbol *result = new Symbol("Temp" + std::to_string(tempVar.size()), Type::pointer);

        arg1Node = node->getChild();
        cout << "node->getChild()" << node->getChild()->getContent()<<endl;
        tempVar.push_back(result);
        if (arg1Node->getNodeType() == ASTNodeType::callVar)
        {
            Symbol *arg1 = symbolTable->findSymbolfromRoot(arg1Node->getContent());
            cout << " symbolTable->findSymbolfromRoot(arg1Node->getContent());" <<endl;
            temp = new Quad(OpCode::GET_ADDRESS, arg1, result);
        }
        else
        {
            std::cout << "\033[31mError: \033[0m"
                      << " lvalue required as unary ‘&’ operand" << std::endl;
            exit(1);
        }
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case opType::andop: // 保证栈顶是：node2List, node1List,所以得先遍历子节点，再到&&节点
    // 很重要的回填操作
    {
        std::list<int> leftTrue, rightTrue, leftFalse, rightFalse;
        rightTrue = trueList.top();
        trueList.pop();
        leftTrue = trueList.top();
        trueList.pop();
        rightFalse = falseList.top();
        falseList.pop();
        leftFalse = falseList.top();
        falseList.pop();
        leftFalse.merge(rightFalse);
        falseList.push(leftFalse);
        trueList.push(rightTrue);
        backpatch(&leftTrue, signal.top());
        signal.pop();
        break;
    }
    case opType::orop:
    {
        std::list<int> leftTrue, rightTrue, leftFalse, rightFalse;
        rightTrue = trueList.top();
        trueList.pop();
        leftTrue = trueList.top();
        trueList.pop();
        rightFalse = falseList.top();
        falseList.pop();
        leftFalse = falseList.top();
        falseList.pop();
        leftTrue.merge(rightTrue);
        trueList.push(leftTrue);
        falseList.push(rightFalse);
        backpatch(&leftFalse, signal.top());
        signal.pop();
        break;
    }
    case opType::notop:
    {
        std::list<int> trueL, falseL;
        trueL = trueList.top();
        trueList.pop();
        falseL = falseList.top();
        falseList.pop();
        trueList.push(falseL);
        falseList.push(trueL);
        break;
    }
    case opType::getvalue:
    {
        Quad *temp;
        Symbol *result = new Symbol("Temp" + std::to_string(tempVar.size()), Type::integer);
        arg1Node = node->getChild();
        tempVar.push_back(result);
        if (arg1Node->getNodeType() == ASTNodeType::callVar)
        {
            Symbol *arg1 = symbolTable->findSymbolfromRoot(arg1Node->getContent());
            temp = new Quad(OpCode::GET_VALUE, arg1, result);
        }
        // else if (arg1Node->getNodeType() == ASTNodeType::callFunc)
        // {
        //     Generate(arg1Node, symbolTable);
        //     Symbol *arg1 = tempVar.back();
        //     temp = new Quad(OpCode::GET_VALUE, arg1, result);
        // }
        else if (arg1Node->getNodeType() == ASTNodeType::op)
        {
            Symbol *arg1 = GenerateOp((OpASTNode *)arg1Node, symbolTable);
            temp = new Quad(OpCode::GET_VALUE, arg1, result);
        }
        else
        {
            std::cout << "\033[31mError: \033[0m"
                      << " lvalue required as unary ‘&’ operand" << std::endl;
            exit(1);
        }
        this->quads.push_back(*temp);
        return result;
        break;
    }
    case opType::getArrayValue:
    {
        Quad *temp;
        Symbol *result = new Symbol("Temp" + std::to_string(tempVar.size()), Type::integer);
        ASTNode *arg1Node = node->getChild();
        ASTNode *arg2Node = arg1Node->getBrother();
        Symbol *arg1 = symbolTable->findSymbolfromRoot(arg1Node->getContent());
        // 如果赋值，就把index push到 childValue中 返回arg1
        // 如果是别的运算，就把值放到temp中，返回temp，并且加一条四元式
        if (node->getParent()->getNodeType() == ASTNodeType::op && ((OpASTNode *)node->getParent())->getType() == opType::assignArrayValue)
        {
            if (arg2Node->getNodeType() == ASTNodeType::callVar)
            {
                childValue.push(symbolTable->findSymbolfromRoot(arg2Node->getContent()));
            }
            // else if (arg2Node->getNodeType() == ASTNodeType::callFunc)
            // {
            //     Generate(arg2Node, symbolTable);
            //     Symbol *arg2 = tempVar.back();
            //     childValue.push(arg2);
            // }
            else if (arg2Node->getNodeType() == ASTNodeType::literal)
            {
                Symbol *arg2 = new Symbol(arg2Node->getContent(), Type::integer);
                childValue.push(arg2);
            }
            else if (arg2Node->getNodeType() == ASTNodeType::op)
            {
                Symbol *arg2 = GenerateOp((OpASTNode *)arg2Node, symbolTable);
                childValue.push(arg2);
            }
            else
            {
                std::cout << "\033[31mError: \033[0m"
                          << "Type error" << std::endl;
                exit(1);
            }
            return arg1;
        }
        else
        {
            if (arg2Node->getNodeType() == ASTNodeType::callVar)
            {
                Symbol *arg2 = symbolTable->findSymbolfromRoot(arg2Node->getContent());
                temp = new Quad(OpCode::GET_ARRAY, arg1, arg2, result);
            }
            // else if (arg2Node->getNodeType() == ASTNodeType::callFunc)
            // {
            //     Generate(arg2Node, symbolTable);
            //     Symbol *arg2 = tempVar.back();
            //     temp = new Quad(OpCode::GET_ARRAY, arg1, arg2, result);
            // }
            else if (arg2Node->getNodeType() == ASTNodeType::literal)
            {
                int arg2 = std::stoi(arg2Node->getContent());
                temp = new Quad(OpCode::GET_ARRAY, arg1, arg2, result);
            }
            else if (arg2Node->getNodeType() == ASTNodeType::op)
            {
                Symbol *arg2 = GenerateOp((OpASTNode *)arg2Node, symbolTable);
                temp = new Quad(OpCode::GET_ARRAY, arg1, arg2, result);
            }
            else
            {
                std::cout << "\033[31mError: \033[0m"
                          << "Type error" << std::endl;
                exit(1);
            }
            tempVar.push_back(result);
            this->quads.push_back(*temp);
            return result;
        }
    }
    // case opType::GetMember:
    // {
    //     Quad *temp;
    //     Symbol *result = new Symbol("Temp" + std::to_string(tempVar.size()), Type::integer);
    //     ASTNode *arg1Node = node->getChild();
    //     ASTNode *arg2Node = arg1Node->getBrother();
    //     Symbol *arg1 = symbolTable->findSymbolfromRoot(arg1Node->getContent());
    //     // 短路写法，应该没啥问题，不行再改
    //     if (node->getParent()->getNodeType() == ASTNodeType::op && ((OpASTNode *)node->getParent())->getType() == opType::AssignMember)
    //     {
    //         if (arg2Node->getNodeType() == ASTNodeType::callVar)
    //         {
    //             std::string typeName = ((structDecSymbol *)arg1)->getTypeName();
    //             int offset = this->rootTable->getStructTable()->findStruct(typeName)->getMemberOffset(arg2Node->getContent());
    //             Symbol *arg2 = new Symbol(std::to_string(offset), Type::literal);
    //             childValue.push(arg2);
    //         }
    //         else
    //         {
    //             std::cout << "\033[31mError: \033[0m"
    //                       << "Type error" << std::endl;
    //             exit(1);
    //         }
    //         return arg1;
    //     }
    //     else
    //     {
    //         if (arg2Node->getNodeType() == ASTNodeType::callVar)
    //         {
    //             std::string typeName = ((structDecSymbol *)arg1)->getTypeName();
    //             int offset = this->rootTable->getStructTable()->findStruct(typeName)->getMemberOffset(arg2Node->getContent());
    //             Symbol *arg2 = new Symbol(std::to_string(offset), Type::literal);
    //             temp = new Quad(OpCode::GET_STRUCT, arg1, arg2, result);
    //         }
    //         else
    //         {
    //             std::cout << "\033[31mError: \033[0m"
    //                       << "Type error" << std::endl;
    //             exit(1);
    //         }
    //         tempVar.push_back(result);
    //         this->quads.push_back(*temp);
    //         return result;
    //     }
    // }
    default:
        break;
    }
    return NULL;
}
// ASTNode
Quad *InterMediate::CaculateOp(OpCode op, ASTNode *arg1Node, ASTNode *arg2Node, Symbol *result, SymbolTable *symbolTable)
{
    Quad *temp;
    

    if (arg1Node->getNodeType() == ASTNodeType::callVar && arg2Node->getNodeType() == ASTNodeType::callVar)
    {
        Symbol *arg1 = symbolTable->findSymbolfromRoot(arg1Node->getContent());
        Symbol *arg2 = symbolTable->findSymbolfromRoot(arg2Node->getContent());
        temp = new Quad(op, arg1, arg2, result);
    }
    else if (arg1Node->getNodeType() == ASTNodeType::callVar && arg2Node->getNodeType() == ASTNodeType::op)
    {
        Symbol *arg1 = symbolTable->findSymbolfromRoot(arg1Node->getContent());
        Symbol *arg2 = GenerateOp((OpASTNode *)arg2Node, symbolTable);
        temp = new Quad(op, arg1, arg2, result);
    }
    else if (arg1Node->getNodeType() == ASTNodeType::callVar && arg2Node->getNodeType() == ASTNodeType::literal)
    {
        Symbol *arg1 = symbolTable->findSymbolfromRoot(arg1Node->getContent());
        int arg2 = std::stoi(arg2Node->getContent());
        temp = new Quad(op, arg1, arg2, result);
    }
    else if (arg1Node->getNodeType() == ASTNodeType::op && arg2Node->getNodeType() == ASTNodeType::callVar)
    {
        Symbol *arg1 = GenerateOp((OpASTNode *)arg1Node, symbolTable);
        Symbol *arg2 = symbolTable->findSymbolfromRoot(arg2Node->getContent());
        temp = new Quad(op, arg1, arg2, result);
    }
    else if (arg1Node->getNodeType() == ASTNodeType::op && arg2Node->getNodeType() == ASTNodeType::op)
    {
        Symbol *arg1 = GenerateOp((OpASTNode *)arg1Node, symbolTable);
        Symbol *arg2 = GenerateOp((OpASTNode *)arg2Node, symbolTable);
        temp = new Quad(op, arg1, arg2, result);
    }
    else if (arg1Node->getNodeType() == ASTNodeType::op && arg2Node->getNodeType() == ASTNodeType::literal)
    {
        Symbol *arg1 = GenerateOp((OpASTNode *)arg1Node, symbolTable);
        int arg2 = std::stoi(arg2Node->getContent());
        temp = new Quad(op, arg1, arg2, result);
    }

    else if (arg1Node->getNodeType() == ASTNodeType::literal && arg2Node->getNodeType() == ASTNodeType::callVar)
    {
        int arg1 = std::stoi(arg1Node->getContent());
        Symbol *arg2 = symbolTable->findSymbolfromRoot(arg2Node->getContent());
        temp = new Quad(op, arg1, arg2, result);
    }
    else if (arg1Node->getNodeType() == ASTNodeType::literal && arg2Node->getNodeType() == ASTNodeType::op)
    {
        int arg1 = std::stoi(arg1Node->getContent());
        Symbol *arg2 = GenerateOp((OpASTNode *)arg2Node, symbolTable);
        temp = new Quad(op, arg1, arg2, result);
    }
    else if (arg1Node->getNodeType() == ASTNodeType::literal && arg2Node->getNodeType() == ASTNodeType::literal)
    {
        int arg1 = std::stoi(arg1Node->getContent());
        int arg2 = std::stoi(arg2Node->getContent());
        temp = new Quad(op, arg1, arg2, result);
    }
    else
    {
        std::cout << "\033[31mError: \033[0m"
                  << "No match type for" << (int)arg1Node->getNodeType() << "  Content:" << arg1Node->getContent() << std::endl;
        exit(1);
    }
    return temp;
}

void InterMediate::RelopOp(Quad *trueQuad, Quad *falseQuad, OpCode op, ASTNode *arg1Node, ASTNode *arg2Node, SymbolTable *symbolTable)
{
    if (arg1Node->getNodeType() == ASTNodeType::callVar && arg2Node->getNodeType() == ASTNodeType::callVar)
    {
        trueQuad = new Quad(op, symbolTable->findSymbolfromRoot(arg1Node->getContent()), symbolTable->findSymbolfromRoot(arg2Node->getContent()), (int)NULL);
        falseQuad = new Quad(OpCode::JUMP, (int)NULL);
    }
    else if (arg1Node->getNodeType() == ASTNodeType::callVar && arg2Node->getNodeType() == ASTNodeType::literal)
    {
        trueQuad = new Quad(op, symbolTable->findSymbolfromRoot(arg1Node->getContent()), std::stoi(arg2Node->getContent()), (int)NULL);
        falseQuad = new Quad(OpCode::JUMP, (int)NULL);
    }
    else if (arg1Node->getNodeType() == ASTNodeType::literal && arg2Node->getNodeType() == ASTNodeType::callVar)
    {
        trueQuad = new Quad(op, std::stoi(arg1Node->getContent()), symbolTable->findSymbolfromRoot(arg2Node->getContent()), (int)NULL);
        falseQuad = new Quad(OpCode::JUMP, (int)NULL);
    }
    else if (arg1Node->getNodeType() == ASTNodeType::literal && arg2Node->getNodeType() == ASTNodeType::literal)
    {
        trueQuad = new Quad(op, std::stoi(arg1Node->getContent()), std::stoi(arg2Node->getContent()), (int)NULL);
        falseQuad = new Quad(OpCode::JUMP, (int)NULL);
    }
    std::list<int> trueL; // Use size to get the index of true quad will be pushed
    trueL.push_back(quads.size());
    this->quads.push_back(*trueQuad);
    std::list<int> falseL; // Same as the upper one
    falseL.push_back(quads.size());
    this->quads.push_back(*falseQuad);
    trueList.push(trueL);
    falseList.push(falseL);
    return;
}

std::list<int> *InterMediate::makelist(int index)
{
    std::list<int> *jumpList = new std::list<int>();
    jumpList->push_back(index);
    return jumpList;
}
std::list<int> *InterMediate::merge(std::list<int> *list1, std::list<int> *list2)
{
    list1->merge(*list2);
    return list1;
}
void InterMediate::backpatch(std::list<int> *backList, int target)
{
    std::list<int>::iterator it;
    for (it = backList->begin(); it != backList->end(); it++)
    {
        quads[*it].backpatch(target);
    }
    return;
}
void InterMediate::printQuads()
{
    std::vector<Quad>::iterator it;
    std::cout << "\t   Operator   \targ1\targ2\tresult" << std::endl;
    int count = 0;
    for (it = this->quads.begin(); it != this->quads.end(); it++)
    {
        std::cout << count++ << "\t";
        it->printQuad();
    }
    return;
}