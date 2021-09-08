/*
解题思路：
	先将原链表的头结点单独拿出来作为排序后的链表的头结点，并指向空
		即：sorthead = head; 
			sorthead->next = NULL;
			cur = head->next;
	在循环遍历源链表，如果cur的值小于sorthead的值，就进行头插;
	如果排序链表中存在多个结点，则将cur结点与排序链表中的所有结点一一相比较，找到所插入位置并进行插入；
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head)
{
    //如果此链表只有一个结点或者没有结点，则返回空
    if(head == NULL || head->next == NULL)
        return head;
    
    //建立一个新的排序链表
    struct ListNode* sorthead = head;
    struct ListNode* cur = head->next;
    sorthead->next =NULL;

    //当cur不为空时，进入循环
    while(cur)
    {
        //将cur的下一个结点进行保存，存入next中
        struct ListNode* next = cur->next;

        //将cur插入到sorthead链表中，并且保持有序
        //头插时
        if(cur->val <= sorthead->val)
        {
            cur->next = sorthead;
            sorthead = cur;
        }
        //中间插
        else
        {
            struct ListNode* sortprev = sorthead;
            struct ListNode* sortcur = sorthead->next;
            while(sortcur)
            {
                //当cur的值小于sortcur的值时，将cur插入到sortcur的前面
                if(sortcur->val > cur->val)
                {
                    sortprev->next = cur;
                    cur->next = sortcur;
                    break;
                }

                //当cur的值大于sortcur的值时，
                else
                {
                    //进行迭代，将cur与sortcur的下一个结点进行比较
                    sortprev = sortcur;
                    sortcur = sortcur->next;
                }
            }
            if(sortcur == NULL)
            {
                //sortcur为空，说明cur的值大于sorthead链表中所有结点的值，此时进行尾插
                sortprev->next = cur;
                cur->next = sortcur;
            }
        }
        //插入完成后将cur进行迭代，开启下一个结点的插入
        cur = next;
    }

    return sorthead;
}

