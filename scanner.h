#include <string>
#include <vector>

typedef struct alpha_token_t alpha_token_t;

 struct  alpha_token_t{
	int token_no;
	int line_no;
	void* token_type; 
	String token_value;
};

int addToken(char* value, int value_lenght, char* type);