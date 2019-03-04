#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <ctype.h>
#include <numeric>
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
    vector<string> wordStorage;
    //temporary vectors will be used to split items apart  from the global
    // storage, at the end , the vector of tokens will house all split items
    // and their definitions
    // cout << "Specify the file you wish to manipulate: ";

    //string filename;
    //cin >> filename;

    ifstream inputFile;

    string commentTrash; // we will ignore comments in the lexical analysis
    string codeEntry;
    //create the data containers that
    //will house the items that we findthrough the lexical analyzer
    // this array of tokens
    // line that will be used to process
    // tokens found in the text file

    //NOTE: on my raspberry pi, my computer would not specify the local directory for
    //the file location, i recommend you specify the file name or the directory to ensure that the correct file is being read in
    //
    inputFile.open("/home/pi/Desktop/CompilersProjects/CompilerClassProject/input2.txt",ios::in);
    if(inputFile.is_open())
    {
        //   cout << "we have located the File: " << filename << endl;
    }
    // this should take in a file that the user should specify
    //we now have the file accessed and open,it is here where we
    //need to begin processing the file to do what wer want
    // as a lexical analyzer
    // make sure to close the file when finished processing

    //read in the file and find a wya to process the contents
    // and seperate them

    while(!inputFile.eof())
    {
        //while input file is taking in some form of inpuit
        //we will need t process teh data within the text file
        inputFile >> codeEntry;
        //cout << codeEntry << endl;
        if(codeEntry.front() == '!')
        {

            //this should remove any line that uses! at the beginning,
            //it is a comment operator/indicator
            getline(inputFile,commentTrash);
            cout <<"we are skipping a comment line: " << codeEntry <<commentTrash << endl;
            inputFile >> codeEntry;
        }
        //take the data from the text file and place it into the vector, so that they may be processed
        //to meet our lexer needs
        GlobalStorage.push_back(codeEntry);
    }

    inputFile.close();
    char lexemeArray[10];


    for(int idx = 0; idx < GlobalStorage.size(); idx++)
    {
        //we begin splitting strings right here
        //this string will take in the current vector element and create it into a string,
        //we then need
        string word;
        string currentLexeme =	GlobalStorage[idx];
        //a respective lexeme should now be held inside this vector of chars
        //ex:  n, u , m , 1 , ","

        //use a for loop to pass array contents into the TempVector
        //split the string into multiple chars and move them into TempVector
        //temp vector represents an individual lexeme, that may be
        //2 or more combined tokens, we must split the tokens, into sperate token
        //word entities, so that they may be registered as 2 seperate entities

        //should house unique lexemes seperated by whitespace and nonalphanumeric
        //chars
        //split the string
        for(int strIdx = 0; strIdx < currentLexeme.length(); strIdx++)
        {
            //we should now have an array of chars
            //with this split array of chars we should now be able to look at each individual item
            //and determine wether the input is alnum or not
            lexemeArray[strIdx] = currentLexeme.at(strIdx);
        }

        for(int arrIdx = 0; arrIdx < currentLexeme.length(); arrIdx ++)
        {
            //search for alphanumeric chars within our lexeme piece, if one is non alphanumerix
            if(isalnum(lexemeArray[arrIdx]) == false)
            {
                //elliminates whitespace from non alphanumeric chars
                //any other found lexemes can be of any different kind of token
                //so we must seperate them all and treat them as different additions to our token vector
                //here we should take all previous chars and combine them into a singular string to add into
                //the vector of tokens, we must push the word we currently have onto the vector, and the new singular token
                if(isspace(lexemeArray[arrIdx]) == false && (lexemeArray[arrIdx] != '$') )
                {
                    //do nothing?
                    wordStorage.push_back(word);
                    word.clear();
                    string symbol(1 ,lexemeArray[arrIdx]);
                    wordStorage.push_back(symbol);
                    continue;
                }

            }
            word.push_back(lexemeArray[arrIdx]);
        }
        wordStorage.push_back(word);
    }
    for(int idx = 0; idx < wordStorage.size(); idx++)
    {
        cout << wordStorage[idx];
    }
}
