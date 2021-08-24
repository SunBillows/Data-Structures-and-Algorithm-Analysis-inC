#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
//˳�����Ч�����������б�����������
//��̬˳������ƣ�˳����С�̶���

typedef int SLDateType;
#define N 10;

struct SeqList
{
	SLDateType a[N];
	int size;
};

//ʹ��β�巨
void SeqListPushBack(struct SeqList* ps, SLDateType x);
void SeqListPopBack(struct SeqList* ps);
//ʹ��ͷ�巨
void SeqListPushFront(struct SeqList* ps, SLDateType x);
void SeqListPopFront(struct SeqList* ps);
*/

//��̬˳�����ƣ���С�ɱ䣩
typedef int SLDateType;

typedef struct SeqList
{
	SLDateType* array;
	int size;			//��Ч���ݵĸ���
	int capacity;		//����
}SL;

//��ʼ��˳���
void SeqListInit(SL* s);
//��ӡ����
void Print(SL* ps);
//���ݽӿ�
void SeqListCheckCapacity(SL* ps);

//β��βɾ
void SeqListPushBack(SL* ps, SLDateType x);
void SeqListPopBack(SL* ps);

//ͷ��ͷɾ
void SeqListPushFront(SL* ps, SLDateType x);
void SeqListPopFront(SL* ps);

//˳���Ĳ���
void SeqListFind(SL* ps, SLDateType x);

//������λ�ò����ɾ��Ԫ��
void SeqListInsert(SL* ps, int pos, SLDateType x);
void SeqListErase(SL* ps, int pos);