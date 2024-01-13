#include <iostream>
#include <fstream> //used for file io
#include "String.h"

using namespace std;
using namespace sdds;
int main() {

	char ch;
	//write to file - myname acts as cout because inherited
	ofstream myname("thename.txt");
	myname << "Joon" << endl; 
	myname.close();
	//read file - name acts as cin because inherited
	ifstream name("thename.txt");
	name >> ch;
	cout << ch << endl;
	return 0;
}

	/*
	The prototypes for the overloaded insertion and extraction operators for standard input and output on objects of our own classes take the form
	Non member helper functions where Type is the name of the class:

		
		Takes parameters cin on the left side and a reference to our class on the right
		-------------------------------------------------------------------------------
		std::istream& operator>>(std::istream& istr, Type&) {
			// call our read function which implements 
					istream& Class::read(istream& istr){

		}
	
		Takes parameters cout on the left side and a constant reference to our class on the right because it's essentially a display function
		-------------------------------------------------------------------------------------------------------------------------------------
		std::ostream& operator<<(std::ostream& ostr, const Type&) {
			// call display function
					ostream& Class::display(ostream& ostr)const {

		}

	*/