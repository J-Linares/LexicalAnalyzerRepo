#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//pre processor directives necessary for file manipulation
//since using namespace is not portable code we will be forced to 
//to include std:: before every type of output manipulation
//
int main(){
	//include means of both reading and writing to a file 
	//then include a file
	std::cout << "What file would you wish to process in this current Directory\n" << std::endl;
	
	std::string filename; 
	std::cin >> filename;
	//create the data containers that
	//will house the items that we findthrough the lexical analyzer
	std::vector<std::string> arrayTokens;
        // this array of tokens 	
	
	std::string processLine; //l;ine that will be used to process
				// tokens found in the text file
	std::fstream inputFile(filename); 
	// this should take in a file that the user should specify
	//we now have the file accessed and open,it is here where we 
	//need to begin processing the file to do what wer want
	// as a lexical analyzer
	// make sure to close the file when finished processing
	
	//read in the file and find a wya to process the contents
	// and seperate them
	
	while(InputFile != NULL){
		//while input file is taking in some form of inpuit
		//we will need t process teh data within the text file
		std::getline(processLine, inputFile);
	
	}
	
}

