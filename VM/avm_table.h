#ifndef AVM_TABLE_LIB
#define AVM_TABLE_LIB
#include "avm.h"
#include <map>
#include <assert.h>

/*numeric, and string keys but also the bonus: user functions,
	lib functions and booleans*/
typedef struct avm_table
{
	unsigned refCounter;
	std::map<std::string, avm_memcell> strIndexed;
	std::map<double, avm_memcell> numIndexed;
	/*FEAUTURE: ADD more map types*/
	unsigned total;
} avm_table;

avm_table *avm_tablenew(void);

void avm_tableincrefcounter(avm_table *t);

void avm_tabledecrefcounter(avm_table *t);

void avm_tabledestroy(avm_table *t);

avm_memcell avm_tablegetelem(avm_table *table, avm_memcell *key);

void avm_tablesetelem(avm_table *table, avm_memcell *key, avm_memcell *val);

typedef std::map<std::string, avm_memcell> strIndexedEntry;
typedef std::map<double, avm_memcell> numIndexedEntry;
typedef std::map<std::string, avm_memcell>::iterator strIndexedIterator;
typedef std::map<double, avm_memcell>::iterator numIndexedIterator;

user_func_array_entry *avm_getfuncinfo(unsigned address);
#endif
