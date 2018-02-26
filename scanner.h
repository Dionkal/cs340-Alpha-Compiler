typedef struct alpha_token_t alpha_token_t;

 struct  alpha_token_t{
	int token_no;
	int line_no;
	char* token_type; 
	char* token_value;
	alpha_token_t * next;
};