//23·Ö maybe 1 -1 -1 0 1 2
#include<stdio.h>

void Maxsub(int a[],int n);
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[10000];
        int x;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            a[i]=x;
        }
        Maxsub(a,n);
    }
    return 0;
}
void Maxsub(int a[],int n)
{
    int left,right;
    int thissum,maxsum;
    int i;
    thissum=left=right=0;
    maxsum=-1;
    int maybe=0;
    int flag=1;
    int flag_all=1;
    for(i=0;i<n;i++)
    {
        thissum+=a[i];
        if(thissum>maxsum)
        {
            flag_all=0;
            maxsum=thissum;
            right=a[i];
            if(flag)
            {
                left=maybe;
                flag=0;
            }
        }
        else if(thissum<0)
        {
            maybe=i+1;
            thissum=0;
            flag=1;
        }
    }
    if(flag_all)
    {
        printf("0 %d %d",a[0],a[n-1]);
    }
    else
        printf("%d %d %d",maxsum,a[left],right);
}
