  
"/*"						
{ 	int com_v [100];
	int sum=1;
	int even=2;
	com_v[0]=yylineno;
	int odd=1;
	
	
	while((c=input()) != EOF))
	{
		if(c == "*")
		{
			if((c=input()) == "/")
			{
				sum --;
				com_v[odd]=yylineno;
				odd=odd+2;
			}
			else
				unput(c);
		}
		
		if(c == "/")
		{
			if((c=input()) == "*")
			{
				sum ++;
				com_v[even]=yylineno;
				even=even+2;
			}
			else
				unput(c);
		}
		
	}
	if(sum!=0) printf("Error in coments.\n");
	else
	{
		int i=0;
		int j=sizeof(com_v);
		
		while(i<sizeof(com_v) && j>0)
		{
			string s1="Multiline Comment from line ",com_v[i]," to line ",com_v[j]," ";
			void addToken(type token_t,string token_sT, string value, int line);
		}
	}

}
