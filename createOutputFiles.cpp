#inlude <iostream>
#inlude <fstream>

avmbinaryfile:	magicnumber arrays code 					{/*TODO generate 2 files:binary and text*/
																fstream outputBinary,outputText;

																outputBinary.open("output.abc", ios::binary);
																if(outputBinary.is_open()){
																	outputBinary<</*binary code load our staff*/;
																}
																outputBinary.close();

																outputText.open("output.txt");
																if(outputText.is_open()){
																	outputText<</*plain text code load our staff*/;
																}
																outputText.close();

															}

magicnumber: 	34020051 /*should be unsigned*/

arrays:			strings numbers userfunctions libfunctions 	{}

strings:		total (string)* /*oeo*/						{}

total:			unsigned									{}

string:			size (char)*/*null terminated*/				{}

size:			unsigned									{}

numbers:		total (double*)								{}

userfunctions:	total (userfunc*)							{}

userfunc: 		address localsize id						{}

address:		unsigned									{}

localsize:		unsigned									{}

id:				string 										{}

libfunctions:	strings										{}

code:			total(instruction)*							{}

instruction:	opcode operand operand operand				{}

opcode:			byte 										{}

operand: 		type value 									{}

type:			byte 										{}

value:			unsigned									{}

