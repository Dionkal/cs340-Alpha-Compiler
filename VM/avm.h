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
#include <map>

#include "initVM.h"
#define MAGIC_NUMBER 340200501
#define AVM_TABLE_HASHTABLE 211
#define AVM_STACKSIZE 4096
#define AVM_STACKENV_SIZE 4

#define AVM_NUMACTUALS_OFFSET 4

typedef enum avm_memcell_t
{
	number_m = 0,
	string_m = 1,
	bool_m = 2,
	table_m = 3,
	userfunc_m = 4,
	libfunc_m = 5,
	nil_m = 6,
	undef_m = 7
} avm_memcell_t;

struct avm_table;

typedef struct avm_memcell
{
	avm_memcell_t type;
	union {
		double numVal;
		char *strVal;
		bool boolVal;
		avm_table *tableVal;
		unsigned funcVal;
		char *libfuncVal;
	} data;
} avm_memcell;

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

typedef void (*library_func_t)(void);

void avm_dec_top(void);

void avm_push_envvalue(unsigned val);

void avm_callsaveenvironment(void);

unsigned avm_get_envvalue(unsigned i);

void avm_calllibfunc(char *id);

unsigned avm_totalactuals(void);

avm_memcell *avm_getactual(unsigned i);

library_func_t avm_getlibraryfunc(std::string id);

/*
	With the following every library function is manually
	added in the VM library function resolution map.
*/
void avm_registerlibfunc(std::string id, library_func_t addr);

user_func_array_entry *avm_getfuncinfo(unsigned address);
#endif
