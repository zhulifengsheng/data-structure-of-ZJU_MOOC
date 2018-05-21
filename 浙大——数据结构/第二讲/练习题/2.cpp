#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
    int ceof,expon;
    struct LNode *next;
}*List;

List read();
void print(List l);
List add(List l1,List l2);
List mult(List l1,List l2);
void attach(int c,int e,List *l); //create one point and then linked   //*l is a tail as a sacrifice

int main()
{
    List l1,l2,pa,px;
    l1=read();
    //print(l1);
    l2=read();
    //print(l2);
    pa=add(l1,l2);
    px=mult(l1,l2);
    print(px);
    print(pa);
    return 0;
}

void attach(int c,int e,List *l)
{
    List p=(List)malloc(sizeof(struct LNode));
    p->ceof=c;
    p->expon=e;
    p->next=NULL;
    (*l)->next=p;
    (*l)=p;
}

List read()
{
    int c,e,n;
    List tmp,t,L=(List)malloc(sizeof(struct LNode));
    L->next=NULL;
    t=L;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&c,&e);
        attach(c,e,&L);
    }
    tmp=t;
    t=t->next;
    free(tmp);
    return t;
}

void print(List l)
{
    if(!l)
    {
        printf("0 0");
    }
    int flag=1;
    while(l)
    {
        printf("%d %d",l->ceof,l->expon);
        l=l->next;
        if(l==NULL)
            flag=0;
        if(flag)
            printf(" ");
    }
    printf("\n");
}

List add(List l1,List l2)
{
    List t,l,p=(List)malloc(sizeof(struct LNode));
    p->next=NULL;
    List pa,pb;
    l=p;
    pa=l1;
    pb=l2;
    while(pa&&pb)
    {
        if(pa->expon==pb->expon)
        {
            if(pa->ceof+pb->ceof==0)
            {
                pa=pa->next;
                pb=pb->next;
            }
            else
            {
                attach(pa->ceof+pb->ceof,pa->expon,&p);
                pa=pa->next;
                pb=pb->next;
            }
        }
        else if(pa->expon>pb->expon)
        {
            attach(pa->ceof,pa->expon,&p);
            pa=pa->next;
        }
        else
        {
            attach(pb->ceof,pb->expon,&p);
            pb=pb->next;
        }
    }
    while(pa)
    {
        attach(pa->ceof,pa->expon,&p);
        pa=pa->next;
    }
    while(pb)
    {
        attach(pb->ceof,pb->expon,&p);
        pb=pb->next;
    }
    t=l;
    l=l->next;
    free(t);
    return l;
}

List mult(List l1,List l2)
{
    if(!l1||!l2)
        return NULL;
    List t,p,pa,pb,l=(List)malloc(sizeof(struct LNode));
    l->next=NULL;
    p=l;
    pa=l1;
    pb=l2;
    while(pb)
    {
        attach(pa->ceof*pb->ceof,pa->expon+pb->expon,&p);
        pb=pb->next;
    }
    pa=pa->next;
    while(pa)
    {
        pb=l2;
        p=l;

        while(pb)
        {
            int e,c;
            e=pa->expon+pb->expon;
            c=pa->ceof*pb->ceof;
            while(p->next&&p->next->expon>e)
                p=p->next;
            if(p->next&&p->next->expon==e)
            {
                if((p->next->ceof+c)==0)
                {
                    t=p->next;
                    p->next=t->next;
                    free(t);
                }
                else
                {
                    p->next->ceof=p->next->ceof+c;
                }
            }
            else
            {
                t=(List)malloc(sizeof(struct LNode));
                t->ceof=c;
                t->expon=e;
                t->next=p->next;
                p->next=t;
                p=p->next;
            }
            pb=pb->next;
        }
        pa=pa->next;
    }
    t=l;
    l=l->next;
    free(t);
    return l;
}
