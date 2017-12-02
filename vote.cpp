/* File: vote.cpp
   Author: Chris Schultz
   Date: 1 December 2017
   Description: Binary Tree Driver File
   */

#include <stdio.h>
#include "bTree.h"
#include "pMT.h"
#include <iostream>
#include <fstream>
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
	cout << endl << "everything is great now!" << endl << endl;
	cout << myTree;
	cout << endl;

	// MTREE TEST SECTION--------------------------------------------------------
	cout << "---------------------------MTREE TEST SECTION--------------------------";
	ifstream theFile, theFile2;
	string data;
	int time;

	theFile.open("mv_test.txt");
	
	cout << endl << "Hash function 1 " << endl;
	pMT TheMerk(1);

	while (!theFile.eof()) {
		theFile >> data >> time;
		TheMerk.insert(data, time);
	}
	theFile.close();

	cout << endl << "Will create another sheet to compare. " << endl;
	theFile.open("mv_text.txt");
	cout << "Hash function 2 " << endl;
	pMT SecondMerk(2);
	
	while (!theFile.eof()) {
		theFile >> data >> time;
		SecondMerk.insert(data, time);
	}
	theFile.close();

	cout << "Will test to see if the trees are the same!" << endl;
	if (TheMerk == SecondMerk) {
		cout << "They are!" << endl;
	}
	else {
		cout << "The two trees are unequal. " << endl;
	}

	cout << endl << "Here is the tree!" << endl << endl;
	cout << TheMerk;
	cout << endl << "And here is the second tree. " << endl << endl;
	cout << SecondMerk;
	return 0;
}
