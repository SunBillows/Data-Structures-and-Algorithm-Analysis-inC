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

//��ʼ��һ��˫������
ListNode* InitList();

//mallocһ�����ռ�
ListNode* BuyListNode(LTDataType x);

//��ӡ����
void ListPrint(ListNode* phead);

//β��βɾ
void ListPushBack(ListNode* phead, LTDataType x);
void ListPopBack(ListNode* phead);

//ͷ��ͷɾ
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);

//˫������Ĳ���
ListNode* ListFind(ListNode* phead, LTDataType x);

//������posλ��ǰ����롢ɾ��
void ListInsert(ListNode* pos,LTDataType x);
void ListErase(ListNode* pos);