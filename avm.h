

typedef enum avm_memcell_t{
	number_m	=0,
	string_m	=1,
	bool_m		=2,
	table_m		=3,
	userfunc_m	=4,
	libfunc_m	=5,
	nil_m		=6,
	undef_m		=7
}avm_memcell_t;

//#define AVM_STACKSIZE 4096
//#define AVM_WIPEOUT(m) memset(&(m),0,sizeof(m))
//struct amv_table; TINEAFTORE
//ti domi tha xrisimopoihsoume gia tin stoiva

struct amv_memcell{
	avm_memcell_t	type;
	typedef union data{
		double			numVal;
		std::string 	strVal;
		unsigned char	boolChar;
		avm_table *		tableVar;//depending on how we implement it
		unsigned		funcVal;
		std::string 	libfuncVal;
	}data;
}

avm_memcell stack[AVM_STACKSIZE];
static void avm_initstack(void){
	unsigned i;
	for(i=0; i<AVM_STACKSIZE; ++i){
		AVM_WIPEOUT(stack[i]);
		stack[i].type=undef_m;
	}
}