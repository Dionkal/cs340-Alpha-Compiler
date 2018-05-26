#include "avm.h"
#include <fstream>

/*Size of the global space*/
extern unsigned globalSize;

/*GLOBAL STATIC STACK*/
avm_memcell stack[AVM_STACKSIZE];

// avm_memcell *avm_translate_operand(vmarg* arg,avm_memcell* reg){
	// switch(arg->type){

		/*Variables*/
	/*	case global_a:	return &stack[AVM_STACKSIZE - 1 - arg->val];
		case local_a:	return &stack[topsp - arg->val];
		case formal_a:	return &stack[topsp+AVM_STACKENV_SIZE+1 + arg->val];
		case retval_a:	return &retval;
*/
		/*Constants*/
	/*	case number_a:	{
			reg->type=number_m;
			reg->data.numVal=consts_getnumber(arg->val);//this function needs to be tested
			return reg;
		}
		case string_a:	{
			reg->type=bool_m;
			reg->data.strVal=consts_getstring(arg->val);//needs to be implemented
		}
	}*/	
// }

static void avm_initstack(void){
	unsigned i;
	for(i=0; i<AVM_STACKSIZE; ++i){
		stack[i].type=undef_m;
	}
}


memclear_func_t memclearFuncs[]={
	0,/*number*/
	memclear_string,
	0,/*bool*/
	memclear_table,
	0,/*user func*/
	0,/*libfunc*/
	0,/*nil*/
	0/*undef*/
};

void avm_memcellclear(avm_memcell* m){
	memclear_func_t  f;

	if(m->type!=undef_m){
		f=memclearFuncs[m->type];
		if(f){
			(*f)(m);
		}
		m->type=undef_m;
	}

}

void memclear_string(avm_memcell* m){
	assert(m->data.strVal);
	free(m->data.strVal);
}

void memclear_table(avm_memcell* m){
	assert(m->data.tableVal);
	avm_tabledecrefcounter(m->data.tableVal);
}

int main(int argc, char *argv[]){
	if(argc!=2){
		std::cout <<"No input file, exiting";
		return 0;
	}
	readFile(std::string(argv[1]));
	avm_initstack(); 
	return 0;
}