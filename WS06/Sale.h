#ifndef SALE_H 
#define SALE_H

#pragma once

#include <vector>
#include <istream>
#include "TaxableProduct.h"

namespace w7 {

	///@Class Sale
	///@brief contain a vector of products/taxableProducts
	class Sale {
	public:
		Sale(const char*);
		~Sale();
		void display(std::ostream& os) const;

	private:
		    //note the pointer to objects of abstract class iProduct
			vector <iProduct*> vecProd; /// Holds information about the set of products sold to a customer 

	};

}

#endif