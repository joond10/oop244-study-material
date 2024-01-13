#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream> 
#include "String.h"

using namespace std;
using namespace sdds;
int main() {

	String name = "james";
	char cString[50];
	//name[0] = 'J'; 
	//name[6] = 'P' or add to a string? Foolproof Indexing
	//we don't have concatenate function, refer to (11) OOP244 NAA - 2231 - Stages of initialization, more operator overloading and casting
	cout << name << endl;
	strcpy(cString, name);	//How do we use our object when it needs to be a const char* to copy into? Overload type conversion of const char*!
	cout << cString << endl;

	return 0;
}