//------------------------------------------------------------
// OOP 345
// Workshop 02 - Move and Copy Semantics 
// Student: Andre
// Std Id:
// Date: 19 MAY 2018
// -----------------------------------------------------------

#include "utility"  //to use std::move 
#include "Text.h"

namespace sict {

	//-----------------------------------------------
	/// @details
	/// DEFAULT CONSTRUCTOR
	/// 1 - Read the file to count the number of lines
	/// 2 - Sets dinamically the string array for the number of lines
	/// 3 - Read the file again to fill the string array
	/// @param file name to be opened
	//-----------------------------------------------
	Text::Text(const string file) {
		
		fstream fs(file);
		string nLine;
		unsigned int lCount = 0; // to count the number of lines

		if (fs.fail() == true) { //set to safe empty state
			this->_size = 0;
			delete [] _aStr;
			return; 
		}
		else {
			while (getline(fs, nLine)) { //count the number of lines
				lCount++;
		    }
			fs.close();
			this->_size = lCount;
			this->_aStr = new string[_size];
			
			fs.open(file); //read again and fill the array
			lCount = 1;
			while (getline(fs, nLine)) {
				this->_aStr[lCount] = nLine;
				lCount++;
			}
		}
	}
	//----------------------------------------
	//----------------------------------------
	/// @details
	/// COPY CONSTRUCTOR
	//----------------------------------------
	Text::Text(const Text &src) {
		*this = src;
	}
	//----------------------------------------
	//----------------------------------------
	/// @details
	/// MOVE CONSTRUCTOR
	//----------------------------------------
	Text::Text(Text &&src) {
		*this = std::move(src); ///en.cppreference.com/w/cpp/utility/move
	}
	//----------------------------------------
	//----------------------------------------
	/// @details
	///  COPY ASSIGNMENT OPERATOR
	//----------------------------------------
	Text& Text::operator=(const Text &src) {
		
		if (this != &src) { //they are not the same
		   // copy values
			this->_size = src._size;
		   // liberate memory
			delete [] this->_aStr;
		   // copy dinamic memory values
			this->_aStr = new string[_size];
			for (unsigned int i = 0; i < _size; i++) {
				this->_aStr[i] = src._aStr[i];
			}
		}
		return *this;
	}
	//----------------------------------------
	//----------------------------------------
	/// @details
	/// MOVE ASSIGNMENT OPERATOR
	/// the move assignment directs the pointer to the new address from the source
	/// then the source pointer is set to null
	//----------------------------------------
	Text& Text::operator=(Text &&src) {
	
		if (this != &src) { //they are not the same
			this->_size = src._size;
			delete [] this->_aStr;
			this->_aStr = src._aStr; //redirects the address
			src._aStr = nullptr;     //set the source pointer to null;
		}

		return *this;
	}
	//----------------------------------------
	//----------------------------------------
	/// @details
	/// DESTRUCTOR
	//----------------------------------------
	Text::~Text() {
		delete[] this->_aStr;
	}
	//----------------------------------------
	//----------------------------------------
	/// @details
	/// Return the number of lines in the file.
	//----------------------------------------
	size_t Text::size() const {
		return this->_size;
	}
	//----------------------------------------

} // end namespace sict