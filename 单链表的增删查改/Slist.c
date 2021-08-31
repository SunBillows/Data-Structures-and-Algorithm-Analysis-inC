#include "SList.h"

void SListPrint(SListNode* phead)
{
	//����һ����ǰָ��ָ��ͷ���
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SListNode* BuySListNode(SListDateType x)
{
	//����һ�����нṹ��
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));

	//�������ʧ��
	if (newNode == NULL)
	{
		printf("����ռ�ʧ��\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}

void SListPushBack(SListNode** pphead, SListDateType x)
{
	if (*pphead == NULL)
	{
		*pphead = BuySListNode(x); 
	}
	else
	{
		SListNode* tail = *pphead;
		//���������ҵ�β���
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = BuySListNode(x);
	}
}

void SListPopBack(SListNode** pphead)
{
	//������û�н��ʱ
	if (*pphead == NULL)
	{
		return;
	}
	//��������һ�����ʱ
	else if ((*pphead)->next == NULL)
	{
		//���ͷŵ�һ�����ռ�
		free(*pphead);

		//����ͷ���ָ���
		*pphead = NULL;
	}
	//��������һ�����Ͻ��ʱ
	else
	{
		SListNode* cur = *pphead;
		//�ҵ������ڶ������λ��
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		
		//�ͷ����һ�����Ŀռ�
		free(cur->next);

		//�������ڶ������λ��ָ��գ�ɾ�����һ�����
		cur->next = NULL;
	}
}
	
void SListPushFront(SListNode** pphead, SListDateType x)
{
	//�ȴ���һ���½ṹ��������
	SListNode* newNode = BuySListNode(x);

	//���������Ϊ��ʱ
	if (*pphead == NULL)
	{
		*pphead = newNode;
		newNode->next = NULL;
	}
	else
	{
		newNode->next = *pphead;
		*pphead = newNode;
	}
}

void SListPopFront(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	else
	{
		SListNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}

SListNode* SListFind(SListNode* phead, SListDateType x)
{
	SListNode* cur = phead;
	
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsertAfter(SListNode* pos, SListDateType x)
{
	assert(pos);

	SListNode* newNode = BuySListNode(x);

	newNode->next = pos->next;
	pos->next = newNode;
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);

	if (pos->next)
	{
		SListNode* next = pos->next->next;
		pos->next = next;
		free(pos->next);
	}
	
}

