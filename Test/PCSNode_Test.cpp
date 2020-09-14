//-----------------------------------------------------------------------------
// Copyright 2020, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "PCSTree.h"
#include "PCSNode.h"

//---------------------------------------------------------------------------
// Modifying any Unit Test to alter the outcome results 
//       is also an Academic Integrity Violation       
//---------------------------------------------------------------------------

PCSNode *pn = nullptr;

//---------------------------------------------------------------------------
// Test Files:
// Single step throught, set break points, but do not modify it
//---------------------------------------------------------------------------
#if Version_Enable
TEST(version, PCSNode_group, Version_Enable)
{
	CHECK(PCSNode::MAJOR_VERSION == 2);
	CHECK(PCSNode::MINOR_VERSION == 2);
} TEST_END
#endif

#if defaultConstructor_Enable
TEST(defaultConstructor, PCSNode_group, defaultConstructor_Enable)
{
	PCSNode node;

	CHECK(node.GetChild() == nullptr);
	CHECK(node.GetParent() == nullptr);
	CHECK(node.GetNextSibling() == nullptr);
	CHECK(node.GetPrevSibling() == nullptr);

	char buff[PCSNode::NAME_SIZE];
	PCSNode::Code returnCode;
	returnCode = node.GetName(buff, PCSNode::NAME_SIZE);
	char testbuff[PCSNode::NAME_SIZE];
	memset(&testbuff[0], 0x0, PCSNode::NAME_SIZE);

	CHECK(memcmp(buff, testbuff, PCSNode::NAME_SIZE) == 0);
	CHECK(returnCode == PCSNode::Code::SUCCESS);
} TEST_END
#endif

#if SetChild_Enable
TEST(SetChild, PCSNode_group, SetChild_Enable)
{
	PCSNode nodeA;
	PCSNode nodeB;

	CHECK(&nodeA != &nodeB);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	nodeA.SetChild(&nodeB);

	CHECK(nodeA.GetChild() == &nodeB);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);
} TEST_END
#endif

#if GetChild_Enable
TEST(GetChild, PCSNode_group, GetChild_Enable)
{
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode *nodeC;

	CHECK(&nodeA != &nodeB);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	nodeA.SetChild(&nodeB);
	nodeC = nodeA.GetChild();

	CHECK(nodeC == &nodeB);

	CHECK(nodeA.GetChild() == &nodeB);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);
} TEST_END
#endif

#if SetParent_Enable
TEST(SetParent, PCSNode_group, SetParent_Enable)
{
	PCSNode nodeA;
	PCSNode nodeB;

	CHECK(&nodeA != &nodeB);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	nodeA.SetParent(&nodeB);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == &nodeB);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);
} TEST_END
#endif

#if GetParent_Enable
TEST(GetParent, PCSNode_group, GetParent_Enable)
{
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode *nodeC;

	CHECK(&nodeA != &nodeB);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	nodeA.SetParent(&nodeB);
	nodeC = nodeA.GetParent();

	CHECK(nodeC == &nodeB);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == &nodeB);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);
} TEST_END
#endif

#if SetNextSibling_Enable
TEST(SetNextSibling, PCSNode_group, SetNextSibling_Enable)
{
	PCSNode nodeA;
	PCSNode nodeB;

	CHECK(&nodeA != &nodeB);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	nodeA.SetNextSibling(&nodeB);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == &nodeB);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);
} TEST_END
#endif

#if SetPrevSibling_Enable
TEST(SetPrevSibling, PCSNode_group, SetPrevSibling_Enable)
{
	PCSNode nodeA;
	PCSNode nodeB;

	CHECK(&nodeA != &nodeB);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	nodeA.SetPrevSibling(&nodeB);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == &nodeB);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);
} TEST_END
#endif

#if GetNextSibling_Enable
TEST(GetNextSibling, PCSNode_group, GetNextSibling_Enable)
{
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode *nodeC;

	CHECK(&nodeA != &nodeB);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	nodeA.SetNextSibling(&nodeB);
	nodeC = nodeA.GetNextSibling();

	CHECK(nodeC == &nodeB);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == &nodeB);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);
} TEST_END
#endif

#if GetPrevSibling_Enable
TEST(GetPrevSibling, PCSNode_group, GetPrevSibling_Enable)
{
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode *nodeC;

	CHECK(&nodeA != &nodeB);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	nodeA.SetPrevSibling(&nodeB);
	nodeC = nodeA.GetPrevSibling();

	CHECK(nodeC == &nodeB);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == &nodeB);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);
} TEST_END
#endif

#if assignOperator_Enable
TEST(assignOperator, PCSNode_group, assignOperator_Enable)
{
	PCSNode nodeA("node_A");
	PCSNode nodeB("node_B");
	PCSNode nodeC("node_C");
	PCSNode nodeD("node_D");
	PCSNode node("TestNode");

	CHECK(&nodeA != &nodeB);
	CHECK(&nodeA != &nodeC);
	CHECK(&nodeA != &nodeD);
	CHECK(&nodeB != &nodeC);
	CHECK(&nodeB != &nodeD);
	CHECK(&nodeC != &nodeD);

	CHECK(node.GetChild() == nullptr);
	CHECK(node.GetParent() == nullptr);
	CHECK(node.GetNextSibling() == nullptr);
	CHECK(node.GetPrevSibling() == nullptr);

	node.SetParent(&nodeA);
	node.SetChild(&nodeB);
	node.SetNextSibling(&nodeC);
	node.SetPrevSibling(&nodeD);

	CHECK(node.GetPrevSibling() == &nodeD);
	CHECK(node.GetNextSibling() == &nodeC);
	CHECK(node.GetParent() == &nodeA);
	CHECK(node.GetChild() == &nodeB);

	CHECK(nodeA.GetPrevSibling() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetChild() == nullptr);

	CHECK(nodeB.GetPrevSibling() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetChild() == nullptr);

	CHECK(nodeC.GetPrevSibling() == nullptr);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetParent() == nullptr);
	CHECK(nodeC.GetChild() == nullptr);

	CHECK(nodeD.GetPrevSibling() == nullptr);
	CHECK(nodeD.GetNextSibling() == nullptr);
	CHECK(nodeD.GetParent() == nullptr);
	CHECK(nodeD.GetChild() == nullptr);

	PCSNode copyNode;
	// assignment
	copyNode = node;

	CHECK(node.GetPrevSibling() == copyNode.GetPrevSibling());
	CHECK(node.GetNextSibling() == copyNode.GetNextSibling());
	CHECK(node.GetParent() == copyNode.GetParent());
	CHECK(node.GetChild() == copyNode.GetChild());

	char buff[PCSNode::NAME_SIZE];
	PCSNode::Code returnCode;
	returnCode = copyNode.GetName(buff, PCSNode::NAME_SIZE);
	CHECK(strcmp(buff, "TestNode") == 0);
	CHECK(returnCode == PCSNode::Code::SUCCESS);

	CHECK(nodeA.GetPrevSibling() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetChild() == nullptr);

	CHECK(nodeB.GetPrevSibling() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetChild() == nullptr);

	CHECK(nodeC.GetPrevSibling() == nullptr);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetParent() == nullptr);
	CHECK(nodeC.GetChild() == nullptr);

	CHECK(nodeD.GetPrevSibling() == nullptr);
	CHECK(nodeD.GetNextSibling() == nullptr);
	CHECK(nodeD.GetParent() == nullptr);
	CHECK(nodeD.GetChild() == nullptr);
} TEST_END
#endif

