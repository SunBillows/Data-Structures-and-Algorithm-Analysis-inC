#include "SList.h"

void TestList1()
{
	SListNode* pList = NULL;	//为头结点，指向空

	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);
	SListPopBack(&pList);
	SListPrint(pList);
	SListPushFront(&pList, 5);
	SListPushFront(&pList, 6);
	SListPushFront(&pList, 7);
	SListPrint(pList);
	SListPushBack(&pList, 4);
	SListPopFront(&pList);
	SListPrint(pList);

}

int main()
{
	TestList1();

	return 0;
}