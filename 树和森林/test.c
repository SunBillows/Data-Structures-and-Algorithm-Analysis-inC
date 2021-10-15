#include "Tree.h"

int main()
{	
	Tree_twoNode* A = Tree_Create();
	PrevOrder_Tree(A);
	printf("\n");
	PostRoot_Tree(A);

	return 0;
}