#include "student.h"
using namespace sdds;
int main() {

	//Initializing our struct/class in main
	//Notice that struct is omitted
	Student S = { "Joon", 3626, 1234.56 }; 

	//To use class function, precede function with owner and dot operator
	S.display();
	return 0;
}
