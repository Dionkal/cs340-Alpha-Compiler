#include "toString.h"

std::string number_tostring(avm_memcell* m){
	assert(m->type == number_m); // type check
	return std::to_string(m->data.numVal);
}

std::string string_tostring(avm_memcell* m){
	assert(m->type == string_m); //type check
	return std::string(m->data.strVal);
}

std::string bool_tostring(avm_memcell* m){
	assert(m->type == bool_m); //type check
	return (m->data.boolVal)? "true" : "false";
}

typedef std::map<std::string,avm_memcell>::iterator strIndexedIterator;
typedef std::map<double,avm_memcell>::iterator  	numIndexedIterator;

std::string table_tostring(avm_memcell* m){
	assert(m->type == table_m); //type check
	std::string buffer;
	buffer = "[ ";
	/*iterate string hash*/
	strIndexedIterator strIndexed_it;
	for(strIndexed_it = m->data.tableVal->strIndexed.begin(); strIndexed_it != m->data.tableVal->strIndexed.end(); ++strIndexed_it){
		buffer +="{ ";
		buffer += strIndexed_it->first;
		buffer +=" : ";
		buffer += avm_tostring(&strIndexed_it->second);
		buffer +=" }";
	}

	/*iterate double hash*/
	numIndexedIterator numIndexed_it;
	for(numIndexed_it = m->data.tableVal->numIndexed.begin(); numIndexed_it != m->data.tableVal->numIndexed.end(); ++numIndexed_it){

		buffer +="{ ";
		buffer += std::to_string(numIndexed_it->first);
		buffer +=" : ";
		buffer += avm_tostring(&numIndexed_it->second);
		buffer +=" }";

	}
	buffer +=" ]";

	return buffer;
}

std::string userfunc_tostring(avm_memcell* m){
	assert(m->type == userfunc_m); //type check
	return std::to_string(m->data.funcVal);
}

std::string libfunc_tostring(avm_memcell* m){
	assert(m->type == libfunc_m); //type check
	return std::string(m->data.libfuncVal);
}

std::string nil_tostring(avm_memcell* m){
	assert(m->type == nil_m); //type check
	return "nil";	
}

std::string undef_tostring(avm_memcell* m){
	assert(m->type == undef_m); //type check
	return "undefined";
}

typedef std::string (*tostring_func_t) (avm_memcell*);

tostring_func_t tostringFuncs[]={
	number_tostring,
	string_tostring,
	bool_tostring,
	table_tostring,
	userfunc_tostring,
	libfunc_tostring,
	nil_tostring,
	undef_tostring
};

std::string avm_tostring(avm_memcell* m){
	assert(m->type >= 0 && m->type <= undef_m);
	return (*tostringFuncs[m->type]) (m);
}