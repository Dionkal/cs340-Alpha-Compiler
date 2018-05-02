#ifndef SYMTABLE_LIB
	#define SYMTABLE_LIB
	#include "symtable.h"
#endif

std::string newtempname();

symTableEntry* newtemp();

void resettemp();

/*Returns the corresponding scopespace type*/
scopespace_t current_scopescape();

typedef struct offset{
	unsigned int functionLocalOffset;
	unsigned int formalArgOffset;
}offset;

/*Creates a new offset entry in the stack for formal and local vars
 and initializes them with 0*/
void newOffset();

/*Deletes one offset entry*/
void deleteOffset();

/*Returns the corresponding offset depending on the current scopespace*/
unsigned int currScopeOffset();

/*Increments the corresponding offset depending on the current scope*/
void incrementScopeOffset();

/*Get the offset of the current function depending
on user input, odds for function local offset
even for function formal offset*/
unsigned getFunctionOffset(unsigned mode);