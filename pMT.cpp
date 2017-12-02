/* File: pMT.cpp
   Author: Chris Schultz
   Date: 1 December 2017
   Description: Pseudo-Merkle Class Functions
   */

#include "pMT.h"

// constructor, default to 1 if the integer is not 1,2, or 3
pMT::pMT(int hashSelect) {
	if (hashSelect == 1 || hashSelect == 2 || hashSelect == 3) {
		selectedHash = hashSelect;
	}
	else {
		selectedHash = 1;
	}
}

// it's another destructor. It's pretty cool stuff
pMT::~pMT() {
}

// inserts a vote and time into a node on the tree
// and returns the operations needed to insert
int pMT::insert(string vote, int time) {
	if (selectedHash >= 1 && selectedHash <= 3) {
		if (selectedHash == 1) {
			myMerkle.insert(hash_1(vote), time);
		}
		else if (selectedHash == 2) {
			myMerkle.insert(hash_2(vote), time);
		}
		else if (selectedHash == 3) {
			myMerkle.insert(hash_3(vote), time);
		}
		return myMerkle.dataInserted();
		}
	else{
		return -1;
	}
}

// searches for the vote, time, and hash and returns the operations to find it
int pMT::find(string vote, int time, int hashSelect) {
	int temp = 0;
	if (1 == (find(vote, time, selectedHash))) {
		temp++;
		return temp;
	}
	else {
		return temp;
	}
}

int pMT::findHash(string mhash) { 
	return myMerkle.find(mhash);
	return 0;
}

// uses locate() function to return the sequence
string pMT::locate(string vote) {
	return myMerkle.locate(vote);
}

// uses locate() function to return the sequence
string pMT::locateHash(string mhash) {
	return myMerkle.locate(mhash);
}

// cycles through and multiplies by the index value
string pMT::hash_1(string key) {
	unsigned int temp = 0;
	for (int i = 0; i < key.length(); i++) {
		temp = key[i] + (temp * i);
	}
	return to_string(temp);
}

// just multiplies by a constant
string pMT::hash_2(string key) {
	unsigned int temp = 0;
	int seed = 37;
	for (int i = 0; i < key.length(); i++) {
		temp = (temp * seed) + key[i];
	}
	return to_string(temp);
}

// uses base number 151 to multiply and then modulo
string pMT::hash_3(string key) {
	unsigned int hash = 0;
	for (int i = 0; i < key.length(); i++) {
		hash = 151 * hash + key[i];
		hash % 3;
		return to_string(hash);
	}
}

// the overloaded operator from bTREE.cpp should take care of this
bool operator ==(const pMT& lhs, const pMT& rhs) {
	if (lhs.myMerkle == rhs.myMerkle) {
		return true;
	}
	else {
		return false;
	}
}

// overloaded operator from bTREE.cpp should take care of this one too
bool operator !=(const pMT& lhs, const pMT& rhs) {
	if (lhs.myMerkle != rhs.myMerkle) {
		return true;
	}
	else {
		return false;
	}
}

// overloaded operator in bTREE.cpp should also do this
ostream& operator <<(ostream& out, const pMT& p) {
	out << p;
	return out;
}