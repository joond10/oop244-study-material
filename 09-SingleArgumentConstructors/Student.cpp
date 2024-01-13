#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Student.h"
using namespace std;
namespace sdds {

	void Student::set() {

		char name[51]{};	//temp variables set to safe state, buffering our reads to validate here
		unsigned int stno{};
		bool done = true;

		cout << "Name: ";
		do {
			done = true;					// Instead we use cin.getline to read whitespace							
			cin.getline(name, 51);			// We specify the size and if it fails means cin was overloaded. getline discards newline by default.
			if (cin.fail()) {
				cin.clear();				// Apologize for it to work again
				cin.ignore(11111, '\n');	// Ignore any input until you reach newline 
				cout << "Too long, shorten the name\n> ";
				done = false;
			}
		} while (!done);
		cout << "Student Number: ";
		cin >> stno;
		set(name, stno);		// Sending temp vars to be copied into our actual attributes 
	}

	void Student::set(const char name[], unsigned int stno) {

		deallocate(); // Prevent memory leak and ensure pointer is severed before assigning again
		//BUT need a constructor at this point to initalize if this is the first function we go into.
		//Because it's trying to delete something that we don't own.
		m_name = new char[strlen(name) + 1]; // +1 for null terminator byte (STRINGS ONLY!)
		strcpy(m_name, name);
		m_stno = stno;
	}

	void Student::display() const {
		if (m_name) {	  // if name exists
			cout << "Name: " << m_name;
			if (m_stno) { // if student number exists
				cout << ", " << "Student number: " << m_stno;
			}
			else {
				cout << " (Student number not registered)";
			}
			cout << endl;
		}
		else {
			cout << "Invalid name!" << endl;
		}
	}
	void Student::deallocate() {
		delete[] m_name;
		m_name = nullptr;
	}
	void Student::init() {
		m_name = nullptr;
		m_stno = 0;
	}
	/*Note: 
	If the class definition includes the prototype for a constructor with some parameters but does not include the prototype for a no-argument default constructor,
	the compiler DOES NOT insert an empty-body, no-argument default constructor. The compiler only inserts an empty-body, no-argument default constructor if 
	the class definition does not declare ANY constructor.

	If we define a constructor with some parameters, we typically also define a no-argument default constructor. This is important in the creation of arrays of objects. 
	The creation of each element in the array requires a no-argument default constructor.
	
	TLDR; If we have a constructor with arguments, make sure you have a no-argument constructor as well.
	*/
	Student::Student(const unsigned int stno) {	// Single argument constructor only recieving stno
		init();
		set("No name", stno);
	}
	Student::Student(const char* name) {	// Single argument constructor only recieving name
		init();								// Still need to initalize our other member variables
		set(name);		
	}
	Student::Student() {
		init();
	}
	Student::~Student() {
		deallocate();
	}
}