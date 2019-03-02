#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <ctype.h>
//pre processor directives necessary for file manipulation
//since using namespace is not portable code we will be forced to
//to include std:: before every type of output manipulation
using namespace std;

struct Tokens
{
    //attributes to describe each tiken we will be taking in
    string nameOfToken;
    string typeName;
};

int main()
{
    //include means of both reading and writing to a file
    //then include a file
    cout << "What file would you wish to process in this current Directory\n" << endl;

    vector<Tokens> VectorOfTokens;	//as we store them, we will classify them
    //with their respective token/lexeme
    vector<char> TempVector;	//will  house split items for the vector
    vector<string> GlobalStorage;	//stores all strings for manipulation
    //temporary vectors will be used to split items apart  from the global
    // storage, at the end , the vector of tokens will house all split items
    // and their definitions
    cout << "Specify the file you wish to manipulate: ";

    string filename;
    cin >> filename;

    ifstream inputFile(filename);

    string commentTrash; // we will ignore comments in the lexical analysis
    string codeEntry;
    //create the data containers that
    //will house the items that we findthrough the lexical analyzer
    // this array of tokens
    // line that will be used to process
    // tokens found in the text file
    inputFile.open(filename.c_str());
        if(inputFile.is_open())
        {
            cout << "we have located the File: " << filename << endl;
        }
    // this should take in a file that the user should specify
    //we now have the file accessed and open,it is here where we
    //need to begin processing the file to do what wer want
    // as a lexical analyzer
    // make sure to close the file when finished processing

    //read in the file and find a wya to process the contents
    // and seperate them

    while(inputFile >> codeEntry)
    {
        //while input file is taking in some form of inpuit
        //we will need t process teh data within the text file
        if(inputFile.peek() == '!')
        {
            //this should remove any line that uses! at the beginning,
            //it is a comment operator/indicator
            getline(inputFile,commentTrash);
            cout <<"we are skipping a comment line " << commentTrash << endl;
        }
        //take the data into the data containers we will use for manipulation
        GlobalStorage.push_back(codeEntry);

    }

    inputFile.close();

    for(int idx = 0; idx < GlobalStorage.size(); idx++)
    {
        //we begin splitting strings right here
        string currentLexeme =	GlobalStorage[idx];
        char lexemeArray[1024];
        strncpy(lexemeArray, currentLexeme.c_str(), sizeof(lexemeArray));
        lexemeArray[sizeof(lexemeArray) - 1] = 0;

        //a respective lexeme should now be held inside this vector of chars
        //ex:  n, u , m , 1 , ","

        //use a for loop to pass array contents into the TempVector
        for(int arrIdx = 0; arrIdx < sizeof(lexemeArray); arrIdx++){
            TempVector.push_back(lexemeArray[arrIdx]);
        }

        vector<char> word;
        for(int charIdx = 0; charIdx < TempVector.size(); charIdx++)
        {
            //if the next item in the vector turns out not to be
            //human language char then, we will take all previous items and convert
            //them to a singular string , andpush it onto the vector, after that
            //we will push that singular object as a singular respective token
            //into the vector

            if(isalnum(TempVector[charIdx]) == false)
            {

                if(TempVector[charIdx] == '$')
                {
                    word.push_back(TempVector[charIdx]);
                }
              //  VectorOfTokens.push_back(TempVector[charIdx]);
            }
            word.push_back(TempVector[charIdx]);
        }
     //   VectorofTokens.push_back(word);
        word.clear();
    }

}


