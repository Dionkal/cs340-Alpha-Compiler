#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct alpha_token_t{
	int number_of_token;
	int line_number;
	string str_type;	
	string token_value;
}alpha_token_t;

void* addToken(string token_t, string value, int line);