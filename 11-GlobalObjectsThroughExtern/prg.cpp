#include <iostream>
#include "Student.h"
#include "Utils.h"
using namespace std;
using namespace sdds;


int main() {

	int v;
	cout << "Integer: ";
	v = U.getInt(0, 100, "Enter your mark: ");
	cout << v << endl;

	return 0;
}