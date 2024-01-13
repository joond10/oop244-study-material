#include <iostream>
#include "Student.h"
using namespace std;
using namespace sdds;


int main() {

	//Overloaded constructor with single argument. 
	//With single arguments, we are not assigning anything but initializing
	//Using assignment operator is a call to one argument constructors
	Student P("Ina Yoon", 36262152);
	Student J = 36262152;
	Student S = "Fred Soley";
	J.display();
	S.display();
	P.display();


	return 0;
}