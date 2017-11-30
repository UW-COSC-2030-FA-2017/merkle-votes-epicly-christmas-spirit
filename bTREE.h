/* File: bTREE.h
Author: Chris Schultz
Date: 1 December 2017
Description: Binary Tree Class
*/

#pragma once
#include <string>
using namespace std;

class bTREE
{
    struct treeNode{
        string data;
        int time;
		bool isLeaf;

		treeNode * left;
		treeNode * right;
    };
    
private:
    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need
	treeNode * root;
	int numberOfNodes(const treeNode * root);
	int insert(treeNode * root, string data, int time);
    
public:
	bTREE();
    ~bTREE();
    
    int dataInserted(const treeNode * root);
    int numberOfNodes();
	int insert(string data, int time);
	int find(const treeNode * root, string toFind);
	void demolish(treeNode * root);
	
	string locate(const treeNode * root, int theTime);
    string locate(string);
    
    
    friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    friend std::ostream& operator<<(std::ostream& out, const bTREE& p);
    
};

