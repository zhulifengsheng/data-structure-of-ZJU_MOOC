#include<stdio.h>

int system[10000];

int Find(int x)
{
    if(system[x]<0)
        return x;
    else
        return system[x]=Find(system[x]);
}

void union1(int v1,int v2)
{
    system[Find(v1)]=v2;
}

void C()
{
    int v1,v2;
    scanf("%d %d",&v1,&v2);
    if(Find(v1)==Find(v2))
        printf("yes\n");
    else
        printf("no\n");
    getchar();
}

void I()
{
    int v1,v2;
    scanf("%d %d",&v1,&v2);
    union1(v1,v2);
    getchar();
}

void S(int n)
{
    int coun=0;
    for(int i=1;i<=n;i++)
    {
        if(system[i]<0)coun++;
    }
    if(coun==1)
        printf("The network is connected.");
    if(coun>1)
        printf("There are %d components.",coun);
}

int main()
{
    int n;
    scanf("%d\n",&n);

    for(int i=1;i<=n;i++)
        system[i]=-1;

    char s=1;
    while(s!='S')
    {
        scanf("%c",&s);
        switch(s)
        {
        case'C':C();break;
        case'I':I();break;
        case'S':S(n);break;
        }
    }

    return 0;
}
