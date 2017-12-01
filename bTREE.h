/* File: bTREE.h
   Author: Chris Schultz
   Date: 1 December 2017
   Description: Binary Tree Class
   */

#pragma once
#include <string>
#include <queue>
#include <iostream>

using namespace std;

class bTREE
{
	struct treeNode {
		string bData;
		int tStamp;
		bool isLeaf;
		
		// need a special constructor for the insertion function
		// ooh so special
		treeNode(string data, int time) {
			this->bData = data;
			this->tStamp= time;
			this->left = NULL;
			this->right = NULL;
		}
		treeNode * left;
		treeNode * right;
	};
    
private:
	treeNode * rootPtr;
	queue <treeNode *> helpMe;
    
public:
	bTREE();
    ~bTREE();
    
    // just the normal stuff
	int dataInserted();
    int numberOfNodes();
	void insert(string data, int time);
	int find(string toFind);
	void demolish(treeNode * &temp);
	
	string locate(const treeNode * root, int time);
    string locate(string);
    
	// helper functions
	int numberOfNodes(const treeNode * temp);
	void insert(treeNode * &temp, queue <treeNode *> &q, string data, int time);
	int find(treeNode * temp, string toFind);

	// display functions - referenced Lab 08
	void bTREE::display(ostream& outfile);
	void bTREE::displayLeft(ostream & outfile, treeNode * subtree, string prefix);
	void bTREE::displayRight(ostream & outfile, treeNode * subtree, string prefix);
    
    // friend functions
	friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    friend std::ostream& operator<<(std::ostream& out, const bTREE& p);
    
};

