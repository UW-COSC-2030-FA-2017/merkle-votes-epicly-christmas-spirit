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
	bTREE test1;
	cout << "Initializing the program." << endl;
	cout << "There are " << test1.numberOfNodes() << 
		" nodes all together in the tree. " << endl;
	test1.insert("cool stuff", 42);
	cout << "There is now " << test1.numberOfNodes() <<
		" node in the tree!" << endl;

	return 0;
}
