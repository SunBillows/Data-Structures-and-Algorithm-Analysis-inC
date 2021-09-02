/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/

/*
解题思路：
	首先创建两个结点cur和prev（prev位于cur的前面）
	当cur为所删除的结点时，prev->next指向cur->next。然后释放到cur所在的结点。最后cur=prev->next；
*/

struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;

    while(cur)
    {
        //当结点为所删除的结点时
        if(cur->val == val)
        {
            //如果所删除的结点为头结点时
            if(cur == head)
            {
                head = cur->next;
                free(cur);
                cur = head;
            }
            //所删除的结点不为头结点时
            else
            {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}

