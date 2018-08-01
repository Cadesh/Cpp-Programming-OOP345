

#include "Sale.h"

using namespace std;

namespace w7 {
	//-------------------------------------------------
	Sale::~Sale() { 
		for (vector<iProduct*>::iterator it = vecProd.begin(); it != vecProd.end(); ++it) {
			delete *it;
		}
	} 
	//-------------------------------------------------
	Sale::Sale(const char* fname) {

		ifstream fs(fname, ios::out);

		if (fs.fail() == true) {
			cout << "Cannot open file." << endl;
		}
		else {
			while (fs) {
				vecProd.push_back(readProduct(fs));
			} //while		
		} //else
	} //Sale Constructor

	//-------------------------------------------------
	void Sale::display(ostream& os) const {

		double total = 0;

		os << "Product No      Cost Taxable" << endl;
		
		//can not use iterator because the display function is const?
		for (unsigned int i =0; i < vecProd.size(); i++) {
			os << *vecProd[i]; //NOTE THE * without the * the code calls the default << operator!!!!
			os << endl;
			total += vecProd[i]->getCharge();
		}
		total = (100 * total) / 100;
		os << "     Total" << setw(10)  << total << endl;
	}
	//------------------------------------------------
} //namespace