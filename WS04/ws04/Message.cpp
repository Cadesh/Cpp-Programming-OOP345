//------------------------------------------------------------
// OOP 345
// Workshop 04 - CONTAINERS
// Student: Andre R
// Std Id:
// Date: 
// -----------------------------------------------------------

#include "Message.h"

#include <iostream>
using namespace std;

namespace sict {


	Message::Message() {
		
		this->_Orig.clear();
		this->_Dest.clear();
		this->_Msg.clear();
	}

	//--------------------------------------------------------
	Message::Message(std::ifstream& in, char c) {

		Message tempMsg; //create a temporary message object
		string Line; //holds a full line frm file
		string tempStr;

		//gets the full line
		getline(in, Line);

		// if can not find any separator in the line just exits
		if (Line.find(" ") == string::npos) {
			return;
		}

		size_t index = Line.find(" "); //get the first separator index

		//gets the first info form the file
		tempStr = Line.substr(0, index);
		tempMsg._Orig = tempStr;
		//cout << "first parse: " << tempStr << endl;

		//erases the first part of the line up to separator
		Line = Line.substr(index+1, Line.length());
		//cout << "second parse: " << Line << endl;

		if (Line != " ") { //if the message is not just a space hanging around....
			if (Line.find("@") == 0) { //there is a msg destination
			    index = Line.find(" "); 
				tempStr = Line.substr(0, index);
				//now we must erase the '@' from the destination
				tempStr = tempStr.substr(1, tempStr.length());
				tempMsg._Dest = tempStr;
				//get the msg text
				Line = Line.substr(index+1, Line.length());
				tempMsg._Msg = Line;
			}
			else { //message text only
				tempMsg._Msg = Line;
			}
		}

		//cout << tempMsg._Orig << " " << tempMsg._Dest << " " << tempMsg._Msg << endl;

		if (!tempMsg._Msg.empty()) {//if the message text is not empty it is a valid message
			*this = tempMsg; // use the copy assignment
		}

	}
	//--------------------------------------------------------
	//--------------------------------------------------------
	void Message::display(std::ostream& out) const {

		out << "Message" << endl;
		out << " User  : " << this->_Orig << endl;
		if (this->_Dest.empty() == false) {
			out << " Reply : " << this->_Dest << endl;
		}
		out << " Tweet : " << this->_Msg << endl << endl;

	}
	//--------------------------------------------------------
	//--------------------------------------------------------
	Message& Message::operator=(const Message& src) {

		if (this != &src) { //they are not the same
			this->_Orig = src._Orig; 
			this->_Dest = src._Dest;
			this->_Msg = src._Msg;
		}
		return *this;
	}
	//--------------------------------------------------------
	//--------------------------------------------------------
	bool Message::isEmpty() {
	     
		if (this->_Orig.empty() == true) {
			return true;
		}
		return false;
	}

}