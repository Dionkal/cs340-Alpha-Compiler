#ifndef AVM_TABLE_LIB
	#define AVM_TABLE_LIB
	#include "avm.h"
	
	#include <assert.h>

	typedef struct avm_table_bucket{
		avm_memcell key;
		avm_memcell value;
		avm_table_bucket* next;
	}avm_table_bucket;

	/*numeric, and string keys but also the bonus: user functions, 
	lib functions and booleans*/
	typedef struct avm_table{
	unsigned refCounter;
		avm_table_bucket* strIndexed[AVM_TABLE_HASHTABLE];
		avm_table_bucket* numIndexed[AVM_TABLE_HASHTABLE];
		avm_table_bucket* userFunc[AVM_TABLE_HASHTABLE];//CHECK THIS NOT SURE
		avm_table_bucket* libFunc[AVM_TABLE_HASHTABLE];
		avm_table_bucket* boolIndexed[AVM_TABLE_HASHTABLE];
		unsigned total;
	}avm_table;


	avm_table *avm_tablenew(void);

	void avm_tabledestroy(avm_table* t);

	avm_memcell *avm_tablegetelem(avm_memcell *key);

	void avm_tablesetelem(avm_memcell *key,avm_memcell *value);

	void avm_tableincrefcounter(avm_table* t);

	void avm_tabledecrefcounter(avm_table* t);

	void avm_tablebucketsinit(avm_table_bucket** p);

	void avm_tablebucketsdestroy(avm_table_bucket** p);
#endif