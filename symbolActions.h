#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <string>



symTableEntry* actionID(std::string id);

symTableEntry* actionLocalID(std::string id);

symTableEntry* actionGlobalID(std::string id);

//eriona ioanna
expr *member_item(expr * e,std::string id);

expr *newxpr_constrstring(std::string s);

expr *emit_iftableitem(expr *e);