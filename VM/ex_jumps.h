#include <assert.h>
#include "avm.h"

typedef unsigned char (*tobool_func_t)(avm_memcell *);

void execute_jeq(instruction *i);

void execute_jne(instruction *i);

void execute_jle(instruction *i);

void execute_jge(instruction *i);

void execute_jlt(instruction *i);

void execute_jgt(instruction *i);