#if destructor_Enable
TEST_WITH_TEARDOWN(destructor, PCSNode_group, destructor_Enable)
{
	pn = new PCSNode();
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeA;
	PCSNode nodeD;

	CHECK(&nodeA != &nodeB);
	CHECK(&nodeA != &nodeC);
	CHECK(&nodeA != &nodeD);
	CHECK(&nodeB != &nodeC);
	CHECK(&nodeB != &nodeD);
	CHECK(&nodeC != &nodeD);

	CHECK(pn->GetChild() == nullptr);
	CHECK(pn->GetParent() == nullptr);
	CHECK(pn->GetNextSibling() == nullptr);
	CHECK(pn->GetPrevSibling() == nullptr);

	pn->SetParent(&nodeA);
	pn->SetChild(&nodeB);
	pn->SetNextSibling(&nodeC);
	pn->SetPrevSibling(&nodeD);

	CHECK(pn->GetPrevSibling() == &nodeD);
	CHECK(pn->GetNextSibling() == &nodeC);
	CHECK(pn->GetParent() == &nodeA);
	CHECK(pn->GetChild() == &nodeB);

} TEST_END

TEST_TEARDOWN(destructor, PCSNode_group)
{
	delete pn;
	pn = nullptr;
} 
#endif

#if copyConstructor_Enable
TEST_WITH_TEARDOWN(copyConstructor, PCSNode_group, copyConstructor_Enable)
{
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeA;
	PCSNode nodeD;

	pn = new PCSNode();

	CHECK(&nodeA != &nodeB);
	CHECK(&nodeA != &nodeC);
	CHECK(&nodeA != &nodeD);
	CHECK(&nodeB != &nodeC);
	CHECK(&nodeB != &nodeD);

	CHECK(pn->GetChild() == nullptr);
	CHECK(pn->GetParent() == nullptr);
	CHECK(pn->GetNextSibling() == nullptr);
	CHECK(pn->GetPrevSibling() == nullptr);

	pn->SetParent(&nodeA);
	pn->SetChild(&nodeB);
	pn->SetNextSibling(&nodeC);
	pn->SetPrevSibling(&nodeD);

	CHECK(pn->GetPrevSibling() == &nodeD);
	CHECK(pn->GetNextSibling() == &nodeC);
	CHECK(pn->GetParent() == &nodeA);
	CHECK(pn->GetChild() == &nodeB);

	PCSNode pn2(*pn);

	char buff[PCSNode::NAME_SIZE];
	PCSNode::Code returnCode;
	returnCode = pn2.GetName(buff, PCSNode::NAME_SIZE);
	CHECK(returnCode == PCSNode::Code::SUCCESS);

	char buff2[PCSNode::NAME_SIZE];
	returnCode = pn->GetName(buff2, PCSNode::NAME_SIZE);
	CHECK(returnCode == PCSNode::Code::SUCCESS);

	CHECK(memcmp(buff, buff2, PCSNode::NAME_SIZE) == 0);

	CHECK(pn->GetPrevSibling() == &nodeD);
	CHECK(pn->GetNextSibling() == &nodeC);
	CHECK(pn->GetParent() == &nodeA);
	CHECK(pn->GetChild() == &nodeB);

	CHECK(pn2.GetPrevSibling() == &nodeD);
	CHECK(pn2.GetNextSibling() == &nodeC);
	CHECK(pn2.GetParent() == &nodeA);
	CHECK(pn2.GetChild() == &nodeB);

} TEST_END

TEST_TEARDOWN(copyConstructor, PCSNode_group)
{
	delete pn;
	pn = nullptr;
} 
#endif

#if copyConstructor3_Enable
TEST_WITH_TEARDOWN(copyConstructor3, PCSNode_group, copyConstructor3_Enable)
{

    PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;
	pn = new PCSNode(&nodeA, &nodeB, &nodeC, &nodeD, "MonkeyBrains");

	CHECK(&nodeA != &nodeB);
	CHECK(&nodeA != &nodeC);
	CHECK(&nodeA != &nodeD);
	CHECK(&nodeB != &nodeC);
	CHECK(&nodeB != &nodeD);
	CHECK(&nodeC != &nodeD);

	CHECK(pn->GetChild() == &nodeB);
	CHECK(pn->GetParent() == &nodeA);
	CHECK(pn->GetNextSibling() == &nodeC);
	CHECK(pn->GetPrevSibling() == &nodeD);

	PCSNode pn2(*pn);

	char buff[PCSNode::NAME_SIZE];
	PCSNode::Code returnCode;
	returnCode = pn2.GetName(buff, PCSNode::NAME_SIZE);
	CHECK(returnCode == PCSNode::Code::SUCCESS);

	char buff2[PCSNode::NAME_SIZE];
	returnCode = pn->GetName(buff2, PCSNode::NAME_SIZE);
	CHECK(returnCode == PCSNode::Code::SUCCESS);

	CHECK(memcmp(buff, buff2, PCSNode::NAME_SIZE) == 0);

	CHECK(pn->GetPrevSibling() == &nodeD);
	CHECK(pn->GetNextSibling() == &nodeC);
	CHECK(pn->GetParent() == &nodeA);
	CHECK(pn->GetChild() == &nodeB);

	CHECK(pn2.GetPrevSibling() == &nodeD);
	CHECK(pn2.GetNextSibling() == &nodeC);
	CHECK(pn2.GetParent() == &nodeA);
	CHECK(pn2.GetChild() == &nodeB);

} TEST_END

TEST_TEARDOWN(copyConstructor3, PCSNode_group)
{
	delete pn;
	pn = nullptr;
} 
#endif

#if copyConstructor2_Enable
TEST_WITH_TEARDOWN(copyConstructor2, PCSNode_group, copyConstructor2_Enable)
{
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeA;
	PCSNode nodeD;

	pn = new PCSNode("MonkeyBrains");

	CHECK(&nodeA != &nodeB);
	CHECK(&nodeA != &nodeC);
	CHECK(&nodeA != &nodeD);
	CHECK(&nodeB != &nodeC);
	CHECK(&nodeB != &nodeD);
	CHECK(&nodeC != &nodeD);

	CHECK(pn->GetChild() == nullptr);
	CHECK(pn->GetParent() == nullptr);
	CHECK(pn->GetNextSibling() == nullptr);
	CHECK(pn->GetPrevSibling() == nullptr);

	pn->SetParent(&nodeA);
	pn->SetChild(&nodeB);
	pn->SetNextSibling(&nodeC);
	pn->SetPrevSibling(&nodeD);

	CHECK(pn->GetPrevSibling() == &nodeD);
	CHECK(pn->GetNextSibling() == &nodeC);
	CHECK(pn->GetParent() == &nodeA);
	CHECK(pn->GetChild() == &nodeB);

	PCSNode pn2(*pn);

	char buff[PCSNode::NAME_SIZE];
	PCSNode::Code returnCode;
	returnCode = pn2.GetName(buff, PCSNode::NAME_SIZE);
	CHECK(returnCode == PCSNode::Code::SUCCESS);

	char buff2[PCSNode::NAME_SIZE];
	returnCode = pn->GetName(buff2, PCSNode::NAME_SIZE);
	CHECK(returnCode == PCSNode::Code::SUCCESS);

	CHECK(memcmp(buff, buff2, PCSNode::NAME_SIZE) == 0);

	CHECK(pn->GetPrevSibling() == &nodeD);
	CHECK(pn->GetNextSibling() == &nodeC);
	CHECK(pn->GetParent() == &nodeA);
	CHECK(pn->GetChild() == &nodeB);

	CHECK(pn2.GetPrevSibling() == &nodeD);
	CHECK(pn2.GetNextSibling() == &nodeC);
	CHECK(pn2.GetParent() == &nodeA);
	CHECK(pn2.GetChild() == &nodeB);

} TEST_END

