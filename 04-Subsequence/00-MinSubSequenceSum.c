#include<stdio.h>
#include<stdlib.h>

/*
//int MinSubsequenceSum(const int A[], int N)
//{
//	int ThisSum, MinSum, i, j;
//
//	MinSum = A[0];
//	for ( i = 0; i < N; i++)
//	{
//		ThisSum = 0;
//		for (j = i; j < N; j++)
//		{
//			ThisSum += A[j];
//
//			if (ThisSum < MinSum)
//			{
//				MinSum = ThisSum;
//			}
//		}
//	}
//	return MinSum;
//
//}
*/

int MinSubsequenceSum(const int A[], int N)
{
	int Thissum, Minsum, i;

	Minsum = A[0];
	Thissum = 0;
	for ( i = 0; i < N; i++)
	{
		Thissum += A[i];
		if (Thissum < Minsum)
		{
			Minsum = Thissum;
		}
		else if (Thissum > 0)
		{
			Thissum = 0;
		}
	}
	return Minsum;
}


int main(void)
{
	int len = 0;
	unsigned int N;
//	int A[8] = { 4, -3, 5, -2, -1, 2, 6, -2 };
//	printf("%d\n", MinSubsequenceSum(A, 8));
	
	while (scanf_s("%d",&N) != EOF)
	{
		int *A = (int *)malloc( N * sizeof(int));
		for (unsigned int i = 0; i < N; i++)
		{
			A[i] = rand() % 200 - 100;				//产生-99 ~ +99之间的随机数
			printf("%5d", A[i]);
		}
		printf("\n%d\n", MinSubsequenceSum(A, N));
		free(A);
	}
	return 0;
}