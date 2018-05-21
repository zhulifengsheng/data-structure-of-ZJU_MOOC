#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void PreorderTraversal(BinTree BT); /* ����������ɲ���ʵ�֣�ϸ�ڲ��� */
void InorderTraversal(BinTree BT);  /* ����������ɲ���ʵ�֣�ϸ�ڲ��� */

BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
Position Find(BinTree BST, ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);

int main()
{
	BinTree BST, MinP, MaxP, Tmp;
	ElementType X;
	int N, i;

	BST = NULL;
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &X);
		BST = Insert(BST, X);
	}
	printf("Preorder:"); PreorderTraversal(BST); printf("\n");
	MinP = FindMin(BST);
	MaxP = FindMax(BST);
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &X);
		Tmp = Find(BST, X);
		if (Tmp == NULL) printf("%d is not found\n", X);
		else {
			printf("%d is found\n", Tmp->Data);
			if (Tmp == MinP) printf("%d is the smallest key\n", Tmp->Data);
			if (Tmp == MaxP) printf("%d is the largest key\n", Tmp->Data);
		}
	}
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &X);
		BST = Delete(BST, X);
	}
	printf("Inorder:"); InorderTraversal(BST); printf("\n");

	return 0;
}
Position Find(ElementType x,BinTree BST)
{
    if(!BST)return NULL;
    if(x>BST->Data)
        return Find(x,BST->Right);
    else if(x<BST->Data)
        return Find(x,BST->Left);
    else
        return BST;
}

Position Find(ElementType x,BinTree BST)
{
    while(BST)
    {
        if(x>BST->Data)
            BST=BST->Right;
        else if(x<BST->Data)
            BST=BST->Left;
        else
            return BST;
    }
    return NULL;
}

Position FindMin(BinTree BST)
{
    if(!BST)
        return NULL;
    else if(!BST->Left)
        return BST;
    else
        return FindMin(BST->Left);
}

Position FindMax(BinTree BST)
{
    if(BST)
        while(BST->Right) BST=BST->Right;

    return BST;
}
BinTree Insert(ElementType x, BinTree BST)
{
	if (!BST)
	{
		BST = malloc(sizeof(struct TreeNode));
		BST->Data = x;
		BST->Left = BST->Right = NULL;
	}
	else
	{
		if (x<BST->Data)
			BST->Left = Insert(x, BST->Left);
		else if (x>BST->Data)
			BST->Right = Insert(x, BST->Right);
	}
	return BST;
}

//Ҷ�ڵ�ֱ��ɾ����NULL
//ֻ��һ�����ӣ������ָ������
//���������ӣ�1.��������СԪ�����2.���������Ԫ������������������һ�����ӣ�
BinTree Delete(ElementType x, BinTree BST)
{
	Position Tmp;
	if (!BST)printf("Ҫɾ����Ԫ��û�ҵ�");
	else if (x<BST->Data)
		BST->Left = Delete(x, BST->Left);
	else if (x>BST->Data)
		BST->Right = Delete(x, BST->Right);
	else if (BST->Left&&BST->Right)
	{
		Tmp = FindMin(BST->Right);
		BST->Data = Tmp->Data;
		BST->Right = Delete(BST->Data, BST->Right);
	}
	else
	{
		Tmp = BST;
		if (!BST->Left)
			BST = BST->Right;
		else if (!BST->Right)
			BST = BST->Left;
		free(Tmp);
	}

	return BST
}
