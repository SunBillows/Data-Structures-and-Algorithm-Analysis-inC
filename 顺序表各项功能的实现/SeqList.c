#include "SeqList.h"

//初始化顺序表
void SeqListInit(SL* c)
{
	c->array = (SLDateType*)malloc(sizeof(SL)*10);
	//如果分配空间失败
	if (c->array == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);
	}
	c->size = 0;
	c->capacity = 10;
}

//尾插法的实现
void SeqListPushBack(SL* ps, SLDateType x)
{
	//确保传入的数据不为空
	assert(ps);

	//当分配的内存空间容量已满时
	SeqListCheckCapacity(ps);
	//将值插入数组中
	ps->array[ps->size] = x;
	//插入完成后，地址+1，指向下一个数组地址
	ps->size++;
}

//尾删
void SeqListPopBack(SL* ps)
{
	assert(ps);
	ps->array[ps->size - 1] = 0;
	ps->size--;
}

//头插法
void SeqListPushFront(SL* ps, SLDateType x)
{
	assert(ps);

	SeqListCheckCapacity(ps);

	SLDateType end = ps->size-1;

	while(end>=0)
	{
		ps->array[end + 1] = ps->array[end];
		end--;
	}
	ps->array[0] = x;
	ps->size++;
}

//头删法
void SeqListPopFront(SL* ps)
{
	assert(ps);
	SLDateType star = 0;

	while(star < ps->size-1)
	{
		ps->array[star] = ps->array[star+1];
		star++;
	}
	ps->size--;
}

//顺序表的查找
void SeqListFind(SL* ps, SLDateType x)
{
	int count = 1;

	for (count; count < ps->size+1; count++)
	{
		if (ps->array[count-1] == x)
			printf("%d ", count);
	}
	printf("\n");
}

//在任意位置插入元素
void SeqListInsert(SL* ps, int pos, SLDateType x)
{
	assert(ps);

	SeqListCheckCapacity(ps);

	for (int i = ps->size; i >= pos - 1; i--)
	{
		ps->array[i + 1] = ps->array[i];
	}
	ps->array[pos - 1] = x;
	ps->size++;
}

//在任意位置删除元素
void SeqListErase(SL* ps, int pos)
{
	assert(ps);

	SeqListCheckCapacity(ps);

	for (int i = pos - 1; i < ps->size-1; i++)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}

//打印函数
void Print(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
		printf("%d ", ps->array[i]);
	printf("\n");
}
//扩容接口
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size >= ps->capacity)
	{
		ps->capacity = ps->capacity * 2;
		ps->array = (SLDateType*)realloc(ps->array, sizeof(SL) * ps->capacity);
		
		//如果扩容空间失败
		if (ps->array == NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
	}
}