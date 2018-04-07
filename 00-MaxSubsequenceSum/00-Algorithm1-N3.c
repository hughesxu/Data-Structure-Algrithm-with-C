#include<stdio.h>
#include<stdlib.h>

//以每个元素为首元素基准，计算每个子序列和，再判断
int MaxSubsequenceSum(const int A[], int N)
{
	int ThisSum, MaxSum, i, j, k;
	MaxSum = 0;
	for (i = 0; i < N; i++)
		for (j = i; j < N; j++)
		{
			ThisSum = 0;
			for (k = i; k < j; k++)
				ThisSum += A[k];
			if (ThisSum > MaxSum)
			{
				MaxSum = ThisSum;
			}
		}
	return MaxSum;
}

int main(void)
{
	int len = 0;
	int A[8] = { 4, -3, 5, -2, -1, 2, 6, -2 };
	//while (scanf("%d",&len) != EOF)
	//{
	//	int *data = (int *)malloc(len);
	//	for (int i = 0; i < len; i++)
	//	{
	//		data[i] = rand() % 100;
	//		printf("%d", data[i]);
	//	}
	//	printf("\n");
	//}
	printf("%d\n", MaxSubsequenceSum(A, 8));
	return 0;
}
