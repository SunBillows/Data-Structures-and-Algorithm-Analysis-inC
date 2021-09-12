/*
方法二：直接删除法
根据方法一，可以优化，在遍历单链表的时候，检查当前节点与下一点是否为相同值，如果相同，继续查找祥同值的最大长度，然后指针改变指向。
*/


class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode *vhead = new ListNode(-1);
        vhead->next = pHead;
        ListNode *pre = vhead, *cur = pHead;        
        while (cur) {
            if (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
                while (cur->next && cur->val == cur->next->val) {
                    cur = cur->next;
                }
                cur = cur->next;
                pre->next = cur;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        return vhead->next;
    }
};

