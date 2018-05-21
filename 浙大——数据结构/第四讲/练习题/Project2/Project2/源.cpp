#include<stdio.h>
#include<stdlib.h>

typedef struct AVLNode
{
	struct AVLNode *left, *right;
	int element;
	int height;
}*AVLTree;

int Max(int a, int b)
{
	return a > b ? a : b;
}

AVLTree SingleLeftRotation(AVLTree A);
AVLTree SingleRightRotation(AVLTree A);
AVLTree MakeTree(int n);
AVLTree NewNode(int v);
AVLTree Insert(AVLTree T, int v);
int GetHeight(AVLTree A);
AVLTree DoubleLeftRightRotation(AVLTree A);
AVLTree DoubleRightLeftRotation(AVLTree A);

int main()
{
	int n;
	scanf("%d", &n);
	AVLTree T = MakeTree(n);
	printf("%d", T->element);
	return 0;
}

AVLTree NewNode(int v)
{
	AVLTree T = (AVLTree)malloc(sizeof(struct AVLNode));
	T->element = v;
	T->left = T->right = NULL;
	T->height = 0;
	return T;
}
AVLTree MakeTree(int n)
{
	int v,i;
	scanf("%d", &v);
	AVLTree A = NewNode(v);
	for (i = 1; i < n; i++)
	{
		scanf("%d", &v);
		A = Insert(A, v);
	}
	return A;
}
AVLTree Insert(AVLTree T, int v)
{
	if (!T)
		T=NewNode(v);
	else if (T->element > v) {
			T->left = Insert(T->left, v);
			if (GetHeight(T->left) - GetHeight(T->right) == 2)
				if (v < T->left->element)
					T = SingleLeftRotation(T);
				else
					T = DoubleLeftRightRotation(T);
		}	
	else if (v > T->element) {
		T->right = Insert(T->right, v);
		if (GetHeight(T->left) - GetHeight(T->right) == -2)
			if (v > T->right->element)
				T = SingleRightRotation(T);
			else
				T = DoubleRightLeftRotation(T);
	}
	T->height = Max(GetHeight(T->left), GetHeight(T->right)) + 1;
	return T;
}
int GetHeight(AVLTree A)
{
	if (A == NULL)
		return -1;
	else
	{
		int BLHeight = GetHeight(A->left);
		int BRHeight = GetHeight(A->right);
		if (BLHeight >= BRHeight)
			return BLHeight + 1;
		else
			return BRHeight + 1;
	}
}
AVLTree SingleLeftRotation(AVLTree A)
{
	AVLTree B = A->left;
	A->left = B->right;
	B->right = A;
	A->height = Max(GetHeight(A->left), GetHeight(A->right)) + 1;
	B->height = Max(GetHeight(B->left), A->height) + 1;
	return B;
}
AVLTree SingleRightRotation(AVLTree A)
{
	AVLTree B = A->right;
	A->right = B->left;
	B->left = A;
	A->height = Max(GetHeight(A->left), GetHeight(A->right)) + 1;
	B->height = Max(GetHeight(B->left), A->height) + 1;
	return B;
}
AVLTree DoubleLeftRightRotation(AVLTree A)
{
	A->left = SingleRightRotation(A->left);
	return SingleLeftRotation(A);
}
AVLTree DoubleRightLeftRotation(AVLTree A)
{
	A->right = SingleLeftRotation(A->right);
	return SingleRightRotation(A);
}