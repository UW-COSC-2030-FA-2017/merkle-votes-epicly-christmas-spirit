/* File: bTREE.cpp
   Author: Chris Schultz
   Date: 1 December 2017
   Description: Binary Tree Functions
   */

#include "bTREE.h"

// constructor sets the root to NULL, making empty tree
bTREE::bTREE() {
	rootPtr = NULL;
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

// calls helper function
int bTREE::find(string toFind) {
	return find(rootPtr, toFind);
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

string bTREE::locate(const treeNode * root, int theTime) {
	return "cool";
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

// returns the timestamp of whatever value is in the node
int bTREE::find(treeNode * temp, string toFind) {
	if (temp->bData == toFind) {
		return temp->tStamp;
	}
	else if (toFind != temp->bData) {
		return find(temp->left, toFind);
	}
	else if (temp == NULL) {
		return -1;
	} 
	else {
		return 0;
	}
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
}