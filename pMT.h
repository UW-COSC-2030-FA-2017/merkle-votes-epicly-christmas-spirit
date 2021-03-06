/* File: pMT.h
   Author: Chris Schultz
   Date: 1 December 2017
   Description: Pseudo-Merkle Tree Header
   */

#pragma once

#include "bTREE.h"
#include <ctime>

using namespace std;
class pMT
{
private:
    int selectedHash;
    bTREE myMerkle;
    
    string hash_1(string stuff);
    string hash_2(string stuff);
    string hash_3(string stuff);
    
public:
    pMT(int);
    ~pMT();
    
    int insert(string, int);
	int find(string vote, int time, int hashSelect);
    int findHash(string);
    
    string locate(string);
	string locateHash(string mhash);
	void displayM(ostream& outFile);
    
    friend bool operator==(const pMT& lhs, const pMT& rhs);
    
    friend bool operator!=(const pMT& lhs, const pMT& rhs);
    
    friend pMT operator^(const pMT& lhs, const pMT& rhs);
    friend ostream& operator<<(std::ostream& out, const pMT& p);
    
};

