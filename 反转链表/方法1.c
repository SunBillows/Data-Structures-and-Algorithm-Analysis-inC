/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
思路：
	先创建三个结点Node1、Node2和Node3，分别将其赋值为NULL、head、head->next；
	先进行反转，将Node2指向Node1
	然后进行迭代，即：
		Node1 = Node2;
		Node2 = Node3;
		Node3 = Node3->next;

	最后完成单链表的反转
*/

struct ListNode* reverseList(struct ListNode* head)
{
    if(head == NULL||head->next == NULL)
        return head;

    //先定义三个结点
    struct ListNode* Node1 = NULL;
    struct ListNode* Node2 = head;
    struct ListNode* Node3 = head->next;

    //当结点2不为空时，进行循环
    while(Node2)
    {
        //进行反转
        Node2->next = Node1;    //将Node2的指针指向Node1

        //进行迭代
        Node1 = Node2;
        Node2 = Node3;
        if(Node3 != NULL)
            Node3 = Node3->next;
    }
    return Node1;
}

