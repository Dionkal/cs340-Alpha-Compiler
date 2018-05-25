#include "avm_table.h"

/*Temp definition
*/
void avm_memcellclear(avm_memcell* m){}


avm_table *avm_tablenew(void){
	avm_table * t = new avm_table();
	// AVM_WIPEOUT(*t);

	t-> refCounter = t->total = 0;
	avm_tablebucketsinit(t->numIndexed);
	avm_tablebucketsinit(t->strIndexed);
	/*TODO init other hash maps for bonus*/	
	return t;
}

void avm_tableincrefcounter(avm_table* t){
	++t->refCounter;
}

/*Automatic garbage collection for tables when reference counter get zero*/
void avm_tabledecrefcounter(avm_table* t){
	assert(t->refCounter > 0);
	if(!(--t->refCounter)){
		avm_tabledestroy(t);
	}
}

void avm_tablebucketsinit(avm_table_bucket** p){
	for(unsigned i =0; i < AVM_TABLE_HASHTABLE; ++i){
		p[i] = (avm_table_bucket*) 0;
	}
}


void avm_tablebucketsdestroy(avm_table_bucket** p){
	for (unsigned i = 0; i < AVM_TABLE_HASHTABLE; ++i, ++p){
		/*Delete inner tables recursively*/
		for(avm_table_bucket* b = *p; b;){
			avm_table_bucket* del = b;
			b = b->next;
			avm_memcellclear(&del->key);
			avm_memcellclear(&del->value);
			delete(del);
		}
		p[i] = (avm_table_bucket*) 0; //clear memory
	}
}

void avm_tabledestroy(avm_table* t){
	avm_tablebucketsdestroy(t->strIndexed);
	avm_tablebucketsdestroy(t->numIndexed);
	delete(t);
}