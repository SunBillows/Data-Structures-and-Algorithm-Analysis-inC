#include "List.h"

//��ʼ��һ��˫������
ListNode* InitList()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}
//����һ�����ռ�
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->val = x;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

//��ӡ����
void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	
	while (cur != phead)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

//β��
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* tail = phead->prev;
	ListNode* newNode = BuyListNode(x);

	tail->next = newNode; 
	newNode->prev = tail;

	newNode->next = phead;
	phead->prev = newNode;
}

//βɾ
void ListPopBack(ListNode* phead)
{
	assert(phead);

	//��������β��Ϊtail,����tail��λ��Ϊͷ����prev��ָ��Ľ���prev��
	ListNode* tail = phead->prev->prev;

	//�ҵ������ڶ���β��ָ��󣬽���ɾ��
	free(tail->next);

	tail->next = phead;
	phead->prev = tail;

	//tail = NULL;
}

//ͷ��
void ListPushFront(ListNode* phead, LTDataType x)
{
	//�ȴ���һ�����
	ListNode* newNode = BuyListNode(x);

	//�������뵽ͷ���͵�һ������м�ʵ��ͷ��
	newNode->next = phead->next;
	newNode->prev = phead;
	phead->next = newNode;
}

//ͷɾ
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	ListNode* First = phead->next;
	ListNode* Second = First->next;

	phead->next = Second;
	Second->prev = phead;
	free(First);
}

//˫������Ĳ���
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* cur = phead->next;
	while (cur != phead)	
	{
		if (cur->val == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//�������е�posλ��֮ǰ����һ������Ϊx�Ľ��
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* newNode = BuyListNode(x);
	ListNode* posPrev = pos->prev;

	posPrev->next = newNode;
	newNode->prev = posPrev;
	newNode->next = pos;
	pos->prev = newNode;
}

//�������е�posλ��֮ǰɾ��һ�����
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
}