TEST_TEARDOWN(copyConstructor2, PCSNode_group)
{
	delete pn;
	pn = nullptr;
} 
#endif

#if SetName_normal_Enable
TEST(SetName_normal, PCSNode_group, SetName_normal_Enable)
{
	PCSNode pna;

	CHECK(pna.GetChild() == nullptr);
	CHECK(pna.GetParent() == nullptr);
	CHECK(pna.GetNextSibling() == nullptr);
	CHECK(pna.GetPrevSibling() == nullptr);

	PCSNode::Code returnCode;

	returnCode = pna.SetName("Node_A");

	CHECK(returnCode == PCSNode::Code::SUCCESS);
	char buff[PCSNode::NAME_SIZE];
	 
	returnCode = pna.GetName(buff, PCSNode::NAME_SIZE);

	CHECK(strcmp(buff, "Node_A") == 0);
	CHECK(returnCode == PCSNode::Code::SUCCESS);

	CHECK(pna.GetChild() == nullptr);
	CHECK(pna.GetParent() == nullptr);
	CHECK(pna.GetNextSibling() == nullptr);
	CHECK(pna.GetPrevSibling() == nullptr);
} TEST_END
#endif

#if SetName_normal_null_Enable
TEST(SetName_normal_null, PCSNode_group, SetName_normal_null_Enable)
{
	PCSNode pna;

	CHECK(pna.GetChild() == nullptr);
	CHECK(pna.GetParent() == nullptr);
	CHECK(pna.GetNextSibling() == nullptr);
	CHECK(pna.GetPrevSibling() == nullptr);

	char *buff_null = 0;
	PCSNode::Code returnCode;

	returnCode = pna.SetName(buff_null);
	CHECK(returnCode == PCSNode::Code::FAIL_NULL_PTR);

	char buff[PCSNode::NAME_SIZE];

	returnCode = pna.GetName(buff, PCSNode::NAME_SIZE);

	CHECK(returnCode == PCSNode::Code::SUCCESS);

	CHECK(pna.GetChild() == nullptr);
	CHECK(pna.GetParent() == nullptr);
	CHECK(pna.GetNextSibling() == nullptr);
	CHECK(pna.GetPrevSibling() == nullptr);
} TEST_END
#endif

#if SetName_too_Big_Enable
TEST(SetName_too_Big, PCSNode_group, SetName_too_Big_Enable)
{
	PCSNode pna;

	CHECK(pna.GetChild() == nullptr);
	CHECK(pna.GetParent() == nullptr);
	CHECK(pna.GetNextSibling() == nullptr);
	CHECK(pna.GetPrevSibling() == nullptr);

	PCSNode::Code returnCode;

	returnCode = pna.SetName("Node_A_123456789012345678901234567890123456789");
	CHECK(returnCode == PCSNode::Code::SUCCESS);
	char buff[PCSNode::NAME_SIZE];

	returnCode = pna.GetName(buff, PCSNode::NAME_SIZE);

	CHECK(strcmp(buff, "Node_A_123456789012345678901234") == 0);
	CHECK(returnCode == PCSNode::Code::SUCCESS);

	CHECK(pna.GetChild() == nullptr);
	CHECK(pna.GetParent() == nullptr);
	CHECK(pna.GetNextSibling() == nullptr);
	CHECK(pna.GetPrevSibling() == nullptr);
} TEST_END
#endif

#if GetName_normal_Enable
TEST(GetName_normal, PCSNode_group, GetName_normal_Enable)
{
	PCSNode pna;

	CHECK(pna.GetChild() == nullptr);
	CHECK(pna.GetParent() == nullptr);
	CHECK(pna.GetNextSibling() == nullptr);
	CHECK(pna.GetPrevSibling() == nullptr);

	pna.SetName("123456789012345");

	char buff[PCSNode::NAME_SIZE];
	PCSNode::Code returnCode;

	returnCode = pna.GetName(buff, PCSNode::NAME_SIZE);

	CHECK(strcmp(buff, "123456789012345") == 0);
	CHECK(returnCode == PCSNode::Code::SUCCESS);

	CHECK(pna.GetChild() == nullptr);
	CHECK(pna.GetParent() == nullptr);
	CHECK(pna.GetNextSibling() == nullptr);
	CHECK(pna.GetPrevSibling() == nullptr);
} TEST_END
#endif

#if GetName_normal_null_Enable
TEST(GetName_normal_null, PCSNode_group, GetName_normal_null_Enable)
{
	PCSNode pna;

	CHECK(pna.GetChild() == nullptr);
	CHECK(pna.GetParent() == nullptr);
	CHECK(pna.GetNextSibling() == nullptr);
	CHECK(pna.GetPrevSibling() == nullptr);

	pna.SetName("123456789012345");

	char *buff_null = 0;

	PCSNode::Code returnCode;

	returnCode = pna.GetName(buff_null, PCSNode::NAME_SIZE);

	CHECK(buff_null == nullptr);
	CHECK(returnCode == PCSNode::Code::FAIL_NULL_PTR);

	CHECK(pna.GetChild() == nullptr);
	CHECK(pna.GetParent() == nullptr);
	CHECK(pna.GetNextSibling() == nullptr);
	CHECK(pna.GetPrevSibling() == nullptr);
} TEST_END
#endif

#if GetName_too_small_Enable
TEST(GetName_too_small, PCSNode_group, GetName_too_small_Enable)
{
	PCSNode pna;

	CHECK(pna.GetChild() == nullptr);
	CHECK(pna.GetParent() == nullptr);
	CHECK(pna.GetNextSibling() == nullptr);
	CHECK(pna.GetPrevSibling() == nullptr);

	pna.SetName("123456789012345");

	char buff[8];
	PCSNode::Code returnCode;

	returnCode = pna.GetName(buff, 8);

	CHECK(strcmp(buff, "1234567") == 0);

	CHECK(returnCode == PCSNode::Code::SUCCESS);

	CHECK(pna.GetChild() == nullptr);
	CHECK(pna.GetParent() == nullptr);
	CHECK(pna.GetNextSibling() == nullptr);
	CHECK(pna.GetPrevSibling() == nullptr);
} TEST_END
#endif

#if GetName_too_big_Enable
TEST(GetName_too_big, PCSNode_group, GetName_too_big_Enable)
{
	PCSNode pna;

	CHECK(pna.GetChild() == nullptr);
	CHECK(pna.GetParent() == nullptr);
	CHECK(pna.GetNextSibling() == nullptr);
	CHECK(pna.GetPrevSibling() == nullptr);

	pna.SetName("123456789012345");

	char buff[80];
	PCSNode::Code returnCode;

	returnCode = pna.GetName(buff, 80);

	CHECK(strcmp(buff, "123456789012345") == 0);

	CHECK(returnCode == PCSNode::Code::SUCCESS);

	CHECK(pna.GetChild() == nullptr);
	CHECK(pna.GetParent() == nullptr);
	CHECK(pna.GetNextSibling() == nullptr);
	CHECK(pna.GetPrevSibling() == nullptr);
} TEST_END
#endif

