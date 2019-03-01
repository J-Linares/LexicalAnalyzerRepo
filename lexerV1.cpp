#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <ctype.h>
//pre processor directives necessary for file manipulation
//since using namespace is not portable code we will be forced to 
//to include std:: before every type of output manipulation
using namespace std;
struct Tokens{
	//attributes to describe each tiken we will be taking in
	string nameOfToken;
	string typeName;
}

void splitString(vector<string> vectorInfo){
	//will not return anything because we will only be manipulating items within a vector
	
}

int main(){
	//include means of both reading and writing to a file 
	//then include a file
	cout << "What file would you wish to process in this current Directory\n" << endl;
	
	vector<Tokens> VectorOfTokens;
	vector<string> TempVector;
		
	cout << "Specify the file you wish to manipulate: "
	string filename; 
	cin >> filename;

	string commentTrash; // we will ignore comments in the lexical analysis

	//create the data containers that
	//will house the items that we findthrough the lexical analyzer
        // this array of tokens 	
       		            // line that will be used to process
		            // tokens found in the text file
	fstream inputFile(filename); 
	// this should take in a file that the user should specify
	//we now have the file accessed and open,it is here where we 
	//need to begin processing the file to do what wer want
	// as a lexical analyzer
	// make sure to close the file when finished processing

	//read in the file and find a wya to process the contents
	// and seperate them
	
	while(inputFile != NULL){
		//while input file is taking in some form of inpuit
		//we will need t process teh data within the text file
		if(inputFile.peek('!')){
			//this should remove any line that uses! at the beginning,
			//it is a comment operator/indicator
			getline(inputFile,commentTrash);
		}
		

	
	}
	
}

