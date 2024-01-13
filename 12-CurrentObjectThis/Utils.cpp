#include <iostream>
#include "Utils.h"
using namespace std;
namespace sdds {
	Utils U; //File scope instance called U of Utils in Utils.cpp

	size_t Utils::strlen(const char* str) const {
		size_t len; 
		for (len = 0; str[len]; len++);
		return len;
	}

	int Utils::getInt() {
		int value{};
		cin >> value;
		bool done{};
		do {
			done = false;
			if (cin) { // if(!cin.fail()) { 
				if (cin.get() != '\n') {  // if the next char after int is not newline
					cout << "Only an integer please, retry: ";
				}
				else {
					// all good
					done = true;
				}

			}
			else {
				cin.clear(); // clear the fail state
				cout << "Invalid Integer, try again: ";
			}
			if (!done) cin.ignore(10000, '\n');
		} while (!done);
		return value;
	}
	int Utils::getInt(int min, int max, const char* prompt) {
		int value{};
		// This is the beginner style coding
	//do {
		//value = getInt();
	//	if (value < min || value > max) {
	//		cout << "[" << min << ">=Val<=" << max << "], retry: ";
	//	}
	//} while (value < min || value > max);
	// 
	// 
		//This is pro level coding 
	//The && operator means it will only look at the first condition for success
	//If user enters a valid number (false) It will not print the cout
	//If user enters an invalid number (true) It will look at the cout condition (also true)
		if (prompt) {
			cout << prompt;
		}
		do {
			value = getInt();
		} while ((value < min || value > max) &&
			cout << "[" << min << ">=Val<=" << max << "], retry: ");
		return value;
	}

}
