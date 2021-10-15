#include "Tree.h"


//创建一棵树
Tree_twoNode* Tree_Create()
{
	Tree_twoNode* T;

	char ch;
	ch = getchar();

	if (ch == '0')
		return NULL;

	//创建一个根节点
	T = (Tree_twoNode*)malloc(sizeof(Tree_twoNode));
	T->data = ch;
	T->first_child = Tree_Create();
	T->brother_node = Tree_Create();

	return T;
}

//树的遍历
//1.树的先根遍历
void PrevOrder_Tree(Tree_twoNode* T)
{
	if (T == NULL)
		return NULL;

	//打印根节点的数据
	printf("%c ", T->data);
	PrevOrder_Tree(T->first_child);
	PrevOrder_Tree(T->brother_node);
}

//2.树的后根遍历
void PostRoot_Tree(Tree_twoNode* T)
{
	if (T == NULL)
		return NULL;

	PostRoot_Tree(T->first_child);
	printf("%c ", T->data);
	PostRoot_Tree(T->brother_node);
}