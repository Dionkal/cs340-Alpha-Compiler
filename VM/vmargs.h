#ifndef VMARGS_LIB
	#define VMARGS_LIB
	#define MAGIC_NUMBER 340200501
#include "quad.h"
#include "assert.h"
#include <vector>
#include <iterator>


/*It's important that invalid_a is represented by zero because all uninitialized
 vmarg_ts will be by default zero */
typedef enum vmarg_t{
	invalid_a,		
	assign_a,
	global_a,
	local_a,
	formal_a,
	bool_a,
	string_a,
	number_a,
	nil_a,
	userfunc_a,
	libfunc_a,
	label_a,
	retval_a
}vmarg_t;

typedef struct vmarg{
	vmarg_t 	type;
	unsigned	val;
}vmarg;


typedef enum vmopcode{
	assign_vmopcode = 0,
	add_vmopcode = 1,
	sub_vmopcode = 2,
	mul_vmopcode = 3 ,
	div_vmopcode = 4,
	mod_vmopcode = 5,
	/*uminus_vmopcode = 6,*/
	/*and_vmopcode = 7,*/
	/*or_vmopcode = 8 ,*/
	/*not_vmopcode = 9,*/
	if_eq_vmopcode = 10,
	if_noteq_vmopcode = 11,
	if_lesseq_vmopcode = 12,
	if_greatereq_vmopcode = 13,
	if_less_vmopcode = 14,
	if_greater_vmopcode = 15,
	call_vmopcode = 16,
	param_vmopcode = 17,
	/*ret_vmopcode = 18,*/
	/*getretval_vmopcode = 19,*/
	funcstart_vmopcode = 20,
	funcend_vmopcode = 21,
	tablecreate_vmopcode = 22,
	tablegetelem_vmopcode = 23,
	tablesetelem_vmopcode = 24,
	jump_vmopcode = 25,
	nop_vmopcode = 26,
}vmopcode;

typedef struct incomplete_jump{
	unsigned	     instrNo; //The jump instruction number
	unsigned 	     iaddress;//The i-code jump-target address
}incomplete_jump;

/*Generate instruction from given quad*/
void generate(iopcode op, quad* q);

/*Generate instruction for relops and jumps
 with incomplete jump handling*/
void generate_relational(iopcode op, quad* q);

/*get the index of the next instruction label*/
unsigned next_instruction_label();

/*TODO: add comment about fuction signature*/
void generate_func (void);

/*Adds the instruction's index of an incomplete and their respective quad to the list
for future backpatching*/
void add_incomplete_jump (unsigned instrNo, unsigned iaddress);

/*Pathes the list of the incomplete instruction jumps*/
void patch_incomplete_jumps();

typedef struct instruction{
	vmopcode vm_op;
	vmarg 	 vm_result;
	vmarg 	 vm_arg1;
	vmarg 	 vm_arg2;
	unsigned vm_srcLine;
}instruction;

/*--------------Helper functions that create a vmarg from a specific value type*/

void make_operand(expr * e, vmarg* arg);

void make_numberoperand(vmarg* arg, double val);

void make_booloperand(vmarg* arg, unsigned val);

void make_retvaloperand(vmarg* arg);

/*resets a specific vmarg to invalid values*/
void reset_operand(vmarg* arg);

/*Matches iopcode to vmopcode*/
int iopcodeToVmopcode(iopcode op);

typedef struct user_func_array_entry{
	unsigned 	address;
	unsigned	local_size;
	std::string id;
}user_func_array_entry;


/*Some typedefs to reduce large code, thnx valsamakis for the tip*/
typedef std::vector<std::string>::iterator constStringiterator;
typedef std::vector<double>::iterator constDoubleiterator;
typedef std::vector<std::string>::iterator libFunciterator;
typedef std::vector<user_func_array_entry>::iterator userFunciterator;
typedef std::vector<instruction>::iterator instrIterator;
typedef std::vector<incomplete_jump>::iterator jumpListIterator;

/*****Filler functions for const arrays*****/
	
/*Fills const_string_array*/
unsigned consts_newstring(std::string str);

/*Fills const_num_array*/
unsigned consts_newnumber(double numconst);

/*Fills lib_func_used_array*/
unsigned libfuncs_newused(std::string str);

unsigned userfuncs_newfunc(symTableEntry* sym);

/*Prints the global arrays*/
void printArrays();

/*Prints the instructions*/
void printInstructions();

/*Print the given vmarg */
void printVmarg(vmarg arg);

std::string vmopcodeToString(vmopcode op);

std::string vmtypeToString(vmarg_t type);

void printToFile(std::string filename);
#endif

