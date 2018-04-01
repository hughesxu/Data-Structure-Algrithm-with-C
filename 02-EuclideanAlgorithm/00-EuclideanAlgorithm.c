#include<stdio.h>

unsigned int Gcd(unsigned int M, unsigned int N)
{
	unsigned int Rem;
	while (N > 0)
	{
		Rem = M % N;
		M = N;
		N = Rem;
	}
	return M;
}

int main(void)
{
	unsigned int M = 0, N = 0;
	while (scanf_s("%d%d", &M, &N) != EOF)
	{
		printf("%d\n", Gcd(M, N));
	}
	return 0;
}