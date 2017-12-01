/* File: vote.cpp
   Author: Chris Schultz
   Date: 1 December 2017
   Description: Binary Tree Driver File
   */

#include <stdio.h>
#include "bTree.h"
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

	cout << "The number of nodes in the tree is " << myTree.numberOfNodes() << "!" << endl;
	cout << "The number of data inserted is " << myTree.dataInserted() << "!" << endl;
	
	cout << "Gonna try to find 'IS IT FINALLY WORKING'!" << endl;
	cout << myTree.find("IS IT FINALLY WORKING");
	cout << endl;
	cout << myTree.find("sure whatever");

	cout << endl << "Everything checks out!" << endl;

	return 0;
}
