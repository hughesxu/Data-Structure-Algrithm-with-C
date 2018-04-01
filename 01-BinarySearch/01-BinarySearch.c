#include<stdio.h>

//二分查找方法
int BinarySearch(int A[], int X, int N)
{
	int low, mid, high;

	low = 0, high = N - 1;
	while (low <= high)
	{
		mid = low + high;
		if (A[mid] < X)
		{
			low = mid + 1;
		}
		else if (A[mid] > X)
		{
			high = mid - 1;
		}
		else
			return mid;
	}
	return -1;
}

int main(void)
{
	int A[] = { 1, 2, 4, 7, 10, 16, 25, 47, 89 };
	int X;
	while (scanf_s("%d",&X) != EOF)
	{
		if (BinarySearch(A, X, 8) != -1)
			printf("The Index Is:%d\n", BinarySearch(A, X, 8));
		else
			printf("Not Found\n");
	}
	return 0;
}