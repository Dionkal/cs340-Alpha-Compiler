#ifndef AVM_LIB
#define AVM_LIB
#include <assert.h>
#include <string>
#include <iostream>
#include "vmargs.h"

#include "initVM.h"
#define MAGIC_NUMBER 340200501
#define AVM_TABLE_HASHTABLE 211
#define AVM_STACKSIZE 4096

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
	typedef union data{
		double			numVal;
		char* 			strVal;
		unsigned char	boolChar;
		avm_table *		tableVar;
		unsigned		funcVal;
		char* 			libfuncVal;
	}data;
}avm_memcell;

void avm_memcellclear(avm_memcell* m);

#endif