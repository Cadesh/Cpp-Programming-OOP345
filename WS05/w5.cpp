// Workshop 5 - Lambda Expression
// w5.cpp
// 2018-05-23
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr <<
			"\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}


	try {
		sict::Grades grades(argv[1]);

		// lambda expression for converting to letter 
		// defining the lambda expression (letter) that converts a numeric grade to its letter equivalent
		//enum Letter { Ap, A, Bp, B, Cp, C, Dp, D, F };
		auto letter = [](double grade)
		{
			int grd;
			if ((grade >= 90) && (grade <= 100)) { grd = Ap; }
			else if ((grade >= 80) && (grade < 90)) { grd = A; }
			else if ((grade >= 75) && (grade < 80)) { grd = Bp; }
			else if ((grade >= 70) && (grade < 75)) { grd = B; }
			else if ((grade >= 65) && (grade < 70)) { grd = Cp; }
			else if ((grade >= 60) && (grade < 65)) { grd = C; }
			else if ((grade >= 55) && (grade < 60)) { grd = Dp; }
			else if ((grade >= 50) && (grade < 55)) { grd = D; }
			else { grd = F; }

			return grd;
		};
		grades.displayGrades(std::cout, letter);

	}
	catch (const char *msg) {
		// report the error message
		std::cerr << argv[0] << msg << argv[1] << "\n";
	}
	return 2;
}
 