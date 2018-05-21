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
    int a[]={-1,3,-2,4,-6,1,6,-1};
    printf("%d",MaxSubseqSum4(a,8));
}
