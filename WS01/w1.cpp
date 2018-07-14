//------------------------------------------------------------
// OOP 345
// Workshop 01 - From One Translation Unit to Another 
// Student: Andre
// Std Id: 
// Date: 10 MAY 2018
// -----------------------------------------------------------

#include "process.h"

//• to pass arguments to program from the command line
//NOTE 1:
// To run a VS program from Command Prompt
// from the Start Menu choose Visual Studio 2017 FOLDER
// then select Developer Command Prompt for VS2017
// and set the path of your .exe file like d:\Personal\SENECA\3_Term\OOP345\ws01\Debug

//NOTE 2:
// To add arguments to run driectly from windows VS 
// go to project 'proprieties -> debugging -> command arguments' 

//------------------------------------------------------------------
//argc = number of arguments, argv[] = array of arguments
// the first argument is always the program name, therefore argc is never 0, but 1.
int main(int argc, char *argv[]) {
	
	extern int STORED;

	//if there are no parameters!
	if (argc <= 1) {  //the first param is always the program name, therefore 1 means no parameters

		std::cout << "Insufficient number of arguments (min 1)" << std::endl;
		

		return 1; //return error code.
	}
	else { //yes there are parameters

		std::cout << "Maximum number of characters stored : ";
		std::cout << STORED << std::endl;

		for (int i = 1; i < argc; i++) {
		   process(argv[i]);
		}
	}

	return 0; //sucessful
}
//-----------------------------------------------------------------


