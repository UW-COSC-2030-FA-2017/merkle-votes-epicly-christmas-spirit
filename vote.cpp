/* File: vote.cpp
   Author: Chris Schultz
   Date: 1 December 2017
   Description: Binary Tree Driver File
   */

#include <stdio.h>
#include "bTree.h"
#include "pMT.h"
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
	// BTREE TEST SECTION -------------------------------------------------------
	// I cleaned it up and made some user input to test the functions
	int selector = 0;
	string userFile = "";
	int userTime = 0;

	cout << "---------------bTREE test section!---------------" << endl;
	bTREE UserTree;
	cout << "I created a Binary Tree for you!" << endl;
	while (selector != -9999) {
		cout << "Select an option. What do you want to do? " << endl;
		cout << "(1) Insert a new node." << endl;
		cout << "(2) Count the nodes currently in the tree." << endl;
		cout << "(3) Find the amount of data present in the tree. " << endl;
		cout << "(4) Find a path to a given string. " << endl;
		cout << "(5) Find the number of operations it takes to get to a string." << endl;
		cout << "(6) Display the tree for me!" << endl;
		cout << "(-9999) Exit to Merkle Tree Section! ";
		cin >> selector;
		if (selector != -9999) {
			switch (selector) {
			case 1:
				cout << endl << "Please enter a string to input into the tree. ";
				cin.clear();
				cin.ignore();
				getline(cin, userFile);
				cout << endl << "Now, enter an integer timestamp. ";
				cin.clear();
				cin.ignore();
				cin >> userTime;
				UserTree.insertR(userFile, userTime);
				cout << "Inserted some data for you!" << endl << endl;
				break;
			case 2:
				cout << endl << "There are " << UserTree.numberOfNodes() <<
					" nodes in the tree!" << endl << endl;
				break;
			case 3:
				cout << endl << "There are " << UserTree.dataInserted() <<
					" nodes with data in the tree!" << endl << endl;
				break;
			case 4:
				cout << endl << "What is the string you wish to search for? ";
				cin.ignore();
				getline(cin, userFile);
				cout << UserTree.locate(userFile) << endl << endl;
				break;
			case 5:
				cout << endl << "What is the string you wish to search for? ";
				cin.ignore();
				getline(cin, userFile);
				cout << "It took " << UserTree.find(userFile) <<
					" operations to find the string! " << endl << endl;
				break;
			case 6:
				cout << endl << UserTree << endl << endl;
				break;
			default:
				cout << endl << "Sorry, could not perform the action for you. "
					<< endl << endl;
			}
		}
	}

	// MTREE TEST SECTION -------------------------------------------------------
	int userIn = 0;
	int hasher = 0;
	string vote;
	int time = 0;
	fstream theFile;
	fstream otherFile;
	
	cout << endl;
	cout << "---------------mTREE test section!---------------" << endl;
	while (hasher != 1 || hasher != 2 || hasher != 3) {
		cout << "Please enter an integer to use for the hash function "
			"for the tree. " << endl;
		cout << "1, 2, and 3 are valid. ";
		cin >> userIn;
		cout << endl;
		if (userIn == 1 || userIn == 2 || userIn == 3) {
			hasher = userIn;
			break;
		}
		else {
			cout << "Invalid input." << endl;
		}
	}

	// This creates the different Merkle Trees for use.
	pMT MyMerkle = pMT(hasher);
	pMT CompMerkle = pMT(1);
	pMT SecondMerkle = pMT(2);
	pMT ThirdMerkle = pMT (3);
	pMT DiffMerkle = pMT(1);
	cout << "I created a Merkle Tree for you!" << endl;
	theFile.open("mv_test.txt");
	
	if (!theFile) {
		cout << "Could not open the test file." << endl;
	}
	else {
		while (theFile >> vote >> time){
			MyMerkle.insert(vote, time);
		}
	}
	cout << endl << "I inserted a bunch of data! " << endl;
	cout << "Now I will create some different Merkle Trees. " << endl;
	while (theFile >> vote >> time) {
		CompMerkle.insert(vote, time);
	}
	cout << "Comparison tree created. Creating a second tree with a "
		"different hash function. " << endl;
	while (theFile >> vote >> time) {
		SecondMerkle.insert(vote, time);
	}
	cout << "Second tree created. Creating a third tree with the " 
		"last hash function. " << endl;
	while (theFile >> vote >> time) {
		ThirdMerkle.insert(vote, time);
	}
	cout << "Third tree created. Creating a final tree with a new "
		"set of data. " << endl;
	otherFile.open("mv_test2.txt"); 
	while (otherFile >> vote >> time) {
		DiffMerkle.insert(vote, time);
	}
	cout << endl << "All trees created!" << endl << endl;
	theFile.close();
	otherFile.close();

	// Merkle Comparison Section
	userIn = 0;
	while (userIn != -9999) {
		cout << "What would you like to do with the constructed Merkle Tree? " << endl;
		cout << "(1) Compare to a tree constructed from the first hash function. " << endl;
		cout << "(2) Compare to a tree constructed from the second hash function. " << endl;
		cout << "(3) Compare to a tree constructed from the third hash function. " << endl;
		cout << "(4) Display the first tree we have created. " << endl;
		cout << "(5) Compare it to a tree with a different set of data. " << endl;
		cout << "(-9999) Quit the program like a nerd " << endl;
		cin >> userIn;
		cout << endl;
		if (userIn != -9999) {
			switch (userIn) {
			case 1:
				cout << "I will compare the first Merkle tree and the "
					"identical comparison tree." << endl;
				if (MyMerkle == CompMerkle) {
					cout << "Validated: Trees are identical." << endl;
				}
				else {
					cout << "Not Validated. " << endl;
				}
				break;
			case 2:
				cout << "I will compare the first Merkle tree to one "
					"created with a different hash." << endl;
				if (MyMerkle == SecondMerkle) {
					cout << "Validated: Trees are identical. " << endl;
				}
				else {
					cout << "Not validated." << endl;
				}
				break;
			case 3:
				cout << "I will compare the first Merkle tree to one "
					"created with the third hash function. " << endl;
				if (MyMerkle == ThirdMerkle) {
					cout << "Validated: Trees are identical. " << endl;
				}
				else {
					cout << "Not validated." << endl;
				}
				break;
			case 4:
				cout << endl << MyMerkle << endl;
				break;
			case 5:
				cout << " I will compare the first Merkle tree to one "
					"with an entirely different set of data. " << endl;
				if (MyMerkle == DiffMerkle) {
					cout << "Validated: Trees are identical. " << endl;
				}
				else {
					cout << "Not validated. " << endl;
				}
				break;
			default:
				cout << "I do not recognize that command. " << endl;
			}
		}
	}

	cout << "Thanks for using this program! Exiting now. ";
	return 0;
}
