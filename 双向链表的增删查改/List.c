#include "List.h"

//初始化一个双向链表
ListNode* InitList()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}
//申请一个结点空间
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->val = x;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

//打印链表
void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	
	while (cur != phead)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

//尾插
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* tail = phead->prev;
	ListNode* newNode = BuyListNode(x);

	tail->next = newNode; 
	newNode->prev = tail;

	newNode->next = phead;
	phead->prev = newNode;
}

//尾删
void ListPopBack(ListNode* phead)
{
	assert(phead);

	//定义链表尾部为tail,其中tail的位置为头结点的prev所指向的结点的prev；
	ListNode* tail = phead->prev->prev;

	//找到倒数第二个尾部指针后，进行删除
	free(tail->next);

	tail->next = phead;
	phead->prev = tail;

	//tail = NULL;
}

//头插
void ListPushFront(ListNode* phead, LTDataType x)
{
	//先创建一个结点
	ListNode* newNode = BuyListNode(x);

	//将结点插入到头结点和第一个结点中间实现头插
	newNode->next = phead->next;
	newNode->prev = phead;
	phead->next = newNode;
}

//头删
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* First = phead->next;
	ListNode* Second = First->next;

	phead->next = Second;
	Second->prev = phead;
	free(First);
}

//双向链表的查找
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* cur = phead->next;
	while (cur != phead)	
	{
		if (cur->val == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//在链表中的pos位置之前插入一个数据为x的结点
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* newNode = BuyListNode(x);
	ListNode* posPrev = pos->prev;

	posPrev->next = newNode;
	newNode->prev = posPrev;
	newNode->next = pos;
	pos->prev = newNode;
}

//在链表中的pos位置之前删除一个结点
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
}
