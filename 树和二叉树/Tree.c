#include "Tree.h"

//ǰ�����
void PrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%c ", root->data);
	PrevOrder(root->_leftChild);
	PrevOrder(root->_rightChild);
}

//�������
void InOrder(BTNode* root)
{
	if (root == NULL)
		return;

	PrevOrder(root->_leftChild);
	printf("%c ", root->data);
	PrevOrder(root->_rightChild);
}

//�������
void PostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	PrevOrder(root->_leftChild);
	PrevOrder(root->_rightChild);
	printf("%c ", root->data);
}

//�����Ľ����������������ķ�����
void TreeSize1(BTNode* root, int* pSize)
{
	//��ĳ�����ĸ����������ʱ
	if (root == NULL)
		return;

	//������ʱ���������++
	++(*pSize);

	//Ȼ���ٱ�����������
	TreeSize1(root->_leftChild, pSize);
	TreeSize1(root->_rightChild, pSize);
}

//�����Ľ�����
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->_leftChild) + TreeSize(root->_rightChild) + 1;
}

//������Ҷ�ӽ�����
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

//�������Ĳ������
void LevelOrder(BTNode* root)
{

}