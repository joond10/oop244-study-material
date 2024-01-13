#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds {
	class Utils {
	public:
		//custom c string functions
		size_t strlen(const char* str) const;
		char* strcpy(char* des, const char* src)const;
		//end 
		int getInt();
		int getInt(int min, int max, const char* prompt = nullptr);
	};

	extern Utils U; // This is a prototype for variables, it makes a file scope variable GLOBAL.
	// Similarly, with function prototype declarations; with any file that includes
	// Utils.h, they have access to this object and its functions

}

#endif	

