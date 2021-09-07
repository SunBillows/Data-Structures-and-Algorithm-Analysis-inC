/*
解题思路：
	我们使用两个指针，fast 与 slow。它们起始都位于链表的头部。随后，slow 指针每次向后移动一个位置，而 fast 指针向后移动两个位置。
如果链表中存在环，则 fast 指针最终将再次与 slow 指针在环中相遇。
	如下图所示，设链表中环外部分的长度为 a。slow 指针进入环后，又走了 b 的距离与 fast 相遇。此时，fast 指针已经走完了环的 n 圈，
因此它走过的总距离为 a+n(b+c)+b=a+(n+1)b+nc。

	根据题意，任意时刻，fast 指针走过的距离都为 slow 指针的 2 倍。因此，我们有a+(n+1)b+nc=2(a+b) 即 a=c+(n-1)(b+c)有了 a=c+(n−1)(b+c) 的等量关系，
我们会发现：从相遇点到入环点的距离加上 n−1 圈的环长，恰好等于从链表头部到入环点的距离。因此，当发现 slow 与 fast 相遇时，我们再额外使用一个指针 ptr。
起始，它指向链表头部；随后，它和 slow 每次向后移动一个位置。最终，它们会在入环点相遇。
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) 
{
    //先定义快慢指针
    struct ListNode* fast,*slow;
    fast = slow = head;

    //找到快慢指针相遇的地方
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }

    //当循环停止且快指针走到尾，则证明此链表没有环
    //当链表只有一个结点或为空链表时，此链表同样没有环
    if(fast == NULL || fast->next == NULL)
        return NULL;

    //再定义一个相遇结点
    struct ListNode* meet = slow;
    //相遇结点和头结点同时向后走一步，当两个相遇时此结点则为入环点
    while(head != meet)
    {
        head = head->next;
        meet = meet->next;
    }
    return meet;
}

