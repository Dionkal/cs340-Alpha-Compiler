#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <sstream> 
#include <fstream>

using namespace std;

typedef enum{KEYWORD,IDENTIFIER,INT_CONST,REAL_CONST,STRING,OPERATOR,PUNCTUATION,COMMENT} type;

typedef struct{
	int number_of_token;
	int line_number;
	type token_type; 
	string str_subType;
	string token_value;
	string arrow_type;

}alpha_token_t;

void addToken(type token_t,string token_sT, string value, int line);
