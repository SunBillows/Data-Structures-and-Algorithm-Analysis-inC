#include "SList.h"

void SListPrint(SListNode* phead)
{
	//定义一个当前指针指向头结点
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SListNode* BuySListNode(SListDateType x)
{
	//新增一个空闲结构体
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));

	//如果开辟失败
	if (newNode == NULL)
	{
		printf("申请空间失败\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}

void SListPushBack(SListNode** pphead, SListDateType x)
{
	if (*pphead == NULL)
	{
		*pphead = BuySListNode(x); 
	}
	else
	{
		SListNode* tail = *pphead;
		//遍历链表找到尾结点
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = BuySListNode(x);
	}
}

void SListPopBack(SListNode** pphead)
{
	//当链表没有结点时
	if (*pphead == NULL)
	{
		return;
	}
	//当链表有一个结点时
	else if ((*pphead)->next == NULL)
	{
		//先释放第一个结点空间
		free(*pphead);

		//再让头结点指向空
		*pphead = NULL;
	}
	//当链表有一个以上结点时
	else
	{
		SListNode* cur = *pphead;
		//找到倒数第二个结点位置
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		
		//释放最后一个结点的空间
		free(cur->next);

		//将倒数第二个结点位置指向空，删除最后一个结点
		cur->next = NULL;
	}
}
	
void SListPushFront(SListNode** pphead, SListDateType x)
{
	//先创建一个新结构用来插入
	SListNode* newNode = BuySListNode(x);

	//如果此链表为空时
	if (*pphead == NULL)
	{
		*pphead = newNode;
		newNode->next = NULL;
	}
	else
	{
		newNode->next = *pphead;
		*pphead = newNode;
	}
}

void SListPopFront(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	else
	{
		SListNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}

SListNode* SListFind(SListNode* phead, SListDateType x)
{
	SListNode* cur = phead;
	
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsertAfter(SListNode* pos, SListDateType x)
{
	assert(pos);

	SListNode* newNode = BuySListNode(x);

	newNode->next = pos->next;
	pos->next = newNode;
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);

	if (pos->next)
	{
		SListNode* next = pos->next->next;
		pos->next = next;
		free(pos->next);
	}
	
}

