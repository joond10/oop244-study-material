#include <iostream>
#ifndef SDDS_STRING_H
#define SDDS_STRING_H
namespace sdds {
class String {
	//Unsigned integer used to measure sizes 
	size_t m_length{};
	char* m_data{};
public:
	//Single argument constructor sets string or set to nullptr if argument not provided
	String(const char* cstr = nullptr);
	//Destructor
	~String();
	//Display function that returns as a cout so it allows us to cascade with more insertions
	//Default argument is cout
	std::ostream& display(std::ostream& ostr = std::cout)const;
	//Boolean overload to use in if blocks
	operator bool()const;
	//Returns length of a
	size_t length() const;
	//Overloaded += to concatenate strings
	String& operator+=(const String& rightString);
	};
//Non-member/helper function overloading insertion operator to use display as primitive
std::ostream& operator<<(std::ostream& ostr, const String& right);
}

#endif // SDDS_STRING_H

