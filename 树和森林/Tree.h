#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
#define MaxSize 100;

//树的存储结构
//1.双亲表示法
typedef struct PTNode_Parents
{
	ElemType data1;		//存储的数据
	int parent;			//双亲结点位置域
}PTPNode;

typedef struct PTPTree
{
	PTPNode nodes[100];		//定义一个存储PTNode结点的数组
	int r, n;					//r 和 n 表示根的位置和结点数
}PTPTree;

//2.孩子链表表示法
//首先定义指向孩子的数据类型
typedef struct child
{
	int pos;				//长子所在位置
	struct child* next;		//若有兄弟，则继续指向其兄弟
}child;
//再定义每个数组结点的数据类型
typedef struct PTNode_Child
{
	ElemType data2;
	int parent;
	child* first_child;		//指向长子的指针
}PTCNode;
//最后定义数组
typedef struct PTCTree
{
	PTCNode nodes[100];
	int r, n;
}PTCTree;

//3.树的二叉链表表示方法
typedef struct Tree
{
	ElemType data;
	struct Tree* first_child;
	struct Tree* brother_node;
}Tree_twoNode;


//创建一棵树
Tree_twoNode* Tree_Create();

//树的遍历
//1.树的先序遍历
void PrevOrder_Tree(Tree_twoNode* T);
//2.树的后根遍历
void PostRoot_Tree(Tree_twoNode* T);