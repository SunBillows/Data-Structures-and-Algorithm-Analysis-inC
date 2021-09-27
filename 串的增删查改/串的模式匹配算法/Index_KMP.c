/*
	KMP算法：
		关键在于求next[j]；

		求出next[j]需要掌握一下内容:
			1.串的前缀：包含第一个字符，且不包含最后一个字符；
			2.串的后缀: 包含最后一个字符，且不包含第一个字符；
			3.当第j个字符匹配失败时，有前j-1个字符组成的字符串记为S；
		则，next[j] 为 S 的最长相等前后缀长度 + 1.

		NOTE:
			1.当失配位置在1时，next[j] = 0；
			2.当失配位置在2时，next[j] = 1；
*/

//对KMP算法的优化，求出nextval数组

/*
先算出next数组
先令nextval[1] = 0;
for(int j = 2;j<=T.length;j++)
{
	if(T.ch[next[j]] == T.ch[j])
		nextval[j] = nextval[next[j]];

	else
		nextval[j] = next[j];
}
*/

//求出模式串的next数组
void get_next(SString* T,int next[])
{
	int i = 1 , j = 0;
	next[1] = 0;

	while(i < T->length)
	{
		if(j == 0 || T->array[i] == T->array[j])
		{
			i++;
			j++;
			//若Pi = Pj，则 next[j+1] = next[j] + 1;
			next[i] = j;
		}
		else
			//否则令j = next[j],循环继续
			j = next[j];
	}
	
}


//模式匹配算法的实现
int Index_KMP(SString* S,SString* T,int pos)
{
	//先定义两个左边
	int i = pos;
	int j = 1;

	//定义一个与T的数组等长的数组
	int next[T->length + 1];
	
	//求出模式串的next数组
	get_next(&T,&next);

	//利用next数组进行串的模式匹配
	while(i <= S->length && j <= T->length)
	{
		//当两个字符相等时，则对下一个字符进行匹配
		if(j == 0 || S->array[i] == T->array[j])
		{
			i++;
			j++;
		}
		//当发生失配时，将j进行回溯；回溯的位置由next数组决定
		else
		{
			j = next[j];
		}
	}

	//当匹配循环结束后
	if(j > T->length)			//当T的坐标j大于T的数组长度时，则表明T的数组全部与S的数组匹配
		return i - T->length;
	else						//否则，则说明两个字符串没能匹配
		return 0;
}
