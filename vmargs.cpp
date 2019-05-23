#include "vmargs.h"
#include <vector>
#include "generateInstrFunc.h"
#include <iostream>
#include <iomanip>
#include "quad.h"
#include <fstream>

extern std::vector<quad> vctr_quads;
extern unsigned int programVarOffset;
static unsigned currprocessedquad = 0;

/*Global vector of instructions*/
std::vector<instruction> vctr_instr;

/*Data storage of all incomplete jump instructions and their respective quads*/
std::vector<incomplete_jump> inc_jump_list;

/*Const values Data storage*/
std::vector<std::string> const_string_array;
std::vector<double> const_num_array;
std::vector<std::string> lib_func_used_array;
std::vector<user_func_array_entry> user_func_array;

unsigned next_instruction_label()
{
	return vctr_instr.size();
}

unsigned consts_newstring(std::string str)
{
	constStringiterator it;
	unsigned i = 0;
	/*Optimisation: Iterate the vector to see if the const already exists*/
	for (it = const_string_array.begin(); it != const_string_array.end(); it++, i++)
	{
		if (*it == str)
		{
			return i;
		}
	}

	const_string_array.push_back(str);
	return i + 1;
}

unsigned consts_newnumber(double numconst)
{
	constDoubleiterator it;
	unsigned i = 0;
	/*Optimisation: Iterate the vector to see if the const already exists*/
	for (it = const_num_array.begin(); it != const_num_array.end(); it++, i++)
	{
		if (*it == numconst)
		{
			return i;
		}
	}

	const_num_array.push_back(numconst);
	return i + 1;
}

unsigned libfuncs_newused(std::string str)
{
	libFunciterator it;
	unsigned i = 0;

	/*Optimisation: Iterate the vector to see if the element already exists*/
	for (it = lib_func_used_array.begin(); it != lib_func_used_array.end(); it++, i++)
	{
		if (*it == str)
		{
			return i;
		}
	}

	lib_func_used_array.push_back(str);
	return i + 1;
}

unsigned userfuncs_newfunc(symTableEntry *sym)
{
	userFunciterator it;
	unsigned i = 0;

	/*Optimisation: Iterate the vector to see if the element already exists*/
	for (it = user_func_array.begin(); it != user_func_array.end(); it++, i++)
	{
		if ((*it).address == sym->address && (*it).local_size == sym->totallocals && (*it).id == sym->name)
		{
			return i;
		}
	}

	user_func_array_entry func_entry;
	func_entry.address = sym->address;
	func_entry.local_size = sym->totallocals;
	func_entry.id = sym->name;
	user_func_array.push_back(func_entry);

	return user_func_array.size() - 1;
}

void make_operand(expr *e, vmarg *arg)
{
	switch (e->type)
	{
	/*All those below use a variable for storage*/
	case var_e:
	case tableitem_e:
	case arithexpr_e:
	case boolexpr_e:
	case newtable_e:
	{

		arg->val = e->sym->offset;

		switch (e->sym->space)
		{
		case programvar:
			arg->type = global_a;
			break;
		case functionlocal:
			arg->type = local_a;
			break;
		case formalarg:
			arg->type = formal_a;
			break;
		default:
			assert(0);
		}
		break;
	}
	case assignexpr_e:
	{
		arg->type = assign_a;
		break;
	}
	case constbool_e:
	{
		arg->val = e->boolConst;
		arg->type = bool_a;
		break;
	}
	case conststring_e:
	{
		arg->val = consts_newstring(e->strConst);
		arg->type = string_a;
		break;
	}

	case constnum_e:
	{
		arg->val = consts_newnumber(e->numConst);
		arg->type = number_a;
		break;
	}

	case nil_e:
	{
		arg->type = nil_a;
		break;
	}

	/*Functions*/
	case programfunc_e:
	{
		arg->type = userfunc_a;
		arg->val = userfuncs_newfunc(e->sym);
		break;
	}

	case libraryfunc_e:
	{
		arg->type = libfunc_a;
		arg->val = libfuncs_newused(e->sym->name);
		break;
	}

	default:
		assert(0);
	}
}

