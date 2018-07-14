//------------------------------------------------------------
// OOP 345
// Workshop 03 - Templates
// Student: Andre
// Std Id: 
// Date: 30 MAY 2018
// -----------------------------------------------------------

#ifndef KVLIST_H
#define KVLIST_H

template <typename K, typename V, int N>

///@class KVList
///@details holds two templated paralel arrays 
class KVList {
	K _KeyArray[N];
	V _ValArray[N];
	size_t _CountElm = 0;
	size_t _Size = N;

public:
	///@details Default constructor - creates an object in a safe empty state
	KVList() {
		size_t _CountElm = 0;
	}

	///@details A query that returns the number of entires in the key-value list
	size_t size() const {
		return (size_t)_CountElm;
	}
	///@details 
	///A query that returns an unmodifiable reference to the key 
	///of element i in the list; if i is out of bounds, returns a 
	///reference to the key for the first element
	const K& key(int i) const {
		if (((size_t)i < _Size) && ((size_t)i >= 0)) {
			return _KeyArray[i];
		}
		else {
			return _KeyArray[0];
		}
	}
	///@details
	///A query that returns an unmodifiable reference to the value 
	///of element i in the list; if i is out of bounds, returns a 
	///reference to the value for the first element
	const V& value(int i) const {
		
		if (((size_t)i < _Size) && ((size_t)i >= 0)) {
			return _ValArray[i];
		}
		else {
			return _ValArray[0];
		}
	}
	///@details
	///Adds a new element to the list if room exists and returns 
	///a reference to the current object, does nothing if no room exists
	KVList& add(const K& parK, const V& parV) {

		if (_CountElm < _Size) {
			_KeyArray[_CountElm] = parK;
			_ValArray[_CountElm] = parV;
			_CountElm++;
		}
		return *this;
	}
	///@details
	///Returns the index of the first element in the list 
	///with a key equal to k - defaults to 0
	int find(const K& k) const {
		int index = 0;
		for (size_t i = 0; i < _CountElm - 1; i++) {
			if (_KeyArray[i] == k) {
				index = i;
				i = _CountElm;
			}
		}
		return index;
	}
	///@details Replaces element i in the list with the key 
	///and value received and returns a reference to the current object
	KVList& replace(int i, const K& k, const V& v) {
		if (((size_t)i < _Size) && ((size_t)i >= 0)) {
			_KeyArray[i] = k;
			_ValArray[i] = v;
		}
		return *this;
	}
};

#endif