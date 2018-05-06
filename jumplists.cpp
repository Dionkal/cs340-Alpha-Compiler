#include "jumplists.h"
#include <stack>
#include <vector>

/*Jump*/
std::stack<jumplistEntry*> jumpListStack;

extern std::vector  <quad> vctr_quads; 

void newlistEntry(){
	jumplistEntry *temp = new jumplistEntry;
	temp->breakList  	= new std::list <unsigned>;
	temp->continueList   = new std::list <unsigned>;

	jumpListStack.push(temp);
}


/*patch all the jumps indexed by the given list with the given label*/
void patchList(std::list<unsigned> List, unsigned label){
	while(!List.empty()){
		(vctr_quads[List.front()]).label = label;
		List.pop_front();
	}
}