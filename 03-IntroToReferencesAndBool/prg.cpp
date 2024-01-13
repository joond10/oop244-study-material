#include <iostream>
using namespace std;

void setTo100(int& ref) {
	ref = 100;
}

bool read(int& val) {
	bool success = true;
	cin >> val;			// age gets passed into here and the val reference				//
						//changes age from this function.

	if (cin.fail()) {				//If the cin recieves invalid(fails)
		cin.clear();				//Clear the failure for reuse
		cin.ignore(100000, '\n');	//and ignore input until it receieves a newline
		success = false;
	}					// In this function we returned the value of the function
						// which is true or false AND the value of age through reference
	return success;
}
int main() {
	int a = 20;
	int& r = a; //Integer reference "r" is now linked to "a"
				//They actually have the exact same address which proves "r" is literally just another alias
	int age;

	cout << r << endl;	
	r = 50;				//"r" also changes the value of "a"
	cout << a << endl;
	setTo100(a);		//"a" becomes 100 because "ref" is linked to "a"
	cout << a << endl;
	// Essentially it is the same thing as pointers with less syntax
	// and no more passing address or dereferencing

	cout << "Your age please: ";
	if (read(age))  {	// if read function is true 
		if (age >= 19) {
			cout << "What would you like to drink?" << endl;
			
		}
		else {
			cout << "Get out of here!" << endl;
		}
	}
	else {				// if read function is false
		cout << "Error invalid input!" << endl;
	}
}
