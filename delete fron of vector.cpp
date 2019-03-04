#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	vector<string> stringVector{"first","middle","last"};
	vector<string> secondVector;

	cout << "print the vector in its entirety" << endl;	
	for(int idx =0; idx < stringVector.size(); idx++){
		
		secondVector.push_back(stringVector.front());
		// we must shift the elments to the front now
		stringVector.erase(stringVector.begin());
		for(int idx = 0;idx < stringVector.size() - 1;idx++){
			stringVector[idx] = stringVector.at(idx+1);
		}
		stringVector.pop_back();
	}
	
	for(int idx = 0; idx < secondVector.size(); idx++){
		cout << secondVector.at(idx) << endl;
	}
}
