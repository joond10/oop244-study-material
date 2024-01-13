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
	//Operator overloads #1 (Changes left operand/SIDE EFFECT)
	//	1. The current object acts as left operand
	//  2. The parameter acts as the right operand
	//  3. The return acts as the type of evaluation 
	//     and returns by reference
	Cup& operator+=(unsigned int volume) {
		set(volume + m_volume);
		return *this;
	}
	//Operator overloads #2 (Does not change any operands/NO SIDE EFFECTS)
	//	1. The current object acts as left operand
	//  2. The parameter acts as the right operand
	//	3. const used in parameter to bar changes to argument (right)
	//	4. const after parameter to bar changes from calling object (left)
	//  5. Type is not a reference and returns a copy to ensure original 
	//  operands remain unchanged
	Cup operator+(const Cup& rightOperand)const {
		//Create new temporary object to hold the addition -
		//constructor sets capacity within parameter
		Cup result(m_capacity + rightOperand.m_capacity);
		//result += calls our += operator function and does
		//the setting of result.m_volume for us
		result += (m_volume + rightOperand.m_volume);
		return result;
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
	Cup c1, c2, c3;

	//Side effect of left operand(calling object) changing
	//The overload += changes c1 by reference

	//Signature looks like with different classes
	//Class1 A, Class2 B, Class3 C
	//Class1& Class2 B::operator(Class3& C);
	//return *this 
	c1.display(cout << "Empty Coffee 1: ") << endl;
	c1 += 100;
    c1.display(cout << "Coffee 1: ") << endl;

	c2 += 50;
	c2.display(cout << "Coffee 2: ") << endl;

	//No side effect of left operand(calling object c2)
	//The overloaded + returns type Cup to store into c3

	//Signature looks like with different classes
	//Class1 A, Class2 B, Class3 C
	//Class1 Class2 B::operator(const Class3& C) const; 
	c3 = c2 + c1;
	c3.display(cout << "Coffee 3: ") << endl;
	return 0;
}