#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
//顺序表，有效数据在数组中必须是连续的
//静态顺序表的设计（顺序表大小固定）

typedef int SLDateType;
#define N 10;

struct SeqList
{
	SLDateType a[N];
	int size;
};

//使用尾插法
void SeqListPushBack(struct SeqList* ps, SLDateType x);
void SeqListPopBack(struct SeqList* ps);
//使用头插法
void SeqListPushFront(struct SeqList* ps, SLDateType x);
void SeqListPopFront(struct SeqList* ps);
*/

//动态顺序表设计（大小可变）
typedef int SLDateType;

typedef struct SeqList
{
	SLDateType* array;
	int size;			//有效数据的个数
	int capacity;		//容量
}SL;

//初始化顺序表
void SeqListInit(SL* s);
//打印函数
void Print(SL* ps);
//扩容接口
void SeqListCheckCapacity(SL* ps);

//尾插尾删
void SeqListPushBack(SL* ps, SLDateType x);
void SeqListPopBack(SL* ps);

//头插头删
void SeqListPushFront(SL* ps, SLDateType x);
void SeqListPopFront(SL* ps);

//顺序表的查找
void SeqListFind(SL* ps, SLDateType x);

//在任意位置插入或删除元素
void SeqListInsert(SL* ps, int pos, SLDateType x);
void SeqListErase(SL* ps, int pos);