#include <iostream>
using namespace std;
class Cup {
	int m_capacity;
	int m_volume;
public:
	Cup(unsigned int capacity = 250u) {
		m_capacity = capacity;
		m_volume = 0;
	};
	ostream& display(ostream& ostr = cout) const {
		ostr << m_volume << "/" << m_capacity;
		return ostr;
		//Making our display function likes this makes it more
		//robust and acts to make it literally act as cout 
		//and allow for us to cascade

		//ostream is the type for cout and so we return a reference
		//to type ostream. By default ostr is cout
	}
};

int main() {
	Cup coffee;
	//Pass cout with a string so it prints prior 
	//to function definition as ostr
	coffee.display(cout << "Here is ") << " cup of coffee!" << endl;
	
	return 0;
}