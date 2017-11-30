/* File: bTREE.cpp
   Author: Chris Schultz
   Date: 1 December 2017
   Description: Binary Tree Functions
   */

#include "bTREE.h"

//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
// constructor sets the root to NULL, making empty tree
bTREE::bTREE() {
	root == NULL;
}

// it's a destructor. it calls the DEMOLISH function
bTREE::~bTREE() {
	demolish(root);
}

// not sure what to do with this function. come back to it
int bTREE::dataInserted(const treeNode * root) {
	return 1;
}

int bTREE::numberOfNodes() {
	return numberOfNodes(root);
}

// insert a value into the tree!
int bTREE::insert(string data, int time) {
	return insert(root, data, time);
}



int bTREE::find(const treeNode * root, string toFind) {
	if (root->data == toFind) {
		return root->time;
	}
	else if (toFind != root->data) {
		return find(root->left, toFind);
	}
	else if (root == NULL) {
		return 0;
	}
}

void bTREE::demolish(treeNode * root) {
	if (root != NULL) {
		demolish(root->left);
		demolish(root->right);
		delete[] root;
		root = NULL;
	}
}

string bTREE::locate(const treeNode * root, int theTime) {
	if (root->time == theTime) {
		return root->data;
	}
	else if (root->time != theTime) {
		return locate(root->left, theTime);
	}
}

// friend bool bTREE::operator ==(const bTREE& lhs, const bTREE& rhs) {
// }

// friend bool bTREE::operator !=(const bTREE& lhs, const bTREE& rhs) {
// }

// friend std::ostream& bTREE::operator <<(std::ostream& out, const bTREE& p) {
// }

// HELPER FUNCTIONS -------------------------------------------------------------

// recursively count the number of nodes
int bTREE::numberOfNodes(const treeNode * root) {
	if (root == NULL) {
		return 0;
	}
	else if (root != NULL) {
		return (numberOfNodes(root->left) + 1 + numberOfNodes(root->right));
	}
}

// insert a string value into the tree, semi-sorting the strings
int bTREE::insert(treeNode * root, string data, int time) {
	if (root == NULL) {
		treeNode * newRoot = new treeNode;
		root = newRoot;
		root->data = data;
		root->time = time;
	}
	else {
		if (data >= root->data) {
			return insert(root->right, data, time);
		}
		else if (data < root->data) {
			return insert(root->left, data, time);
		}
	}
}