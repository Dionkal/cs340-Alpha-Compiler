#include "avm_table.h"

/*Temp definition
*/
void avm_memcellclear(avm_memcell* m){}


avm_table *avm_tablenew(void){
	avm_table * t = new avm_table();

	t-> refCounter = t->total = 0;
	return t;
}

void avm_tableincrefcounter(avm_table* t){
	++t->refCounter;
}

/*Automatic garbage collection for tables when reference counter get zero*/
void avm_tabledecrefcounter(avm_table* t){
	assert(t->refCounter > 0);
	if(!(--t->refCounter)){
		avm_tabledestroy(t);
	}
}


void avm_tabledestroy(avm_table* t){
	/*Clear str indexed*/
	strIndexedIterator strIndexed_it;
	for(strIndexed_it = t->strIndexed.begin(); strIndexed_it != t->strIndexed.end(); ++strIndexed_it){
		avm_memcellclear(&strIndexed_it->second);
	}

	numIndexedIterator numIndexed_it;
	/*Clear num indexed*/
	for(numIndexed_it = t->numIndexed.begin(); numIndexed_it != t->numIndexed.end(); ++numIndexed_it){
		avm_memcellclear(&numIndexed_it->second);
	}

	t->strIndexed.clear();
	t->numIndexed.clear();
	delete(t);
}

/*TODO check proper string copy of data field because instead of strings we have char* */
avm_memcell avm_tablegetelem(avm_table* table, avm_memcell* key){
	numIndexedIterator numIndexed_it;
	strIndexedIterator strIndexed_it;
	/*Get the correct hash table depending on the type of the given key*/
	switch(key->type){
		case number_m:
			numIndexed_it = table->numIndexed.find(key->data.numVal);
			return numIndexed_it->second;
		case string_m:
			strIndexed_it = table->strIndexed.find(key->data.strVal);
			return strIndexed_it->second;
		default:
			assert(0);
	}
}


void avm_tablesetelem(avm_table* table, avm_memcell* key, avm_memcell* val){
	std::pair<numIndexedEntry::iterator,bool> retInt;
	std::pair<strIndexedEntry::iterator,bool> retStr;
	/*Get the correct hash table depending on the type of the given key*/
	switch(key->type){
		case number_m:
			retInt = table->numIndexed.insert(std::pair<double,avm_memcell> (key->data.numVal,*val));
			//entry already exists
			if(retInt.second == false){ 
				(retInt.first)->second.data.numVal = val->data.numVal;
			}else{
				table->total++;
			}
			return;
		case string_m:
			retStr = table->strIndexed.insert(std::pair<std::string,avm_memcell> (key->data.strVal,*val));
			//entry already exists
			if(retStr.second == false){ 
				(retStr.first)->second.data.strVal = val->data.strVal;
			}else{
				table->total++;
			}
			return;
		default:
			assert(0);
	}
}