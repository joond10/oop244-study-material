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
		//Rule of three
		//Copy Constructor
		String(const String& S);

		//Copy Assignment
		String& operator=(const String& S);

		//Destructor
		~String();
		//End rule of three

		//Display function that returns as a cout so it allows us to cascade with more insertions
		//Default argument is cout
		std::ostream& display(std::ostream& ostr = std::cout)const;

		//Read in string function that returns a cin so it allows us to cascade with more insertions
		//and handles dynamic memory allocation of our strings
		//Default argument is cin
		std::istream& read(std::istream& istr = std::cin);

		//Boolean overload to use in if blocks
		operator bool()const;

		//Returns length of string
		size_t length() const;

		//Overloaded += to concatenate strings
		//String& operator+=(const String& rightString);
		//
	};
//Non-member/helper function overloading insertion operator to use display as primitive
std::ostream& operator<<(std::ostream& ostr, const String& right);
//Non-member/helper function overloading extraction operator to use read as primitive
std::istream& operator>>(std::istream& istr, String& right);
}

#endif // SDDS_STRING_H

