#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SListDateType;

//������� 
typedef struct SListNode
{
	SListDateType data;
	struct SListNode* next;
}SListNode;

//β��βɾ
void SListPushBack(SListNode** pphead, SListDateType x);
void SListPopBack(SListNode** pphead);

//ͷ��ͷɾ
void SListPushFront(SListNode** pphead, SListDateType x);
void SListPopFront(SListNode** pphead);

//��������
SListNode* SListFind(SListNode* phead, SListDateType x);

//��������posλ�ú����x   /ɾ��pos��Ľṹ��
void SListInsertAfter(SListNode* pos, SListDateType x);
void SListEraseAfter(SListNode* pos);

//��ӡ����
void SListPrint(SListNode* phead); 

//����һ���ṹ��
SListNode* BuySListNode(SListDateType x);
