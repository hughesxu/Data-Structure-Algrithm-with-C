#include<stdio.h>

//以每个元素为首元素基准，依此计算子序列和并及时判断
int MaxSubsequenceSum(const int A[], int N)
{
	int ThisSum, MaxSum, i, j;

	MaxSum = 0;
	for (i = 0; i < N; i++)
	{
		ThisSum = 0;
		for (j = i; j < N; j++)
		{
			ThisSum += A[j];
			if (ThisSum > MaxSum)
			{
				MaxSum = ThisSum;
			}
		}
	}
	return MaxSum;
}

int main(void)
{
	int len = 0;
	int A[8] = { 4, -3, 5, -2, -1, 2, 6, -2 };
	printf("%d\n", MaxSubsequenceSum(A, 8));
	return 0;
}