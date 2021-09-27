#include "String.h"

void TestArray()
{
	int i = 0;
	char* chars = "ababcabcacbab";
	char* x = "abcac";
	Str T;
	Str S;
	StrInit(&T);
	StrInit(&S);
	StrAssign(&S, chars);
	StrAssign(&T, x);
	//StrAssign(&T, x);
	//StrInsert(&T, 10, x);
	//ClearString(&T);
	int cur = Index(&S, &T, 1);
	printf("%d\n", cur);

	/*printf("%d\n", T.length);
	while (T.length--)
	{
		printf("%c", T.array[i++]);
	}*/
}

int main()
{
 	TestArray();

	return 0;
}