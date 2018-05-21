

/*TODO generate 2 files:binary and text*/
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