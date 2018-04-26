#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <sstream> 
#include <fstream>
#include <map>

using namespace std;

typedef enum{KEYWORD,IDENTIFIER,INT_CONST,REAL_CONST,STRING_TYPE,OPERATOR,PUNCTUATION,COMMENT} type;

typedef struct{
	int number_of_token;
	int line_number;
	type token_type; 
	string str_subType;
	string token_value;
	string arrow_type;

}alpha_token_t;

/*Adds the given token to the global vector*/
void addToken(type token_t,string token_sT, string value, int line);


/*code for strings*/
void stringAction();