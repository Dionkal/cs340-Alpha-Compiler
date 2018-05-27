#include "avm.h"
#include <fstream>
#include <cstring>

/*Size of the global space*/
extern unsigned globalSize;
extern std::vector<instruction> vctr_instr;

/*Const values Data storage*/
extern std::vector <std::string> 				const_string_array;
extern std::vector <double> 					const_num_array;
extern std::vector <std::string> 				lib_func_used_array;
extern std::vector <user_func_array_entry>		user_func_array;



/*AVM registers*/
avm_memcell eax, bx, cx, retval;

/*Stack pointers*/
unsigned top,topsp;

/*GLOBAL STATIC STACK*/
avm_memcell stack[AVM_STACKSIZE];

double 		consts_getnumber(unsigned index) {return const_num_array[index];}
char*  		consts_getstring(unsigned index) {return (char*) (const_string_array[index]).c_str();}
char*  		libfuncs_getused(unsigned index) {return (char*) (lib_func_used_array[index]).c_str();}
unsigned	userfunc_getaddr(unsigned index) {return user_func_array[index].address;}

avm_memcell *avm_translate_operand(vmarg* arg,avm_memcell* reg){
	switch(arg->type){

		/*Variables*/
		case global_a:	return &stack[AVM_STACKSIZE - 1 - arg->val];
		case local_a:	return &stack[topsp - arg->val];
		case formal_a:	return &stack[topsp + AVM_STACKENV_SIZE + 1 + arg->val];
		case retval_a:	return &retval;

		/*Constants*/
		case number_a:	{
			reg->type=number_m;
			reg->data.numVal=consts_getnumber(arg->val);
			return reg;
		}
		case string_a:	{
			reg->type=bool_m;
			reg->data.strVal=strdup(consts_getstring(arg->val));
			return reg;
			/*TODO check were strings are deleted and free the pointer
			in order to avoid memory leaks*/
		}

		case bool_a: {
			reg->type = bool_m;
			reg->data.boolVal = (arg->val)? true: false;
			return reg;
		}

		case nil_a: {
			reg->type = nil_m;
			return reg;
		}

		/*Functions*/
		case userfunc_a: {
			reg->type = userfunc_m;
			reg->data.funcVal = userfunc_getaddr(arg->val);  
		}

		case libfunc_a: {
			reg->type = libfunc_m;
			reg->data.libfuncVal = strdup(libfuncs_getused(arg->val));
			/*TODO check were strings are deleted and free the pointer
			in order to avoid memory leaks*/
		}

		default:
			assert(0); //error no know type
	}	
}

static void avm_initstack(void){
	unsigned i;
	for(i=0; i<AVM_STACKSIZE; ++i){
		stack[i].type=undef_m;
	}
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