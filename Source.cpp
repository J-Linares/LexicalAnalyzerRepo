#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//**********************GLOBAL DECLARATIONS AND VARIABLES*****************************//

vector<string> firstVector;
vector<char> wordVector;
vector<string> finalVector;

bool symbolHere = false;
bool inFront = false;

int symbolIndex = 0;

string begWord;
string tempString;

//*******************************FUNCTIONS HERE****************************************************//

//Takes in a Character vector and finds the location of the symbol and stores the index for later use
void isSymbol(vector<char> tempVector)
{
	int counter = 0;									//Temporary variable created for index to keep track of things

	while (symbolHere == false)							//As long as the symbol hasn't been found, we go through the array
	{
		if (tempVector[counter] == '!' || tempVector[counter] == '(' || tempVector[counter] == ')' || tempVector[counter] == ','
			|| tempVector[counter] == '{' || tempVector[counter] == '}' || tempVector[counter] == ';')
		{
			if (counter == 0)							//Assuming that the symbol is in the front
			{
				symbolIndex = 0;						//resets symbol index at the front of CHAR vector
				symbolHere = true;						//exits the while loop
				inFront = true;							//marks the index at the front
			}
			else
			{											//If the symbol is anywhere else but the front, it will mark the counter
				symbolIndex = counter;					//makes index the same as the couter
				symbolHere = true;						//exits out of the loop
			}
		}
		else if (counter == tempVector.size()-1)		//Assuming we iterate until the end of the array, we assume there is no actual symbol
		{
			symbolHere = true;							//exits the loop
			counter = tempVector.size();				//Just making sure the counter is equal to the size of the vector
		}
		else
		{												//assuming that the current element is not a symbol?
			counter++;									//fucking increment counter, go through loop again at next index
		}
	}
	
}

//BUG CHECKER: Takes in a CHAR vector and prints out the elements in descending order
void printVector(vector<char> tempString)
{
	for (int idx = 0; idx < tempString.size(); idx++)			//Loop to go through the string
	{
		cout << tempString[idx] << endl;						//Print that bitch
	}
}

//Takes in the first single STRING vector and splits it into characters for a CHAR vector
//Will prolly need to be rewritten to just take a string. But general idea is the same
void splitString(vector<string> tempWordString)
{
	string tempString = tempWordString[0];					//Temporary Variable stores the first element of the first vector as a string
	for (int idx = 0; idx < tempString.length(); idx++)		//goes through the tempString we created until the end
	{
		wordVector.push_back(tempString.at(idx));			//Pushes the CHAR at the index onto the wordVector
	}
}

//Function to delete first member of the vector and shift the node to the left by one
void shiftVector(vector<char> othertempWord)
{
	
	int firstVectorSize = othertempWord.size();					//Stores the vector size as an int variable
	if (firstVectorSize != 1)									//Assuming that the first vector isn't the size 1
	{
		for (int idx = 1; idx < othertempWord.size(); idx++)	//shift shit here. Start at 2nd index
		{
			wordVector[idx - 1] = wordVector[idx];				//Moves everything from the right one index to the left. Shift this way <--
		}
		wordVector.pop_back();									//Pops the end of the vector and decriments vector size overall
	}	
	if (othertempWord.size() == 1)								//If the vector has only one element
	{
		wordVector.clear();										//clear the vector and "reset" it
	}
	
}

//prints final vector
void printFinalVector(vector<string> finVec)
{
	for (int idx = 0; idx < finVec.size(); idx++)
	{
		cout << finVec[idx] << " ";
	}
	cout << endl;
}

//Function takes in a CHAR vector and goes through it to either split the symbols two at a time
//or to just append it to the end of the final string.
//This will use recursion
void splitSymbol(vector<char> tempWord)
{

	//If the symbol exists and is the only item in the vector
	//IE !
	if (symbolHere == true && symbolIndex == 0 && inFront == true && tempWord.size() == 1)
	{

		string tempSymbolString;							//initiate temporary string for this function
		tempSymbolString.push_back(tempWord[0]);			//push the symbol into the string by itself
		finalVector.push_back(tempSymbolString);			//Push the string with symbol into the back of the vector

		wordVector.clear();									//clears word Vector
																//Resets data used for this
		inFront = false;
		symbolHere = false;
		symbolIndex = 0;

	}

	//If the symbol exists in the first position vector and there is more elements in the vector
	// IE: (BOOOOOOB
	else if (symbolHere == true && symbolIndex == 0 && inFront == true && tempWord.size() > 1)
	{

		string tempSymbolString;							//initiate temporary string for this function
		tempSymbolString.push_back(tempWord[0]);			//push the symbol into the string by itself
		finalVector.push_back(tempSymbolString);			//Push the string with symbol into the back of the vector

		shiftVector(wordVector);							//shifts the vector and deletes the last element of vector

															//Resets data used for this
		inFront = false;
		symbolHere = false;
		symbolIndex = 0;

	}

	//We can assume that the symbol exists and is not at the front, therefore let's split the bitch
	//IE Bob!Lee
	else if (symbolHere == true && symbolIndex != 0 && inFront == false)
	{
		string tempString1;							//initialize two temporary strings that will be used
		string tempString2;							//to push two "Elements" into final array

		for (int idx = 0; idx < symbolIndex; idx++)		//Will go through the CHAR vector up until the symbol index
		{
			tempString1.push_back(tempWord[idx]);		//Populate the temporary first temporary string
			shiftVector(wordVector);					//decrements and shifts CHAR vector
		}
			//Once we exit the loop, string one should be fully populated
		finalVector.push_back(tempString1);				//Push the string into the last vector

			//This will push the remaining symbol onto the final array
		tempString2.push_back(wordVector[0]);			//This assumes that the symbol is in the front
		finalVector.push_back(tempString2);				//Push the string with the symbol onto the final array
		shiftVector(wordVector);						//Shift the array and pop the back of CHAR array

			//Resets the values
		symbolHere = false;
		symbolIndex = 0;

	}

	//We assume that there is no symbol, so let's forget about it and just shove in the string into last array
	//IE: BOB
	else
	{
		string tempFString;									//Temporary string created
		for (int idx = 0; idx < tempWord.size(); idx++)		//Loop to go through the vector
		{
			tempFString.push_back(tempWord[idx]);			//Pushes the character onto the string
			shiftVector(wordVector);						//Decrements vector size 
		}
		finalVector.push_back(tempFString);

		//Resetting the vectors properties if called again
		symbolHere = false;
		symbolIndex = 0;
	}
	

}




int main()
{

	//Store user input -> string. Store string -> first element of a vector. 
	cout << "Hey Asshole, put in a word: " << endl;
	cin >> begWord;
	firstVector.push_back(begWord);

	//takes first vector's element and splits it to second array in individual letters
	//May need to put a for loop here so we go through the entire first vector. 
	//Shifting everything from first vector isn't needed, but can work
	cout << "Now to split the vector " << endl;
	splitString(firstVector);
	cout << "Successfully split the string " << endl;

	//Now we split and append strings either one or two until second vector is empty
	cout << "Testing recursive function " << endl;
	while(wordVector.empty() == false)
	{
		isSymbol(wordVector);				//Checks if symbol is there. Finds index of symbols if true
		splitSymbol(wordVector);			//Takes in CHAR vector and splits it by symbol and appends to final Vector

	}

	//BUG CHECK: Just to see if our last vector is fully populated
	cout << "Now printing the last vector" << endl;
	printFinalVector(finalVector);

	//system.("pause");
	return 0;
}
