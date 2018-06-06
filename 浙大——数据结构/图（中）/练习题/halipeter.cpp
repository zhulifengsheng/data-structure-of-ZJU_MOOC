#include<stdio.h>
#include<stdlib.h>

#define MAX 101

struct ENode
{
    int weight;
    int v1,v2;
};
typedef struct ENode* Edge;

struct GNode
{
    int Nv;  /* ¶¥µãÊý */
    int Ne;  /* ±ßÊý   */
    int G[MAX][MAX];
};
typedef struct GNode* MGraph;

MGraph CreateGraph(int vernum);
void InsertEdge(Edge E,MGraph G);

int main()
{
    int N,M;
    scanf("%d",&N);
    MGraph G=CreateGraph(N);
    scanf("%d",&M);
    for(int i=0;i<M;i++)
    {
        Edge E=(Edge)malloc(sizeof(struct ENode));
        scanf("%d %d %d",&E->v1,&E->v2,&E->weight);
        InsertEdge(E,G);
    }
    return 0;
}

MGraph CreateGraph(int vernum)
{
    MGraph Graph=(MGraph)malloc(sizeof(struct GNode));
    Graph->Nv=vernum;
    Graph->Ne=0;

    for(int i=1;i<=vernum;i++)
    {
        for(int j=1;j<=vernum;j++)
        {
            Graph->G[i][j]=MAX;
        }
    }
    return Graph;
}

void InsertEdge(Edge E,MGraph Graph)
{
    Graph->G[E->v1][E->v2]=E->weight;
}
