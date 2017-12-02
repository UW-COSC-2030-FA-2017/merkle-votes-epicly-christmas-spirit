/* File: bTREE.cpp
   Author: Chris Schultz
   Date: 1 December 2017
   Description: Binary Tree Functions
   */

#include "bTREE.h"

// constructor sets the root to NULL, making empty tree
bTREE::bTREE() {
	rootPtr = NULL;
	counter = 0;
}

// it's a destructor. it calls the DEMOLISH function
bTREE::~bTREE() {
	demolish(rootPtr);
}

// will be the same as the Number of Nodes because data will always be inserted
int bTREE::dataInserted() {
	return numberOfNodes(rootPtr);
}

// calls helper function 
int bTREE::numberOfNodes() {
 	return numberOfNodes(rootPtr);
 }

// calls helper function
void bTREE::insert(string data, int time) {
	insert(rootPtr, helpMe, data, time);
	return;
}

// for the destructor
void bTREE::demolish(treeNode * &temp) {
	if (temp != NULL) {
		demolish(temp->left);
		demolish(temp->right);
		delete temp;
	}
	return;
}

// calls helper function
int bTREE::find(string toFind) {
	return find(rootPtr, toFind);
}

// calls helper function
string bTREE::locate(string toFind) {
	return locate(rootPtr, toFind);
}

// HELPER FUNCTIONS -------------------------------------------------------------

// count the number of total nodes in the tree!
int bTREE::numberOfNodes(const treeNode * temp) {
	if (temp == NULL) {
		return 0;
	}
	else {
		return 1 + numberOfNodes(temp->left) + numberOfNodes(temp->right);
	}
}

// insert a value into the tree! uses a queue and just alternates between "left" and "right"
void bTREE::insert(treeNode * &temp, queue <treeNode *> &q, string data, int time) {
	treeNode * stuff = new treeNode(data, time);
	if (temp != NULL) {
		treeNode * prev = q.front();
		if (prev->left == NULL) {
			prev->left = stuff;
		}
		else if (prev->right == NULL) {
			prev->right = stuff;
		}
		if (temp != NULL && temp->left != NULL && temp->right != NULL) {
			q.pop();
		}
	}
	else if (temp == NULL) {
		temp = stuff;
	}
	q.push(stuff);
	return;
}

// returns the number of operations it took to get the string
int bTREE::find(treeNode * temp, string toFind) {
	if (temp == NULL) {
		return 0;
	}
	int temp1 = 0, temp2 = 0;
	if (toFind == temp->bData) {
		return (temp1 + temp2 + 1);
	}
	else if (toFind != temp->bData) {
		temp1 = find(temp->left, toFind);
		temp2 = find(temp->right, toFind);
	}
	return (temp1 + temp2 + 1);
}

// locates a string and returns the L-R path to find it
// this straight up doesn't work. come back to it
string bTREE::locate(treeNode * temp, string toFind) {
	string test;
	if (temp == NULL) {
		return "empty tree";
	}
	else if (toFind == temp->bData) {
		test = test + "-END";
		return test;
	}
	else if (temp->left->bData == toFind) {
		test = test + "-L-";
		return locate(temp->left, toFind);
	}
	else if (temp->right->bData == toFind) {
		test = test + "-R-";
		return locate(temp->right, toFind);
	}
	else if (temp->left != NULL) {
		return locate(temp->left, toFind);
	}
	else if (temp->right != NULL) {
		return locate(temp->right, toFind);
	}
	return test;
}

// DISPLAY FUNCTIONS ------------------------------------------------------------
void bTREE::display(ostream& outfile) {
	std::string prefix;
	if (rootPtr == NULL) {
		outfile << "-" << std::endl;
	}
	else {
		displayLeft(outfile, rootPtr->left, "      ");
		outfile << "-----" << rootPtr->bData << endl;
		displayRight(outfile, rootPtr->right, "      ");
	}
}

void bTREE::displayLeft(ostream & outfile, treeNode * subtree, string prefix) {
	if (subtree == NULL) {
		outfile << prefix + "/" << std::endl;
	}
	else {
		displayLeft(outfile, subtree->left, prefix + "       ");
		outfile << prefix + "/-----" << subtree->bData << endl;
		displayRight(outfile, subtree->right, prefix + "|      ");
	}
}

void bTREE::displayRight(ostream & outfile, treeNode * subtree, string prefix) {
	if (subtree == NULL) {
		outfile << prefix + "\\" << std::endl;
	}
	else {
		displayLeft(outfile, subtree->left, prefix + "|      ");
		outfile << prefix + "\\-----" << subtree->bData << endl;
		displayRight(outfile, subtree->right, prefix + "       ");
	}
	return;
}