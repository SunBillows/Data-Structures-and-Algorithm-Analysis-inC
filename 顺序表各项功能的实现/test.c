#include "SeqList.h"

//测试头尾的插入删除
void TestSeqList1()
{
	//建立一个顺序表
	SL s;
	//初始化一个顺序表
	SeqListInit(&s);

	//尾插法函数的实现
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	Print(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	Print(&s);
	SeqListPushFront(&s, 10);
	SeqListPushFront(&s, 9);
	Print(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	Print(&s);
	SeqListFind(&s, 2);
	SeqListInsert(&s, 2, 3);
	SeqListInsert(&s, 3, 3);
	Print(&s);
	SeqListErase(&s, 3);
	Print(&s);
	SeqListErase(&s, 5);
	Print(&s);
}

int main()
{
	TestSeqList1();

	return 0;
}