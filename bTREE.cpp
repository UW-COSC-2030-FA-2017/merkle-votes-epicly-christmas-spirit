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
	// demolish(rootPtr);
}

// calls helper function
int bTREE::dataInserted() {
	return dataInserted(rootPtr);
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

void bTREE::insertR(string data, int time) {
	insertR(rootPtr, data, time);
	return;
}

// for the destructor
// void bTREE::demolish(treeNode * &temp) {
	// if (temp != NULL) {
		// demolish(temp->left);
		// demolish(temp->right);
		// delete temp;
// 	}
// else if (temp == NULL) {
	// return;
// }
// }

// calls helper function
int bTREE::find(string toFind) {
	return find(rootPtr, toFind);
}

// calls helper function
string bTREE::locate(string toFind) {
	return locate(rootPtr, toFind);
}

// calls helper function
bool bTREE::isLeaf() {
	return isLeaf(rootPtr);
}

// HELPER FUNCTIONS -------------------------------------------------------------

// find the amount of data actually inserted into the tree
// should generally be the same as the number of nodes
int bTREE::dataInserted(treeNode * temp) {
	if (temp == NULL) {
		return 0;
	}
	else if (temp->left == NULL && temp->right == NULL) {
		return 1;
	}
	else {
		return 1 + (dataInserted(temp->left) + dataInserted(temp->right));
	}
}

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
	treeNode * stuff = new treeNode;
	stuff->bData = data;
	stuff->tStamp = time;
	stuff->left = NULL;
	stuff->right = NULL;
	if (temp == NULL) {
		temp = stuff;
	}
	else if (temp != NULL) {
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
	q.push(stuff);
	return;
}

// recursively insert a value into the tree - testing for an alternative method
// modded from -https://stackoverflow.com/questions/8183985/recursive-insertion-of-bst
// priorization of left tree for simplicity
void bTREE::insertR(treeNode * &temp, string data, int time) {
	if (temp == NULL) {
		treeNode * stuff = new treeNode;
		stuff->bData = data;
		stuff->tStamp = time;
		stuff->left = NULL;
		stuff->right = NULL;
		stuff->isLeaf = true;
		temp = stuff;
	}
	else if (temp->left == NULL){
		return insertR(temp->left, data, time);
	}
	else if (temp->right == NULL) {
		return insertR(temp->right, data, time);
	}
	else if (temp->left != NULL) {
		return insertR(temp->left, data, time);
	}
	else {
		return insertR(temp->right, data, time);
	}
	return;
}

// returns the number of operations it took to get the string
int bTREE::find(treeNode * temp, string toFind) {
	if (temp == NULL) {
		return 0;
	}
	else {
		int temp1 = 0, temp2 = 0;
		if (toFind == temp->bData) {
			return (temp1 + temp2 + 1);
		}
		else if (toFind != temp->bData) {
			temp1 = find(temp->left, toFind);
			temp2 = find(temp->right, toFind);
			return (temp1 + temp2 + 1);
		}
	}
}

// locates a string and returns the L-R path to find it
// based off of the find() function
string bTREE::locate(treeNode * temp, string toFind) {
	string testy1, testy2;
	if (temp == NULL) {
		return "empty";
	}
	else {
		if (toFind == temp->bData) {
			return (testy1 + testy2 + "-FINISH");
		}
		else if (toFind != temp->bData) {
			testy1 = testy1 + "-L-" + locate(temp->left, toFind);
			testy2 = testy2 + "-R-" + locate(temp->right, toFind);
			return testy1 + testy2;
		}
	}
	return testy1 + testy2;
}

// searches the left and right trees to test if the root node is a leaf
bool bTREE::isLeaf(treeNode * temp) {
	if (temp->left == NULL && temp->right == NULL) {
		return true;
	}
	else if (temp->left != NULL) {
		return isLeaf(temp->left);
	}
	else if (temp->right != NULL) {
		return isLeaf(temp->right);
	}
	else {
		return false;
	}
}

// DISPLAY FUNCTIONS ------------------------------------------------------------
// Lab 08 code from Tom Bailey
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

// OVERLOADED OPERATORS ---------------------------------------------------------
bool operator ==(const bTREE& left, const bTREE& right) {
	if ((left.rootPtr->bData == right.rootPtr->bData)
		&& (left.rootPtr->tStamp == right.rootPtr->tStamp)) {
		return true;
	}
	else {
		return false;
	}
}

bool operator !=(const bTREE& left, const bTREE & right) {
	if ((left.rootPtr->bData == right.rootPtr->bData)
		&& (left.rootPtr->tStamp == right.rootPtr->tStamp)) {
		return false;
	}
	else {
		return true;
	}
}

ostream& operator << (ostream& out, bTREE b) {
	b.display(cout);
	return out;
}