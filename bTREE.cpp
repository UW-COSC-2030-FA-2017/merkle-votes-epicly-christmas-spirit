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

// calls helper function
string bTREE::locate(int theTime) {
	return locate(rootPtr, theTime);
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
	// creates a temporary "stuff" node to work with the queue
	treeNode * stuff = new treeNode(data, time);
	// if temp exists
	if (temp != NULL) {
		// "prev" node is assigned to the front of the queue
		treeNode * prev = q.front();
		// if the left subtree doesn't exist, assign "stuff" to it
		if (prev->left == NULL) {
			prev->left = stuff;
		}
		// if the right subtree doesn't exist, assign "stuff" to it
		else if (prev->right == NULL) {
			prev->right = stuff;
		}
		// if the node and the left and right pointers all exist, pop off top of queue
		if (temp != NULL && temp->left != NULL && temp->right != NULL) {
			q.pop();
		}
	}
	// if the node does not exist, assign "stuff" to it
	else if (temp == NULL) {
		temp = stuff;
	}
	// then push the assigned data into the queue
	q.push(stuff);
	return;
}

// returns the timestamp of whatever value is in the node
int bTREE::find(treeNode * temp, string toFind) {
	if (temp->bData == toFind) {
		return temp->tStamp;
	}
	else if (toFind != temp->bData && temp == NULL) {
		return -1;
	}
	else if (toFind != temp->bData) {
		if (temp->left) {
			return find(temp->left, toFind);
		}
		else if (temp->right) {
			return find(temp->right, toFind);
		}
	}
}

// searching the tree by time stamp
string bTREE::locate(treeNode * temp, int theTime) {
	if (temp->tStamp == theTime) {
		return temp->bData;
	}
	else if (theTime != temp->tStamp) {
		return locate(temp->left, theTime);
	}
	else if (theTime != temp->tStamp && temp == NULL) {
		return "";
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

void bTREE::displayLeft(ostream & outfile, treeNode * temp, string prefix) {
	if (temp == NULL) {
		outfile << prefix + "/" << std::endl;
	}
	else {
		displayLeft(outfile, temp->left, prefix + "       ");
		outfile << prefix + "/-----" << temp->bData << endl;
		displayRight(outfile, temp->right, prefix + "|      ");
	}
}

void bTREE::displayRight(ostream & outfile, treeNode * temp, string prefix) {
	if (temp == NULL) {
		outfile << prefix + "\\" << std::endl;
	}
	else {
		displayLeft(outfile, temp->left, prefix + "|      ");
		outfile << prefix + "\\-----" << temp->bData << endl;
		displayRight(outfile, temp->right, prefix + "       ");
	}
}

