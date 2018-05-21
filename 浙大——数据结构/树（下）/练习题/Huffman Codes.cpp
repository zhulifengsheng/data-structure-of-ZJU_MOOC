//±§Ç¸£¬ÄÜÁ¦²»×ã
#include<stdio.h>
#include<stdlib.h>

typedef struct HuffmanTreeNode
{
    int weight;
    struct HuffmanTreeNode *left,*right;
}*HuffmanTree;


int sizeheap=0;
int heap[64];


int Delete(int c[])
{
    if(sizeheap<1)
        return 0;

    int x=c[1];
    c[1]=c[sizeheap];
    sizeheap--;
    if(sizeheap==0)return x;

    int parent,child;
    int x1=c[1];
    for(parent=1;parent*2<=sizeheap;parent=child)
    {
        child=parent*2;
        if((parent!=sizeheap)&&(c[child]>c[child+1]))
            child++;
        if(x1<=c[child])break;
        else
            c[parent]=c[child];
    }
    c[parent]=x1;

    return x;
}

void PrecDown(int c[],int i)
{
    int parent,child;
    int x=c[i];
    for(parent=i;parent*2<=sizeheap;parent=child)
    {
        child=parent*2;
        if((child!=sizeheap)&&(c[child]>c[child+1]))
            child++;
        if(x<=c[child])break;
        else
            c[parent]=c[child];
    }
    c[parent]=x;
}

void buildheap(int c[])//create empty min heap
{
    for(int i=sizeheap/2;i>0;i--)
    {
        PrecDown(c,i);
    }
}

void insertheap(int c[],int x)
{
    int i=++sizeheap;
    for(;c[i/2]>x;i/=2)
    {
        c[i]=c[i/2];
    }
    c[i]=x;
}

HuffmanTree Huffman(int c[])
{
    int i;
    buildheap(c);
    HuffmanTree T;
    int n=sizeheap;
    for(i=0;i<n-1;i++)
    {
        T=(HuffmanTree)malloc(sizeof(struct HuffmanTreeNode));
        T->left->weight=Delete(c);
        T->right->weight=Delete(c);
        T->weight=T->left->weight+T->right->weight;
        insertheap(c,T->weight);
    }
    //sizeheap=n;
    return T;
}

int WPL(HuffmanTree T,int depth)
{
    if(!T->left&&!T->right)
        return(depth*T->weight);
    else
        return(WPL(T->left,depth+1)+WPL(T->right,depth+1));
}

void check(int n)
{

}

int main()
{
    heap[0]=-1;
    int n,i;
    scanf("%d\n",&n);
    sizeheap=n+1;

    char *c=(char *)malloc((n+1)*sizeof(char));
    //int *f=(int *)malloc(n*sizeof(int));
    for(i=1;i<=n;i++)
    {
        if(i==n)
            scanf("%c %d",&c[i],&heap[i]);
        else
            scanf("%c %d ",&c[i],&heap[i]);
        //getchar();
    }

    HuffmanTree T=Huffman(heap);
    int wpl=WPL(T,0);

    printf("%d",wpl);

    int t=n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        check(t);
    }
    return 0;
}
