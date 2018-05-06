#ifndef JUMP_LIST_LIB
	#define JUMP_LIST_LIB
	#include "quad.h"
	#include <list>
typedef struct jumplistEntry{
	std::list<unsigned>* breakList;
	std::list<unsigned>* continueList;
}jumplistEntry;


void newlistEntry();

/*patch all the jumps indexed by the given list with the given label*/
void patchList(std::list<unsigned> List, unsigned label);

#endif