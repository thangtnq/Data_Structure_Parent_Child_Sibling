//-----------------------------------------------------------------------------
// Copyright 2020, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef PCSTREE_H
#define PCSTREE_H

// forward declare
class PCSNode;

// PCSTree class 
class PCSTree
{
public:
	// Simple data structure
	struct Info
	{
		int currNumNodes;
		int maxNumNodes;
		int currNumLevels;
		int maxNumLevels;
	};

public:
	// constructor
	PCSTree();

	// copy constructor 
	PCSTree(const PCSTree &in) = delete;

	// assignment operator
	PCSTree & operator = (const PCSTree &in) = delete;

	// destructor
	~PCSTree();

	// get Root
	PCSNode *GetRoot() const;

	// insert
	void Insert(PCSNode * const pInNode, PCSNode * const pParent);

	// remove
	void Remove(PCSNode * const pInNode);

	// get info
	void GetInfo(Info &info);
	void Print() const;

private:

	// Data
	Info	mInfo;
	PCSNode *pRoot;

	void set_Everything_To_Null(PCSNode* const target);
	int totalChild(PCSNode* const target);
	void removeNodeHelper(PCSNode* target);
	void newDepth(PCSNode* target, int& count);
	void currentNumLevelHeper(PCSNode* const pInNode, int& info);
	void printTreeHelper(PCSNode* const pNode) const;
};

#endif

// ---  End of File ---------------
