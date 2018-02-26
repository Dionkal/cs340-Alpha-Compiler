#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>


using namespace std;

typedef struct alpha_token_t alpha_token_t;

 struct  alpha_token_t{
	int number_of_token;
	int line_number;
	void* token_type; 
	string token_value;
};

void addToken(void* token_t, string value);