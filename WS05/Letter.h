//------------------------------------------------------------
// OOP 345
// Workshop 05 - Lambda Expressions
// Student: Andre
// Std Id: 
// Date: 14 JUN 2018
// -----------------------------------------------------------

#ifndef LETTER_H 
#define LETTER_H
#pragma once


#include <string>
using namespace std;

namespace sict {

	enum Letter { Ap, A, Bp, B, Cp, C, Dp, D, F };
	

	
	string grade; //**************
	template <typename T>
	string& converter(const T& letter) {

		//string grade; /// grade can not be declared here.... why?
		//Because I am returning the reference of this variable and when it gets out of scope it is destroyed!!!!

		switch (letter) {
		case Ap:
			grade = "A+"; break;
		case A:
			grade = "A"; break;
		case Bp:
			grade = "B+"; break;
		case B:
			grade = "B"; break;
		case Cp:
			grade = "C+"; break;
		case C:
			grade = "C"; break;
		case Dp:
			grade = "D+"; break;
		case D:
			grade = "D"; break;
		default:  //F
			grade = "F";
		}
		return grade;
	}

}
#endif