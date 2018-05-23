#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxNum 64

typedef struct TreeNode
{
	int weight;
	struct TreeNode *left,*right;
}*HuffmanTree;

typedef struct HeapNode
{
	struct TreeNode Data[MaxNum];
	int size;
}*Heap;

typedef struct  JNode
{
	int flag;
	struct JNode *left,*right;
}*JTree;

Heap CreateHeap(int N);
HuffmanTree Delete(Heap H);
void Insert(Heap H,HuffmanTree item);
Heap ReadData(int N,Heap H,int A[]);
HuffmanTree Huffman(Heap H);
int WPL(HuffmanTree T,int depth);
int Judge(char *s,JTree J);

int main()
{
	int N,n;
	scanf("%d\n",&N);
	Heap H=CreateHeap(N);
	int Value[MaxNum]={};
	H=ReadData(N,H,Value);

	HuffmanTree T=Huffman(H);
    //printf("%d",T->weight);
	int wpl=WPL(T,0);

	scanf("%d\n",&n);
	char temp[n-1];
	char c;
	int result=0,i;
	for(i=0;i<n;i++)
	{
		int count=0,flag=0;
		JTree J=(JTree)malloc(sizeof(struct JNode));
		J->flag=0;
		J->left=J->right=NULL;
		int k;
		for(k=0;k<N;k++)
		{
			scanf("%c",&c);
			scanf("%s",temp);
			getchar();
			count+=strlen(temp)*Value[k];
			if(!flag)
			{
				result=Judge(temp,J);
				if(!result)
					flag=1;
			}
		}
		free(J);
		if(result&&(count==wpl))
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}

Heap CreateHeap(int N)
{
	Heap H=(Heap)malloc(sizeof(struct HeapNode));
	H->size=0;
	H->Data[0].weight=-1;
	return H;
}

HuffmanTree Delete(Heap H)
{
	int parent=0,child=0;
	struct TreeNode temp1;
	HuffmanTree MinItem=(HuffmanTree)malloc(sizeof(struct TreeNode));
	//MinItem->left=MinItem->right=NULL;
	*MinItem=H->Data[1];
	temp1=(H->Data[(H->size)--]);
	/*
	TreeNode temp;
	TreeNode MinItem=malloc(sizeof(TreeNode));
	MinItem=H->Data[1];

	temp=(H->Data[(H->size)--]);
	*/
	for(parent=1;parent*2<=H->size;parent=child)
	{
		child=parent*2;
		if((child!=H->size)&&((H->Data[child].weight)>(H->Data[child+1].weight)))
			child++;
		if((temp1.weight)<=(H->Data[child].weight))
			break;
		else
			H->Data[parent]=H->Data[child];
	}

	H->Data[parent]=temp1;
	//printf("%d\n",MinItem->weight);
	return MinItem;
}

void Insert(Heap H,HuffmanTree item)
{
	int i=0;
	i=++(H->size);
	for(;H->Data[i/2].weight>item->weight;i/=2)
		H->Data[i]=H->Data[i/2];
	H->Data[i]=*item;
}

Heap ReadData(int N,Heap H,int A[])
{
	char s;
	int value=0;
	int i=0;
	for(;i<N;i++)
	{
	    if(i==N-1)
            scanf("%c %d",&s,&value);
        else
             scanf("%c %d ",&s,&value);
		//scanf("%d",&value);
		A[i]=value;
		HuffmanTree T=(HuffmanTree)malloc(sizeof(struct TreeNode));
		T->left=T->right=NULL;
		T->weight=value;
		Insert(H,T);
	}
	return H;
}

HuffmanTree Huffman(Heap H)
{
	HuffmanTree T;
	int num=H->size;
	int i=0;
	for(;i<num-1;i++)
	{
		T=(HuffmanTree)malloc(sizeof(struct TreeNode));
		T->left=T->right=NULL;
		T->left=Delete(H);
		T->right=Delete(H);
		T->weight=T->left->weight+T->right->weight;
		Insert(H,T);
	}
	T=Delete(H);
	return T;
}

int WPL(HuffmanTree T,int depth)
{
	if((T->left==NULL)&&(T->right==NULL))
		return depth*(T->weight);
	else
		return (WPL(T->left,depth+1)+WPL(T->right,depth+1));
}

int Judge(char *s,JTree J)
{
	int i=0;
	for(;i<strlen(s);i++)
	{
		if(s[i]=='0')
		{
			if(J->left==NULL)
			{
				JTree J_1=(JTree)malloc(sizeof(struct JNode));
				J_1->left=J_1->right=NULL;
				J_1->flag=0;
				J->left=J_1;
			}
			else if (J->left->flag==1)
			{
				return 0;
			}
			J=J->left;
		}
		else
		{
			if(J->right==NULL)
			{
				JTree J_1=(JTree)malloc(sizeof(struct JNode));
				J_1->left=J_1->right=NULL;
				J_1->flag=0;
				J->right=J_1;
			}
			else if (J->right->flag==1)
			{
				return 0;
			}
			J=J->right;
		}
	}
	J->flag=1;
	if(J->left==NULL&&J->right==NULL)
		return 1;
	else
		return 0;
}
