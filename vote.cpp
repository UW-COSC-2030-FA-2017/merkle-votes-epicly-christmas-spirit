/* File: vote.cpp
   Author: Chris Schultz
   Date: 1 December 2017
   Description: Binary Tree Driver File
   */

#include <stdio.h>
#include "bTree.h"
#include "pMT.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	// BTREE TEST SECTION -------------------------------------------------------
	cout << "Begin the program" << endl;
	bTREE myTree;
	myTree.insert("geez", 69);
	cout << "I inserted a thing!" << endl;
	myTree.insert("uhhuhuh", 1111);
	cout << "I inserted more things. " << endl;
	myTree.display(cout);
	
	cout << endl << endl << endl;
	
	myTree.insert("why would you do this", 1);
	myTree.insert("IS IT FINALLY WORKING", 10);
	myTree.insert("I THINK IT IS OH YEAH", 101010101);
	myTree.display(cout);

	cout << endl << endl << endl;

	cout << "The number of nodes in the tree is " << 
		myTree.numberOfNodes() << "!" << endl;
	cout << "The number of data inserted is " <<
		myTree.dataInserted() << "!" << endl;
	
	cout << "Gonna try to find 'IS IT FINALLY WORKING'!" << endl;
	cout << myTree.find("IS IT FINALLY WORKING") << 
		" operations to find the string!" << endl;
	cout << myTree.find("why would you do this") << 
		" operations to find 'why would you do this'!" << endl << endl;
	
	cout << myTree.locate("IS IT FINALLY WORKING");
	cout << endl << "everything is great now!" << endl;

	// MTREE TEST SECTION--------------------------------------------------------
	cout << endl << "making three pseudo-Merkle trees." << endl;
	pMT Merks1(1);
	pMT Merks2(2);
	pMT Merks3(3);
	cout << "They, indeed, have been made. " << endl;

	return 0;
}
