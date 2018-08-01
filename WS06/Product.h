#ifndef PRODUCT_H 
#define PRODUCT_H

#pragma once

#include "iProduct.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace w7 {

	class Product : public iProduct {

	private:
		int index;
		double cost;

	public:
		Product(int id, double cost) : index(id), cost(cost) { }
		double getCharge() const { return cost; }
		void display(ostream& os) const;
	};

}

#endif