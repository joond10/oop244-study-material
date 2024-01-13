#include <iostream>
using namespace std;
int main() {
	char str[21] = "Freddie";
	char ch = 'A';
	int iv = 123;
	double dv = 123.123456789;

	clog.setstate(ios::failbit); //disables clog
	cout.setstate(ios::failbit); //disables cout which enables cerr

	if (cout.fail()) { //If cout fails and we don't clear it, we need another stream to print from so we use cerr. Cerr prints immediately unbuffered
		cerr << "cout is currently in fail state" << endl;
	}
	clog << "Printing double: " << endl;
	cout << dv << endl;
	cout.clear();	//apologize to cout for making it fail and have it work again (enable it)
	clog << "Printing double with 6 digits after decimal point: ";
	cout.precision(6);
	cout << dv << endl;	//successfully prints because cout.clear

	//Essentially what this all could be used for is for readability.
	//If we had debug testing messages with clog, we could disable all of them with one line
}