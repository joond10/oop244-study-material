#include <iostream>
#include "String.h"

using namespace std;
using namespace sdds;
int main() {
	String name = "Joon", empty{};
	cout << name.length();
	cout << name << endl;
	if (empty) {
		cout << empty << endl;
	}
	else {
		cout << "The string is empty!" << endl;
	}
 	return 0;
}