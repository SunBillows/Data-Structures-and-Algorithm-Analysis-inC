#include "Tree.h"

int main()
{
	//½¨Ôì¼¸¿ÃÊ÷
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->_leftChild = NULL;
	A->_rightChild = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->_leftChild = NULL;
	B->_rightChild = NULL;
	
	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->_leftChild = NULL;
	C->_rightChild = NULL;
	
	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->_leftChild = NULL;
	D->_rightChild = NULL;
	
	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->_leftChild = NULL;
	E->_rightChild = NULL;

	A->_leftChild = B;
	A->_rightChild = C;
	B->_leftChild = D;
	B->_rightChild = E;

	PrevOrder(A);
	printf("\n");

	InOrder(A);
	printf("\n");

	printf("%d ", TreeSize(A));
	printf("%d ", TreeSize(B));
	printf("%d ", TreeLeafSize(A));
	printf("%d ", TreeLeafSize(B));
	
	return 0;
}