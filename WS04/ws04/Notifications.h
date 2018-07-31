//------------------------------------------------------------
// OOP 345
// Workshop 04 - CONTAINERS
// Student: Andre R
// Std Id: 
// Date:
// -----------------------------------------------------------

#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include "Message.h"

namespace sict {

	const int aMsgSize = 10;
	///@class KVList
	///@details holds two templated paralel arrays 
	class Notifications {
	public:

		Notifications(std::ifstream&); /// constructor
		Notifications(Notifications&&); /// move constructor
		Notifications& operator=(Notifications&&); /// move assignment operator
		~Notifications(); /// destructor
		void display(std::ostream& os) const; /// inserts the Message objects to the os output stream
	 
        ///both the copy constructor and copy assingment operator are deleted 
		Notifications(const Notifications&) = delete;
		Notifications& operator= (const Notifications&) = delete;

	private:
		//Message array is an aggregation
		Message *_aMsg;  ///Array of Messsage objects

	};

}

#endif