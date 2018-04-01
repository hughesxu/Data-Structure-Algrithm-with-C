#include<stdio.h>

//计算三个整数间最大值
int Max3(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return a;
		else
			return c;
	}
	else if (b > c)
	{
		return b;
	}
	else
		return c;
}

//分治策略,整个数列分成左右两个部分，分别求最大子列和
int MaxSubsequenceSum(const int A[], int left, int right)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum, RightBorderSum;
	int Center, i;

	if (left == right)
	{
		if (A[left] > 0)
			return A[left];
		else
			return 0;
	}

	Center = (left + right) / 2;
	MaxLeftSum = MaxSubsequenceSum(A, left, Center);
	MaxRightSum = MaxSubsequenceSum(A, Center + 1, right);

	MaxLeftBorderSum = 0, MaxRightBorderSum = 0;
	LeftBorderSum = 0, RightBorderSum = 0;
	for ( i = Center; i >= left; i--)
	{
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}

	for ( i = Center + 1; i <= right; i++)
	{
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int main(void)
{
	int len = 0;
	int A[8] = { 4, -3, 5, -2, -1, 2, 6, -2 };
	printf("%d\n", MaxSubsequenceSum(A, 0, 7));
	return 0;
}
