#include <iostream>
#include "Student.h"
#include "Utils.h"
using namespace std;
using namespace sdds;


int main() {

	//*p and R and i are ALL references to i. 
	int* p;
	int i;
	p = &i;
	int& R = i;

	Student S("Jack");
	S.set("Homer", 12345).display(); 
	//Cascading effect: 
	//Because S.set returns a reference to itself, we can use it as if it were an object on its own
	return 0;
}