#if print_Enable
TEST(print, PCSNode_group, print_Enable)
{
	PCSNode n;

	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;

	nodeA.SetName("Node_A");
	nodeB.SetName("Node_B");
	nodeC.SetName("Node_C");
	nodeD.SetName("Node_D");

	n.SetName("Node_X");

	n.SetParent(&nodeA);
	n.SetNextSibling(&nodeB);
	n.SetPrevSibling(&nodeC);
	n.SetChild(&nodeD);

	CHECK(n.GetChild() == &nodeD);
	CHECK(n.GetParent() == &nodeA);
	CHECK(n.GetNextSibling() == &nodeB);
	CHECK(n.GetPrevSibling() == &nodeC);

	n.PrintNode();

	CHECK(n.GetChild() == &nodeD);
	CHECK(n.GetParent() == &nodeA);
	CHECK(n.GetNextSibling() == &nodeB);
	CHECK(n.GetPrevSibling() == &nodeC);
} TEST_END
#endif

#if specializeConstuctor_Enable
TEST(specializeConstuctor, PCSNode_group, specializeConstuctor_Enable)
{
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;

	PCSNode n(&nodeA, &nodeB, &nodeC, &nodeD, "Node_Z");

	nodeA.SetName("Node_A");
	nodeB.SetName("Node_B");
	nodeC.SetName("Node_C");
	nodeD.SetName("Node_D");

	CHECK(n.GetChild() == &nodeB);
	CHECK(n.GetParent() == &nodeA);
	CHECK(n.GetNextSibling() == &nodeC);
	CHECK(n.GetPrevSibling() == &nodeD);

	char tmpName[PCSNode::NAME_SIZE];

	n.GetName(tmpName, PCSNode::NAME_SIZE);

	CHECK(strcmp(tmpName, "Node_Z") == 0);

	CHECK(n.GetChild() == &nodeB);
	CHECK(n.GetParent() == &nodeA);
	CHECK(n.GetNextSibling() == &nodeC);
	CHECK(n.GetPrevSibling() == &nodeD);
} TEST_END
#endif

#if specializeConstuctorName_Enable
TEST(specializeConstuctorName, PCSNode_group, specializeConstuctorName_Enable)
{
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;

	PCSNode n("Node_X");

	CHECK(n.GetChild() == nullptr);
	CHECK(n.GetParent() == nullptr);
	CHECK(n.GetNextSibling() == nullptr);
	CHECK(n.GetPrevSibling() == nullptr);

	nodeA.SetName("Node_A");
	nodeB.SetName("Node_B");
	nodeC.SetName("Node_C");
	nodeD.SetName("Node_D");

	n.SetParent(&nodeA);
	n.SetNextSibling(&nodeC);
	n.SetPrevSibling(&nodeD);
	n.SetChild(&nodeB);

	CHECK(n.GetChild() == &nodeB);
	CHECK(n.GetParent() == &nodeA);
	CHECK(n.GetNextSibling() == &nodeC);
	CHECK(n.GetPrevSibling() == &nodeD);

	char tmpName[PCSNode::NAME_SIZE];
	n.GetName(tmpName, PCSNode::NAME_SIZE);
	CHECK(strcmp(tmpName, "Node_X") == 0);
} TEST_END
#endif

#if printNode_with0Links_Enable
TEST(printNode_with0Links, PCSNode_group, printNode_with0Links_Enable)
{
	PCSNode n("Node_X");

	CHECK(n.GetChild() == nullptr);
	CHECK(n.GetParent() == nullptr);
	CHECK(n.GetNextSibling() == nullptr);
	CHECK(n.GetPrevSibling() == nullptr);

	n.PrintNode();
} TEST_END
#endif

#if fullTree_printChildren_Enable
TEST(fullTree_printChildren, PCSNode_group, fullTree_printChildren_Enable)
{
	PCSTree::Info info;
	PCSTree tree;
	PCSNode  *root;

	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeB("Node_B");
	PCSNode nodeC("Node_C");
	PCSNode nodeD("Node_D");
	PCSNode nodeE("Node_E");
	PCSNode nodeI("Node_I");
	PCSNode nodeK("Node_K");
	PCSNode nodeL("Node_L");
	PCSNode nodeR("Node_R");
	PCSNode nodeF("Node_F");
	PCSNode nodeG("Node_G");
	PCSNode nodeJ("Node_J");
	PCSNode nodeM("Node_M");
	PCSNode nodeN("Node_N");
	PCSNode nodeO("Node_O");
	PCSNode nodeP("Node_P");
	PCSNode nodeQ("Node_Q");
	PCSNode nodeH("Node_H");
	PCSNode nodeS("Node_S");
	PCSNode nodeT("Node_T");
	PCSNode nodeU("Node_U");
	PCSNode nodeV("Node_V");
	PCSNode nodeW("Node_W");

	root = tree.GetRoot();

	tree.Insert(&nodeRoot, root);

	tree.Insert(&nodeC, &nodeRoot);
	tree.Insert(&nodeB, &nodeRoot);
	tree.Insert(&nodeA, &nodeRoot);
	tree.Insert(&nodeI, &nodeA);
	tree.Insert(&nodeE, &nodeA);
	tree.Insert(&nodeD, &nodeA);
	tree.Insert(&nodeL, &nodeB);
	tree.Insert(&nodeK, &nodeB);
	tree.Insert(&nodeR, &nodeC);
	tree.Insert(&nodeF, &nodeD);
	tree.Insert(&nodeJ, &nodeI);
	tree.Insert(&nodeG, &nodeI);
	tree.Insert(&nodeN, &nodeL);
	tree.Insert(&nodeM, &nodeL);
	tree.Insert(&nodeQ, &nodeR);
	tree.Insert(&nodeP, &nodeR);
	tree.Insert(&nodeO, &nodeR);
	tree.Insert(&nodeH, &nodeF);
	tree.Insert(&nodeS, &nodeP);
	tree.Insert(&nodeW, &nodeS);
	tree.Insert(&nodeV, &nodeS);
	tree.Insert(&nodeU, &nodeS);
	tree.Insert(&nodeT, &nodeS);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 24);

	CHECK(nodeRoot.GetChild() == &nodeA);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == &nodeD);
	CHECK(nodeA.GetParent() == &nodeRoot);
	CHECK(nodeA.GetNextSibling() == &nodeB);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == &nodeK);
	CHECK(nodeB.GetParent() == &nodeRoot);
	CHECK(nodeB.GetNextSibling() == &nodeC);
	CHECK(nodeB.GetPrevSibling() == &nodeA);

	CHECK(nodeC.GetChild() == &nodeR);
	CHECK(nodeC.GetParent() == &nodeRoot);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == &nodeB);

	CHECK(nodeD.GetChild() == &nodeF);
	CHECK(nodeD.GetParent() == &nodeA);
	CHECK(nodeD.GetNextSibling() == &nodeE);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeE.GetChild() == nullptr);
	CHECK(nodeE.GetParent() == &nodeA);
	CHECK(nodeE.GetNextSibling() == &nodeI);
	CHECK(nodeE.GetPrevSibling() == &nodeD);

	CHECK(nodeI.GetChild() == &nodeG);
	CHECK(nodeI.GetParent() == &nodeA);
	CHECK(nodeI.GetNextSibling() == nullptr);
	CHECK(nodeI.GetPrevSibling() == &nodeE);

	CHECK(nodeK.GetChild() == nullptr);
	CHECK(nodeK.GetParent() == &nodeB);
	CHECK(nodeK.GetNextSibling() == &nodeL);
	CHECK(nodeK.GetPrevSibling() == nullptr);

	CHECK(nodeL.GetChild() == &nodeM);
	CHECK(nodeL.GetParent() == &nodeB);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == &nodeK);

	CHECK(nodeR.GetChild() == &nodeO);
	CHECK(nodeR.GetParent() == &nodeC);
	CHECK(nodeR.GetNextSibling() == nullptr);
	CHECK(nodeR.GetPrevSibling() == nullptr);

	CHECK(nodeF.GetChild() == &nodeH);
	CHECK(nodeF.GetParent() == &nodeD);
	CHECK(nodeF.GetNextSibling() == nullptr);
	CHECK(nodeF.GetPrevSibling() == nullptr);

	CHECK(nodeG.GetChild() == nullptr);
	CHECK(nodeG.GetParent() == &nodeI);
	CHECK(nodeG.GetNextSibling() == &nodeJ);
	CHECK(nodeG.GetPrevSibling() == nullptr);

	CHECK(nodeJ.GetChild() == nullptr);
	CHECK(nodeJ.GetParent() == &nodeI);
	CHECK(nodeJ.GetNextSibling() == nullptr);
	CHECK(nodeJ.GetPrevSibling() == &nodeG);

	CHECK(nodeM.GetChild() == nullptr);
	CHECK(nodeM.GetParent() == &nodeL);
	CHECK(nodeM.GetNextSibling() == &nodeN);
	CHECK(nodeM.GetPrevSibling() == nullptr);

	CHECK(nodeN.GetChild() == nullptr);
	CHECK(nodeN.GetParent() == &nodeL);
	CHECK(nodeN.GetNextSibling() == nullptr);
	CHECK(nodeN.GetPrevSibling() == &nodeM);

	CHECK(nodeO.GetChild() == nullptr);
	CHECK(nodeO.GetParent() == &nodeR);
	CHECK(nodeO.GetNextSibling() == &nodeP);
	CHECK(nodeO.GetPrevSibling() == nullptr);

	CHECK(nodeP.GetChild() == &nodeS);
	CHECK(nodeP.GetParent() == &nodeR);
	CHECK(nodeP.GetNextSibling() == &nodeQ);
	CHECK(nodeP.GetPrevSibling() == &nodeO);

	CHECK(nodeQ.GetChild() == nullptr);
	CHECK(nodeQ.GetParent() == &nodeR);
	CHECK(nodeQ.GetNextSibling() == nullptr);
	CHECK(nodeQ.GetPrevSibling() == &nodeP);

	CHECK(nodeH.GetChild() == nullptr);
	CHECK(nodeH.GetParent() == &nodeF);
	CHECK(nodeH.GetNextSibling() == nullptr);
	CHECK(nodeH.GetPrevSibling() == nullptr);

	CHECK(nodeS.GetChild() == &nodeT);
	CHECK(nodeS.GetParent() == &nodeP);
	CHECK(nodeS.GetNextSibling() == nullptr);
	CHECK(nodeS.GetPrevSibling() == nullptr);

	CHECK(nodeT.GetChild() == nullptr);
	CHECK(nodeT.GetParent() == &nodeS);
	CHECK(nodeT.GetNextSibling() == &nodeU);
	CHECK(nodeT.GetPrevSibling() == nullptr);

	CHECK(nodeU.GetChild() == nullptr);
	CHECK(nodeU.GetParent() == &nodeS);
	CHECK(nodeU.GetNextSibling() == &nodeV);
	CHECK(nodeU.GetPrevSibling() == &nodeT);

	CHECK(nodeV.GetChild() == nullptr);
	CHECK(nodeV.GetParent() == &nodeS);
	CHECK(nodeV.GetNextSibling() == &nodeW);
	CHECK(nodeV.GetPrevSibling() == &nodeU);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == &nodeS);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == &nodeV);

	CHECK(nodeS.GetNumChildren() == 4);
	nodeS.PrintChildren();

	// visually verify it prints nodes: T,U,V,W

	CHECK(nodeA.GetNumChildren() == 3);
	nodeA.PrintChildren();

	// visually verify it prints nodes: D,E,I
} TEST_END
#endif

