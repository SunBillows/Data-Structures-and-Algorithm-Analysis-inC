#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

//二叉树的定义
typedef struct BinarryTreeNode
{
	struct BinarryTreeNode* _leftChild;
	struct BinarryTreeNode* _rightChild;
	DataType data;
}BTNode;

//前序遍历
void PrevOrder(BTNode* root);

//中序遍历
void InOrder(BTNode* root);

//后序遍历
void PostOrder(BTNode* root);

//求树的结点个数(遍历计数方法)
void TreeSize1(BTNode* root, int* pSize);

//求树的结点个数
int TreeSize(BTNode* root);

//求树的叶子结点个数
int TreeLeafSize(BTNode* root);

//二叉树的层序遍历
void LevelOrder(BTNode* root);