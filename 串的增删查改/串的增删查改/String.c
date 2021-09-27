#include "String.h"

//初始化一个字符串
void StrInit(Str* T)
{
	T->array = NULL;
	T->length = 0;
}

//生成一个串
void StrAssign(Str* T, ElementType* chars)
{
	//如果T中有空间，则释放空间
	if (T->array)
		free(T->array);

	//计算chars的长度
	int len = strlen(chars);

	//如果插入的字符串为空串,则生成的串也为空串
	if (!len)
	{
		T->array = NULL;
		T->length = 0;
	}
	//如果插入的串不为空串，则为T->array分配存储空间并将chars中的字符赋值到T->array中
	else
	{
		//重新创建一个和x长度相等的新空间
		T->array = (ElementType*)malloc(sizeof(ElementType) * len);
		
		//如果分配失败，则返回
		if (T->array == NULL)
			printf("malloc fail.\n");
		//如果分配成功，则将chars中的字符赋值到T->array中
		else
		{
			int i = 0;
			T->length = len;
			while (len--)
			{
				T->array[i++] = *chars++;
			}
		}
	}
}

//在串S的第pos个字符之前插入串T
void StrInsert(Str* S, int pos, ElementType* T)
{
	int i = 0;
	int k = pos;

	//当pos位置不合法时，返回失败
	if (pos < 0 || pos > S->length + 1)
		printf("error\n");

	//当位置合法时，进行插入
	int len = strlen(T);		//求出带插入字符串的长度

	if (S->length)
	{
		//增加S的内存空间
		S->array = (ElementType*)realloc(S->array, sizeof(ElementType) * (S->length + len));
		if (S->array == NULL)
			printf("realloc fail.\n");

		//将S中字符pos位置后的字符向后移动,为插入字符串T提供空间
		for (i = S->length - 1; i >= pos - 1; i--)
		{
			S->array[i + len] = S->array[i];
		}

		//将T的串插入到S->array中
		S->length = S->length + len;
		while (len--)
		{
			S->array[pos++] = *T++;
		}
	}
}

//串的复制
Str* StrCopy(Str* T, Str* S);

//判断串是否为空
bool StrEmpty(Str* S)
{
	return !S->length;
}

//比较两个串
int StrCompare(Str* T, Str* S);

//求串的长度
int StrLength(Str* S)
{
	return S->length;
}

//将串清空
void ClearString(Str* S)
{
	if (S->array)
	{
		free(S->array);
		S->array = NULL;
	}
	S->length = 0;
}

//合并两个串
void ConCat(Str* T, Str* S1, Str* S2);

//用Sub返回串S的第pos个字符起长度为len的字串
void SubString(Str* Sub, Str* S, int pos, int len);

//子串定位函数（模式匹配）,返回位置（BF算法）
int Index(Str* S, Str* T, int pos)
{
	if (T->array == NULL)
	{
		printf("字串为空\n");
		return 0;
	}

	//判断位置pos是否合法
	if (pos < 1 && pos > S->length)
		return ERROR;

	//设置两个整数用来定位
	int i = pos;
	int j = 1;

	//当两个定位整数位于两个字符串长度之内则进入循环比较
	while (i <= S->length && j <= T->length)
	{
		if (S->array[i - 1] == T->array[j - 1])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	//当j的大小大于T的长度时，说明全部相等，则匹配
	if (j > T->length)
		return i - T->length;
	else
	{
		printf("匹配失败\n");
		return 0;
	}
	
	////进行比较
	//while ((S->length - pos) > T->length)
	//{
	//	//当两个字符串元素相等时，则比较下一个字符
	//	while (S->array[i-1] == T->array[j-1])
	//	{
	//		i++;
	//		j++;
	//	}
	//	//匹配成功时
	//	if (j == T->length + 1)
	//		return pos;
	//	//匹配失败时
	//	else
	//	{
	//		i = i - j + 2;
	//		j = 1;
	//	}
	//	pos++;
	//}
	//printf("匹配失败\n");
	//return 0;
}
