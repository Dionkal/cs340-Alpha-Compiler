#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>


using namespace std;

typedef enum {IF,ELSE,WHILE,ASSIGNMENT} token_type_enum ;

typedef union {
	token_type_enum enumerator_t;
	char* char_t;
}token_type_union;

typedef struct{
	int number_of_token;
	int line_number;
	token_type_union token_type; 
	string token_value;
}alpha_token_t;

void addToken(token_type_union token_t, string value);