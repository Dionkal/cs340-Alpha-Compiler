#include <string>
#define AVM_TABLE_HASHTABLE 211
#define AVM_STACKSIZE 4096
#define AVM_WIPEOUT(m) memset(&(m),0,sizeof(m))//why ont call realloc

typedef enum avm_memcell_t{
	number_m	=0,
	string_m	=1,
	bool_m		=2,
	table_m		=3,
	userfunc_m	=4,
	libfunc_m	=5,
	nil_m		=6,
	undef_m		=7
}avm_memcell_t;//auto pou used oeo

typedef struct avm_table_bucket{
	avm_memcell key;
	avm_memcell value;
	avm_table_bucket* next;
}avm_table_bucket;

/*numeric, and string keys but also the bonus: user functions, 
lib functions and booleans*/
typedef struct avm_table{
	unsigned refCounter;
	avm_table_bucket* strIntexed[AVM_TABLE_HASHTABLE];
	avm_table_bucket* numIntexed[AVM_TABLE_HASHTABLE];
	avm_table_bucket* userFunc[AVM_TABLE_HASHTABLE];//CHECK THIS NOT SURE
	avm_table_bucket* libFunc[AVM_TABLE_HASHTABLE];
	avm_table_bucket* boolIntexed[AVM_TABLE_HASHTABLE];
	unsigned total;
}avm_table;

typedef struct avm_memcell{
	avm_memcell_t	type;
	typedef union data{
		double			numVal;
		std::string 	strVal;
		unsigned char	boolChar;
		avm_table *		tableVar;
		unsigned		funcVal;
		std::string 	libfuncVal;
	}data;
}avm_memcell;

avm_memcell stack[AVM_STACKSIZE]; 

static void avm_initstack(void);

avm_table *avm_tablenew(void);

void avm_tabledestroy(avm_table* t);

avm_memcell *avm_tablegetelem(avm_memcell *key);

void avm_tablesetelem(avm_memcell *key,avm_memcell *value);

void avm_tableincrefcounter(avm_table* t);

void avm_tabledecrefcounter(avm_table* t);

void avm_tablebucketsinit(avm_table_bucket** p);

void avm_memcellclear(avm_memcell* m);

void avm_tablebucketsdestroy(avm_table_bucket** p);


