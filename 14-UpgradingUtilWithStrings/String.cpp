#include <iostream>
#include "String.h"
#include "Utils.h"
using namespace std;
namespace sdds {


	String::String(const char* cstr){
		if (cstr) {
			m_length = U.strlen(cstr);
			m_data = new char[m_length + 1];
			U.strcpy(m_data, cstr);
		}
	} 

	String::~String() {
		delete[] m_data;
	}

	//Technically just returning a cout 
	ostream& String::display(ostream& ostr)const {
		if (*this) {
			ostr << m_data;
		}
		return ostr;
	}

	String::operator bool() const{
		return m_data;	//return if not null
	}

	size_t String::length() const
	{
		return m_length;
	}

	String& String::operator+=(const String& rightString) {
		
		char* temp = new char[length() + rightString.length() + 1];
		if (rightString) { //if right string is not empty, concatenate
			if (*this) {
				U.strcpy(temp, m_data);
			}
			else {
				temp[0] = 0;
			}

			U.strcat(temp, rightString.m_data);
			m_length += rightString.length();

			delete[] m_data;
			m_data = temp;
		}
		return *this;
	}


	ostream& operator<<(ostream& ostr, const String& string){
		return string.display(ostr);
	}

}