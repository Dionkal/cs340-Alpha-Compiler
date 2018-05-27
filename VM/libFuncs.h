#include<iostream>

/*Info apo to FAQ*/

void print(/*opoiodipote arithmo parametron*/);

void libfunc_typeof(void);

typedef union inputRet{
	unsigned 	number_ret;
	bool		bool_ret
	unsigned 	nil_ret;
	char *		string_ret;
}inputRet;
inputRet input(/*diavazei apo prokathorismeni eisodo*/);

/*void gia na kanei compile alla thelei int-indeexed array*/
void objectmemberkeys(/*pinakas*/);

/*Returns the number of table members*/
unsigned objecttotalmebers(/*pinakas*/);

/*Makes shalow copy of table and returns it*/
void /*void tha ginei pinakas stin ilopoohsh*/objectcopy(/*pinakas*/);

/*Return the number of arguments that are given to function. 
If space of function is global, returns nil(0)*/
unsigned totalarguments(/*sinartisi*/);

/*Return the i-th arg of curFunc. If curFunc is in global scope, return nil(0)*/
void /*i-osti arg tis currFunc*/argument(int i);

typedef union typeofRet{
	bool 		bool_ret;
	unsigned	number_ret;
	unsigned	nil_ret;
	char *		string_ret;
	void		userFunc;/*void gt den einmai na skfto ti tipo thelei*/
	void		libFunc;/*void gt den einmai na skfto ti tipo thelei*/
	void		table;/*void gt den einmai na skfto ti tipo thelei*/
}typeofRet;

//DAMN, I juse realised oti ginontai esoterika auta p epistrfontai k den thelo eidkes domes
//nevermind den to svino akoma :P
void typeof(void);


//aurio oi parakato
void strtonum(void);

void sqrt(void);

void cos(void);

void sin(void);



