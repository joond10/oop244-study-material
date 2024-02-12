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
	String::String(const String& S){
	//The copy constructor is simply a use of the assignment operator overload
	//Make sure the DMA data pointer is nullptr
		operator=(S);
	}

	String& String::operator=(const String& S) {
		if (this != &S) { // To make sure we don't copy ourselves into ourselves
			delete[] m_data;	//delete existing data
			m_data = nullptr;	//and set safe empty state
			m_length = 0;		//in case S is garbage

			if (S) {
				m_length = S.length();
				m_data = new char[S.length() + 1];
				U.strcpy(m_data, S.m_data);
			}
		}
		return *this;
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

	istream& String::read(istream& istr){
		char temp[4096];
		istr.getline(temp, 4096); //cin.getline
		if (istr) {	// if cin doesn't reach limit and doesn't fail
			delete[] m_data; // clear existing data
			m_length = U.strlen(temp);
			m_data = new char[m_length + 1];
			U.strcpy(m_data, temp);
		}
		return istr;
	}

	String::operator bool() const{
		return m_data;	//return if not null
	}

	size_t String::length() const
	{
		return m_length;
	}

	//String& String::operator+=(const String& rightString) {
	//	
	//	char* temp = new char[length() + rightString.length() + 1];
	//	if (rightString) { //if right string is not empty, concatenate
	//		if (*this) {
	//			U.strcpy(temp, m_data);
	//		}
	//		else {
	//			temp[0] = 0;
	//		}

	//		U.strcat(temp, rightString.m_data);
	//		m_length += rightString.length();

	//		delete[] m_data;
	//		m_data = temp;
	//	}
	//	return *this;
	//}

	//Basically this allows us to not have to use our display function in main
	ostream& operator<<(ostream& ostr, const String& string){
		return string.display(ostr);
	}

	istream& operator>>(istream& istr, String& string){
		return string.read(istr);
	}

}