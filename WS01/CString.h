//------------------------------------------------------------
// OOP 345
// Workshop 01 - From One Translation Unit to Another 
// Student: Andre
// Std Id: 
// Date: 10 MAY 2018
// -----------------------------------------------------------

// 1. Conditional macro that guards against repeated use
// Check for explanation: https://en.wikipedia.org/wiki/Include_guard
#ifndef CSTRING_H  //• to guard a class definition from repetition
#define CSTRING_H

// Use the cstring functions.
#include <cstring>
#include <iostream>

// 2. Namespace named w1.
namespace w1 {

	// 3. Constant definition of the number of characters to be stored
	const int MAX = 3;


	class CString {  //• to define a class within its own namespace
	  
	  private:
	    char _Name[MAX + 1];

	  // 4. Constructor that receives the address of a C - style null - terminated string
	  public:
		CString(const char *pName = nullptr);

	  // 6. a member query named display()that receives a reference to an ostream object and displays the string as stored in your CString object
		void display(std::ostream& os) const;

	};
	
	//7. Helper non-friend operator that inserts the stored string into the left ostream operand.
	//This operator prefaces the string with the number of the insertion and increment that number
	std::ostream & operator<<(std::ostream& os, const CString& pStr);

} //end of namespace w1

#endif //end of #include guard