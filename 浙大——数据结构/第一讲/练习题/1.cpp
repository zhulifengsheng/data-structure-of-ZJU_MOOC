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
