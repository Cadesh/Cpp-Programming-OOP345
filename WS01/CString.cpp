//------------------------------------------------------------
// OOP 345
// Workshop 01 - From One Translation Unit to Another 
// Student: Andre
// Std Id: 
// Date: 10 MAY 2018
// -----------------------------------------------------------

#include "CString.h"

// Use of extern keyowrd, book pg 9.
extern int STORED = w1::MAX;  // • to link to a variable in another translation unit

namespace w1 {


	//-------------------------------------------------------------------------------------
	// 5. Stores the MAX characters of the string.
	CString::CString(const char *pName) {
	    
		bool empty = false;
		//5.1. Check null address.Store empty string in that case
		if (pName == nullptr) {
			_Name[0] = '\0';
			empty = true;
		}

	    // not null then count to MAX to set chars
		if (empty == false) {
			for (int i = 0; i < MAX; i++) {
				_Name[i] = pName[i];
			}
			_Name[MAX] = '\0';
		}
	}
	//-------------------------------------------------------------------------------------
	
	//-------------------------------------------------------------------------------------
	void CString::display(std::ostream& os) const {
		
		//os.width(MAX);
		os << _Name;
	}
	//-------------------------------------------------------------------------------------

	//-------------------------------------------------------------------------------------
	std::ostream& operator<<(std::ostream& os, const CString& pStr) {
		
		static int count = 0;  // can only be accessed from inside this function but lasts the lifetime of the program
		os << count++ << ": ";
		pStr.display(os);
		return os;
	}
	//-------------------------------------------------------------------------------------

} //end of namespace w1