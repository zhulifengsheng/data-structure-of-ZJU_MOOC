#include<stdio.h>

int MaxSubseqSum4( int A[], int N )
{   int ThisSum, MaxSum;
    int i;
    ThisSum = MaxSum = 0;
    for( i = 0; i < N; i++ ) {
          ThisSum += A[i]; /* 向右累加 */
          if( ThisSum > MaxSum )
                  MaxSum = ThisSum; /* 发现更大和则更新当前结果 */
          else if( ThisSum < 0 ) /* 如果当前子列和为负 */
                  ThisSum = 0; /* 则不可能使后面的部分和增大，抛弃之 */
    }
    return MaxSum;
}//在线的意思是指每输入一个数据就进行及时处理

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[100000];
        int x;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            a[i]=x;
        }
        printf("%d\n",MaxSubseqSum4(a,n));
    }
    return 0;
}
