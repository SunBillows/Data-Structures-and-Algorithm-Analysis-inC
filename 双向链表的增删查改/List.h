#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;
typedef struct ListNode ListNode;

struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	int val;
};

//初始化一个双向链表
ListNode* InitList();

//malloc一个结点空间
ListNode* BuyListNode(LTDataType x);

//打印链表
void ListPrint(ListNode* phead);

//尾插尾删
void ListPushBack(ListNode* phead, LTDataType x);
void ListPopBack(ListNode* phead);

//头插头删
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);

//双向链表的查找
ListNode* ListFind(ListNode* phead, LTDataType x);

//在链表pos位置前面插入、删除
void ListInsert(ListNode* pos,LTDataType x);
void ListErase(ListNode* pos);