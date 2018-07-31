//------------------------------------------------------------
// OOP 345
// Workshop 04 - CONTAINERS
// Student: Andre R
// Std Id: 
// Date: 
// -----------------------------------------------------------

#include "Notifications.h"

namespace sict {

	//-----------------------------------------------------------------------
	Notifications::Notifications(std::ifstream& in) {

		this->_aMsg = new Message[aMsgSize];

		for (int i = 0; i < aMsgSize; i++) {
	
			//Message *lMsg = new Message(in, ' ');
			//delete this->_aMsg;
			this->_aMsg[i] = *new Message(in, ' ');
			//lMsg = nullptr;
	
		}

	}
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	Notifications::Notifications(Notifications&& src) {
		*this = std::move(src); ///move Constructor
	}
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	///@details Move Assignment Operator
	Notifications& Notifications::operator=(Notifications&& src) {

		if (this != &src) { //they are not the same
			delete[] this->_aMsg;
			this->_aMsg = src._aMsg; //redirects the address
			src._aMsg = nullptr;     //set the source pointer to null;
		}
		return *this;
	}
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	Notifications::~Notifications() {
		delete[] this->_aMsg;
	}
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	void Notifications::display(std::ostream& os) const {

		for (int i = 0; i < aMsgSize; i++) {
			if (this->_aMsg[i].isEmpty() == false) {
				this->_aMsg[i].display(os);
			}
		}

	} 
	//-----------------------------------------------------------------------

}