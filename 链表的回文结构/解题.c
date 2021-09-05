/*
解题思路：
	首先通过快慢指针找到中间结点，再将中间结点之后的链表尽心反转
	最后再一个个比较A链表和反转的之后的链表的值，最后判断此链表是否为回文链表
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
class PalindromeList
{
public:
	bool chkPalindrome(ListNode* A)
	{
		//定义快慢指针
		ListNode* slow,*fast;
		slow = fast = A;

		//如果快指针为NULL或者快指针的next为空则跳出循环
		while(fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		//再将slow链表进行逆置
		ListNode* prev,*head,*tail;
		prev = NULL;
		head = slow;
		tail = slow->next;
		while(head)
		{
			head->next = prev;
			prev = head;
			head = tail;
			if(tail)
				tail = tail->next;
		}

		//再将两个新链表一个个进行对比
		while(prev)
		{
			//如果两个数相等，则进行迭代
			if(prev->val == A->val)
			{
				prev = prev->next;
				A = A->next;
			}
			//若有一组数不相等，则此链表不是回文链表
			else
				return false;
		}
		return true;
	}
};
