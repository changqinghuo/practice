#include "StdAfx.h"
#include <iostream>
#include "001.h"
using namespace std;
void Interview_001::Run()
{
	m_pRoot = CreateBSTree();
	BSTreeNode* tail = NULL;
	Transform(tail, m_pRoot);
	BSTreeNode* node = tail;
	while(node != NULL)
	{
		std::cout << node->m_nValue << std::endl;
		node = node->m_pLeft;
	}

}

void Interview_001::Transform(BSTreeNode* &pLastNodeInList, BSTreeNode* root)
{
	if(root == NULL)
	{
	    return;
	}
	if(root->m_pLeft != NULL)
	{
		Transform(pLastNodeInList, root->m_pLeft);
	}
	root->m_pLeft = pLastNodeInList;
	if(pLastNodeInList != NULL)
	{
		pLastNodeInList->m_pRight = root;		
	}
	pLastNodeInList = root;

	if(root->m_pRight != NULL)
	{
		Transform(pLastNodeInList, root->m_pRight);
	}

	

	
}

BSTreeNode* Interview_001::CreateBSTree()
{
	
	int ary[] = {10, 6, 4, 8, 14, 12, 16};
	BSTreeNode* root = NULL;
	for(int i = 0; i < 7; i++)
	{
		InsertNode(root, ary[i]);
	}
	return root;

}

void Interview_001::InsertNode(BSTreeNode* &root, int n)
{
      if(root == NULL)
	  {
		  root = new BSTreeNode;
		  root->m_nValue = n;
		  root->m_pLeft = NULL;
		  root->m_pRight = NULL;
		  return;
	  }
	  BSTreeNode* node = root;
	  BSTreeNode* parent = NULL;
	  while(node != NULL)
	  {
		  parent = node;
		  if(node->m_nValue > n)
		  {
			  node = node->m_pLeft;			 
		  }
		  else
		  {
			  node = node->m_pRight;
		  }		  
	  }

	  if(parent != NULL)
	  {
		  BSTreeNode* newnode = new BSTreeNode;
		  newnode->m_nValue = n;
		  newnode->m_pLeft = NULL;
		  newnode->m_pRight = NULL;
		  if(parent->m_nValue > n)
		  {
			  parent->m_pLeft = newnode;
		  }
		  else
		  {
			  parent->m_pRight = newnode;
		  }
	  }
}

void Interview_001::InOrder(BSTreeNode* root)
{
	if(root != NULL)
	{		
		InOrder(root->m_pLeft);			
	    std::cout << root->m_nValue << std::endl;
		InOrder(root->m_pRight);
	}	

}
void Interview_001::PreOrder(BSTreeNode* root)
{
	if(root != NULL)
	{
		std::cout << root->m_nValue << std::endl;
		PreOrder(root->m_pLeft);	    
		PreOrder(root->m_pRight);
	}	

}

void Interview_001::PostOrder(BSTreeNode* root)
{
	if(root != NULL)
	{		
		PostOrder(root->m_pLeft);	    
		PostOrder(root->m_pRight);
		std::cout << root->m_nValue << std::endl;
	}	

}