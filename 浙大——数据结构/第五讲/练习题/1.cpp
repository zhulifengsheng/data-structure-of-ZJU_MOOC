#include<stdio.h>
#define MAXN 1001
#define MINH -10001
//数组表示
int H[MAXN],Size;//size:当前堆的大小

void Create()
{
    Size=0;
    H[0]=MINH;//哨兵 i/2
}
void Insert(int x)
{
    int i;
    for(i=++Size;H[i/2]>x;i/=2)
        H[i]=H[i/2];
    H[i]=x;
}

int main()
{
    int n,m,x,i,j;
    scanf("%d %d",&n,&m);
    Create();
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        Insert(x);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&j);
        if(j!=1)
            printf("%d ",H[j]);
        else printf("%d",H[j]);
        while(j>1)
        {
            j/=2;
            if(j!=1)
                printf("%d ",H[j]);
            else printf("%d",H[j]);
        }
        printf("\n");
    }
    return 0;
}
