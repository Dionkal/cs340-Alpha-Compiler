#ifndef AVM_LIB
#define AVM_LIB
#include <assert.h>
#include <string>
#include <iostream>
#include "vmargs.h"
#include <stdlib.h>

#include "initVM.h"
#define MAGIC_NUMBER 340200501
#define AVM_TABLE_HASHTABLE 211
#define AVM_STACKSIZE 4096
#define AVM_STACKENV_SIZE 4

typedef enum avm_memcell_t{
	number_m	=0,
	string_m	=1,
	bool_m		=2,
	table_m		=3,
	userfunc_m	=4,
	libfunc_m	=5,
	nil_m		=6,
	undef_m		=7
}avm_memcell_t;

struct avm_table;

typedef struct avm_memcell{
	avm_memcell_t	type;
	union{
		double			numVal;
		char* 			strVal;
		bool			boolVal;
		avm_table*		tableVal;
		unsigned		funcVal;
		char* 			libfuncVal;
	}data;
}avm_memcell;

typedef void (*memclear_func_t)(avm_memcell *);

void avm_memcellclear(avm_memcell* m);

void memclear_string(avm_memcell* m);

void memclear_table(avm_memcell* m);

void avm_warning(std::string format);

/*translate a vmarg into a register*/
avm_memcell *avm_translate_operand(vmarg* arg,avm_memcell* reg);

/*Get consts and functions*/
double 		consts_getnumber(unsigned index);
char*  		consts_getstring(unsigned index);
char*  		libfuncs_getused(unsigned index);
unsigned	userfunc_getaddr(unsigned index);

#endif