#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H
namespace sdds {
	//Structs are the same as classes
	struct Student {
		//Data inside a class (class scope)
		char name[81];
		int stNo;
		double balance;
		//Behaviour
		//We can put functions inside of a class scope
		//Define this function in student cpp module
		void display(); 

	};
}


#endif // !1 SDDS_STUDENT_H
