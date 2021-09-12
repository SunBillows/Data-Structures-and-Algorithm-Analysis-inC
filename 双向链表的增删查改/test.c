#include "List.h"

void TestList()
{
	ListNode* phead = InitList();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint(phead);
	ListPopBack(phead);
	ListPrint(phead);
	ListPushFront(phead, 3);
	ListPushFront(phead, 4);
	ListPrint(phead);
	ListPopFront(phead);
	ListPopFront(phead);
	ListPopFront(phead);
	ListPrint(phead);
	ListNode* pos = ListFind(phead, 2);
	ListInsert(pos, 4);
	ListPrint(phead);
	ListErase(pos);


}


int main()
{
	TestList();

	return 0;
}