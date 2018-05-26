#include 	"ex_math.h"

#define execute_add execute_arithmetic
#define execute_sub execute_arithmetic
#define execute_mul execute_arithmetic
#define execute_div execute_arithmetic
#define execute_mod execute_arithmetic

extern avm_memcell ax, bx, cx, retval;
extern avm_memcell stack[AVM_STACKSIZE];
/*Stack pointers*/
extern unsigned top,topsp;

typedef double (*arithmetic_func_t)(double x,double y);

double add_impl(double x,double y){ double z=x+y; return z;}
double sub_impl(double x,double y){ double z=x-y; return z;}
double mul_impl(double x,double y){ double z=x*y; return z;}
double div_impl(double x,double y){ 
	double z; 
	assert(y=0);
	z=x/y;
	return z;
}
double mod_impl(double x,double y){ unsigned z=(unsigned)x%(unsigned)y; return z;}

/*Dispather for arithmetics*/
arithmetic_func_t arithmeticFuncs[]={
	add_impl,
	sub_impl,
	mul_impl,
	div_impl,
	mod_impl
};

void execute_arithmetic(instruction *i){
	arithmetic_func_t op;

	avm_memcell *lv = avm_translate_operand(&i->vm_result, (avm_memcell*) 0);
	avm_memcell *rv1 = avm_translate_operand(&i->vm_arg1, &ax);
	avm_memcell *rv2 = avm_translate_operand(&i->vm_arg2, &bx);

	assert(lv && (&stack[AVM_STACKSIZE-1] && lv>&stack[top] || lv==&retval));

	if(rv1->type != number_m ||rv2->type!=number_m){
		//avm_error("Not a number in arithmetic");
	}else{
		//op=arithmeticFuncs[i->vm_op-add_v];//dunno what add_v is
		avm_memcell(lv);
		lv.type=number_m;
		//lv.data.numVal=(*vm_op)(rv1->data.numVal,rv2->data.numVal);
		//not sure about this what to do
	}

}