void make_numberoperand(vmarg *arg, double val)
{
	arg->val = consts_newnumber(val);
	arg->type = number_a;
}

void make_booloperand(vmarg *arg, unsigned val)
{
	arg->val = val;
	arg->type = bool_a;
}

void make_retvaloperand(vmarg *arg)
{
	arg->type = retval_a;
	arg->val = 0;
}

void reset_operand(vmarg *arg)
{
	arg->val = 0;
	arg->type = invalid_a;
}

int iopcodeToVmopcode(iopcode op)
{

	assert(op <= 26); /*check out of bounds enum*/

	if (op == 6)
	{
		return 3;
	}
	else if (op == 7 || op == 8 || op == 9 || op == 18 || op == 19)
	{
		std::cout << "No translation for " << op;
		assert(0);
		return -1;
	}
	else
	{
		return (int)op;
	}
}

void add_incomplete_jump(unsigned instrNo, unsigned iaddress)
{
	incomplete_jump *ij = new incomplete_jump();
	ij->instrNo = instrNo;
	ij->iaddress = iaddress;

	inc_jump_list.push_back(*ij);
}

void patch_incomplete_jumps()
{
	jumpListIterator it_jumpList;

	for (it_jumpList = inc_jump_list.begin(); it_jumpList != inc_jump_list.end(); ++it_jumpList)
	{
		if (it_jumpList->iaddress == vctr_quads.size())
		{
			vctr_instr[it_jumpList->instrNo].vm_result.val = vctr_instr.size() - 1;
		}
		else
		{
			vctr_instr[it_jumpList->instrNo].vm_result.val = vctr_quads[it_jumpList->iaddress].taddress;
		}
	}
}

typedef void (*generator_func_t)(quad *);

generator_func_t generators[] = {
	generate_ASSIGN,
	generate_ADD,
	generate_SUB,
	generate_MUL,
	generate_DIV,
	generate_MOD,
	generate_UMINUS,
	generate_OR,
	generate_OR,
	generate_NOT,
	generate_IF_EQ,
	generate_IF_NOTEQ,
	generate_IF_LESSEQ,
	generate_IF_GREATEREQ,
	generate_IF_LESS,
	generate_IF_GREATER,
	generate_CALL,
	generate_PARAM,
	generate_RETURN,
	generate_GETRETVAL,
	generate_FUNCSTART,
	generate_FUNCEND,
	generate_NEWTABLE,
	generate_TABLEGETELEM,
	generate_TABLESETELEM,
	generate_JUMP,
	generate_NOP};

void generate(iopcode op, quad *q)
{
	q->taddress = next_instruction_label();
	instruction *newInst = new instruction();

	newInst->vm_op = (vmopcode)iopcodeToVmopcode(q->op);

	if (q->arg1 != NULL)
		make_operand(q->arg1, &(newInst->vm_arg1));
	if (q->arg2 != NULL)
		make_operand(q->arg2, &(newInst->vm_arg2));
	if (q->result != NULL)
		make_operand(q->result, &(newInst->vm_result));
	newInst->vm_srcLine = q->line;

	vctr_instr.push_back(*newInst);
}

void generate_relational(iopcode op, quad *q)
{
	q->taddress = next_instruction_label();
	instruction *newInst = new instruction();
	newInst->vm_op = (vmopcode)iopcodeToVmopcode(op);

	if (op != jump_iopcode)
	{
		make_operand(q->arg1, &(newInst->vm_arg1));
		make_operand(q->arg2, &(newInst->vm_arg2));
	}
	newInst->vm_result.type = label_a;

	if (q->label < currprocessedquad)
	{
		newInst->vm_result.val = vctr_quads[q->label].taddress;
	}
	else
	{
		add_incomplete_jump(next_instruction_label(), q->label);
	}

	q->taddress = next_instruction_label();
	newInst->vm_srcLine = q->line;
	vctr_instr.push_back(*newInst);
}

