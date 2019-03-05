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
vector<string> TextInput;  //this vector will house info from fstream
vector<char> wordVector;   //this vector will house a string taken from
//fstream, spkit into chars
vector<string> splitLexemes;	//vector that houses split lexemes

bool symbolHere = false;
bool inFront = false;

int symbolIndex = 0;

string begWord;
string tempString;


void splitString(string lexeme)
{
    //will split  the string into the word vector as a vector
    //of chars
    for(int strIdx	= 0; strIdx < lexeme.length(); strIdx++)
    {
        wordVector.push_back(lexeme.at(strIdx));
    }

}
//Takes in a Character vector and finds the location of the symbol and stores the index for later use
void isSymbol(vector<char> word)
{
    int wordPosition = 0;									//Temporary variable created for index to keep track of things

    while (symbolHere == false)							//As long as the symbol hasn't been found, we go through the array
    {
        if(isalnum(word[wordPosition]) == false && isspace(word[wordPosition] == false && word[wordPosition != '$']))
        {
            if (wordPosition == 0)							//Assuming that the symbol is in the front
            {
                symbolIndex = 0;						//resets symbol index at the front of CHAR vector
                symbolHere = true;						//exits the while loop
                inFront = true;							//marks the index at the front
            }
            else
            {
                //If the symbol is anywhere else but the front, it will mark the counter
                symbolIndex = wordPosition;					//makes index the same as the couter
                symbolHere = true;						//exits out of the loop
            }
        }
        else if (wordPosition == word.size()-1)		//Assuming we iterate until the end of the array, we assume there is no actual symbol
        {
            symbolHere = true;							//exits the loop
            wordPosition = word.size();				//Just making sure the counter is equal to the size of the vector
        }
        else
        {
            //assuming that the current element is not a symbol?
            wordPosition++;									//fucking increment counter, go through loop again at next index
        }
    }

}



void shiftVector(vector<char> word)
{

    int currentWordSize = word.size();

    if(currentWordSize != 1)
    {
        for(int wIdx = 1; wIdx < word.size(); wIdx++)
        {
            wordVector[wIdx -1] = wordVector[wIdx];
        }
        wordVector.pop_back();
    }

    if(word.size() == 1)
    {
        wordVector.clear();
    }

}

void splitSymbol(vector<char> currentWord)
{
    if(symbolHere == true && symbolIndex == 0, && inFront == true && currentWord.size() == 1)
    {

        string tempSymbol;
        tempSymbol.push_back(currentWord[0]);
        splitLexemes.push_back(tempSymbol);
        wordVector.clear();

        inFront = false;
        symbolHere = false;
        symbolIndex = 0;

    }

    else if(symbolHere == true && symbolIndex == 0 && inFront == true && currentWord.size() > 1)
    {

        string tempSymbol;
        tempSymbol.push_back(currentWord[0]);
        splitLexemes.push_back(tempSymbol);
        shiftVector(wordVector);

        inFront =  false;
        symbolHere = false;
        symbolIndex = 0;

    }

    else if(symbolHere == true && symbolIndex !=0 && inFront == false)
    {
        string tempOne;
        string tempTwo;

        for(int idx = 0; idx < symbolIndex; idx++)
        {

            tempOne.push_back(currentWord[idx]);
            shiftVector(word);
        }

        splitLexemes.push_back(tempOne);

        tempTwo.push_back(wordVector[0]);
        splitLexemes.push_back(tempTwo);
        shiftVector(wordVector);

        symbolHere = false;
        symbolIndex = 0;

    }

    else
    {
        string tempFString;

        for(int idx = 0; idx < currentWord.size(); idx++)
        {

            tempFString.push_back(currentWord[idx]);
            shiftVector(wordVector);

        }
        splitLexemes.push_back(tempFString);
        symbolHere = false;
        symbolndex = 0;
    }
}



int main()
{
    //include means of both reading and writing to a file
    //then include a file
    //string filename;
    //cin >> filename;

    ifstream inputFile;

    string commentLine;
    string codeEntry;
    //NOTE: on my raspberry pi, my computer would not specify
    //the local directory for
    //the file location, i recommend you specify the file
    //name or the directory to ensure that the correct file is
    //being read in
    inputFile.open("inputfile.txt");
    // this should take in a file that the user should specify
    //we now have the file accessed and open,it is here where we
    // make sure to close the file when finished processing
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
            cout <<"we are skipping a comment line: " << codeEntry <<commentLine << endl;
            inputFile >> codeEntry;
        }
        //take the data from the text file and place it into the vector
        //to meet our lexer needs
        textInput.push_back(codeEntry);
    }

    inputFile.close();

    //we are transfering strings from textInput, into splitLexemes
    for(int idx = 0; idx < textInput.size(); idx++)
    {
        //take current index into a split function
        string currentLexeme = textInput[idx];

        //takes string, and will place it into the word vector
        splitString(currentLexeme);

        while(wordVector.empty() == false)
        {
            isSymbol(wordVector);
            splitSymbol(wordVector);
        }

    }

    for(int idx = 0; idx < splitLexemes.size(); idx++)
    {
        cout << splitLexemes[idx] << endl;
    }

}
