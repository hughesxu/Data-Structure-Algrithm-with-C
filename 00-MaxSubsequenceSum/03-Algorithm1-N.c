#include<stdio.h>


int MaxSubsequenceSum(const int A[], int N)
{
	int ThisSum, MaxSum, i;

	MaxSum = 0, ThisSum = 0;
	for (i = 0; i < N; i++)
	{
		ThisSum += A[i];
		if (ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
		}
		else if (ThisSum < 0)
			ThisSum = 0;
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
