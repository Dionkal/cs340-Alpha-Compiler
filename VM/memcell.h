#ifndef MEMCELL_LIB
#define MEMCELL_LIB
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

#endif
