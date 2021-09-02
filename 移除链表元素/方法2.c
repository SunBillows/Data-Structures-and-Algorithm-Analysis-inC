/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/

/*
解题思路
	链表的定义具有递归的性质，因此链表题目常可以用递归的方法求解。这道题要求删除链表中所有节点值等于特定值的节点，可以用递归实现。
	对于给定的链表，首先对除了头节点 \textit{head}head 以外的节点进行删除操作，然后判断 head 的节点值是否等于给定的 val。
如果 head 的节点值等于 val，则 head 需要被删除，因此删除操作后的头节点为 head.next；如果 head 的节点值不等于 val，则 head 保留，
因此删除操作后的头节点还是 head。上述过程是一个递归的过程。
	递归的终止条件是 head 为空，此时直接返回 head。当 head 不为空时，递归地进行删除操作，然后判断 head 的节点值是否等于 val 并决定是否要删除 head。
*/

struct ListNode* removeElements(struct ListNode* head, int val) 
{
    if (head == NULL) 
	{
        return head;
    }
	
    head->next = removeElements(head->next, val);
	
    return head->val == val ? head->next : head;
}

