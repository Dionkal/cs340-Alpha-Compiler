#ifndef JUMP_LIST_LIB
	#define JUMP_LIST_LIB
	#include "quad.h"
	#include <list>
typedef struct jumplistEntry{
	std::list<unsigned>* breakList;
	std::list<unsigned>* continueList;
}jumplistEntry;


typedef std::list <unsigned> returnList;

/*Creates a new jumplistEntry*/
void newlistEntry();

void newReturnListEntry();

/*patch all the jumps indexed by the given list with the given label*/
void patchList(std::list<unsigned> List, unsigned label);

void debbug_printList(std::list<unsigned> mylist);
#endif