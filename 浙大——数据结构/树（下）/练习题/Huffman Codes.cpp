//真心不知道为啥测试点1不通过
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Huffman编码（不唯一）是最优编码，但最优编码不一定是Huffman编码

//WPL最小，无歧义（前缀码）
typedef struct HuffmanTreeNode
{
    int weight;
    struct HuffmanTreeNode *left,*right;
}*HuffmanTree;

typedef struct HeapNode
{
    HuffmanTree * Data;//储存HuffmanTreeNode.weight数组
    int sizeheap;//当前大小
    //int capacity;//容量
}*MinHeap;

typedef struct BinTreeNode
{
    int flag;
    struct BinTreeNode *left,*right;
}*BinTree;

HuffmanTree Huffman(MinHeap H);
int WPL(HuffmanTree T,int depth);
HuffmanTree Delete(MinHeap H);
void Insert(MinHeap H,HuffmanTree HT);
//int check(char *c,int n,int *f,int t);
int checktree(char *s,BinTree T);

int main()
{

    int n,i;

    MinHeap H=(MinHeap)malloc(sizeof(struct HeapNode));
    HuffmanTree HT;

    scanf("%d\n",&n);
    H->Data=(HuffmanTree*)malloc(64*sizeof(struct HuffmanTreeNode));
    H->Data[0]=(HuffmanTree)malloc(sizeof(struct HuffmanTreeNode));
    H->Data[0]->weight=-1;
    H->sizeheap=0;
    //H->capacity=n+1;

    char *c=(char *)malloc((n+1)*sizeof(char));
    int f[64];
    for(i=1;i<=n;i++)
    {
        HT=(HuffmanTree)malloc(sizeof(struct HuffmanTreeNode));
        HT->left=HT->right=NULL;
        if(i==n)
        {
            scanf("%c %d",&c[i],&(HT->weight));
            f[i]=HT->weight;
        }
        else
        {
            scanf("%c %d ",&c[i],&(HT->weight));
            f[i]=HT->weight;
        }

        Insert(H,HT);
    }

    HuffmanTree T=Huffman(H);
    int wpl=WPL(T,0);

    int t;
    scanf("%d\n",&t);

    char c1;
    char e[n-1];
    int result=0;
    for(i=0;i<t;i++)
    {
        char d[n+1];
        for(int i=1;i<=n;i++)
        {
            d[i]=c[i];
        }
        int coun=0;int flag=0;
        BinTree BT=(BinTree)malloc(sizeof(struct BinTreeNode));
        BT->left=BT->right=NULL;
        BT->flag=0;
        for(int k=0;k<n;k++)
        {
            scanf("%c",&c1);
            scanf("%s",e);
            getchar();

            for(int j=1;j<=n;j++)
            {
                if(d[j]==c1)
                {
                    coun+=strlen(e)*f[j];
                    d[j]='+';
                    break;
                }

                if(j==n)
                {
                    result=0;
                    flag=1;
                }
            }
            if(!flag)
            {
                result=checktree(e,BT);
                if (!result)
                {
                    flag=1;
                }
            }
        }
        free(BT);
        if(result&&(coun==wpl))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}

void Insert(MinHeap H,HuffmanTree HT)
{
    int i=++H->sizeheap;
    //if(H->sizeheap==H->capacity)return;
    for(;H->Data[i/2]->weight>HT->weight;i/=2)
    {
        H->Data[i]=H->Data[i/2];
    }
    H->Data[i]=HT;
}

HuffmanTree Huffman(MinHeap H)
{
    HuffmanTree T;
    int n=H->sizeheap;
    for(int i=0;i<n-1;i++)
    {
        T=(HuffmanTree)malloc(sizeof(struct HuffmanTreeNode));
        T->left=Delete(H);
        T->right=Delete(H);
        T->weight=T->left->weight+T->right->weight;
        Insert(H,T);
    }
    T=Delete(H);
    return T;
}

HuffmanTree Delete(MinHeap H)
{
    HuffmanTree T;
    T=H->Data[1];
    HuffmanTree T1=H->Data[H->sizeheap];

    H->Data[1]=H->Data[H->sizeheap];
    H->sizeheap--;

    int parent,child;
    for(parent=1;parent*2<=H->sizeheap;parent=child)
    {
        child=parent*2;
        if((child!=H->sizeheap)&&(H->Data[child]>H->Data[child+1]))
            child++;
        if(H->Data[child]->weight<T1->weight)
            H->Data[parent]=H->Data[child];
        else
            break;
    }
    H->Data[parent]=T1;
    return T;
}

int WPL(HuffmanTree T,int depth)
{
    if(!T->left&&!T->right)
        return T->weight*depth;
    else
        return WPL(T->left,depth+1)+WPL(T->right,depth+1);
}

int checktree(char *s,BinTree T)
{
    int k;
    for(k=0;k<strlen(s);k++)
    {
        if(s[k]=='0')
        {
            if(!T->left)
            {
                BinTree T1=(BinTree)malloc(sizeof(struct BinTreeNode));
                T1->left=T1->right=NULL;
                T1->flag=0;
                T->left=T1;
            }
            else if(T->left->flag==1)
                return 0;
            T=T->left;
        }
        else
        {
            if(!T->right)
            {
                BinTree T1=(BinTree)malloc(sizeof(struct BinTreeNode));
                T1->left=T1->right=NULL;
                T1->flag=0;
                T->right=T1;
            }
            else if(T->right->flag==1)
                return 0;
            T=T->right;
        }
    }
    T->flag=1;
    if(T->left||T->right)
        return 0;
    else
        return 1;
}
