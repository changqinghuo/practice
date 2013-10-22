#include "StdAfx.h"
#include <iostream>
#include "001.h"
using namespace std;
void Interview_001::Run()
{
	m_pRoot = CreateBSTree();
	BSTreeNode* tail = NULL;
	//DeleteTree(m_pRoot->m_pLeft);
	//DeleteNode(m_pRoot, 10);
	std::cout << IsBST(m_pRoot) << std::endl;
	std::cout << IsBST(m_pRoot, -99, 99) << std::endl;
	DeleteNodeOutsideRange(m_pRoot, 11, 30);
	InOrder(m_pRoot);

// 	Transform(tail, m_pRoot);
// 	BSTreeNode* node = tail;
// 	while(node != NULL)
// 	{
// 		std::cout << node->m_nValue << std::endl;
// 		node = node->m_pLeft;
// 	}

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
void Interview_001::DeleteNode(BSTreeNode* &root, int n)
{

	if(root == NULL)
	{
		return;
	}

	if(n < root->m_nValue)
	{
		DeleteNode(root->m_pLeft, n);
	}
	else if(n > root->m_nValue)
	{
		DeleteNode(root->m_pRight, n);
	}
	else if( n == root->m_nValue)
	{
		if(root->m_pLeft == NULL)
		{
			BSTreeNode* right = root->m_pRight;
			delete root;
			root = right;
		}
		else if(root ->m_pRight == NULL)
		{
			BSTreeNode* left = root->m_pLeft;
			delete root;
			root = left;
		}
		else
		{
			BSTreeNode* curr = root->m_pRight;
			//find min data in the righ subtree
			BSTreeNode* parent = NULL;
			while(curr->m_pLeft != NULL)
			{
				parent = curr;
				curr = curr->m_pLeft;
			}
			int mindata = curr->m_nValue;
			root->m_nValue = mindata;
			if(parent != NULL)
			{
				parent->m_pLeft = NULL;
			}
			else
			{
				root->m_pRight = NULL;
			}
			
			delete curr;
			curr = NULL;
		}
	}
}
void Interview_001::DeleteTree(BSTreeNode* &root)
{
	if(root == NULL)
	{
		return;
	}
	DeleteTree(root->m_pLeft);
	DeleteTree(root->m_pRight);
	delete root;
	root = NULL;
}
bool Interview_001::IsBST(BSTreeNode* root, int min, int max)
{
	if(root == NULL)
	{
		return true;
	}
	if(root->m_nValue < min || root->m_nValue > max)
	{
		return false;
	}

	return IsBST(root->m_pLeft, min, root->m_nValue-1) &&
		   IsBST(root->m_pRight, root->m_nValue+1, max);

}
bool Interview_001::IsBST(BSTreeNode* root)
{
	static BSTreeNode* prev = NULL;
	if(root == NULL)
	{
		return true;
	}


	if(!IsBST(root->m_pLeft))
	{
		return false;
	}
	
	if(prev != NULL)
	{
		if(root->m_nValue < prev->m_nValue)
		{
			return false;
		}
	}
	prev = root;

	if(!IsBST(root->m_pRight))
	{
		return false;
	}

	return true;
}

void Interview_001::DeleteNodeOutsideRange(BSTreeNode* &root, int min, int max)
{
	//Method 1
	//post order: from leaves to root, delete leaves first and then root

	if(root == NULL)
	{
		return;
	}
	DeleteNodeOutsideRange(root->m_pLeft, min, max);
	DeleteNodeOutsideRange(root->m_pRight, min, max);

	if(root->m_nValue < min)
	{
		std::cout<< "deleting node: " << root->m_nValue << std::endl;
		BSTreeNode* right = root->m_pRight;
		delete root;
		root = right;
		return;
	}
	
	if(root->m_nValue > max)
	{
		std::cout<< "deleting node: " << root->m_nValue << std::endl;
		BSTreeNode* left = root->m_pLeft;
		delete root;
		root = left;
		return;
	}


//Method 2: preorder, if root < min, delete left tree and root, if root > max, delete right tree and root
// 	// not so elegant
// 	if(root == NULL)
// 	{
// 		return;
// 	}
// 	
// 	if(root->m_nValue < min)
// 	{
// 		DeleteTree(root->m_pLeft);
//	 	BSTreeNode* right = root->m_pRight;
// 		delete root;
// 		root = right;
// 		DeleteNodeOutsideRange(root, min, max);
// 
// 	}
// 	else if(root->m_nValue > max)
// 	{
// 		DeleteTree(root->m_pRight);
// 		BSTreeNode* left = root->m_pLeft;
// 		delete root;
// 		root = left;
// 		DeleteNodeOutsideRange(root, min, max);
// 	}
// 	else
// 	{
// 		DeleteNodeOutsideRange(root->m_pLeft, min, max);
// 		DeleteNodeOutsideRange(root->m_pRight, min, max);
// 
// 	}
//     std::cout << "processing node: " << root->m_nValue << std::endl;

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