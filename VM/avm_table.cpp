#include "avm_table.h"

avm_table *avm_tablenew(void){
	avm_table * t =new avm_table();
	// AVM_WIPEOUT(*t);

	t-> refCounter = t->total = 0;
	/*avm_tablebucketsinit(t->numIndexed);
	avm_tablebucketsinit(t->strIndexed);
*/
	return t;
}

void avm_tableincrefcounter(avm_table* t){
	++t->refCounter;
}

/*Automatic garbage collection for tables when reference counter get zero*/
void avm_tabledecrefcounter(avm_table* t){
	assert(t->refCounter > 0);
	//if()
	//TODO
}