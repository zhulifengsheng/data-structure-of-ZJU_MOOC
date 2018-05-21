#include<stdio.h>

int MaxSubseqSum4( int A[], int N )
{   int ThisSum, MaxSum;
    int i;
    ThisSum = MaxSum = 0;
    for( i = 0; i < N; i++ ) {
          ThisSum += A[i]; /* �����ۼ� */
          if( ThisSum > MaxSum )
                  MaxSum = ThisSum; /* ���ָ��������µ�ǰ��� */
          else if( ThisSum < 0 ) /* �����ǰ���к�Ϊ�� */
                  ThisSum = 0; /* �򲻿���ʹ����Ĳ��ֺ���������֮ */
    }
    return MaxSum;
}//���ߵ���˼��ָÿ����һ�����ݾͽ��м�ʱ����

int main()
{
    int a[]={-1,3,-2,4,-6,1,6,-1};
    printf("%d",MaxSubseqSum4(a,8));
}
