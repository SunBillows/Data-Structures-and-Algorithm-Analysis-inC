/*
解题思路：
	先遍历一遍单链表，查出此链表有几个结点
	然后再重新遍历单链表，直到找到中间的结点
	最后将其返回
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
    int i = 0;
    struct ListNode* cur = head;

    //遍历链表，找到此链表一共有多少个结点
    while(cur)
    {
        cur = cur->next;
        i++;
    }
    i = i/2;
    while(i)
    {
        i--;
        head = head->next;
    }
    return head;
}

