#ifndef EXECUTE_ASSIGN_LIB
#define EXECUTE_ASSIGN_LIB
#include "memcell.h"
#include "vmargs.h"

void avm_assign(avm_memcell *lv, avm_memcell *rv);
void execute_assign(instruction *);
#endif
