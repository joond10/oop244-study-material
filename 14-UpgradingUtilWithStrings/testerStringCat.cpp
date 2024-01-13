#include <iostream>
#include "String.h"

using namespace std;
using namespace sdds;
int main() {
	String name = "Joon", lastname = "Dong";
	name += lastname;
	cout << name << endl;
	return 0;
}