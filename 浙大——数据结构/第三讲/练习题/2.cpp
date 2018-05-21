#include<stdio.h>
#include<stdlib.h>

typedef struct QNode
{
    int data;
    struct QNode *next;
}*Queue;
typedef struct
{
    Queue Front,Rear;
}LinkQueue;
struct TreeNode
{
    int left,right;
}T[10];

void InitQueue(LinkQueue *Q)
{
    (*Q).Front=(*Q).Rear=(Queue)malloc(sizeof(struct QNode));
    (*Q).Front->next=NULL;
}

void EnQueue(LinkQueue *Q,int c)
{
    Queue p;
    p=(Queue)malloc(sizeof(struct QNode));
    p->data=c;
    p->next=NULL;
    (*Q).Rear->next=p;
    (*Q).Rear=p;
}

int DeQueue(LinkQueue *Q)
{
    int e;
    if((*Q).Front==(*Q).Rear) return -1;
    Queue p;
    p=(*Q).Front->next;
    e=p->data;
    (*Q).Front->next=p->next;
    if((*Q).Rear==p)(*Q).Rear=(*Q).Front;
    free(p);
    return e;
}

int Create(struct TreeNode T[],int n)
{
    int i,check[10],root=-1;
    char l,r;
    if(n)
    {
        for(i=0;i<n;i++)check[i]=0;
        for(i=0;i<n;i++)
        {
            scanf("%c %c\n",&l,&r);
            if(l!='-')
            {
                T[i].left=l-'0';
                check[T[i].left]=1;
            }
            else T[i].left=-1;
            if(r!='-')
            {
                T[i].right=r-'0';
                check[T[i].right]=1;
            }
            else T[i].right=-1;
        }
        for(i=0;i<n;i++)
            if(!check[i])break;
        root=i;
    }
    return root;
}
int main()
{
    int R,n,i,t;
    scanf("%d\n",&n);
    LinkQueue Q;
    R=Create(T,n);
    InitQueue(&Q);
    EnQueue(&Q,R);
    for(i=0;i<n;i++)
    {
        t=DeQueue(&Q);
        if((T[t].left==-1)&&(T[t].right==-1))
        {
            if(i==n-1)
                printf("%d",t);
            else printf("%d ",t);
            continue;
        }
        if(T[t].left!=-1)EnQueue(&Q,T[t].left);
        if(T[t].right!=-1)EnQueue(&Q,T[t].right);
    }
    return 0;
}
