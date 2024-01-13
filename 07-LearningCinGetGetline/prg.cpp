#include <iostream>
using namespace std;

int main() {

	int v{};
	char str[21]{};
	char ch{};
	double dv{};
	//1. Extraction operator (>>) with cin always leaves at least one '\n' in buffer
	//2. cin and operator (>>) for all overloads skips leading whitespace e.g tabs, spaces etc
	cout << "Int: ";
	cin >> v; 
	cout << v << endl;

	cout << "Double: ";
	cin >> dv;
	cout << dv << endl;

	//3. Any type of whitespace is treated as a delimiter
	//similarly to scanf in C. (Cannot read in multi strings)
	cout << "String: ";
	cin >> str;
	cout << str << endl;

	cout << "Char: ";
	cin >> ch;
	cout << ch << endl;
	cout << endl;
	cin.ignore(10000, '\n'); //Discard up to 10,000 inputs or newline. Whichever comes first
	
	//Addressing some confusion:
	//In summary, endl is more related to output and flushing the output buffer,
	//while newline characters in the input buffer are more relevant to input operations and reading from cin. 
	//They are separate concepts, and using endl does not clear the input buffer.

	//get for single chars

	//1. get function is only for strings and characters
	//2. Does NOT ignore whitespace characters which is why we use cin.ignore above

	cout << "char: ";
	ch = cin.get(); //returns an int
	cout << "*" << ch << "*" << endl;
	cin.ignore(10000, '\n');

	cout << "char with reference: "; //passing our variable, get changes it by reference
	cin.get(ch); //returns the cin reference
	//with this method, you can check this for failure because cin is returned again
	//if (cin.get(ch).fail()) { // if the operation failed
	//	//
	//}
	cout << "*" << ch << "*" << endl;
	cin.ignore(10000, '\n');
	//Strongly reccomend to always do cin.ignore after cins

	//get and getline for strings

	//1. Identical to getline prototype
	//2. get does not eat \n and leaves it in input buffer
	// whereas getline eats and discards the \n
	//3. get will not fail if exceeded string size, will leave in the buffer for you to handle

	cout << "Try entering a string more than 20: ";
	cin.get(str, 21); // 
	cout << "*" << str << "*" << endl;

	cout << "Now look at the next cin: ";
	ch = cin.get();
	cout << "*" << ch << "*" << endl;
	cin.ignore(10000, '\n');


	cout << "Try entering a string more than 20 again: ";
	cin.getline(str, 21); // 
	cout << "*" << str << "*" << endl;

	cout << "Now look at the next cin, the buffer is cleared but the next cin fails: ";
	ch = cin.get();
	cout << "*" << ch << "*" << endl;
	cin.ignore(10000, '\n');

	return 0;
}