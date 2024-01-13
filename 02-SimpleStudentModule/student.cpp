#include <iostream>
#include "student.h"
using namespace std;
namespace sdds{
	//Global variable
	const double interestRate = 0.02;

	//This function just displays output and does an inline calculation
	//Precede function name with owner and bind with ::
	void Student::display() { 
		cout << name << ", " 
			 << stNo << ", " 
			 << "OSAP loan: " << balance << "Interest: " << 
			  balance*interestRate << endl;
	}
}
