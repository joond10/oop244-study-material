#include <iostream>
#include <fstream> 
#include "String.h"

using namespace std;
using namespace sdds;
int main() {
	
	String name = "Joon", empty;
	cout << name[0] << endl;
	cout << name[200] << endl; // Prints garbage out of array bounds BUT can use % in function overload to prevent

	for (int i = 0; i < 30; i++) { //Will succesfully only print Joon and not garbage/crash once i is at an index past "n"
		cout << name[i];
	}

	cout << empty[0] << endl; //How to safeguard against crash trying to print something that doesn't exist? - Refer to function

	return 0;
}