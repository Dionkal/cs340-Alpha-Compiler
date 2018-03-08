"/*"	{
			int c;
			int start_line;
			std :: vector <int> v;

			v.push_back (yylineno);
	
			while((c=input()) != EOF))
			{
				if(c == '*')
				{
					if((c = input()) == '/')
					{
						if(!v.empty())
						{
							start_line=v.back();
							v.pop_back();
					
							std::cout << "Comment opens at line "start_line" and closes at line "yylineno'\n';
						}
						else break;
					}	
					else unput(c);
				}
		
		
				if(c == '/')
				{
					if((c = input()) == '*')
					v.push_back(yylineno);
					
					else
					unput(c);
				}
			}
		}