#if fullTree_printSiblings_Enable
TEST(fullTree_printSiblings, PCSNode_group, fullTree_printSiblings_Enable)
{
	PCSTree::Info info;
	PCSTree tree;
	PCSNode  *root;

	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeB("Node_B");
	PCSNode nodeC("Node_C");
	PCSNode nodeD("Node_D");
	PCSNode nodeE("Node_E");
	PCSNode nodeI("Node_I");
	PCSNode nodeK("Node_K");
	PCSNode nodeL("Node_L");
	PCSNode nodeR("Node_R");
	PCSNode nodeF("Node_F");
	PCSNode nodeG("Node_G");
	PCSNode nodeJ("Node_J");
	PCSNode nodeM("Node_M");
	PCSNode nodeN("Node_N");
	PCSNode nodeO("Node_O");
	PCSNode nodeP("Node_P");
	PCSNode nodeQ("Node_Q");
	PCSNode nodeH("Node_H");
	PCSNode nodeS("Node_S");
	PCSNode nodeT("Node_T");
	PCSNode nodeU("Node_U");
	PCSNode nodeV("Node_V");
	PCSNode nodeW("Node_W");

	root = tree.GetRoot();

	tree.Insert(&nodeRoot, root);

	tree.Insert(&nodeC, &nodeRoot);
	tree.Insert(&nodeB, &nodeRoot);
	tree.Insert(&nodeA, &nodeRoot);
	tree.Insert(&nodeI, &nodeA);
	tree.Insert(&nodeE, &nodeA);
	tree.Insert(&nodeD, &nodeA);
	tree.Insert(&nodeL, &nodeB);
	tree.Insert(&nodeK, &nodeB);
	tree.Insert(&nodeR, &nodeC);
	tree.Insert(&nodeF, &nodeD);
	tree.Insert(&nodeJ, &nodeI);
	tree.Insert(&nodeG, &nodeI);
	tree.Insert(&nodeN, &nodeL);
	tree.Insert(&nodeM, &nodeL);
	tree.Insert(&nodeQ, &nodeR);
	tree.Insert(&nodeP, &nodeR);
	tree.Insert(&nodeO, &nodeR);
	tree.Insert(&nodeH, &nodeF);
	tree.Insert(&nodeS, &nodeP);
	tree.Insert(&nodeW, &nodeS);
	tree.Insert(&nodeV, &nodeS);
	tree.Insert(&nodeU, &nodeS);
	tree.Insert(&nodeT, &nodeS);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 24);
	CHECK(nodeRoot.GetChild() == &nodeA);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == &nodeD);
	CHECK(nodeA.GetParent() == &nodeRoot);
	CHECK(nodeA.GetNextSibling() == &nodeB);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == &nodeK);
	CHECK(nodeB.GetParent() == &nodeRoot);
	CHECK(nodeB.GetNextSibling() == &nodeC);
	CHECK(nodeB.GetPrevSibling() == &nodeA);

	CHECK(nodeC.GetChild() == &nodeR);
	CHECK(nodeC.GetParent() == &nodeRoot);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == &nodeB);

	CHECK(nodeD.GetChild() == &nodeF);
	CHECK(nodeD.GetParent() == &nodeA);
	CHECK(nodeD.GetNextSibling() == &nodeE);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeE.GetChild() == nullptr);
	CHECK(nodeE.GetParent() == &nodeA);
	CHECK(nodeE.GetNextSibling() == &nodeI);
	CHECK(nodeE.GetPrevSibling() == &nodeD);

	CHECK(nodeI.GetChild() == &nodeG);
	CHECK(nodeI.GetParent() == &nodeA);
	CHECK(nodeI.GetNextSibling() == nullptr);
	CHECK(nodeI.GetPrevSibling() == &nodeE);

	CHECK(nodeK.GetChild() == nullptr);
	CHECK(nodeK.GetParent() == &nodeB);
	CHECK(nodeK.GetNextSibling() == &nodeL);
	CHECK(nodeK.GetPrevSibling() == nullptr);

	CHECK(nodeL.GetChild() == &nodeM);
	CHECK(nodeL.GetParent() == &nodeB);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == &nodeK);

	CHECK(nodeR.GetChild() == &nodeO);
	CHECK(nodeR.GetParent() == &nodeC);
	CHECK(nodeR.GetNextSibling() == nullptr);
	CHECK(nodeR.GetPrevSibling() == nullptr);

	CHECK(nodeF.GetChild() == &nodeH);
	CHECK(nodeF.GetParent() == &nodeD);
	CHECK(nodeF.GetNextSibling() == nullptr);
	CHECK(nodeF.GetPrevSibling() == nullptr);

	CHECK(nodeG.GetChild() == nullptr);
	CHECK(nodeG.GetParent() == &nodeI);
	CHECK(nodeG.GetNextSibling() == &nodeJ);
	CHECK(nodeG.GetPrevSibling() == nullptr);

	CHECK(nodeJ.GetChild() == nullptr);
	CHECK(nodeJ.GetParent() == &nodeI);
	CHECK(nodeJ.GetNextSibling() == nullptr);
	CHECK(nodeJ.GetPrevSibling() == &nodeG);

	CHECK(nodeM.GetChild() == nullptr);
	CHECK(nodeM.GetParent() == &nodeL);
	CHECK(nodeM.GetNextSibling() == &nodeN);
	CHECK(nodeM.GetPrevSibling() == nullptr);

	CHECK(nodeN.GetChild() == nullptr);
	CHECK(nodeN.GetParent() == &nodeL);
	CHECK(nodeN.GetNextSibling() == nullptr);
	CHECK(nodeN.GetPrevSibling() == &nodeM);

	CHECK(nodeO.GetChild() == nullptr);
	CHECK(nodeO.GetParent() == &nodeR);
	CHECK(nodeO.GetNextSibling() == &nodeP);
	CHECK(nodeO.GetPrevSibling() == nullptr);

	CHECK(nodeP.GetChild() == &nodeS);
	CHECK(nodeP.GetParent() == &nodeR);
	CHECK(nodeP.GetNextSibling() == &nodeQ);
	CHECK(nodeP.GetPrevSibling() == &nodeO);

	CHECK(nodeQ.GetChild() == nullptr);
	CHECK(nodeQ.GetParent() == &nodeR);
	CHECK(nodeQ.GetNextSibling() == nullptr);
	CHECK(nodeQ.GetPrevSibling() == &nodeP);

	CHECK(nodeH.GetChild() == nullptr);
	CHECK(nodeH.GetParent() == &nodeF);
	CHECK(nodeH.GetNextSibling() == nullptr);
	CHECK(nodeH.GetPrevSibling() == nullptr);

	CHECK(nodeS.GetChild() == &nodeT);
	CHECK(nodeS.GetParent() == &nodeP);
	CHECK(nodeS.GetNextSibling() == nullptr);
	CHECK(nodeS.GetPrevSibling() == nullptr);

	CHECK(nodeT.GetChild() == nullptr);
	CHECK(nodeT.GetParent() == &nodeS);
	CHECK(nodeT.GetNextSibling() == &nodeU);
	CHECK(nodeT.GetPrevSibling() == nullptr);

	CHECK(nodeU.GetChild() == nullptr);
	CHECK(nodeU.GetParent() == &nodeS);
	CHECK(nodeU.GetNextSibling() == &nodeV);
	CHECK(nodeU.GetPrevSibling() == &nodeT);

	CHECK(nodeV.GetChild() == nullptr);
	CHECK(nodeV.GetParent() == &nodeS);
	CHECK(nodeV.GetNextSibling() == &nodeW);
	CHECK(nodeV.GetPrevSibling() == &nodeU);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == &nodeS);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == &nodeV);

	CHECK(nodeE.GetNumSiblings() == 3);
	nodeE.PrintSiblings();
	// visually verify it prints nodes: D,E,I

	CHECK(nodeI.GetNumSiblings() == 3);
	nodeI.PrintSiblings();
	// visually verify it prints nodes: D,E,I

	CHECK(nodeD.GetNumSiblings() == 3);
	nodeD.PrintSiblings();

	// visually verify it prints nodes: D,E,I
} TEST_END
#endif

