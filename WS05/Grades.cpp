//------------------------------------------------------------
// OOP 345
// Workshop 05 - Lambda Expressions
// Student: Andre
// Std Id: 
// Date: 14 JUN 2018
// -----------------------------------------------------------

#include "Grades.h"
#include <fstream>
#include <iostream>


using namespace std;

namespace sict {

	//------------------------------------------------------------------------
	///@details class constructor opens the file and save the contents in dinamically allocated memory
	//-------------------------------------------------------------------------
	Grades::Grades(const char *file) {

		fstream fs;
		string nLine;
		unsigned int lCount = 0; // to count the number of lines


			fs.open(file);
			if (fs.fail() == true) { //check if file opens
				throw "Open file failed.";
			}
			else {
				while (getline(fs, nLine)) { //count the number of lines
					lCount++;
				}
				fs.close();
				this->_size = lCount;
				this->_aStd = new string[_size];
				this->_aGrd = new double[_size];

				fs.open(file); //read again and fill the array
				
				lCount = 0; 
				while (getline(fs, nLine)) {
					if (nLine.find(" ") == string::npos) {
						throw "Format of data in file is not allowed.";
					}

					size_t index = nLine.find(" ");
					this->_aStd[lCount] = nLine.substr(0, index);

					nLine = nLine.substr(index + 1, nLine.length());
					this->_aGrd[lCount] = stod(nLine); //stod - converts the string to double 
					                                   //http://www.cplusplus.com/reference/string/stod/

				lCount++;
				}

			} //else
		} 


		//	this->_size = 0;
		//	delete[] _aStd;
		//	delete[] _aGrd;
		//	cout << err << std::endl;
	
	

}