/*
解题思路：
	创建两个新的链表，将满足条件的值放到两个链表之中，最后将两个链表进行链接就能得到最终的链表
*/


/*
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};
*/

typedef struct ListNode ListNode;
class Partition
{
public;
	ListNode* partition(ListNode* phead,int x)
	{
		//创建两个头结点和两个链表的标记
		ListNode* lessHead,*lessTail;
		ListNode* greaterHead,*greaterTail;
		
		//将两个头结点和标记定位哨兵位的头结点
		lessHead = lessTail = (ListNode*)malloc(sizeof(ListNode));
		greaterHead = greaterTail = (ListNode*)malloc(sizeof(ListNode));

		//将两个哨兵位的头结点的下一个地址赋值为NULL
		lessHead->next = greaterHead->next = NULL;

		//为phead链接设立一个标记
		ListNode* cur = phead;
		
		//循环遍历phead所有结点
		while(cur)
		{
			//如果当前结点的值小于给定的值val,则将cur结点链接至lessTail处
			if(cur->val < x)
			{
				lessTail->next = cur;
				lessTail = lessTail->next;
			}

			//如果当前结点的值大于给定的值val,则将cur结点链接至greaterTail处
			else
			{
				greaterTail->next = cur;
				greaterTail = greaterTail->next;
			}

			//将cur进行迭代
			cur = cur->next;
		}

		//为了防止出线带环，必须将第二个链表的尾部指向NULL
		greaterTail->next = NULL;

		//将其中一个链表的头部链接至另一个链表的尾部
		lessTail->next = greaterHead->next;
		
		ListNode* newhead = lessHead->next;
		free(lessHead);
		free(greaterHead);

		return newhead;
	}
}
