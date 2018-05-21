
#MAXSIZE 10
typedef struct LNode *List;
struct LNode
{
    int Data[MAXSIZE];
    int Lastl;
};
struct LNode L;
//长度  PtrL->Last+1
//建表
List MakEmpty()
{
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->Last=-1;
    return PtrL;
}
//查找
int Find(int x,List PtrL)
{
    int i=0;
    while(i<=PtrL->Last&&PtrL->Data[i]!=x)
        i++;
    if(i>PtrL->Last)
        return -1;
    else return i;
}
//插入
void Insert(int x,int i,List PtrL)
{
    int j;
    if(PtrL->Last==MAXSIZE-1)
    {
        printf("full");
        return;
    }
    if(i<1||i>PtrL->Last+2)
    {
        printf("location-error");
        return;
    }
    for(int j=PtrL->Last;j>=i-1;j--)
        PtrL->Data[j+1]=PtrL->Data[j];
    PtrL->Data[i-1]=x;
    PtrL->Last++;
    return;
}
//删除
void Delete(int i,List PtrL)
{
    int j;
    if(i<1||i>PtrL->Last+1)
    {
        printf("location-error");
        return;
    }
    for(j=i;j<=PtrL->Last;j++)
        Ptrl->Data[j-1]=PtrL->Data[j];
    PtrL->Last--;
    return;
}
