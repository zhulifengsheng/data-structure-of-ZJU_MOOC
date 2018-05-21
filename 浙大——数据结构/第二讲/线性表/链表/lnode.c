typedef struct LNode *List;
struct LNode
{
    int data;
    List next;
};
struct LNode L;
//求长度
int Length(List PtrL)
{
    List p=PtrL;
    int j=0;
    while(p)
    {
        p=p->next;
        j++;
    }
    return j;
}
//查找按序号找
List Find(int k,List PtrL)
{
    List p=PtrL;
    int i=1;
    while(p!=NULL&&i<k)
    {
        p=p->next;
        i++;
    }
    if(i==k)return p;
    else return NULL;
}
//插入
List Insert(int x,int i,List PtrL)
{
    List p,s;
    if(i==1)
    {
        s=(List)malloc(sizeof(struct LNode));
        s->Data=x;
        s->next=PtrL;
        return s;
    }
    p=Find(i-1,PtrL)
    if(p==NULL)
    {
        printf("i-error");
        return NULL;
    }
    else
    {
        s=(List)malloc(sizeof(struct LNode));
        s->Data=x;
        s->next=p->next;
        p->next=s;
        return PtrL;
    }
}
//删除
List detele(int i,List PtrL)
{
    List p,s;
    if(i==1)
    {
        s=PtrL;
        if(PtrL!=NULL)
            PtrL=PtrL->next;
        else return NULL;
        free(s);
        return PtrL;
    }
    p=find(i-1,PtrL)
    if(p==NULL)
        return NULL;
    else if(p->next=NUll)
        return NULL;
    else
    {
        s=p->next;
        p->next=s->next;
        free(s);
        return PtrL;
    }
}
