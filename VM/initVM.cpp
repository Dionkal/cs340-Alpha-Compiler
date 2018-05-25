#include <iostream>
#include <sstream>
#include "initVM.h"

std::vector<instruction> vctr_instr;
/*Const values Data storage*/
std::vector <std::string> 				const_string_array;
std::vector <double> 					const_num_array;
std::vector <std::string> 				lib_func_used_array;
std::vector <user_func_array_entry>		user_func_array;


void readFile(std::string filename){
	std::ifstream infile(filename);
	// All the different input types
	int 			const_string_size,const_num_size,user_func_size,lib_func_size,instr_size;
	double 			input_double;
	std::string 	input_string_line;

	std::ifstream input( filename);


	std::string::size_type sz;
	std::string line;
	std::getline(input,line);

	if(std::stoi (line,&sz) != MAGIC_NUMBER ){ 
		std::cout << "Incorrect input file type";
		// infile.close();
		exit(-1);
	}

	/*Get all the array sizes*/
	std::getline(input,line);
	const_string_size 	= std::stoi (line,&sz);
	std::getline(input,line);
	const_num_size 		= std::stoi (line,&sz);
	std::getline(input,line);
	lib_func_size 		= std::stoi (line,&sz);
	std::getline(input,line);
	user_func_size 		= std::stoi (line,&sz);
	std::getline(input,line);
	instr_size 			= std::stoi (line,&sz);
	

	
	/*Fill const_string array*/
	for(int i = 0; i< const_string_size; i++){
		std::getline(input,line);
		const_string_array.push_back(line);
	}

	/*Fill const num array*/
	for(int i = 0; i< const_num_size; i++){
		std::getline(input,line);
		std::string::size_type sz;     
		const_num_array.push_back(std::stod (line,&sz));
	}	
	
	/*Fill lib_func array*/
	for(int i = 0; i < lib_func_size; i++){
		std::getline(input,line);
		lib_func_used_array.push_back(line);
	}

	std::cout <<"TEST" <<std::endl;
}