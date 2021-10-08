#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

//�������Ķ���
typedef struct BinarryTreeNode
{
	struct BinarryTreeNode* _leftChild;
	struct BinarryTreeNode* _rightChild;
	DataType data;
}BTNode;

//ǰ�����
void PrevOrder(BTNode* root);

//�������
void InOrder(BTNode* root);

//�������
void PostOrder(BTNode* root);

//�����Ľ�����(������������)
void TreeSize1(BTNode* root, int* pSize);

//�����Ľ�����
int TreeSize(BTNode* root);

//������Ҷ�ӽ�����
int TreeLeafSize(BTNode* root);

//�������Ĳ������
void LevelOrder(BTNode* root);