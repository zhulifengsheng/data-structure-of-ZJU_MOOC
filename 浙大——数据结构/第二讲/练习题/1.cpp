#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲������������NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    Print(L1);
    L2 = Read();
    Print(L2);
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
List Read()
{
    int n;
    scanf("%d",&n);
    List L=(List)malloc(sizeof(PtrToNode));   ///����һ��ͷ���
    L->Next = NULL;        ///ͷָ��Ϊ��
    if(n)    ///��n����0ʱ
    {
        List r=L;     ///r��һ���м�����Ľڵ�
        for(int i=0;i<n;i++)
        {
            List p=(List)malloc(sizeof(struct Node));
            scanf("%d",&(p->Data));    ///β�巨
            r->Next = p;
            r = p;
        }
        r->Next = NULL;
    }
    return L;
}

void Print( List L )
{
   List p=L->Next;
   if(p)
   {
       List r;
       r = L;
       while(r->Next)
       {
           r = r->Next;
           printf("%d ",r->Data);
           printf("%d ",r);
       }
   }
   else
   {
       printf("NULL");
   }
   printf("\n");
}
List Merge(List L1,List L2)
{
    List t2,t,pa,pb;
    t2=t=(List)malloc(sizeof(struct Node));  //must create empty list head
    pa=L1->Next;
    pb=L2->Next;
    while(pa&&pb)
    {
        if(pa->Data<=pb->Data)
        {
            t->Next=pa;
            t=pa;
            pa=pa->Next;
        }
        else
        {
            t->Next=pb;
            t=pb;
            pb=pb->Next;
        }
    }
    if(pa)
    {
        t->Next=pa;
    }
    if(pb)
    {
        t->Next=pb;
    }
    //L1->Next=NULL;
    //L2->Next=NULL;
    return t2;
}
