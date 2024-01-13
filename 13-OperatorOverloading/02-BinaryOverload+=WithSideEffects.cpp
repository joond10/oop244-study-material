#include <iostream>
using namespace std;
class Cup {
	int m_capacity;
	int m_volume;
	Cup& set(unsigned int volume) {
		//If we recieve a valid volume
		if (volume <= m_capacity) { 
			m_volume = volume;
		}
		else {	
			// If we recieve an invalid volume, set it as invalid
			setInvalid();
		}
		return *this;
	}
	// Make a boolean for if it's invalid for use
	bool isInvalid() const {
		return m_capacity == 0;
	}
public:
	// Set the capacity to something impossible
	Cup& setInvalid() {	
		m_capacity = 0;
		return *this;
	}
	Cup(unsigned int capacity = 250u) {
		m_capacity = capacity;
		m_volume = 0;
	};
	Cup& add(unsigned int volume) {
		//Send client volume + current volume of current object
		set(volume + m_volume);
		return *this;
	}
	//Operator overload
	//	The current object acts as left operand
	//  The parameter acts as the right operand
	//  The return acts as the type of evaluation 
	Cup& operator+=(unsigned int volume) {
		set(volume + m_volume);
		return *this;
	}
	ostream& display(ostream& ostr = cout) const {
		//Making our display function likes this makes it more
		//robust and acts to make it literally act as cout 
		//and allow for us to cascade

		//ostream is the type for cout and so we return a reference
		//to type ostream. By default ostr is cout
		if (!isInvalid()) {
		ostr << m_volume << "/" << m_capacity;
		}
		else {
			ostr << "Invalid cup object!";
		}
		return ostr;
	}
};

int main() {
	Cup coffee;
	coffee.display() << endl;
	coffee.add(100);
	coffee.display() << endl;
	coffee += 50;

	return 0;
}