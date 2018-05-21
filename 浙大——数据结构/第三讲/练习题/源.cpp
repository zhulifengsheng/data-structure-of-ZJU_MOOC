#include<stdio.h>
#include<stdlib.h>

#define MaxTree 10
#define Null -1

struct TreeNode
{
	char element;
	int left, right;
}T1[MaxTree],T2[MaxTree];

int BuildTree(struct TreeNode T[]);
int Isomorphic(int R1,int R2);
int main()
{
	int R1,R2;
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	if (Isomorphic(R1, R2))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}

int BuildTree(struct TreeNode T[])
{
	int n,i,root;
	char cl, cr;
	int check[MaxTree];
	scanf("%d\n", &n);
	if (n)
	{
		for (i = 0; i < n; i++)check[i] = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%c %c %c\n",&T[i].element,&cl,&cr);
			if (cl != '-')
			{
				T[i].left = cl - '0';
				check[T[i].left] = 1;
			}
			else T[i].left = Null;
			if (cr != '-')
			{
				T[i].right = cr - '0';
				check[T[i].right] = 1;
			}
			else T[i].right = Null;
		}
		for (i = 0; i < n; i++)
			if (!check[i])break;
		root = i;
	}
	return root;
}

int Isomorphic(int R1, int R2)
{
	if ((R1 == Null) && (R2 == Null))
		return 1;
	if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)))
		return 0;
	if (T1[R1].element != T2[R2].element)
		return 0;
	if ((T1[R1].left == Null) && (T2[R2].left == Null))
		return Isomorphic(T1[R1].right, T2[R2].right);
	if (((T1[R1].left != Null) && (T2[R2].left != Null)) && ((T1[T1[R1].left].element) == (T2[T2[R2].left].element)))
		return (Isomorphic(T1[R1].left, T2[R2].left) && (Isomorphic(T1[R1].right,T2[R2].right)));
	else return(Isomorphic(T1[R1].left, T2[R2].right) && (Isomorphic(T1[R1].right, T2[R2].left)));
}