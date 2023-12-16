#include "../codeGeneration/codeGeneration.h"

void InitializeModuleAndPassManager();
void HandleDefinition(); 
void HandleExtern();
void HandleTopLevelExpression();
void MainLoop();

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif
extern "C" DLLEXPORT double putchard(double X);
extern "C" DLLEXPORT double printd(double X);