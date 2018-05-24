#include "avm.h"

avm_memcell *avm_translate_operand(vmarg* arg,avm_memcell* reg){
	switch(arg->type){

		/*Variables*/
		case global_a:	return &stack[AVM_STACKSIZE - 1 - arg->val];
		case local_a:	return &stack[topsp - arg->val];
		case formal_a:	return &stack[topsp+AVM_STACKENV_SIZE+1 + arg->val];
		case retval_a:	return &retval;

		/*Constants*/
		case number_a:	{
			reg->type=number_m;
			reg->data.numVal=consts_getnumber(arg->val);//this function needs to be tested
			return reg;
		}
		case string_a:	{
			reg->type=bool_m;
			reg->data.strVal=consts_getstring(arg->val);//needs to be implemented
		}
	}	
}

static void avm_initstack(void){
	unsigned i;
	for(i=0; i<AVM_STACKSIZE; ++i){
		AVM_WIPEOUT(stack[i]);
		stack[i].type=undef_m;
	}
}

avm_table *avm_tablenew(void){
	avm_table * t =new avm_table();
	AVM_WIPEOUT(*t);

	t-> refCounter = t->total = 0;
	avm_tablebucketsinit(t->numIndexed);
	avm_tablebucketsinit(t->strtIndexed);

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

int main(){return 0;}