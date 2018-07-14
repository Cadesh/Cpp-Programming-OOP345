//------------------------------------------------------------
// OOP 345
// Workshop 01 - From One Translation Unit to Another 
// Student: Andre Rosa
// Std Id: 
// Date: 10 MAY 2018
// -----------------------------------------------------------

#include "process.h"

//notice that CString is included in the process.cpp this is why w1 main can`t see the CString!
#include "CString.h"

void process(const char *pChar) {

	using namespace w1;
	CString lStr(pChar);
	std::cout << lStr << std::endl;

}