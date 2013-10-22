#ifndef FILE001_H
#define FILE001_H

#include "global.h"
//1.�Ѷ�Ԫ������ת��������˫������
//��Ŀ��
//����һ�ö�Ԫ�����������ö�Ԫ������ת����һ�������˫������
//Ҫ���ܴ����κ��µĽ�㣬ֻ����ָ���ָ��
//10
/// \
//6 14
/// \ / \
//4 8 12 16
//ת����˫������
//4=6=8=10=12=14=16��
//�������Ƕ���Ķ�Ԫ�������ڵ�����ݽṹ���£�
//struct BSTreeNode
//{
//int m_nValue; // value of node
//BSTreeNode *m_pLeft; // left child of node
//BSTreeNode *m_pRight; // right child of node
//};
struct  BSTreeNode{
	int m_nValue;
	BSTreeNode* m_pLeft;
	BSTreeNode* m_pRight;
};

class Interview_001:public Interview
{
public:
	void Run();
private:
	BSTreeNode* CreateBSTree();
	void InsertNode(BSTreeNode* &root, int n);

	void DeleteNode(BSTreeNode* &root, int n);
	void DeleteNodeOutsideRange(BSTreeNode* &root, int min, int max);
	void DeleteTree(BSTreeNode* &root);
	bool IsBST(BSTreeNode* &root);

	void InOrder(BSTreeNode* root);
	void PreOrder(BSTreeNode* root);
    void PostOrder(BSTreeNode* root);

	void Transform(BSTreeNode* &pLastNodeInList, BSTreeNode* root);
	BSTreeNode* m_pRoot;


	
};

#endif