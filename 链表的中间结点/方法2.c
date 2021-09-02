/*
解题思路：
	使用快慢指针，快指针每次走两次，慢指针每次走一次
	如果快指针走到尾部代表慢指针处于链表的正中间位置
	此时返回慢指针
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head)
{
    //定义快慢指针
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while(fast)
    {
        if(fast->next == NULL)
        {
            break;
        }
        else
            fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

