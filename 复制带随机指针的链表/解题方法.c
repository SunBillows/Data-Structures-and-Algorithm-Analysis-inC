/*
我们首先将该链表中每一个节点拆分为两个相连的节点，例如对于链表 A→B→C，我们可以将其拆分为 A→A′→B→B′→C→C′。对于任意一个原节点 S，其拷贝节点 S'即为其后继节点。
这样，我们可以直接找到每一个拷贝节点 S' 的随机指针应当指向的节点，即为其原节点 S 的随机指针指向的节点 T 的后继节点 T'。
需要注意原节点的随机指针可能为空，我们需要特别判断这种情况。
当我们完成了拷贝节点的随机指针的赋值，我们只需要将这个链表按照原节点与拷贝节点的种类进行拆分即可，只需要遍历一次。同样需要注意最后一个拷贝节点的后继节点为空，我们需要特别判断这种情况。

*/

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) 
{
    //当结点为NULL时，返回NULL
	if (head == NULL) 
        return NULL;

    //循环遍历整个链表，将链表中的每个结点都与复制的结点相连
    for (struct Node* node = head; node != NULL; node = node->next->next)
    {
        //创建一个新结点用来复制源结点
        struct Node* nodeNew = malloc(sizeof(struct Node));
        nodeNew->val = node->val;
        nodeNew->next = node->next;

        //将复制的结点链接在源结点之后
        node->next = nodeNew;
    }

    //将源节点的random指针
    for (struct Node* node = head; node != NULL; node = node->next->next) 
    {
        struct Node* nodeNew = node->next;
        nodeNew->random = (node->random != NULL) ? node->random->next : NULL;
    }

    struct Node* headNew = head->next;

    //循环遍历整个链表进行拆分
    for (struct Node* node = head; node != NULL; node = node->next) 
    {
        struct Node* nodeNew = node->next;
        node->next = node->next->next;
        nodeNew->next = (nodeNew->next != NULL) ? nodeNew->next->next : NULL;
    }

    //最后返回复制后的结点
    return headNew;

}

