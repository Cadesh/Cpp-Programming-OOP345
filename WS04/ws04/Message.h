//------------------------------------------------------------
// OOP 345
// Workshop 04 - CONTAINERS
// Student: Andre R
// Std Id: 
// Date: 
// -----------------------------------------------------------

#ifndef MESSAGE_H
#define MESSAGE_H

#include <fstream>
#include <string>

using namespace std;

namespace sict {

	///@class Message 
	///@details Holds a message composed by text, user origin and user destiny. 
	class Message {
	public:
		Message();
		Message(std::ifstream& in, char c); /// Constructor retrieves a record from the in file object, parses the record(as described above) and stores its components in the Message object.c is the character that delimits each record
		void display(std::ostream&) const;  /// Displays the Message objects within the container

		Message& operator=(const Message& src); ///Copy assignment
		bool isEmpty(); 

	private:
		//these private strings are Compositions, if the object is destroyed they are gone too
		string _Msg;   /// the text message
		string _Orig;  /// the user origin of the message
		string _Dest;  /// the user destiny of the message
	};
}

#endif