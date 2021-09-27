#include "String.h"

//��ʼ��һ���ַ���
void StrInit(Str* T)
{
	T->array = NULL;
	T->length = 0;
}

//����һ����
void StrAssign(Str* T, ElementType* chars)
{
	//���T���пռ䣬���ͷſռ�
	if (T->array)
		free(T->array);

	//����chars�ĳ���
	int len = strlen(chars);

	//���������ַ���Ϊ�մ�,�����ɵĴ�ҲΪ�մ�
	if (!len)
	{
		T->array = NULL;
		T->length = 0;
	}
	//�������Ĵ���Ϊ�մ�����ΪT->array����洢�ռ䲢��chars�е��ַ���ֵ��T->array��
	else
	{
		//���´���һ����x������ȵ��¿ռ�
		T->array = (ElementType*)malloc(sizeof(ElementType) * len);
		
		//�������ʧ�ܣ��򷵻�
		if (T->array == NULL)
			printf("malloc fail.\n");
		//�������ɹ�����chars�е��ַ���ֵ��T->array��
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

//�ڴ�S�ĵ�pos���ַ�֮ǰ���봮T
void StrInsert(Str* S, int pos, ElementType* T)
{
	int i = 0;
	int k = pos;

	//��posλ�ò��Ϸ�ʱ������ʧ��
	if (pos < 0 || pos > S->length + 1)
		printf("error\n");

	//��λ�úϷ�ʱ�����в���
	int len = strlen(T);		//����������ַ����ĳ���

	if (S->length)
	{
		//����S���ڴ�ռ�
		S->array = (ElementType*)realloc(S->array, sizeof(ElementType) * (S->length + len));
		if (S->array == NULL)
			printf("realloc fail.\n");

		//��S���ַ�posλ�ú���ַ�����ƶ�,Ϊ�����ַ���T�ṩ�ռ�
		for (i = S->length - 1; i >= pos - 1; i--)
		{
			S->array[i + len] = S->array[i];
		}

		//��T�Ĵ����뵽S->array��
		S->length = S->length + len;
		while (len--)
		{
			S->array[pos++] = *T++;
		}
	}
}

//���ĸ���
Str* StrCopy(Str* T, Str* S);

//�жϴ��Ƿ�Ϊ��
bool StrEmpty(Str* S)
{
	return !S->length;
}

//�Ƚ�������
int StrCompare(Str* T, Str* S);

//�󴮵ĳ���
int StrLength(Str* S)
{
	return S->length;
}

//�������
void ClearString(Str* S)
{
	if (S->array)
	{
		free(S->array);
		S->array = NULL;
	}
	S->length = 0;
}

//�ϲ�������
void ConCat(Str* T, Str* S1, Str* S2);

//��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���ִ�
void SubString(Str* Sub, Str* S, int pos, int len);

//�Ӵ���λ������ģʽƥ�䣩,����λ�ã�BF�㷨��
int Index(Str* S, Str* T, int pos)
{
	if (T->array == NULL)
	{
		printf("�ִ�Ϊ��\n");
		return 0;
	}

	//�ж�λ��pos�Ƿ�Ϸ�
	if (pos < 1 && pos > S->length)
		return ERROR;

	//������������������λ
	int i = pos;
	int j = 1;

	//��������λ����λ�������ַ�������֮�������ѭ���Ƚ�
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
	//��j�Ĵ�С����T�ĳ���ʱ��˵��ȫ����ȣ���ƥ��
	if (j > T->length)
		return i - T->length;
	else
	{
		printf("ƥ��ʧ��\n");
		return 0;
	}
	
	////���бȽ�
	//while ((S->length - pos) > T->length)
	//{
	//	//�������ַ���Ԫ�����ʱ����Ƚ���һ���ַ�
	//	while (S->array[i-1] == T->array[j-1])
	//	{
	//		i++;
	//		j++;
	//	}
	//	//ƥ��ɹ�ʱ
	//	if (j == T->length + 1)
	//		return pos;
	//	//ƥ��ʧ��ʱ
	//	else
	//	{
	//		i = i - j + 2;
	//		j = 1;
	//	}
	//	pos++;
	//}
	//printf("ƥ��ʧ��\n");
	//return 0;
}
