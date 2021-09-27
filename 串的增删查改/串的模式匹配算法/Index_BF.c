/*
	BF算法为暴力算法
		
*/

int Index_BF(SString* S,SString*T,int pos)
{
	//设置两个整数用来定位
	int i = pos;
	int j = 1;

	//当两个定位整数位于两个字符串长度之内则进入循环比较
	while(i <= S->length && j <= T->length)
	{
		
		if(S->array[i - 1] == T->array[j - 1])
		{
			i++;
			j++;
		}
		
		else
			i = i - j + 2;
			j = 1;
	}

	//当j的大小大于T的长度时，说明全部相等，则匹配
	if(j > T->length)
		return i - T->length;
	
	else
		return 0;
}
