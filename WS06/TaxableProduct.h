#ifndef TAXABLE_H 
#define TAXABLE_H

#pragma once

#include "Product.h"
#include <vector>
#include <iostream>

namespace w7 {

#define NON 1.00
#define PST 1.08
#define HST 1.13

	    const double taxes[3] = { NON, PST, HST };

		class TaxableProduct : public Product {
		private:
			double tax = NON;

		public:
			TaxableProduct(int id, double cost, double type) : Product(id, cost), tax(type) {}
			double getCharge() const;
			void display(ostream& os) const;

		};

}


#endif 

