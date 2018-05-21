#include<stdio.h>
#include<stdlib.h>

int visited[10]={0};

typedef struct QNode
{
    int data;
    struct QNode *next;
}*Queue;
typedef struct
{
    Queue Front,Rear;
}LinkQueue;

typedef struct GNode
{
    int Vernum;
    int Edgenum;
    int vexs[10];
    int arcs[10][10];
}*MGraph;

MGraph CreateGraph(int VerNum)
{
    MGraph G=(MGraph)malloc(sizeof(struct GNode));
    G->Vernum=VerNum;
    G->Edgenum=0;
    for(int i=0;i<VerNum;i++)
    {
        G->vexs[i]=i;
        for(int j=0;j<VerNum;j++)
            G->arcs[i][j]=0;
    }

    return G;
}

MGraph BuildGraph(MGraph G,int V1,int V2)
{
    G->Edgenum++;
    G->arcs[V1][V2]=1;
    G->arcs[V2][V1]=1;
    return G;
}

void DFS(MGraph G,int v)
{
    visited[v]=1;
    printf("%d ",v);
    int j;
    //for(i=v;((i<G->Vernum));i++)  一次只能做一次循环，否则递归会出现问题
    //0 1 4 2 3 5 7 在2返回的时候 i会变成3
    for(j=0;j<G->Vernum;j++)
    {
        if((visited[j]!=1)&&(G->arcs[v][j]==1))//没被访问且与i相连
            DFS(G,j);
    }
}

void DFSTraverse(MGraph G)
{
    for(int i=0;i<G->Vernum;i++)
    {
        if(visited[i]!=1)
        {
            printf("{ ");
            DFS(G,i);
            printf("}\n");
        }

    }
}

void Enqueue(LinkQueue Q,int i)
{
    Queue q=(Queue)malloc(sizeof(struct QNode));
    q->data=i;
    q->next=NULL;
    Q.Rear->next=q;
    Q.Rear=q;
}

int Dequeue(LinkQueue Q)
{
    Queue t=Q.Front->next;
    int e=t->data;
    Q.Front=Q.Front->next;
    if(Q.Rear==t)
        Q.Rear=Q.Front;
    return e;
}

void BFS(MGraph G,int i)
{
    LinkQueue Q;
    Q.Front=Q.Rear=(Queue)malloc(sizeof(struct QNode));
    Q.Front->next=NULL;
    printf("%d ",i);
    visited[i]=1;
    Enqueue(Q,i);
    int t,j;
    while(Q.Front!=Q.Rear)
    {
        t=Dequeue(Q);
        for(j=0;j<G->Vernum;j++)
        {
            if((visited[j]!=1)&&(G->arcs[t][j]==1))
            {
                visited[j]=1;
                printf("%d ",j);
                Enqueue(Q,j);
            }
        }
    }
}

void BFSTraverse(MGraph G)
{
    for(int i=0;i<G->Vernum;i++)
    {
        if(visited[i]!=1)
        {
            printf("{ ");
            BFS(G,i);
            printf("}\n");
        }
    }
}

int main()
{
    int n;
    MGraph G;
    scanf("%d",&n);
    if(n)
        G=CreateGraph(n);
    scanf("%d",&n);
    int v1,v2;
    while(n--)
    {
        scanf("%d %d",&v1,&v2);
        G=BuildGraph(G,v1,v2);
    }
    DFSTraverse(G);
    for(n=0;n<G->Vernum;n++)
        visited[n]=0;
    BFSTraverse(G);
    return 0;
}