#if fullTree_GetNumChildren_Enable
TEST(fullTree_GetNumChildren, PCSNode_group, fullTree_GetNumChildren_Enable)
{
	PCSTree::Info info;
	PCSTree tree;
	PCSNode  *root;

	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeB("Node_B");
	PCSNode nodeC("Node_C");
	PCSNode nodeD("Node_D");
	PCSNode nodeE("Node_E");
	PCSNode nodeI("Node_I");
	PCSNode nodeK("Node_K");
	PCSNode nodeL("Node_L");
	PCSNode nodeR("Node_R");
	PCSNode nodeF("Node_F");
	PCSNode nodeG("Node_G");
	PCSNode nodeJ("Node_J");
	PCSNode nodeM("Node_M");
	PCSNode nodeN("Node_N");
	PCSNode nodeO("Node_O");
	PCSNode nodeP("Node_P");
	PCSNode nodeQ("Node_Q");
	PCSNode nodeH("Node_H");
	PCSNode nodeS("Node_S");
	PCSNode nodeT("Node_T");
	PCSNode nodeU("Node_U");
	PCSNode nodeV("Node_V");
	PCSNode nodeW("Node_W");

	root = tree.GetRoot();

	tree.Insert(&nodeRoot, root);

	tree.Insert(&nodeC, &nodeRoot);
	tree.Insert(&nodeB, &nodeRoot);
	tree.Insert(&nodeA, &nodeRoot);
	tree.Insert(&nodeI, &nodeA);
	tree.Insert(&nodeE, &nodeA);
	tree.Insert(&nodeD, &nodeA);
	tree.Insert(&nodeL, &nodeB);
	tree.Insert(&nodeK, &nodeB);
	tree.Insert(&nodeR, &nodeC);
	tree.Insert(&nodeF, &nodeD);
	tree.Insert(&nodeJ, &nodeI);
	tree.Insert(&nodeG, &nodeI);
	tree.Insert(&nodeN, &nodeL);
	tree.Insert(&nodeM, &nodeL);
	tree.Insert(&nodeQ, &nodeR);
	tree.Insert(&nodeP, &nodeR);
	tree.Insert(&nodeO, &nodeR);
	tree.Insert(&nodeH, &nodeF);
	tree.Insert(&nodeS, &nodeP);
	tree.Insert(&nodeW, &nodeS);
	tree.Insert(&nodeV, &nodeS);
	tree.Insert(&nodeU, &nodeS);
	tree.Insert(&nodeT, &nodeS);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 24);

	CHECK(nodeRoot.GetChild() == &nodeA);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == &nodeD);
	CHECK(nodeA.GetParent() == &nodeRoot);
	CHECK(nodeA.GetNextSibling() == &nodeB);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == &nodeK);
	CHECK(nodeB.GetParent() == &nodeRoot);
	CHECK(nodeB.GetNextSibling() == &nodeC);
	CHECK(nodeB.GetPrevSibling() == &nodeA);

	CHECK(nodeC.GetChild() == &nodeR);
	CHECK(nodeC.GetParent() == &nodeRoot);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == &nodeB);

	CHECK(nodeD.GetChild() == &nodeF);
	CHECK(nodeD.GetParent() == &nodeA);
	CHECK(nodeD.GetNextSibling() == &nodeE);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeE.GetChild() == nullptr);
	CHECK(nodeE.GetParent() == &nodeA);
	CHECK(nodeE.GetNextSibling() == &nodeI);
	CHECK(nodeE.GetPrevSibling() == &nodeD);

	CHECK(nodeI.GetChild() == &nodeG);
	CHECK(nodeI.GetParent() == &nodeA);
	CHECK(nodeI.GetNextSibling() == nullptr);
	CHECK(nodeI.GetPrevSibling() == &nodeE);

	CHECK(nodeK.GetChild() == nullptr);
	CHECK(nodeK.GetParent() == &nodeB);
	CHECK(nodeK.GetNextSibling() == &nodeL);
	CHECK(nodeK.GetPrevSibling() == nullptr);

	CHECK(nodeL.GetChild() == &nodeM);
	CHECK(nodeL.GetParent() == &nodeB);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == &nodeK);

	CHECK(nodeR.GetChild() == &nodeO);
	CHECK(nodeR.GetParent() == &nodeC);
	CHECK(nodeR.GetNextSibling() == nullptr);
	CHECK(nodeR.GetPrevSibling() == nullptr);

	CHECK(nodeF.GetChild() == &nodeH);
	CHECK(nodeF.GetParent() == &nodeD);
	CHECK(nodeF.GetNextSibling() == nullptr);
	CHECK(nodeF.GetPrevSibling() == nullptr);

	CHECK(nodeG.GetChild() == nullptr);
	CHECK(nodeG.GetParent() == &nodeI);
	CHECK(nodeG.GetNextSibling() == &nodeJ);
	CHECK(nodeG.GetPrevSibling() == nullptr);

	CHECK(nodeJ.GetChild() == nullptr);
	CHECK(nodeJ.GetParent() == &nodeI);
	CHECK(nodeJ.GetNextSibling() == nullptr);
	CHECK(nodeJ.GetPrevSibling() == &nodeG);

	CHECK(nodeM.GetChild() == nullptr);
	CHECK(nodeM.GetParent() == &nodeL);
	CHECK(nodeM.GetNextSibling() == &nodeN);
	CHECK(nodeM.GetPrevSibling() == nullptr);

	CHECK(nodeN.GetChild() == nullptr);
	CHECK(nodeN.GetParent() == &nodeL);
	CHECK(nodeN.GetNextSibling() == nullptr);
	CHECK(nodeN.GetPrevSibling() == &nodeM);

	CHECK(nodeO.GetChild() == nullptr);
	CHECK(nodeO.GetParent() == &nodeR);
	CHECK(nodeO.GetNextSibling() == &nodeP);
	CHECK(nodeO.GetPrevSibling() == nullptr);

	CHECK(nodeP.GetChild() == &nodeS);
	CHECK(nodeP.GetParent() == &nodeR);
	CHECK(nodeP.GetNextSibling() == &nodeQ);
	CHECK(nodeP.GetPrevSibling() == &nodeO);

	CHECK(nodeQ.GetChild() == nullptr);
	CHECK(nodeQ.GetParent() == &nodeR);
	CHECK(nodeQ.GetNextSibling() == nullptr);
	CHECK(nodeQ.GetPrevSibling() == &nodeP);

	CHECK(nodeH.GetChild() == nullptr);
	CHECK(nodeH.GetParent() == &nodeF);
	CHECK(nodeH.GetNextSibling() == nullptr);
	CHECK(nodeH.GetPrevSibling() == nullptr);

	CHECK(nodeS.GetChild() == &nodeT);
	CHECK(nodeS.GetParent() == &nodeP);
	CHECK(nodeS.GetNextSibling() == nullptr);
	CHECK(nodeS.GetPrevSibling() == nullptr);

	CHECK(nodeT.GetChild() == nullptr);
	CHECK(nodeT.GetParent() == &nodeS);
	CHECK(nodeT.GetNextSibling() == &nodeU);
	CHECK(nodeT.GetPrevSibling() == nullptr);

	CHECK(nodeU.GetChild() == nullptr);
	CHECK(nodeU.GetParent() == &nodeS);
	CHECK(nodeU.GetNextSibling() == &nodeV);
	CHECK(nodeU.GetPrevSibling() == &nodeT);

	CHECK(nodeV.GetChild() == nullptr);
	CHECK(nodeV.GetParent() == &nodeS);
	CHECK(nodeV.GetNextSibling() == &nodeW);
	CHECK(nodeV.GetPrevSibling() == &nodeU);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == &nodeS);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == &nodeV);

	CHECK(nodeH.GetNumChildren() == 0);
	CHECK(nodeF.GetNumChildren() == 1);
	CHECK(nodeD.GetNumChildren() == 1);
	CHECK(nodeA.GetNumChildren() == 3);
	CHECK(nodeE.GetNumChildren() == 0);
	CHECK(nodeI.GetNumChildren() == 2);
	CHECK(nodeG.GetNumChildren() == 0);
	CHECK(nodeJ.GetNumChildren() == 0);

	CHECK(nodeB.GetNumChildren() == 2);
	CHECK(nodeK.GetNumChildren() == 0);
	CHECK(nodeL.GetNumChildren() == 2);
	CHECK(nodeM.GetNumChildren() == 0);
	CHECK(nodeN.GetNumChildren() == 0);

	CHECK(nodeC.GetNumChildren() == 1);
	CHECK(nodeR.GetNumChildren() == 3);
	CHECK(nodeO.GetNumChildren() == 0);
	CHECK(nodeP.GetNumChildren() == 1);
	CHECK(nodeQ.GetNumChildren() == 0);
	CHECK(nodeS.GetNumChildren() == 4);
	CHECK(nodeT.GetNumChildren() == 0);
	CHECK(nodeU.GetNumChildren() == 0);
	CHECK(nodeV.GetNumChildren() == 0);
	CHECK(nodeW.GetNumChildren() == 0);

	CHECK(nodeRoot.GetNumChildren() == 3);

} TEST_END
#endif

