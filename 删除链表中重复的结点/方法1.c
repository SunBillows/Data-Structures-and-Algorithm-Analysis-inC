/*
解题思路：
	创建cur结点和next结点以及prev，当cur->val == next->val时，讲next向后移动，直到next->val != cur->val时，将prev->next = next;
		上述描述为其中一种情况： 1->2->2->3->4->NULL;
		还有三种种情况需要讨论：
		1: 1->1->1->2->3->4->NULL;
		2: 1->2->3->4->4->4->4->NULL;
		3: 1->1->1->1->NULL;
	特殊情况特殊讨论
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution 
{
public:
    ListNode* deleteDuplication(ListNode* pHead) 
    {
        struct ListNode* prev = NULL;
        struct ListNode* cur = pHead;
        struct ListNode* next = pHead->next;
        
        //当链表只有一个结点或者链表为空时，则返回pHead
        if(pHead == NULL || pHead->next == NULL)
            return pHead;
        
        //当next结点不为空时，进入循环
        while(next)
        {
            //当cur结点的值和next结点的值相等时，遍历链表
            if(cur->val == next->val)
            {
                //当结点跑完时或者cur的值和next的值不相等时，跳出遍历链表循环
                while(next && cur->val == next->val)
                {
                    //将next向后移动，知道找到不相等的值或者next为空时
                    next = next->next;
                }
                //当找到不重复的结点后，prev为空时，
                //直接将next所处的结点变为头结点，删除中间所有重复值得结点
                if(prev == NULL)
                {
                    pHead = next;
                }
                //如果prev不为空时，prev指向next
                else 
                {
                    prev->next = next;
                }
                //释放要删除的节点空间
                while(cur != next)
                {
                    //首先将要删除的结点保存，在使cur走向下一个结点
                    //然后再释放此结点
                    ListNode* del = cur;
                    cur = cur->next;
                    free(del);
                }
                //当next不为空时，循环未结束，next继续向前走
                //为空时，则代表链表已经终结，next不再移动
                if(next)
                    next = next->next;
            }
            //当cur的值和next的值不相同且next不为空时，三者都进行迭代
            else
            {
                prev = cur;
                cur = next;
                next = next->next;
            } 
        } 
        return pHead;
    }
};

