#pragma once
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#define ERROR 0
typedef char ElementType;

//定义一个串结构
typedef struct String
{
	ElementType* array;
	int length;
}Str;

//初始化一个字符串
void StrInit(Str* T);

//生成一个串
void StrAssign(Str* T, ElementType* chars);

//在串S的第pos个字符之前插入串T
void StrInsert(Str* S, int pos, ElementType* T);

//串的复制
Str* StrCopy(Str* T, Str* S);

//判断串是否为空
bool StrEmpty(Str* S);

//比较两个串
int StrCompare(Str* T, Str* S);

//求串的长度
int StrLength(Str* S);

//将串清空
void ClearString(Str* S);

//合并两个串
void ConCat(Str* T, Str* S1, Str* S2);

//用Sub返回串S的第pos个字符起长度为len的字串
void SubString(Str* Sub, Str* S, int pos, int len);

//子串定位函数（模式匹配）,返回位置
int Index(Str* S, Str* T, int pos);
