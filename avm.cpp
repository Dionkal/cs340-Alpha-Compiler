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