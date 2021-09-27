#pragma once
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#define ERROR 0
typedef char ElementType;

//����һ�����ṹ
typedef struct String
{
	ElementType* array;
	int length;
}Str;

//��ʼ��һ���ַ���
void StrInit(Str* T);

//����һ����
void StrAssign(Str* T, ElementType* chars);

//�ڴ�S�ĵ�pos���ַ�֮ǰ���봮T
void StrInsert(Str* S, int pos, ElementType* T);

//���ĸ���
Str* StrCopy(Str* T, Str* S);

//�жϴ��Ƿ�Ϊ��
bool StrEmpty(Str* S);

//�Ƚ�������
int StrCompare(Str* T, Str* S);

//�󴮵ĳ���
int StrLength(Str* S);

//�������
void ClearString(Str* S);

//�ϲ�������
void ConCat(Str* T, Str* S1, Str* S2);

//��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���ִ�
void SubString(Str* Sub, Str* S, int pos, int len);

//�Ӵ���λ������ģʽƥ�䣩,����λ��
int Index(Str* S, Str* T, int pos);
