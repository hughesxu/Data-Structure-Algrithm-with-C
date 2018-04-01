#include<stdio.h>

//大数会受限于数据类型的范围
int IsEven(unsigned int N)
{
	if (N % 2 == 1)
		return 0;
	else
		return 1;
}

long int pow(long int X, unsigned int N)
{
	if (N == 0)
		return 1;
	if (IsEven(N) == 1)
		return pow(X * X, N / 2);
	else
		return pow(X * X, N / 2) * X;
}

int main(void)
{
	long int X, Result;
	unsigned int N;
	printf("%d\n", sizeof(long int));
	while (scanf_s("%ld %d", &X, &N) != EOF)
	{
		Result = pow(X, N);
		printf("The Result Is: %ld\n", Result);
	}
	return 0;
}