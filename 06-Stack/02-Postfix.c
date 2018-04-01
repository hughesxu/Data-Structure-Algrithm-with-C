#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "postfix.h"

#define EmptyOfStack (-1)

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

Stack CreateStack(int MaxElements)
{
	Stack S;
	S = (Stack)malloc(sizeof(struct StackRecord));
	if (S == NULL)
		printf("Out of space !");
	S->Array = (ElementType *)malloc(sizeof(ElementType)*MaxElements);
	if (S->Array == NULL)
		printf("Out of space !");
	S->Capacity = MaxElements;
	S->TopOfStack = EmptyOfStack;

	return S;
}

ElementType Pop(Stack S)
{
	ElementType TopElem;
	if (IsEmpty(S))
		printf("Stack is Empty!");
	else
	{
		TopElem = S->Array[S->TopOfStack];
		S->TopOfStack--;
	}
	return TopElem;
}

void Push(ElementType X, Stack S)
{
	//if (IsFull(S))
	//	printf("Stack is full !");
	S->Array[++S->TopOfStack] = X;
}

int IsEmpty(Stack S)
{
	return (S->TopOfStack == EmptyOfStack);
}

void DisposeStack(Stack S)
{
	if (S != NULL)
	{
		free(S->Array);
		free(S);
	}
}

double Caculate(char ch, double a, double b)
{
	double Result = 0;
	switch (ch)
	{
	case '+':
		Result = a + b;
		break;
	case '-':
		Result = a - b;
		break;
	case '*':
		Result = a * b;
		break;
	case '/':
		Result = a / b;
		break;
	default:
		break;
	}
	return Result;
}

int main(void)
{
	char s[100] ;
	int i = 0, data = 0;
	int data_a, data_b;
	memset(s, '\0', 100);
	printf("Please input postfix expression with space interval!\n");
	while (gets_s(s, 50) != NULL)
	{
		Stack PostArray = CreateStack(50);
		for (i = 0; s[i] != '\0'; i++)
		{
			if (s[i] <= '9' && s[i] >= '0')
			{
				data = data * 10 + s[i] - '0';
			}
			else if (s[i] == ' ')
			{
				if (data != 0)
				{
					Push(data, PostArray);
					data = 0;
				}
			}
			else
			{
				if (data != 0)
				{
					Push(data, PostArray);
					data = 0;
				}
				data_b = Pop(PostArray);
				data_a = Pop(PostArray);
				data = Caculate(s[i], data_a, data_b);
				Push(data, PostArray);
				data = 0;
			}
		}
		if (i != 0)
		{
			if (PostArray->TopOfStack == 0)
				printf("The result is: %d\n", Pop(PostArray));
			else
				printf("The signs mismatch !\n");
		}	
		DisposeStack(PostArray);
	}
}

