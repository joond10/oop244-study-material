#include <iostream>;
using namespace std;

int* allocateInts(int& num) {
	cout << "How many ints ? \n> ";
	cin >> num;
	int* intsPtr = new int[num];
	cin.ignore(10000, '\n');
	return intsPtr;
}
int main() {

	int size; 
	int* values;
	int i;

	//Calling overload function that will perform DMA on values anad size through references and pointers
	//values is dynamically allocated from the return of the function and is continued to be used as an array
	//size becomes the dynamically allocated array size from the function parameter "num"
	values = allocateInts(size); 
	if (values == nullptr) {
		cout << "Allocation failed!..." << endl;
	}
	else {

		cout << "Enter ints: " << endl;
		for (i = 0; i < size; i++) {
			cout << (i + 1) << "> ";
			cin >> values[i];
		}
		for (i = size - 1; i >= 0; i--) {
			cout << values[i] << " ";
		}
	}
	cout << endl;
	delete[] values;
}