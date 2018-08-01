
// iProduct COMMONS

#include "TaxableProduct.h"
#include <iomanip>
#include "Product.h"
#include "iProduct.h"

namespace w7 {

	iProduct* readProduct(std::ifstream& fs) {
		int index;
		double cost;
		char isTax;
		TaxableProduct *locTProd;
		Product *locProd;

		fs >> index >> cost;  //loads the two values
		isTax = fs.get();     
		if (isTax == ' ') { fs >> isTax; } //checks if there is tax and load

		if (isTax == 'H') {
			locTProd = new TaxableProduct(index, cost, HST);
			return locTProd;

		}
		
		if (isTax == 'P') {
			locTProd = new TaxableProduct(index, cost, PST);
			return locTProd;
		}

			locProd = new Product(index, cost);
			return locProd;
		
	}

	//------------------------------------------------
	std::ostream& operator<<(std::ostream& os, const iProduct& prod) {
		prod.display(os); //call the polymorphic function
		return os;
	}

	//------------------------------------------------
	//PRODUCT
	//------------------------------------------------
	void Product::display(ostream& os) const {
		os << std::fixed;        //use both lines to set two digits precision fixed as '3.20'
		os << std::setprecision(2);
		os << setw(10) << this->index;
		os << setw(10) << this->cost;
	}

	//------------------------------------------------
	//TAXABLE PRODUCT
	//------------------------------------------------
	void TaxableProduct::display(ostream& os) const {
		Product::display(os);
		if (this->tax == HST) {
			os << " HST";
		} else {
			os << " PST";
		}
	}
	//-------------------------------------------------
	double TaxableProduct::getCharge() const {
		const double lCost = Product::getCharge() * tax;
		return lCost;
	}

}