void generate_func(void)
{

	for (unsigned currprocessedquad = 0; currprocessedquad < vctr_quads.size(); ++currprocessedquad)
	{
		(*generators[vctr_quads[currprocessedquad].op])(&(vctr_quads[currprocessedquad]));
	}
}

void printArrays()
{
	constStringiterator it_String;
	unsigned i = 0;

	std::cout << "------------String const array------------" << std::endl;
	for (it_String = const_string_array.begin(); it_String != const_string_array.end(); it_String++, i++)
	{
		std::cout << i << ": " << *it_String << std::endl;
	}

	constDoubleiterator it_Double;
	i = 0;

	std::cout << "-------------Num const array--------------" << std::endl;
	for (it_Double = const_num_array.begin(); it_Double != const_num_array.end(); it_Double++, i++)
	{
		std::cout << i << ": " << *it_Double << std::endl;
	}

	libFunciterator it_libFunc;
	i = 0;

	std::cout << "-------------Lib func array--------------" << std::endl;
	for (it_libFunc = lib_func_used_array.begin(); it_libFunc != lib_func_used_array.end(); it_libFunc++, i++)
	{
		std::cout << i << ": " << *it_libFunc << std::endl;
	}

	userFunciterator it_userFunc;
	i = 0;

	std::cout << "-------------User func array--------------" << std::endl;
	for (it_userFunc = user_func_array.begin(); it_userFunc != user_func_array.end(); it_userFunc++, i++)
	{
		std::cout << i << ": " << it_userFunc->address << std::setw(6) << it_userFunc->local_size << std::setw(6) << it_userFunc->id << std::endl;
	}
}

void printInstructions()
{
	instrIterator it_Instr;
	unsigned i = 0;
	//       opcode            arg1              arg2              result     sourceline
	std::cout << "===================================Instructions===================================" << std::endl;
	std::cout << "       "
			  << "opcode            arg1              arg2              result     sourceline" << std::endl;
	for (it_Instr = vctr_instr.begin(); it_Instr != vctr_instr.end(); it_Instr++, i++)
	{
		std::cout << std::setw(4) << i << ": " << std::setw(9) << vmopcodeToString(it_Instr->vm_op) << " "; //print op
		outputBinary << std::setw(9) << vmopcodeToString(it_Instr->vm_op) << " ";
		outputText << std::setw(4) << i << ": " << std::setw(9) << vmopcodeToString(it_Instr->vm_op) << " ";

		printVmarg(it_Instr->vm_arg1);
		printVmarg(it_Instr->vm_arg2);
		printVmarg(it_Instr->vm_result);

		std::cout << "\tline: " << it_Instr->vm_srcLine << std::endl;
		// outputBinary<<"\tline: " <<it_Instr->vm_srcLine <<std::endl;
		// outputText<<"\tline: " <<it_Instr->vm_srcLine <<std::endl;
	}
}

void printVmarg(vmarg arg)
{
	if (arg.type != invalid_a)
	{
		if (arg.type != nil_a && arg.type != assign_a && arg.type != retval_a)
		{
			std::cout << std::setw(6) << arg.val << " ";
			// outputBinary<<std::setw(6) <<arg.val <<" ";
		}
		else
		{
			std::cout << std::setw(7) << " ";
		}
		std::cout << std::setw(10) << vmtypeToString(arg.type) << " ";
		// outputBinary<<std::setw(10) <<vmtypeToString(arg.type) <<" ";
	}
	else
	{
		std::cout << std::setw(18) << " ";
		// outputBinary<<std::setw(18) <<" ";
	}
}

