#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


typedef char STDataType;

typedef struct Stack
{
	STDataType* val;	//定义一个数组用来做栈
	int top;			//为栈顶做一个标记	
	int capacity;		//定义栈的容量
}ST;

//栈的初始化
void StackInit(ST* ps)
{
	assert(ps);

	ps->val = (STDataType*)malloc(sizeof(STDataType) * 10);
	ps->capacity = 10;
	ps->top = 0;
}

//栈的销毁
void StackDestory(ST* ps)
{
	assert(ps);

	free(ps->val);
	ps->val = NULL;
	ps->top = ps->capacity = 0;
}

//栈顶插入数据 - 入栈
void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	//如果此栈的空间已满
	if (ps->top == ps->capacity)
	{
		//开辟空间，一般开辟的空间为原容量的两倍
		STDataType* new = (STDataType*)realloc(ps->val, ps->capacity * 2 * sizeof(STDataType));
		//当开辟失败时，直接返回
		if (new == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		//当开辟成功时，则将新开辟的空间赋值给val，同时ps中的容量要*2
		else
		{
			ps->val = new;
			ps->capacity = ps->capacity * 2;
		}
	}

	//数组中插入数据x,同时栈顶要++
	ps->val[ps->top] = x;
	ps->top++;
}

//栈顶删除数据 - 出栈
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);

	ps->top--;
}

//取栈顶的数据
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);

	return ps->val[ps->top - 1];
}

//栈中数据的个数
int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

//判断栈是否为空
bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}

bool isValid(char * s)
{
    //先创建一个栈并将其初始化
    ST stack;
    StackInit(&stack);
    while(*s != '\0')
    {
        if(*s == '('||*s =='['||*s == '{')
            StackPush(&stack,*s);
        else if(*s == ')'||*s ==']'||*s == '}')
        {   
            //若此时栈为空，则代表括号不匹配
            if(StackEmpty(&stack))
            {
                StackDestory(&stack);
                return false;
            }

            //取出栈顶元素，并出栈
            char top = StackTop(&stack);
            StackPop(&stack);

            //将栈顶元素和此右括号进行比较
            if(*s == ')'&& top != '('
             ||*s == '}'&& top != '{'
             ||*s == ']'&& top != '[')            //如果两个元素不匹配
            {
                StackDestory(&stack);
                return false;
            }
        }
        s++;
    }

    //若栈为空，则代表括号全部匹配完成
    bool ret = StackEmpty(&stack);

    StackDestory(&stack);
    return ret;
}

