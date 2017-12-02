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
/**
 * @brief given a vote, timestamp, and hash function, does this vote exist in the tree?
 * @param vote, a string
 * @param time, an int
 * @param hashSelect, an int corresponding to the hash functions _1, _2, and _3
 * @return 0 if not found, else number of opperations required to find the matching vote
 */

int pMT::findHash(string mhash) { 
	return 0;
}
/**
 * @brief does this hash exist in the tree?
 * @param mhash, a string to search for in the tree
 * @return 0 if not found, else number of opperations required to find the matching hash
 */

string pMT::locate(string vote) {
	return "cool";
}
/**
 * @brief Function takes a hash of Vote and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root. 
 * @param vote, the data to search for 
 * @return sequence of L's and R's comprising the movement to the leaf node; else return a dot '.'
 */

string pMT::locateHash(string mhash) {
	return "more stuff";
}
/**
 * @brief Function takes a hash and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root. 
 * @param mhash, the hash to search for 
 * @return sequence of L's and R's comprising the movement to the hash node, ; else return a dot '.'
 */


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
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */

// friend bool pMT::operator ==(const pMT& lhs, const pMT& rhs)
/**
 * @brief Comparison between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if equal, false otherwise
 */

// friend bool pMT::operator !=(const pMT& lhs, const pMT& rhs)
/**
 * @brief Comparison between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if not equal, false otherwise
 */

// friend pMT pMT::operator ^=(const pMT& lhs, const pMT& rhs)
/**
 * @brief XOR between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if not equal, false otherwise
 */


// friend std::ostream& pMT::operator <<(std::ostream& out, const pMT& p)
/**
 * @brief Print out a tree
 * @param out
 * @param p
 * @return a tree to the screen
 */

// friend pMT pMT::operator ^(const pMT& lhs, const pMT& rhs)
/**
 * @brief Where do two trees differ
 * @param lhs
 * @param rhs
 * @return a tree comprised of the right hand side tree nodes that are different from the left
 */
