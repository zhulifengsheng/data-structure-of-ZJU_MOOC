//搜索树中序输出一个递增序列
//用到qsort函数。这样，得到了所求的完全二叉搜索树的中序遍历输出a数组
//进行中序遍历，但让b数组以层次遍历顺序计入每个子树根的值
/*
void mid_tre(int root,int N,int a[])
{
    if(root<=N)
    {
        mid_tre(2*root,N,a);
        b[root]=a[j++];
        mid_tre(2*root+1,N,a);
    }
}
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int Tree[1000];
int A[1000];

int compare(const void *a,const void *b);

void Min(int first,int last,int treelocation)
{
    //printf("%d %d %d\n",first,last,treelocation);
    int n=last-first+1;
    if(n==0)return;
    if(n==1){Tree[treelocation]=A[first];return;}
    int h,t;
    h=floor(log(n+1)/log(2));

    int x=n-pow(2,h)+1;
    if(x<=pow(2,h-1))
    {
        t=n-((n-x-1)/2)-1+first;
        Tree[treelocation]=A[t];
    }

    else
    {
        t=n-((n-x-1)/2)-1-(x-pow(2,h-1))+first;
        Tree[treelocation]=A[t];
    }

    Min(first,t-1,treelocation*2+1);
    Min(t+1,last,treelocation*2+2);

}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    qsort(A,n,sizeof(int),compare);
    Min(0,n-1,0);
    for(int i=0;i<n;i++)
    {
        if(i!=n-1)
            printf("%d ",Tree[i]);
        else
            printf("%d",Tree[i]);
    }

    return 0;
}


int compare(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
