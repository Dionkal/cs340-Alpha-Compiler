#include "avm.h"
#include <fstream>
#include <cstring>
#include <cstdarg>

/*Size of the global space*/
extern unsigned globalSize;
extern std::vector<instruction> vctr_instr;

/*Const values Data storage*/
extern std::vector<std::string> const_string_array;
extern std::vector<double> const_num_array;
extern std::vector<std::string> lib_func_used_array;
extern std::vector<user_func_array_entry> user_func_array;

extern void avm_tabledecrefcounter(avm_table *t);

extern std::vector<instruction> vctr_instr;

bool executionFinished = false;
unsigned pc = 0;
unsigned currLine = 0;
unsigned codeSize = 0;
instruction *code = NULL;

#define AVM_ENDING_PC codeSize

/*AVM registers*/
avm_memcell ax, bx, cx, retval;

/*Stack pointers*/
unsigned top, topsp;

/*GLOBAL STATIC STACK*/
avm_memcell stack[AVM_STACKSIZE];

/*Types to strings*/
std::string typeStrings[] = {
	"number_m",
	"string_m",
	"bool_m",
	"table_m",
	"userfunc_m",
	"libfunc_m",
	"nil_m",
	"undef_m"};

std::map<std::string, library_func_t> libFuncHash;

double consts_getnumber(unsigned index) { return const_num_array[index]; }
char *consts_getstring(unsigned index) { return (char *)(const_string_array[index]).c_str(); }
char *libfuncs_getused(unsigned index) { return (char *)(lib_func_used_array[index]).c_str(); }
unsigned userfunc_getaddr(unsigned index) { return user_func_array[index].address; }

void loadLibFuncs()
{
	avm_registerlibfunc("print", libfunc_print);
	// TODO: Register more lib funcs
}

avm_memcell *avm_translate_operand(vmarg *arg, avm_memcell *reg)
{
	switch (arg->type)
	{

	/*Variables*/
	case global_a:
		return &stack[AVM_STACKSIZE - 1 - arg->val];
	case local_a:
		return &stack[topsp - arg->val];
	case formal_a:
		return &stack[topsp + AVM_STACKENV_SIZE + 1 + arg->val];
	case retval_a:
		return &retval;

	/*Constants*/
	case number_a:
	{
		reg->type = number_m;
		reg->data.numVal = consts_getnumber(arg->val);
		return reg;
	}
	case string_a:
	{
		reg->type = string_m;
		reg->data.strVal = strdup(consts_getstring(arg->val));
		return reg;
		/*TODO check were strings are deleted and free the pointer
			in order to avoid memory leaks*/
	}

	case bool_a:
	{
		reg->type = bool_m;
		reg->data.boolVal = (arg->val) ? true : false;
		return reg;
	}

	case nil_a:
	{
		reg->type = nil_m;
		return reg;
	}

	/*Functions*/
	case userfunc_a:
	{
		reg->type = userfunc_m;
		reg->data.funcVal = userfunc_getaddr(arg->val);
		return reg;
	}

	case libfunc_a:
	{
		reg->type = libfunc_m;
		reg->data.libfuncVal = strdup(libfuncs_getused(arg->val));
		/*TODO check were strings are deleted and free the pointer
			in order to avoid memory leaks*/
		return reg;
	}

	default:
		assert(0); //error no known type
	}
}

static void avm_initstack(void)
{
	unsigned i;
	for (i = 0; i < AVM_STACKSIZE; ++i)
	{
		stack[i].type = undef_m;
	}
}

memclear_func_t memclearFuncs[] = {
	0, /*number*/
	memclear_string,
	0, /*bool*/
	memclear_table,
	0, /*user func*/
	0, /*libfunc*/
	0, /*nil*/
	0  /*undef*/
};

void avm_memcellclear(avm_memcell *m)
{
	memclear_func_t f;

	if (m->type != undef_m)
	{
		f = memclearFuncs[m->type];
		if (f)
		{
			(*f)(m);
		}
		m->type = undef_m;
	}
}

void memclear_string(avm_memcell *m)
{
	assert(m->data.strVal);
	delete (m->data.strVal);
}

void memclear_table(avm_memcell *m)
{
	assert(m->data.tableVal);
	avm_tabledecrefcounter(m->data.tableVal);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "No input file, exiting";
		return 0;
	}
	readFile(std::string(argv[1]));
	avm_initstack();
	loadLibFuncs();

	top = topsp = AVM_STACKSIZE - vctr_instr.size();

	while (!executionFinished)
		execute_cycle();

	return 0;
}

void avm_warning(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	fprintf(stderr, "Error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");

	va_end(args);
}

void avm_error(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	fprintf(stderr, "Error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");

	va_end(args);
	executionFinished = true; //stop execution
}

execute_func_t executeFuncs[] = {
	execute_assign,
	execute_add,
	execute_sub,
	execute_mul,
	execute_div,
	execute_mod,
	execute_nop, // uminus
	execute_nop, // and
	execute_nop, // or
	execute_nop, // not
	execute_jeq,
	execute_jne,
	execute_jle,
	execute_jge,
	execute_jlt,
	execute_jgt,
	execute_call,
	execute_pusharg,
	execute_nop, // return
	execute_nop, // get return value
	execute_funcenter,
	execute_funcexit,
	execute_newtable,
	execute_tablegetelem,
	execute_tablesetelem,
	execute_jump, //jump
	execute_nop};

void execute_cycle()
{
	if (executionFinished)
		return;

	if (pc == AVM_ENDING_PC)
	{
		executionFinished = 1;
		return;
	}
	else
	{
		assert(pc < AVM_ENDING_PC);
		instruction *instr = &vctr_instr[pc]; //get the next isntruction to execute
		assert(instr->vm_op >= 0 && instr->vm_op <= AVM_MAX_INSTRUCTIONS);

		/*Optimization: change the currline only if the
		source line has changed from previous instruction*/
		if (instr->vm_srcLine)
		{
			currLine = instr->vm_srcLine;
		}

		unsigned oldPC = pc;
		(*executeFuncs[instr->vm_op])(instr);

		if (pc == oldPC)
			++pc; //execute next instr
	}
}
