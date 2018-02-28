
  std::vector<int> com_v (10);   // 10 zero-initialized elements

  
  std::vector<int>::size_type sz = com_v.size();
"/*"						
{ 	int sum=1;
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
		int j=com_v.size();
		
		while(i<com_v.size() && j>0)
		{
			string s1="Multiline Comment from line ",com_v[i]," to line ",com_v[j],";
			void addToken(type token_t,string token_sT, string value, int line);
		}
	}

}
