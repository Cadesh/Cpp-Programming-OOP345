//------------------------------------------------------------
// OOP 345
// Workshop 02 - Move and Copy Semantics 
// Student: Andre
// Std Id: 
// Date: 19 MAY 2018
// -----------------------------------------------------------

#ifndef TEXT_H 
#define TEXT_H

#include <string> 
#include <fstream>

using namespace std;

namespace sict {

	/// @class Text
	class Text {

	public:
		string * _aStr;  ///< array of strings
		size_t _size;     ///< number of records 

	public:

		Text(const string file = "");       ///< default constructor
		Text(const Text &src);              ///< copy constructor
		Text(Text &&src);                   ///< move constructor YOU CANT USE CONST OR IT WILL CALL THE COPY ASSIGNMENT
		Text& operator=(const Text &src);   ///< copy assignment operator
		Text& operator=(Text &&src);        ///< move assignment operator
		~Text();                            ///< destructor
		size_t size() const;                ///< member function named size_t size() const that returns the number of records of text data

	};

} // end namespace sict

#endif //end of guard