#include "Tree.h"

//前序遍历
void PrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%c ", root->data);
	PrevOrder(root->_leftChild);
	PrevOrder(root->_rightChild);
}

//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
		return;

	PrevOrder(root->_leftChild);
	printf("%c ", root->data);
	PrevOrder(root->_rightChild);
}

//后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	PrevOrder(root->_leftChild);
	PrevOrder(root->_rightChild);
	printf("%c ", root->data);
}

//求树的结点个数（遍历计数的方法）
void TreeSize1(BTNode* root, int* pSize)
{
	//当某棵树的根结点无数据时
	if (root == NULL)
		return;

	//有数据时，则结点个数++
	++(*pSize);

	//然后再遍历各个子树
	TreeSize1(root->_leftChild, pSize);
	TreeSize1(root->_rightChild, pSize);
}

//求树的结点个数
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->_leftChild) + TreeSize(root->_rightChild) + 1;
}

//求树的叶子结点个数
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else if (root->_leftChild == NULL && root->_rightChild == NULL)
		return 1;
	else
		return TreeLeafSize(root->_leftChild) + TreeLeafSize(root->_rightChild);
	//return (root->_leftChild == NULL && root->_rightChild == NULL) ? 1 : TreeLeafSize(root->_leftChild) + TreeLeafSize(root->_rightChild);
}

//二叉树的层序遍历
void LevelOrder(BTNode* root)
{

}