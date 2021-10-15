#include "Tree.h"


//����һ����
Tree_twoNode* Tree_Create()
{
	Tree_twoNode* T;

	char ch;
	ch = getchar();

	if (ch == '0')
		return NULL;

	//����һ�����ڵ�
	T = (Tree_twoNode*)malloc(sizeof(Tree_twoNode));
	T->data = ch;
	T->first_child = Tree_Create();
	T->brother_node = Tree_Create();

	return T;
}

//���ı���
//1.�����ȸ�����
void PrevOrder_Tree(Tree_twoNode* T)
{
	if (T == NULL)
		return NULL;

	//��ӡ���ڵ������
	printf("%c ", T->data);
	PrevOrder_Tree(T->first_child);
	PrevOrder_Tree(T->brother_node);
}

//2.���ĺ������
void PostRoot_Tree(Tree_twoNode* T)
{
	if (T == NULL)
		return NULL;

	PostRoot_Tree(T->first_child);
	printf("%c ", T->data);
	PostRoot_Tree(T->brother_node);
}