std::string vmopcodeToString(vmopcode op)
{
	switch (op)
	{
	case assign_vmopcode:
		return "ASSIGN";
	case add_vmopcode:
		return "ADD";
	case sub_vmopcode:
		return "SUB";
	case mul_vmopcode:
		return "MUL";
	case div_vmopcode:
		return "DIV";
	case mod_vmopcode:
		return "MOD";
	case if_eq_vmopcode:
		return "EQ";
	case if_noteq_vmopcode:
		return "NEQ";
	case if_lesseq_vmopcode:
		return "LEQ";
	case if_greatereq_vmopcode:
		return "GEQ";
	case if_less_vmopcode:
		return "LESS";
	case if_greater_vmopcode:
		return "GRT";
	case call_vmopcode:
		return "CALL";
	case param_vmopcode:
		return "PARAM";
	case funcstart_vmopcode:
		return "FUNCSTART";
	case funcend_vmopcode:
		return "FUNCEND";
	case tablecreate_vmopcode:
		return "NEWTABLE";
	case tablegetelem_vmopcode:
		return "GETELEM";
	case tablesetelem_vmopcode:
		return "SETELEM";
	case jump_vmopcode:
		return "JUMP";
	default:
		return "NOP"; //nop_vmopcode
	}
}

std::string vmtypeToString(vmarg_t type)
{
	switch (type)
	{
	case assign_a:
		return "assign_a";
	case global_a:
		return "global_a";
	case local_a:
		return "local_a";
	case formal_a:
		return "formal_a";
	case bool_a:
		return "bool_a";
	case string_a:
		return "string_a";
	case number_a:
		return "number_a";
	case nil_a:
		return "nil_a";
	case userfunc_a:
		return "userfunc_a";
	case libfunc_a:
		return "libfunc_a";
	case label_a:
		return "label_a";
	case retval_a:
		return "retval_a";
	default:
		return "invalid";
	}
}

void printToFile(std::string filename)
{
	std::ofstream ofile;
	ofile.open(filename, std::ios::binary);

	ofile << MAGIC_NUMBER << std::endl;

	ofile << programVarOffset << std::endl;			  //number of program vars
	ofile << const_string_array.size() << std::endl;  //number of const stirngs
	ofile << const_num_array.size() << std::endl;	 //number of const nums
	ofile << lib_func_used_array.size() << std::endl; //number of funcdefs
	ofile << user_func_array.size() << std::endl;	 //number of lib calls
	ofile << vctr_instr.size() << std::endl;		  //number of instructions

	constStringiterator it_String;

	for (it_String = const_string_array.begin(); it_String != const_string_array.end(); it_String++)
	{
		ofile << *it_String << std::endl;
	}

	constDoubleiterator it_Double;

	for (it_Double = const_num_array.begin(); it_Double != const_num_array.end(); it_Double++)
	{
		ofile << *it_Double << std::endl;
	}

	libFunciterator it_libFunc;

	for (it_libFunc = lib_func_used_array.begin(); it_libFunc != lib_func_used_array.end(); it_libFunc++)
	{
		ofile << *it_libFunc << std::endl;
	}

	userFunciterator it_userFunc;

	for (it_userFunc = user_func_array.begin(); it_userFunc != user_func_array.end(); it_userFunc++)
	{
		ofile << it_userFunc->address << std::endl;
		ofile << it_userFunc->local_size << std::endl;
		ofile << it_userFunc->id << std::endl;
	}

	instrIterator it_Instr;

	for (it_Instr = vctr_instr.begin(); it_Instr != vctr_instr.end(); it_Instr++)
	{
		// opdcode
		ofile << it_Instr->vm_op << std::endl;

		// arg1
		ofile << it_Instr->vm_arg1.type << std::endl;
		ofile << it_Instr->vm_arg1.val << std::endl;

		// arg2
		ofile << it_Instr->vm_arg2.type << std::endl;
		ofile << it_Instr->vm_arg2.val << std::endl;

		// result
		ofile << it_Instr->vm_result.type << std::endl;
		ofile << it_Instr->vm_result.val << std::endl;

		// line
		ofile << it_Instr->vm_srcLine << std::endl;
	}

	ofile.close();
}
