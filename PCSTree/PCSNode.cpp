//-----------------------------------------------------------------------------
// Copyright 2020, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "PCSTree.h"
#include "PCSNode.h"

// constructor
PCSNode::PCSNode():
	pParent(nullptr), pChild(nullptr), pNextSibling(nullptr), pPrevSibling(nullptr)

{
	memset(&pName[0], 0x0, PCSNode::NAME_SIZE);
}

// copy constructor
PCSNode::PCSNode(const PCSNode &in):
	pParent(in.pParent), pChild(in.pChild), pNextSibling(in.pNextSibling), pPrevSibling(in.pPrevSibling)
{
	this->SetName(in.pName);
}

// Specialize Constructor
PCSNode::PCSNode(PCSNode * const pInParent, PCSNode * const pInChild, PCSNode * const pInNextSibling, PCSNode * const pInPrevSibling, const char * const pInName):
	pParent(pInParent), pChild(pInChild), pNextSibling(pInNextSibling), pPrevSibling(pInPrevSibling)
{
	memset(&pName[0], 0x0, PCSNode::NAME_SIZE);
	this->SetName(pInName);
}

PCSNode::PCSNode(const char * const pInName):
	pParent(nullptr), pChild(nullptr), pNextSibling(nullptr), pPrevSibling(nullptr)
{
	memset(&pName[0], 0x0, PCSNode::NAME_SIZE);
	this->SetName(pInName);
}

// destructor
PCSNode::~PCSNode()
{
}

// assignment operator
PCSNode &PCSNode::operator = (const PCSNode &in)
{
	if (this == &in)
	{
		return *this;
	}
	this->pParent = in.pParent;
	this->pChild = in.pChild;
	this->pNextSibling = in.pNextSibling;
	this->pPrevSibling = in.pPrevSibling;
	this->SetName(in.pName);
	return *this;
}

void PCSNode::SetParent(PCSNode * const pIn)
{
	this->pParent = pIn;
}

void PCSNode::SetChild(PCSNode * const pIn)
{
	this->pChild = pIn;
}

void PCSNode::SetNextSibling(PCSNode * const pIn)
{
	this->pNextSibling = pIn;
}

void PCSNode::SetPrevSibling(PCSNode * const pIn)
{
	this->pPrevSibling = pIn;
}

PCSNode *PCSNode::GetParent(void) const
{
	return this->pParent;
}

PCSNode *PCSNode::GetChild(void) const
{
	return this->pChild;
}

PCSNode *PCSNode::GetNextSibling(void) const
{
	return this->pNextSibling;
}

PCSNode *PCSNode::GetPrevSibling(void) const
{
	return this->pPrevSibling;
}

PCSNode::Code PCSNode::SetName(const char * const pInName)
{
	if (pInName == nullptr)
	{
		return Code::FAIL_NULL_PTR;
	}

	size_t size = strlen(pInName);
	if (size > PCSNode::NAME_SIZE)
	{
		size = PCSNode::NAME_SIZE;
	}

	memcpy(pName, pInName, size);

	return Code::SUCCESS;
}

PCSNode::Code PCSNode::GetName(char * const pOutBuffer, unsigned int sizeOutBuffer) const
{
	if (pOutBuffer == nullptr)
	{
		return Code::FAIL_NULL_PTR;
	}

	unsigned int size = sizeOutBuffer;
	
	if (sizeOutBuffer > PCSNode::NAME_SIZE)
	{
		size = PCSNode::NAME_SIZE;
	}

	memcpy(pOutBuffer, pName, size);
	pOutBuffer[size - 1] = '\0';

	return Code::SUCCESS;
}

void PCSNode::PrintNode() const
{
	Trace::out("Node name: %s \n", this->pName);

	//print parent
	if (this->pParent == nullptr) {
		Trace::out("\tNo parent exist for %s.\n", this->pName);
	}
	else {
		Trace::out("\tParent name: %s \n", this->pParent->pName);
	}

	//print child
	if (this->pChild == nullptr) {
		Trace::out("\t\tNo child exist for %s.\n", this->pName);
	}
	else {
		Trace::out("\t\tParent name: %s, Child name: %s \n", this->pName, this->pChild->pName);
	}

	//print next sibling
	if (this->pNextSibling == nullptr) {
		Trace::out("\t\t\tNo next sibling exist for %s.\n", this->pName);
	}
	else {
		Trace::out("\t\t\tCurrent node: %s, Next sibling name: %s \n", this->pName, this->pNextSibling->pName);
	}

	//print previous sibling
	if (this->pPrevSibling == nullptr) {
		Trace::out("\t\t\tNo previous sibling exist for %s.\n", this->pName);
	}
	else {
		Trace::out("\t\t\tCurrent node: %s, Previous sibling name: %s \n", this->pName, this->pPrevSibling->pName);
	}
}

void PCSNode::PrintChildren() const
{
	if (this->pChild == nullptr)
	{
		Trace::out("No child exist for %s\n", this->pName);
	}
	else
	{
		int count = 1;
		PCSNode* currentNode = this->pChild;
		while (currentNode != nullptr)
		{
			Trace::out("Parent name: %s, Child %d name: %s \n", this->pName, count, currentNode->pName);
			count++;
			currentNode = currentNode->GetNextSibling();
		}
	}
}


void PCSNode::PrintSiblings() const
{
	PCSNode* currentNode = this->pPrevSibling;
	int count = 1;
	if (currentNode == nullptr)
	{
		Trace::out("No previous sibling exists for %s\n", this->pName);
	}
	else
	{
		while (currentNode != nullptr)
		{
			Trace::out("Current Node: %s, Previous Sibling %d: %s \n", this->pName, count, currentNode->pName);
			count++;
			currentNode = currentNode->GetPrevSibling();
		}
	}

	if (this->pNextSibling == nullptr)
	{
		Trace::out("No next sibling exist for %s\n", this->pName);
	}
	else
	{
		count = 1;
		currentNode = this->pNextSibling;
		while (currentNode != nullptr)
		{
			Trace::out("Current Node: %s, Next Sibling %d: %s \n", this->pName, count, currentNode->pName);
			count++;
			currentNode = currentNode->GetNextSibling();
		}
	}
}

int PCSNode::GetNumSiblings() const
{
	/*int count = 1;
	
	PCSNode* tempNode = this->GetNextSibling();
	while (tempNode != nullptr)
	{
		count++;
		tempNode = tempNode->GetNextSibling();
	}

	tempNode = this->GetPrevSibling();
	while (tempNode != nullptr)
	{
		count++;
		tempNode = tempNode->GetPrevSibling();
	}*/
	
	if (this->GetParent() == nullptr)
	{
		return 1;
	}
	else
	{
		PCSNode* tempNode = this->GetParent()->GetChild();
		int count = 0;
		while (tempNode != nullptr)
		{
			count++;
			tempNode = tempNode->GetNextSibling();
		}
		return count;
	}
	
}

int PCSNode::GetNumChildren() const
{
	PCSNode* tempNode = this->GetChild();
	int count = 0;
	while (tempNode != nullptr)
	{
		count++;
		tempNode = tempNode->GetNextSibling();
	}

	return count;
}

// ---  End of File ---------------
