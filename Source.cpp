#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const SIZE = 10;
int arr2count = 0;
int iterS;
int isSymBeg = 0;

string arr1[SIZE];
string finalString;
string arr3[SIZE];

bool isAlNumD = true;

char arr2[SIZE];

vector<string> vectorArray;



//Put functions here
/*
char storeVector(string array1, char array2, string tempString)
{
	for (int idx = 0; idx < array1.length(); idx++)
	{
		array2[idx] = tempString.at(idx);
		//vectorArray.push_back(tempWord.at(idx));
	}
	return array2;
}
*/

//Prints the content to the vector descending order for safe check
void printVector(string arrayWord) {
	for (int i = 0; i < arrayWord.length(); i++)
	{
		cout << arrayWord[i] << endl;
		arr2count++;
	}
}


//goes through the array of characters and tries to find a symbol and will return a bool value for later use
bool isAlNum(char arrayString[], int arrSize)
{
	for (int idx = 0; idx < arrSize; idx++)						//This will check where the index for the weird symbol is
	{
		if (arrayString[idx] == '!' || arrayString[idx] == '(' || arrayString[idx] == ')' || arrayString[idx] == ','
			|| arrayString[idx] == '{' || arrayString[idx] == '}' || arrayString[idx] == ';')
		{
			iterS = idx;										//This will mark the index where the symbol is
			
		}
	}
	if (isSymBeg == iterS)
	{
		isSymBeg = 1;
		return true;
	}
	else if (iterS != 0)										//As long as the symbol isn't 0, then it exists in the array
	{
		return true;											//Changes the bool value to 1
	}
	else
		return false;											//Else, nothing changes
}

//This function will print the final array after manipulation
void printFinalArray(string lastArray[])
{

	cout << "The last array content is: ";
	for (int idx = 0; idx < sizeof(lastArray); idx++)
	{
		cout << lastArray[idx] << " ";
	}
	cout << endl;
}


int main()
{

	
	cout << "enter a name plx \n";
	cin >> arr1[0];

	cout << "array 1 is " << arr1[0] << endl;
	string tempWord;
	tempWord = arr1[0];

	//arr2 = storeVector(arr1, arr2, tempWord);
	for (int idx = 0; idx < tempWord.length(); idx++)
	{
		arr2[idx] = tempWord.at(idx);
		//vectorArray.push_back(tempWord.at(idx));
	}

	//Print the Vector so we can figure out if it took in all of the inputs
	printVector(arr2);

	
	for (int idx = 0; idx < arr2count; idx++)
	{
		isAlNumD =  isAlNum(arr2, arr2count);
	}
	cout << "The truth value of array isAlNumD is " << isAlNumD << endl;	//So it will return a bool value of 1 or 0, we can use this for a sort statement

	cout << "The value of the foreign symbol is at " << iterS << endl;

	cout << "char array 2 is: " << arr2 << endl;

	cout << "This will now put the characters in the array back into a different string" << endl;

	if (isAlNumD == 1)		//This will tell us if the string has a symbol or not. If it does, time to seperate that bitch
	{
		//create temporary variables to store the data
		string temp1;
		string temp2;
		string temp3;

		if (iterS == arr2count)			//Checks if the symbol is at the end of the char array
		{
			for (int idx = 0; idx < iterS; idx++)
			{
				temp1.push_back(arr2[idx]);
			}
			temp2.push_back(arr2[iterS]);
			cout << "The two strings are " << temp1 << " " << temp2 << endl;
			arr3[0] = temp1;
			arr3[1] = temp2;

		}
		else
		{											//If it is in the middle, then we will split it three ways
			for (int idx = 0; idx < iterS; idx++)
			{
				temp1.push_back(arr2[idx]);			//Pushes character in the array into a temporary string up until symbol point
			}
			temp2.push_back(arr2[iterS]);			//Finally pushes the string symbol into another string for later
			for (int idx = iterS + 1; idx < arr2count; idx++)	//Pushes the remaining amount of the characters into the string
			{
				temp3.push_back(arr2[idx]);
			}
			cout << "The 3 strings are " << temp1 << " " << temp2 << " " << temp3 << endl;
			arr3[0] = temp1;
			arr3[1] = temp2;
			arr3[2] = temp3;

		}

		cout << "checking the content of the array to see if it has changed" << endl;
		printVector(arr2); 
	}
	else														//Just push the characters into a string and post it in an array
	{
		for (int idx = 0; idx < arr2count; idx++)
		{
			finalString.push_back(arr2[idx]);
		}
		cout << "The single string is " << finalString << endl;
		arr3[0] = finalString;
	}

	cout << "Now let's put the string into the array " << endl;
	printFinalArray(arr3);

	system("pause");
}



