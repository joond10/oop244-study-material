#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Student.h"
using namespace std;
namespace sdds {

	// Setting from keyboard (input)
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
								// All functions are within the same class scope so they can be accessed
								// If the function you want to access is outside the class scope, (global scope) - prefix with ::
	}

	void Student::set(const char name[], unsigned int stno) {

		//BEFORE IMPLEMENTING CONSTRUCTOR AND DESTRUCTOR
		// The problem we face now is that if we call set again, m_name will already be pointing to a value 
		// so we must delete anything in it incase if it's already pointing to something

		deallocate(); // Prevent memory leak and ensure pointer is severed before assigning again
		// BUT HAVING DEALLOCATE HERE BRINGS ANOTHER PROBLEM IF WE HAVEN'T INITIALIZED ANYTHING
		// by this point m_name is garbage when starting the program, it is not null. If it's null, there is no issue.
		// When it deallocates, it will crash the program because you are attempting to delete something you did not allocate yet
		// we need to have a function opposite to deallocate. We need a function for initialization! REFER to init

		m_name = new char[strlen(name) + 1]; // +1 for null terminator byte (STRINGS ONLY!)
		strcpy(m_name, name);
		m_stno = stno;
	}

	// Notice const is outside the parameters
	void Student::display() const {
		if (m_name) { //Now we can upgrade our display function to perform it's computations only if m_name actually has a value!
			cout << "Name: " << m_name << ", "	// displaying our attributes
				<< "Student number: " << m_stno << endl;
		}
		else {
			cout << "Data unavailable" << endl;
		}
	}

	void Student::deallocate() {
		delete[] m_name;
		m_name = nullptr; 
	}
	void Student::init(){
		m_name = nullptr;
		m_stno = 0;
	}
	Student::Student() {
		init();
	}
	Student::~Student() {
		deallocate();
	}
}