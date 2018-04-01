#include<stdio.h>
#include<stdlib.h>


int MinSubsequenceSum(const int A[], int N)
{
	int Thissum, Minsum, i, j = 0;

	while (A[j] <= 0)
	{
		j++;
	}
	Minsum = A[j];
	
	for (i = 0; i < N; i++)
	{
		Thissum = 0;
		for (j = i; j < N; j++)
		{
			Thissum += A[j];
			if ((Thissum < Minsum)  && (Thissum > 0))
				Minsum = Thissum;
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

	while (scanf_s("%d", &N) != EOF)
	{
		int *A = (int *)malloc(N * sizeof(int));
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