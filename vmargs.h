#ifndef VMARGS_LIB
	#define VMARGS_LIB

#include "quad.h"
#include "assert.h"

typedef enum vmarg_t{
	global_a,
	local_a,
	formal_a,
	bool_a,
	string_a,
	number_a,
	nil_a,
	userfunc_a,
	libfunc_a
}vmarg_t;

typedef struct vmarg{
	vmarg_t 	type;
	unsigned	val;
}vmarg;

/*ME POIA SEIRA NA TA EXOUME? SAN EMAS I SAN TOU FRONT?*/
/*added NOP but dunno what it does*/
typedef enum vmopcode{//to xa struct tora egine struct
	assign_vmopcode = 0,
	add_vmopcode = 1,
	sub_vmopcode = 2,
	mul_vmopcode = 3 ,
	div_vmopcode = 4,
	mod_vmopcode = 5,
	/*uminus_vmopcode,*/
	/*and_vmopcode,	*/
	or_vmopcode = 8 ,
	not_vmopcode = 9,
	if_eq_vmopcode = 10,
	if_noteq_vmopcode = 11,
	if_lesseq_vmopcode = 12,
	if_greatereq_vmopcode = 13,
	if_less_vmopcode = 14,
	if_greater_vmopcode = 15,
	call_vmopcode = 16,
	param_vmopcode = 17,
	ret_vmopcode = 18,
	getretval_vmopcode = 19,
	funcstart_vmopcode = 20,
	funcend_vmopcode = 21,
	tablecreate_vmopcode = 22,
	tablegetelem_vmopcode = 23,
	tablesetelem_vmopcode = 24,
	jump_vmopcode = 25,
	invalid_vmopcode = 26
}vmopcode;

typedef struct incomplete_jump{
	unsigned	     instrNo; //The jump instruction number
	unsigned 	     iaddress;//The i-code jump-target address
	incomplete_jump* next;	  //a trivial linked list.
}incomplete_jump;

/*Generate instruction from given quad*/
void generate(iopcode op, quad q);

/*TODO: add comment about fuction signature*/
void generate_func (void);

void add_incomplete_jump (unsigned instrNo, unsigned iaddress);

/*TODO: patch_incomplete_jumps function*/

extern void generate_ADD(quad*);
extern void generate_SUB(quad*);
extern void generate_MUL(quad*);
extern void generate_DIV(quad*);
extern void generate_MOD(quad*);
extern void generate_NEWTABLE(quad*);
extern void generate_TABLEGETELEM(quad*);
extern void generate_TABLESETELEM(quad*);
extern void generate_ASSIGN(quad*);
extern void generate_NOP(quad*);
extern void generate_JUMP(quad*);
extern void generate_IF_EQ(quad*);
extern void generate_IF_NOTEQ(quad*);
extern void generate_IF_GREATER(quad*);
extern void generate_IF_GREATEREQ(quad*);
extern void generate_IF_LESS(quad*);
extern void generate_IF_LESSEQ(quad*);
extern void generate_NOT(quad*);
extern void generate_OR(quad*);
extern void generate_PARAM(quad*);
extern void generate_CALL(quad*);
extern void generate_GETRETVAL(quad*);
extern void generate_FUNCSTART(quad*);
extern void generate_RETURN(quad*);
extern void generate_FUNCEND(quad*);

typedef struct instruction{
	vmopcode vm_op;
	vmarg 	 vm_result;
	vmarg 	 vm_arg1;
	vmarg 	 vm_arg2;
	unsigned vm_srcLine;
}instruction;

void make_operand(expr * e, vmarg* arg);

/*Matches iopcode to vmopcode*/
int iopcodeToVmopcode(iopcode op);

/*TO IMPLEMENT*/
unsigned consts_newstring(std::string str);

unsigned consts_newnumber(double numconst);

unsigned libfuncs_newused(std::string str);


#endif