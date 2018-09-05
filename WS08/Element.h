/*
@author Andre R
@date Jul 2018
*/

#ifndef _ELEMENT_H
#define _ELEMENT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

extern const int FWC;
extern const int FWD;
extern const int FWP;

using namespace std;

namespace w9 { 

//-------------------------------------------------------------
///@class Description 
///@detail holds a procduct code and the description.
//-------------------------------------------------------------
	struct Description {
		unsigned code;
		std::string desc;
		//-----------------------------------------------------
		bool load(std::ifstream& f) {
			f >> code >> desc;
			return f.good();
		}
		//-----------------------------------------------------
		void display(std::ostream& os) const {
			os << std::setw(FWC) << code << std::setw(FWD)
				<< desc << std::endl;
		}
		//-----------------------------------------------------
	};
//-------------------------------------------------------------

//-------------------------------------------------------------
///@class Price 
///@detail holds a product code and the current price.
//-------------------------------------------------------------
	struct Price {
		unsigned code;
		double price;
		//-----------------------------------------
		bool load(std::ifstream& f) {
			f >> code >> price;
			return f.good();
		}
		//-----------------------------------------
		void display(std::ostream& os) const {
			os << std::setw(FWC) << code << std::setw(FWP)
				<< price << std::endl;
		}
		//-----------------------------------------
	};
//-------------------------------------------------------

//-------------------------------------------------------------
///@class Product 
///@detail holds a description and the product price
//-------------------------------------------------------------
	struct Product {
		std::string desc;
		double price;

		Product() {}
		//-------------------------------------------------
		Product(const std::string& str, double p) : desc(str), price(p) {}
		void display(std::ostream& os) const {
			os << std::setw(FWD) << desc << std::setw(FWP)
				<< price << std::endl;
		}
		//-------------------------------------------------
		void validade() {
			if (this->price < 0) {
				throw "*** Negative prices are invalid ***";
			}
		}
		//--------------------------------------------------
	};


} // end of namespace

#endif