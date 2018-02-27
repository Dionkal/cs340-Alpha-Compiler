#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>



using namespace std;

//typedef enum{KEYWORD,OPERATOR,PUNCTUATION,STRING,INTEGER} type;
/*typedef enum {IF, ELSE, WHILE, FOR, FUNCTION, RETURN, BREAK, CONTINUE, AND, NOT, OR, LOCAL, TRUE, FALSE, NIL} keyword_enum; 
typedef enum {ASSIGNMENT, PLUS, MINUS, PRODUCT, DIVIDE, PERCENT, EQUALS, NOT_OP, D_PLUS, D_MINUS, GREATER, LESS, G_EQUAL, L_EQUAL} operators_enum;*/


typedef struct alpha_token_t{
	int number_of_token;
	int line_number;

	string str_type;	
	string token_value;
	
	//Constructor specifies the token type
	// alpha_token_t(type t): token_type(t){}
}alpha_token_t;

void* addToken(string token_t, string value, int line);