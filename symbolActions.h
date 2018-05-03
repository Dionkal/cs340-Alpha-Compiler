#ifndef SYMBOL_ACTIONS_LIB
#define SYMBOL_ACTIONS_LIB


#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <string>



symTableEntry* actionID(std::string id);

symTableEntry* actionLocalID(std::string id);

symTableEntry* actionGlobalID(std::string id);

#endif