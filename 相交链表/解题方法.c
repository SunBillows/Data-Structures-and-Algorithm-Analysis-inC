/*
解题思路：
	先计算两个链表的长度
	再让长链表向前走两个链表之间的差值，使两个链表的长度处于相同长度
	最后两个链表同时向前走，当两个地址一样时，则返回改地址，否则返回空
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    //首先计算出两个链表有多长
    int num1=0,num2=0;
    struct ListNode* cur1,*cur2;
    cur1 = headA;
    cur2 = headB;
    while(cur1)
    {
        num1++;
        cur1 = cur1->next;
    }
    while(cur2)
    {
        num2++;
        cur2 = cur2->next;
    }

    //找出长链表和锻炼表
    struct ListNode* Longlist = headA;
    struct ListNode* Shortlist = headB;
    if(num1 < num2)
    {
        Longlist = headB;
        Shortlist = headA;
    }

    //长链表向前走两个链表长度的差值使两个链表长度一样
    int gap = abs(num1 - num2);                 //找到差值
    while(gap--)
    {
        Longlist = Longlist->next;
    }

    //最后两者同时走，结点地址一样时就为相交点。否则返回NULL
    while(Longlist)
    {
        //当两者地址相同时，则此结点便为相交结点
        if(Longlist == Shortlist)
        {
            return Longlist;
        }
        //两者地址不同时，两个链表进行迭代
        else
            Longlist = Longlist->next;
            Shortlist = Shortlist->next;
    }
    //当链表遍历完成还没找到相交结点时，则两个链表没有交点，返回空
    return NULL;
}

