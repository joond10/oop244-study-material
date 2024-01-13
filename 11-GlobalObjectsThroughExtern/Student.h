#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

namespace sdds {
	class Student {
		//1. char m_name[51];
		char* m_name = nullptr;		//Dynamic name
		unsigned int m_stno;
		void deallocate();
		void init();

	public:
		//Double Argument Constructors
		Student(const char* name, const unsigned int stno);

		//Single Argument Constructors
		//	Used to provide flexibility for client code to initialize objects with specific, predetermined values.
		//	Allow objects to be created with specific initializations based on the arguments provided.
		Student(const unsigned int stno);
		Student(const char* name);

		//No argument constructor	
		// (Used to create an object with default or safe empty state. 
		// Used for default values without requiring specific input from the client side.
		Student();

		//Destructor 
		~Student();


		// Get input
		void set();
		// Recieve input and implement DMA in our main set function
		void set(const char name[], unsigned int stno = 0);

		// Query
		void display()const;
	};
}

#endif 