#if fullTree_GetNumSiblings_Enable
TEST(fullTree_GetNumSiblings, PCSNode_group, fullTree_GetNumSiblings_Enable)
{
	PCSTree::Info info; 
	PCSTree tree;
	PCSNode  *root;

	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeB("Node_B");
	PCSNode nodeC("Node_C");
	PCSNode nodeD("Node_D");
	PCSNode nodeE("Node_E");
	PCSNode nodeI("Node_I");
	PCSNode nodeK("Node_K");
	PCSNode nodeL("Node_L");
	PCSNode nodeR("Node_R");
	PCSNode nodeF("Node_F");
	PCSNode nodeG("Node_G");
	PCSNode nodeJ("Node_J");
	PCSNode nodeM("Node_M");
	PCSNode nodeN("Node_N");
	PCSNode nodeO("Node_O");
	PCSNode nodeP("Node_P");
	PCSNode nodeQ("Node_Q");
	PCSNode nodeH("Node_H");
	PCSNode nodeS("Node_S");
	PCSNode nodeT("Node_T");
	PCSNode nodeU("Node_U");
	PCSNode nodeV("Node_V");
	PCSNode nodeW("Node_W");

	root = tree.GetRoot();

	tree.Insert(&nodeRoot, root);

	tree.Insert(&nodeC, &nodeRoot);
	tree.Insert(&nodeB, &nodeRoot);
	tree.Insert(&nodeA, &nodeRoot);
	tree.Insert(&nodeI, &nodeA);
	tree.Insert(&nodeE, &nodeA);
	tree.Insert(&nodeD, &nodeA);
	tree.Insert(&nodeL, &nodeB);
	tree.Insert(&nodeK, &nodeB);
	tree.Insert(&nodeR, &nodeC);
	tree.Insert(&nodeF, &nodeD);
	tree.Insert(&nodeJ, &nodeI);
	tree.Insert(&nodeG, &nodeI);
	tree.Insert(&nodeN, &nodeL);
	tree.Insert(&nodeM, &nodeL);
	tree.Insert(&nodeQ, &nodeR);
	tree.Insert(&nodeP, &nodeR);
	tree.Insert(&nodeO, &nodeR);
	tree.Insert(&nodeH, &nodeF);
	tree.Insert(&nodeS, &nodeP);
	tree.Insert(&nodeW, &nodeS);
	tree.Insert(&nodeV, &nodeS);
	tree.Insert(&nodeU, &nodeS);
	tree.Insert(&nodeT, &nodeS);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 24);

	CHECK(nodeRoot.GetChild() == &nodeA);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == &nodeD);
	CHECK(nodeA.GetParent() == &nodeRoot);
	CHECK(nodeA.GetNextSibling() == &nodeB);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == &nodeK);
	CHECK(nodeB.GetParent() == &nodeRoot);
	CHECK(nodeB.GetNextSibling() == &nodeC);
	CHECK(nodeB.GetPrevSibling() == &nodeA);

	CHECK(nodeC.GetChild() == &nodeR);
	CHECK(nodeC.GetParent() == &nodeRoot);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == &nodeB);

	CHECK(nodeD.GetChild() == &nodeF);
	CHECK(nodeD.GetParent() == &nodeA);
	CHECK(nodeD.GetNextSibling() == &nodeE);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeE.GetChild() == nullptr);
	CHECK(nodeE.GetParent() == &nodeA);
	CHECK(nodeE.GetNextSibling() == &nodeI);
	CHECK(nodeE.GetPrevSibling() == &nodeD);

	CHECK(nodeI.GetChild() == &nodeG);
	CHECK(nodeI.GetParent() == &nodeA);
	CHECK(nodeI.GetNextSibling() == nullptr);
	CHECK(nodeI.GetPrevSibling() == &nodeE);

	CHECK(nodeK.GetChild() == nullptr);
	CHECK(nodeK.GetParent() == &nodeB);
	CHECK(nodeK.GetNextSibling() == &nodeL);
	CHECK(nodeK.GetPrevSibling() == nullptr);

	CHECK(nodeL.GetChild() == &nodeM);
	CHECK(nodeL.GetParent() == &nodeB);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == &nodeK);

	CHECK(nodeR.GetChild() == &nodeO);
	CHECK(nodeR.GetParent() == &nodeC);
	CHECK(nodeR.GetNextSibling() == nullptr);
	CHECK(nodeR.GetPrevSibling() == nullptr);

	CHECK(nodeF.GetChild() == &nodeH);
	CHECK(nodeF.GetParent() == &nodeD);
	CHECK(nodeF.GetNextSibling() == nullptr);
	CHECK(nodeF.GetPrevSibling() == nullptr);

	CHECK(nodeG.GetChild() == nullptr);
	CHECK(nodeG.GetParent() == &nodeI);
	CHECK(nodeG.GetNextSibling() == &nodeJ);
	CHECK(nodeG.GetPrevSibling() == nullptr);

	CHECK(nodeJ.GetChild() == nullptr);
	CHECK(nodeJ.GetParent() == &nodeI);
	CHECK(nodeJ.GetNextSibling() == nullptr);
	CHECK(nodeJ.GetPrevSibling() == &nodeG);

	CHECK(nodeM.GetChild() == nullptr);
	CHECK(nodeM.GetParent() == &nodeL);
	CHECK(nodeM.GetNextSibling() == &nodeN);
	CHECK(nodeM.GetPrevSibling() == nullptr);

	CHECK(nodeN.GetChild() == nullptr);
	CHECK(nodeN.GetParent() == &nodeL);
	CHECK(nodeN.GetNextSibling() == nullptr);
	CHECK(nodeN.GetPrevSibling() == &nodeM);

	CHECK(nodeO.GetChild() == nullptr);
	CHECK(nodeO.GetParent() == &nodeR);
	CHECK(nodeO.GetNextSibling() == &nodeP);
	CHECK(nodeO.GetPrevSibling() == nullptr);

	CHECK(nodeP.GetChild() == &nodeS);
	CHECK(nodeP.GetParent() == &nodeR);
	CHECK(nodeP.GetNextSibling() == &nodeQ);
	CHECK(nodeP.GetPrevSibling() == &nodeO);

	CHECK(nodeQ.GetChild() == nullptr);
	CHECK(nodeQ.GetParent() == &nodeR);
	CHECK(nodeQ.GetNextSibling() == nullptr);
	CHECK(nodeQ.GetPrevSibling() == &nodeP);

	CHECK(nodeH.GetChild() == nullptr);
	CHECK(nodeH.GetParent() == &nodeF);
	CHECK(nodeH.GetNextSibling() == nullptr);
	CHECK(nodeH.GetPrevSibling() == nullptr);

	CHECK(nodeS.GetChild() == &nodeT);
	CHECK(nodeS.GetParent() == &nodeP);
	CHECK(nodeS.GetNextSibling() == nullptr);
	CHECK(nodeS.GetPrevSibling() == nullptr);

	CHECK(nodeT.GetChild() == nullptr);
	CHECK(nodeT.GetParent() == &nodeS);
	CHECK(nodeT.GetNextSibling() == &nodeU);
	CHECK(nodeT.GetPrevSibling() == nullptr);

	CHECK(nodeU.GetChild() == nullptr);
	CHECK(nodeU.GetParent() == &nodeS);
	CHECK(nodeU.GetNextSibling() == &nodeV);
	CHECK(nodeU.GetPrevSibling() == &nodeT);

	CHECK(nodeV.GetChild() == nullptr);
	CHECK(nodeV.GetParent() == &nodeS);
	CHECK(nodeV.GetNextSibling() == &nodeW);
	CHECK(nodeV.GetPrevSibling() == &nodeU);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == &nodeS);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == &nodeV);

	CHECK(nodeH.GetNumSiblings() == 1);
	CHECK(nodeF.GetNumSiblings() == 1);
	CHECK(nodeD.GetNumSiblings() == 3);
	CHECK(nodeA.GetNumSiblings() == 3);
	CHECK(nodeE.GetNumSiblings() == 3);
	CHECK(nodeI.GetNumSiblings() == 3);
	CHECK(nodeG.GetNumSiblings() == 2);
	CHECK(nodeJ.GetNumSiblings() == 2);

	CHECK(nodeB.GetNumSiblings() == 3);
	CHECK(nodeK.GetNumSiblings() == 2);
	CHECK(nodeL.GetNumSiblings() == 2);
	CHECK(nodeM.GetNumSiblings() == 2);
	CHECK(nodeN.GetNumSiblings() == 2);

	CHECK(nodeC.GetNumSiblings() == 3);
	CHECK(nodeR.GetNumSiblings() == 1);
	CHECK(nodeO.GetNumSiblings() == 3);
	CHECK(nodeP.GetNumSiblings() == 3);
	CHECK(nodeQ.GetNumSiblings() == 3);
	CHECK(nodeS.GetNumSiblings() == 1);
	CHECK(nodeT.GetNumSiblings() == 4);
	CHECK(nodeU.GetNumSiblings() == 4);
	CHECK(nodeV.GetNumSiblings() == 4);
	CHECK(nodeW.GetNumSiblings() == 4);

	CHECK(nodeRoot.GetNumSiblings() == 1);

} TEST_END
#endif

// ---  End of File ---------------
