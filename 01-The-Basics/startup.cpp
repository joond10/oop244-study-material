#include <iostream>	//Header file library that allows us to use things like cout
using namespace std;//Allows us to use names for variables and objects from that library 

	struct Student; //like a prototype for a function but for structure
	//FORWARD DECLARATION! (can only be done for addresses)
	//If you need a structure declaration when putting function prototype before structure definition

	struct Student {	//Structs are declared the same way as C
		char name[81];
		int stNo;
		double balance;
	};
	void prnStudent(const Student* st); //Notice we omit struct

	int main() {
		int i;
		auto b = 5; //This keyword deduces the object's type directly from its initializer's type
		//Just remember concept, but no use for this in oop244


		cout << "Hello OOP244 NAA, welcome!" << endl;
		cout << endl; //endl acts as newline and flush
		cout << "Enter a number: ";
		cin >> i;	  //Extracts input and assigns to i
		cout << "You entered " << i << endl;

		Student S = { "Fred", 123456, 1234.56 }; //struct omitted, Student is now a type
		prnStudent(&S);
		return 0;
	}

	void prnStudent(const Student* st) { //You cannot concatenate without another << and can't mix different data types
		cout << st->name << ", "
			<< st->stNo << ", "
			<< "OSAP loan : " << st->balance << endl;
	}
