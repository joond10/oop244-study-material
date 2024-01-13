#include <iostream>
#include "Student.h"
using namespace std;
using namespace sdds;


int main() {

	Student S;
	//S.init();					  // Use constructor
	S.display();
	S.set("Joon Dong", 36262152); // This function passes arguments to display
	S.display();
	S.set();					  // This function would be used to receive input
	//S.m_stno = 9999999		  // To prevent stuff like this, we make our members private
	S.display();
	//S.deallocate();			   // Use destructor


	return 0;
}