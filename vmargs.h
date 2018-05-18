#include "quad.h"

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

typedef struct instruction{
	vmopcode opcode;
	vmarg 	 result;
	vmarg 	 arg1;
	vmarg 	 arg2;
	unsigned srcLine;
}instruction;

/*ME POIA SEIRA NA TA EXOUME? SAN EMAS I SAN TOU FRONT?*/
/*added NOP but dunno what it does*/
typedef struct vmopcode{
	assign_vmopcode,
	add_vmopcode,
	sub_vmopcode,
	mul_vmopcode,
	div_vmopcode,
	mod_vmopcode,
	/*uminus_iopcode,*/
	/*and_iopcode,	*/
	or_vmopcode,
	not_vmopcode,
	if_eq_vmopcode,
	if_noteq_vmopcode,
	if_lesseq_vmopcode,
	if_greatereq_vmopcode,
	if_less_vmopcode,
	if_greater_vmopcode,
	call_vmopcode,
	param_vmopcode,
	ret_vmopcode,
	getretval_vmopcode,
	funcstart_vmopcode,
	funcend_vmopcode,
	tablecreate_vmopcode,
	tablegetelem_vmopcode,
	tablesetelem_vmopcode,
	jump_vmopcode,
	/*invalid_iopcode*/
}vmopcode;

typedef struct incomplete_jump{
	unsigned	     instrNo; //The jump instruction number
	unsigned 	     iaddress;//The i-code jump-target address
	incomplete_jump* next;	  //a trivial linked list.
}incomplete_jump;

incomplete_jump *ij_head = (incomplete_jump *) 0;
unsigned		ij_total=0;

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





















