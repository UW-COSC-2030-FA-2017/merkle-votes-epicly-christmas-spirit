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
		treeNode * left;
		treeNode * right;
		bool isLeaf;
	};
    
private:
	treeNode * rootPtr;
	treeNode * root;
	queue <treeNode *> helpMe;
    
public:
	bTREE();
    ~bTREE();
    
    // usable functions
	int dataInserted();
    int numberOfNodes();
	void insert(string data, int time);
	void insertR(string data, int time);
	// void demolish(treeNode * &temp);
	int find(string toFind);
    string locate(string toFind);
	bool isLeaf();
    
	// helper functions
	int dataInserted(treeNode * temp);
	int numberOfNodes(const treeNode * temp);
	void insert(treeNode * &temp, queue <treeNode *> &q, string data, int time);
	void insertR(treeNode * &temp, string data, int time);
	int find(treeNode * temp, string toFind);
	string locate(treeNode * temp, string toFind);
	bool isLeaf(treeNode * temp);

	// display functions - referenced Lab 08
	void display(ostream& outfile);
	void displayLeft(ostream & outfile, treeNode * subtree, string prefix);
	void displayRight(ostream & outfile, treeNode * subtree, string prefix);
    
    // friend functions
	friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);
	friend ostream& operator<<(ostream& out, const bTREE b);
    
};

