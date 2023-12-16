#include "../Parser/parser.h"

/*
To generate LLVM IR, we define a pure virtual 
function codegen in ExprAST (abstract class 
for expressions). The codegen() method says 
to emit IR for that AST node along with all 
the things it depends on, and they all return 
an LLVM Value object. 

Note that instead of adding virtual methods to 
the ExprAST class hierarchy, it could also make
 sense to use a visitor pattern or some other 
 way to model this. It is worth considering 
 doing this in the future. 
For LLVM IR generation we need to include 
some LLVM header and define the following modules. 


*/

extern std::unique_ptr<LLVMContext> TheContext;
extern std::unique_ptr<Module> TheModule;
extern std::unique_ptr<IRBuilder<>> Builder;
extern std::map<std::string, AllocaInst *> NamedValues;
extern std::map<std::string, std::unique_ptr<PrototypeAST>> FunctionProtos;
extern ExitOnError ExitOnErr;

Value *LogErrorV(const char *Str);
Function *getFunction(std::string Name);
static AllocaInst *CreateEntryBlockAlloca(Function *TheFunction,
                                          StringRef VarName);