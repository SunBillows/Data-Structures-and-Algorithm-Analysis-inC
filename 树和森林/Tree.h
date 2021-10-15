#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
#define MaxSize 100;

//���Ĵ洢�ṹ
//1.˫�ױ�ʾ��
typedef struct PTNode_Parents
{
	ElemType data1;		//�洢������
	int parent;			//˫�׽��λ����
}PTPNode;

typedef struct PTPTree
{
	PTPNode nodes[100];		//����һ���洢PTNode��������
	int r, n;					//r �� n ��ʾ����λ�úͽ����
}PTPTree;

//2.���������ʾ��
//���ȶ���ָ���ӵ���������
typedef struct child
{
	int pos;				//��������λ��
	struct child* next;		//�����ֵܣ������ָ�����ֵ�
}child;
//�ٶ���ÿ�����������������
typedef struct PTNode_Child
{
	ElemType data2;
	int parent;
	child* first_child;		//ָ���ӵ�ָ��
}PTCNode;
//���������
typedef struct PTCTree
{
	PTCNode nodes[100];
	int r, n;
}PTCTree;

//3.���Ķ��������ʾ����
typedef struct Tree
{
	ElemType data;
	struct Tree* first_child;
	struct Tree* brother_node;
}Tree_twoNode;


//����һ����
Tree_twoNode* Tree_Create();

//���ı���
//1.�����������
void PrevOrder_Tree(Tree_twoNode* T);
//2.���ĺ������
void PostRoot_Tree(Tree_twoNode* T);