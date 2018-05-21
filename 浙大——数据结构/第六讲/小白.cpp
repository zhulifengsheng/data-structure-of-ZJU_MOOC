//�ڽӾ���
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];//������Ϣ
};
typedef PtrToGNode MGraph;

typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1,V2;//�����<V1,V2>
    WeightType Weight;//Ȩ��
};
typedef PtrToENode Edge;

typedef int Vertex;

MGraph CreateGraph(int VertexNum)
{
    Vertex v,w;
    MGraph Graph;
    Graph=(MGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;

    for(v=0;v<Graph->Nv;v++)
        for(w=0;w<Graph->Nv;w++)
            Graph->G[v][w]=0;

    return Graph;
}

void InserEdge(MGraph Graph,Edge E)
{
    Graph->G[E->V1][E->V2]=E->Weight;
    //����ͼ����������
    Graph->G[E->V2][E->V1]=E->Weight;
}

MGraph BuildGraph()
{
    Edge E;
    Vertex V;
    int Nv,i;
    MGraph Graph;

    scanf("%d",&Nv);
    Graph=CreateGraph(Nv);
    scanf("%d",&(Graph->Ne));
    if(Graph->Ne!=0)
    {
        E=(Edge)malloc(sizeof(struct ENode));
        for(i=0;i<Graph->Ne;i++)
        {
            scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
            InserEdge(Graph,E);
        }
    }
    //�����㶼����
    for(V=0;V<Graph->Nv;V++)
        scanf("%c",&(Graph->Data[V]));

    return Graph;
}
//�ڽӱ�
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;
    int Ne;
    AdjList G;//�ڽӱ�
};
typedef PtrToGNode LGraph;

typedef struct Vnode
{
    PtrToAdjVNode FirstEdge;
    DataType Data;//��������
}AdjList[MaxVertexNum];

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode
{
    Vertex AdjV;//�ڽӱ��±�
    WeightType Weight;
    PtrToAdjVNode Next;
};

typedef int Vertex;
LGraph CreateGraph(int VertexNum)
{
    Vertex V,M;
    LGraph Graph;

    Graph=(LGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;
    //��0��ʼ
    for(V=0;V<Graph->Nv;V++)
        Graph->G[V].FirstEdge=NULL;
    return Graph;
}

typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1,V2;//�����<V1,V2>
    WeightType Weight;//Ȩ��
};
typedef PtrToENode Edge;

void InserEdge(LGraph Graph,Edge E)
{
    PtrToAdjVNode NewNode;

    NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV=E->V2;
    NewNode->Weight=E->Weight;

    NewNode->Next=Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge=NewNode;
}

LGraph BuildGraph()
{
    LGraph Graph;
}
