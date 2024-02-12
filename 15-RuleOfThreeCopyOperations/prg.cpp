#include <iostream>
#include "String.h"

using namespace std;
using namespace sdds;
int main() {
	//Testing overload for extraction operator and cin for reading a string
	String name = "Jack", name2 = "John", name3 = name2;
	cout << "Name: ";
	cin >> name;
	cout << "Hello " << name << "!" << endl;
	name2 = name; 
	cout << "Hello to " << name2 << " too!" << endl;
	//Crashes here because destructor crash AND memory leak!
	//1. name2 is created and then 
	//	 instructed to point to the same variable as name.
	//   But now name2 loses what it orignally points to causing memory leak
	//2. When the destructor of name 2 is called
	//	 it destroys the address of name
	//3. When we try to deallocate name, it is trying to delete an 
	//	 address that doesn't belong to us

	//Summary: When assigning an object, they both point to the same place
	//Unless we have a constructor which manages a copies own resources
	//BASICALLY!!! WE WANT TO COPY DATA WHILE ENSURING EACH OBJECT HAS ITS OWN MEMORY ALLOCATED
	//WALKTHROUGH TO UNDERSTAND!
	
	//We need to implement the rule of 3

	return 0;
}