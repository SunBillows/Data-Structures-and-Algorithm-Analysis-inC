#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SListDateType;

//建立结点 
typedef struct SListNode
{
	SListDateType data;
	struct SListNode* next;
}SListNode;

//尾插尾删
void SListPushBack(SListNode** pphead, SListDateType x);
void SListPopBack(SListNode** pphead);

//头插头删
void SListPushFront(SListNode** pphead, SListDateType x);
void SListPopFront(SListNode** pphead);

//查找链表
SListNode* SListFind(SListNode* phead, SListDateType x);

//单链表在pos位置后插入x   /删除pos后的结构体
void SListInsertAfter(SListNode* pos, SListDateType x);
void SListEraseAfter(SListNode* pos);

//打印链表
void SListPrint(SListNode* phead); 

//建立一个结构体
SListNode* BuySListNode(SListDateType x);
