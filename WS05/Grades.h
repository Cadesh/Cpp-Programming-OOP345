//------------------------------------------------------------
// OOP 345
// Workshop 05 - Lambda Expressions
// Student: Andre
// Std Id: 
// Date: 14 JUN 2018
// -----------------------------------------------------------

#ifndef GRADES_H 
#define GRADES_H
#pragma once

#include <string>
#include <iomanip>


using namespace std;

namespace sict {

	class Grades {

	public:
		Grades(const char *); //constructor

		///receives a reference to the output stream object and the address 
		///of the expression to be used in determining the letter grade.  
		///Your function displays the student number, the student grade, and the letter equivalent as shown below on the right. 
		template <typename F>
		void displayGrades(std::ostream&os, F lambda) const;

		//Your design prohibits copying, moving and assigning.
		Grades(const Grades& ) = delete; ///Disabled Copy Constructor
		Grades(Grades&& ) = delete; ///Disabled Move constructor
		Grades& operator=(const Grades& ) = delete; ///Disabled Copy Assignment
		Grades&& operator=(Grades&& ) = delete; ///Disabled Move Assignment

	private:
		string * _aStd; ///< array to hold the students		
		double * _aGrd; ///< array to hold the grades
		size_t _size;   ///< Size to control pararel arrays

	};

	//--------------------------------------------------------------------------
	template <typename F>
	void Grades::displayGrades(std::ostream&os, F lambda) const {
		
		os << std::fixed;
		os << std::setprecision(2);
		for (size_t i = 0; i < _size; i++)
		{
			int grad = lambda(_aGrd[i]);
			string letter = converter(grad);
			//cout << converter(grad).length() << endl;
			
			os << _aStd[i] << ' ' ;
			os << _aGrd[i] << ' ' ;
			os << letter << "\n";
		}
	}
	//------------------------------------------------------------------------
}
#endif