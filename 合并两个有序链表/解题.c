/*

解题思路：
	通过定义一个新的头结点，将所给两个链表中较小的元素的地址链接给新的结点。
	链接完成后将较小的链表向后移动一位，并继续比较大小
	最后将不为NULL的链表直接链接给新链表从而完成合并。
	
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    //当两个链表中某个链表为空时，则直接返回另一个链表
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;

    //定义两个指针，newhead为代插入的链表的头结点，headtail为新链表的标记地址
    struct ListNode* newhead = NULL;
    struct ListNode* headtail = NULL;

    //直接malloc一个结构体，并将其地址赋值给newhead形成头结点
    //此为带哨兵位的头结点，其不存储有效数据，只为了方便尾插
    newhead = headtail = (struct ListNode*)malloc(sizeof(struct ListNode));

/*
    //先将两个链表中较小的一个地址赋值给newhead和headtail，作为新链表的头结点
    if(l1->val <= l2->val)
    {
        newhead = l1;
        headtail = l1;
        l1 = l1->next;      //l1向后移动
    }
    else
    {
        newhead = l2;
        headtail = l2;
        l2 = l2->next;      //l2向后移动
    }
*/

    //当两者都不为空时，进入循环
    while(l1 && l2)
    {
        //将小的那一个结点赋值给headtail，同时自己向后移动
        if(l1->val < l2->val)
        {
            headtail->next = l1;
            l1 = l1->next;
        }
        else
        {
            headtail->next = l2;
            l2 = l2->next;
        }

        //链表链接成功后，headtail向后移动
        headtail = headtail->next;
    }

    //循环结束后，不为空的那个链表直接链接到headtail之后完成合并
    if(l1)
        headtail->next = l1;
    else
        headtail->next = l2;

    struct ListNode* realhead = newhead->next;
    free(newhead);

    return realhead;
}

