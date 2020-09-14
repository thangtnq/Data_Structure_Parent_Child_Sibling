//-----------------------------------------------------------------------------
// Copyright 2020, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "PCSTree.h"
#include "PCSNode.h"

// constructor
PCSTree::PCSTree() :
	pRoot(nullptr)
{
	mInfo = { 0,0,0,0 };
};

// destructor
PCSTree::~PCSTree()
{
};


// get Root
PCSNode *PCSTree::GetRoot() const
{
	return this->pRoot;
}


// insert
void PCSTree::Insert(PCSNode * const pInNode, PCSNode * const pParent)
{
	//check if pInNode is valid
	if (pInNode == nullptr)
	{
		return;
	}

	//case parent does not exist
	if (pParent == nullptr)
	{
		this->pRoot = pInNode;
		this->set_Everything_To_Null(this->pRoot);
		this->mInfo = { 1,1,1,1 };
	}

	//there is an existing parent
	else
	{
		//Case 1: No child is at base
		if (pParent->GetChild() == nullptr)
		{
			pParent->SetChild(pInNode);
			pInNode->SetParent(pParent);

			//check if depth needs to be increased by going back to the root
			int depth = 1;
			PCSNode* currentNode = pParent;
			while (currentNode != nullptr)
			{
				depth++;
				currentNode = currentNode->GetParent();
			}

			if (depth > this->mInfo.maxNumLevels)
			{
				this->mInfo.currNumLevels++;
				this->mInfo.maxNumLevels++;
			}
		}

		//Case 2: there is an existing child at base
		else
		{
			PCSNode* firstSibling = pParent->GetChild();
			firstSibling->SetPrevSibling(pInNode);
			pInNode->SetNextSibling(firstSibling);
			pInNode->SetParent(pParent);
			pParent->SetChild(pInNode);
		}

		this->mInfo.currNumNodes++;
		if (this->mInfo.maxNumNodes < mInfo.currNumNodes)
		{
			this->mInfo.maxNumNodes = this->mInfo.currNumNodes;
		}
	}

}

void PCSTree::set_Everything_To_Null(PCSNode* const target)
{
	target->SetChild(nullptr);
	target->SetParent(nullptr);
	target->SetNextSibling(nullptr);
	target->SetPrevSibling(nullptr);
}

int PCSTree::totalChild(PCSNode* const target) {
	PCSNode* currentChild = target->GetChild();
	PCSNode* currentSibling = currentChild;

	int total = 0;
	while (currentSibling != nullptr) {
		int count = totalChild(currentSibling) + 1;
		total += count;
		currentSibling = currentSibling->GetNextSibling();
	}

	return total;
}

void PCSTree::removeNodeHelper(PCSNode* target) {

	PCSNode* currChild = target->GetChild();
	PCSNode* nextChild = nullptr;
	while (currChild != nullptr)
	{
		nextChild = currChild->GetNextSibling();
		removeNodeHelper(currChild);
		currChild = nextChild;
	}

	this->set_Everything_To_Null(target);
}

void PCSTree::newDepth(PCSNode* target, int& count) {
	if (target->GetChild() != nullptr) {
		PCSNode* currentChild = target->GetChild();
		while (currentChild != nullptr) {
			newDepth(currentChild, count);
			currentChild = currentChild->GetNextSibling();
		}
	}
	else {
		int depth = 0;
		PCSNode* currentNode = target;
		while (currentNode != nullptr) {
			depth++;
			currentNode = currentNode->GetParent();
		}

		if (depth > count) {
			count = depth;
		}

		PCSNode* nextNode = target->GetNextSibling();
		if (nextNode != nullptr) {
			newDepth(nextNode, count);
		}
	}
}

void PCSTree::currentNumLevelHeper(PCSNode* const pInNode, int& info) {
	int depth = 0;
	newDepth(pInNode, depth);
	info = depth;
}

// Remove
void PCSTree::Remove(PCSNode * const pInNode)
{
	//check if pInNode is valid
	if (pInNode == nullptr)
	{
		return;
	}

	if (pInNode->GetParent() == nullptr) {
		this->pRoot = nullptr;
		this->mInfo.currNumLevels = 0;
		this->mInfo.currNumNodes = 0;
		removeNodeHelper(pInNode);
	}
	else
	{
		this->mInfo.currNumNodes--;

		PCSNode* prevNode = pInNode->GetPrevSibling();
		PCSNode* nextNode = pInNode->GetNextSibling();

		//remove middle node

		this->mInfo.currNumNodes -= totalChild(pInNode);

		if (prevNode != nullptr && nextNode != nullptr)
		{
			prevNode->SetNextSibling(nextNode);
			nextNode->SetPrevSibling(prevNode);
			pInNode->SetParent(nullptr);
			pInNode->SetPrevSibling(nullptr);
			pInNode->SetNextSibling(nullptr);
		}

		//remove last node in the chain
		else if (prevNode != nullptr && nextNode == nullptr)
		{
			prevNode->SetNextSibling(nullptr);
		}

		//remove first node in the chain which parent has a pointer point to
		else if (prevNode == nullptr && nextNode != nullptr)
		{
			PCSNode* nextSibling = pInNode->GetNextSibling();

			nextSibling->SetPrevSibling(nullptr);
			nextSibling->GetParent()->SetChild(nextSibling);

		}
		//remove node that doesn't have previous and next node
		else {

			pInNode->GetParent()->SetChild(nullptr);
			pInNode->SetParent(nullptr);
		}
		removeNodeHelper(pInNode);
		currentNumLevelHeper(this->pRoot, this->mInfo.currNumLevels);
	}
}

// get tree info
void PCSTree::GetInfo(Info &info)
{
	info = this->mInfo;
}

void PCSTree::Print() const
{
	this->printTreeHelper(this->pRoot);
}

//use the same concept as newDepth above but with extra walks because we need to print all nodes, not just height calculation
void PCSTree::printTreeHelper(PCSNode* const pNode) const
{
	PCSNode* temp = pNode;
	if (temp == nullptr)
	{
		return;
	}
	if (temp->GetChild() != nullptr && temp->GetNextSibling() != nullptr)
	{
		this->printTreeHelper(temp->GetChild());
		this->printTreeHelper(temp->GetNextSibling());
		temp->PrintNode();
	}
	else if (temp->GetNextSibling() == nullptr)
	{
		this->printTreeHelper(temp->GetChild());
		temp->PrintNode();
	}
	else if (temp->GetChild() == nullptr)
	{
		this->printTreeHelper(temp->GetNextSibling());
		temp->PrintNode();
	}
	else
	{
		temp->PrintNode();
	}
}

// ---  End of File ---------------
