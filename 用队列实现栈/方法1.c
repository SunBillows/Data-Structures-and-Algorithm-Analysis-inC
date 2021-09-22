/*
typedef int QDataType;

typedef struct QueueNode
{
	QDataType val;
	struct	QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

//队列的初始化
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->head = pq->tail = NULL;
}

//队列的删除
void QueueDestory(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->head;

	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = cur->next;
	}
	pq->head = pq->tail = NULL;
}

//入队列 - 队尾入
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	//创建一个队列结点
	QNode * new = (QNode*)malloc(sizeof(QNode));
	if (new == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	//将创建的结点进行赋值
	new->val = x;
	new->next = NULL;
	
	//当队列的尾部为空时，则表示这是一个空队列，需要插入一个结点
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = new;
	}
	else
	{
		//将插入的结点链接到前面的结点后
		pq->tail->next = new;
		pq->tail = new;
	}
}

//出队列 - 队头出
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	//当队列中只存在一个结点时
	if (pq->head == pq->tail)
	{
		//直接释方head，同时队头和队尾都指向空
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		//出队列时将头结点的下一个进行保存
		QNode* temp = pq->head->next;
		free(pq->head);
		pq->head = temp;
	}
}

//找到队头的位置
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	//当队头为空，就禁止调用此函数
	assert(pq->head);

	return pq->head->val;
}

//找到队尾的位置
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->tail->val;
}

//返回队列的长度
int QueueSize(Queue* pq)
{
	int count = 0;
	//创建一个当前结点将头结点的地址保存在cur中
	QNode* cur = pq->head;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

//判断队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL;
}
*/

//以上是队列的实现代码
//以下是本题答案代码

typedef struct 
{
    Queue q1;
    Queue q2;
    int top;
    
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() 
{
    MyStack* QStack = (MyStack*)malloc(sizeof(MyStack));
    if(QStack == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    QueueInit(&QStack->q1);
    QueueInit(&QStack->q2);
    
    return QStack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) 
{
    //将x插入到不为空的队列中
    if(!QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1,x);
    }
    else
    {
        QueuePush(&obj->q2,x);
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) 
{
    Queue* emptyQ = &obj->q1;
    Queue* nonemptyQ = &obj->q2;
    if(!QueueEmpty(&obj->q1))
    {
        emptyQ = &obj->q2;
        nonemptyQ = &obj->q1;
    }

    //倒数据
    while(QueueSize(nonemptyQ) > 1)
    {
        QueuePush(emptyQ,QueueFront(nonemptyQ));
        QueuePop(nonemptyQ);
    }
    int top = QueueFront(nonemptyQ);
    QueuePop(nonemptyQ);

    return top;

    /*
    //如果q1队列不为空
    if(!QueueEmpty(&obj->q1))
    {
        //将q1队列中的最后一个元素前的所有元素移动到q2队列中
        while(QueueSize(&obj->q1) > 1)
        {
            QueuePush(&obj->q2,QueueFront(&obj->q1));
            QueuePop(&obj->q1);
        }
        int top1 = QueueFront(&obj->q1);
        QueuePop(&obj->q1);
        return top1;
    }
    //如果q2队列不为空
    else
    {
        //将q2队列中的最后一个元素前的所有元素移动到q1队列中
        while(QueueSize(&obj->q2) > 1)
        {
            QueuePush(&obj->q1,QueueFront(&obj->q2));
            QueuePop(&obj->q2);
        }
        int top2 = QueueFront(&obj->q2);
        QueuePop(&obj->q2);
        return top2;
    }
    */
}

/** Get the top element. */
int myStackTop(MyStack* obj) 
{
    //去栈顶数据就是取不为空的队列中的队尾数据
    if(!QueueEmpty(&obj->q1))
    {
        return QueueBack(&obj->q1);
    }
    else
    {
        return QueueBack(&obj->q2);
    }
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) 
{
    //如果两个队列都为空，则栈为空
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) 
{
    QueueDestory(&obj->q1);
    QueueDestory(&obj->q2);

    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/

