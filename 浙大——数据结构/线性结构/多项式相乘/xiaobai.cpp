#include<stdio.h>
#include<stdlib.h>

typedef struct PolyNode *Polynomial;
struct PolyNode
{
    int coef;
    int expon;
    Polynomial link;
};
void Attach(int c,int e,Polynomial *l)
{
    Polynomial p;
    p=(Polynomial)malloc(sizeof(struct PolyNode));
    p->coef=c;
    p->expon=e;
    p->link=NULL;
    (*l)->link=p;
    (*l)=p;
}
Polynomial readPoly()
{
    Polynomial p,l,t;
    int n,c,e;
    scanf("%d",&n);
    p=(Polynomial)malloc(sizeof(struct PolyNode));
    p->link=NULL;
    l=p;
    while(n--)
    {
        scanf("%d %d",&c,&e);
        Attach(c,e,&l);
    }
    t=p;p=p->link;free(t);
    return p;
}
Polynomial Add(Polynomial p1,Polynomial p2)
{
    Polynomial p,l,t1,t2,t;
    t1=p1;
    t2=p2;
    p=(Polynomial)malloc(sizeof(struct PolyNode));
    p->link=NULL;
    l=p;
    while(t1&&t2)
    {
        if(t1->expon==t2->expon)
        {
            int sum;
            sum=t1->coef+t2->coef;
            if(sum!=0)
                Attach(sum,t1->expon,&l);
            t1=t1->link;
            t2=t2->link;
        }
        else if(t1->expon>t2->expon)
        {
            Attach(t1->coef,t1->expon,&l);
            t1=t1->link;
        }
        else
        {
            Attach(t2->coef,t2->expon,&l);
            t2=t2->link;
        }
    }
    while(t1){Attach(t1->coef,t1->expon,&l);t1=t1->link;}
    while(t2){Attach(t2->coef,t2->expon,&l);t2=t2->link;}
    t=p;p=p->link;free(t);
    return p;
}
Polynomial mult(Polynomial p1,Polynomial p2)
{
    Polynomial p,l,t1,t2,t;
    int c,e;
    if(!p1||!p2)
        return NULL;
    t1=p1;
    t2=p2;
    p=(Polynomial)malloc(sizeof(struct PolyNode));
    p->link=NULL;
    l=p;
    while(t2)
    {
        Attach(t1->coef*t2->coef,t1->expon+t2->expon,&l);
        t2=t2->link;
    }
    t1=t1->link;
    while(t1)
    {
        t2=p2;
        l=p;
        while(t2)
        {
            e=t1->expon+t2->expon;
            c=t1->coef*t2->coef;
            while(l->link&&l->link->expon>e)
                l=l->link;
            if(l->link&&l->link->expon==e)
            {
                t=l->link;
                l->link=t->link;
                free(t);
            }
            else
            {
                t=(Polynomial)malloc(sizeof(struct PolyNode));
                t->coef=c;
                t->expon=e;
                t->link=l->link;
                l->link=t;
                l=l->link;
            }
            t2=t2->link;
        }
        t1=t1->link;
    }
    t2=p;
    p=p->link;
    free(t2);
    return p;
}

void printPoly(Polynomial p)
{
    int flag=0;
    if(!p)
    {
        printf("0 0\n");
        return;
    }
    while(p)
    {
        if(!flag)
            flag=1;
        else
            printf(" ");
        printf("%d %d",p->coef,p->expon);
        p=p->link;
    }
    printf("\n");
}

int main()
{
    Polynomial p1,p2,pp,ps;
    p1=readPoly();
    p2=readPoly();
    pp=mult(p1,p2);
    printPoly(pp);
    ps=Add(p1,p2);
    printPoly(ps);
    return 0;
}
