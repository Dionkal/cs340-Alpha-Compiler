#ifndef AVM_LIB
#define AVM_LIB
#include <assert.h>
#include <string>
#include <iostream>
#include "vmargs.h"
#include <stdlib.h>
#include <cstdarg>
#include <algorithm>
#include "execute_call.h"
#include "execute_nop.h"
#include "ex_assign.h"
#include "ex_math.h"
#include "ex_jumps.h"
#include "execute_table.h"
#include <map>
#include "memcell.h"

#include "initVM.h"
#define MAGIC_NUMBER 340200501
#define AVM_TABLE_HASHTABLE 211
#define AVM_STACKSIZE 4096
#define AVM_STACKENV_SIZE 4
#define AVM_MAX_INSTRUCTIONS nop_vmopcode //the max valid opode an isntruction can take

#define AVM_NUMACTUALS_OFFSET 4

typedef void (*memclear_func_t)(avm_memcell *);

void avm_memcellclear(avm_memcell *m);

void memclear_string(avm_memcell *m);

void memclear_table(avm_memcell *m);

void avm_warning(const char *format, ...);

void avm_error(const char *fmt, ...);

/*translate a vmarg into a register*/
avm_memcell *avm_translate_operand(vmarg *arg, avm_memcell *reg);

/*Get consts and functions*/
double consts_getnumber(unsigned index);
char *consts_getstring(unsigned index);
char *libfuncs_getused(unsigned index);
unsigned userfunc_getaddr(unsigned index);

typedef void (*execute_func_t)(instruction *);

void execute_cycle();

#endif
