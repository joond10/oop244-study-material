#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

namespace sdds {
	class Student {
		// Any structure is now a class in C++	// CLASSES ARE PRIVATE BY DEFAULT. STRUCT IS PUBLIC BY DEFAULT.
		// with a member variable or ATTRIBUTE.
		
	// This is access modification. These members are barred from being changed in main when PRIVATE.
	//private:
		
		//1. char m_name[51];
		// Let's implement DMA instead of sizing to 51
		// If we are going to implement DMA, we need to deallocate. Create deallocate method.
		char* m_name = nullptr;		//Dynamic name
		unsigned int m_stno;
		void deallocate();
		void init();

	public:
		// PROCEDURE - NOT a function, it looks like one but it's not. 
		Student();  //CONSTRUCTOR	- A procedure that is automatically called when an object is born.
		~Student(); //DESTRUCTOR	- A procedure that is automatically called when an object dies. 

		// Member functions/Methods/Behaviours
		// All the member variables despite being private can be accessed by these methods
		void set();											// Get input
		void set(const char name[], unsigned int stno);		// Implementing DMA in our main set function

		//Query type function
		//A query does not change the state of its object.
		void display()const;
	};
}

#endif 
