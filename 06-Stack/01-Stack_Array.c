#include <stdio.h>
#include <stdlib.h>
#include "stack_array.h"

#define EmptyOfStack (-1)

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

int IsEmpty(Stack S);
{
	return (S->TopOfStack == EmptyOfStack);
}

int IsFull(Stack S)
{
	return (S->TopOfStack == S->Capacity - 1);
}

Stack CreateStack(int MaxElements)
{
	Stack S;
	S = (Stack)malloc(sizeof(struct StackRecord));
	if (S == NULL)
		printf("Out of space !");
	S->Array = (ElementType *)malloc(sizeof(ElementType)*MaxElements);
	if(S->Array == NULL)
		printf("Out of space !");
	S->Capacity = MaxElements;
	MakeEmpty(S);
	
	return S;
}

void DisposeStack(Stack S)
{
	if (S != NULL)
	{
		free(S->Array);
		free(S);
	}
}

void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyOfStack;
}

void Pop(Stack S)
{
	if (IsEmpty(S))
		printf("Stack is Empty!");
	else
		S->TopOfStack--;
}
void Push(ElementType X, Stack S)
{
	if (IsFull(S))
		printf("Stack is full !");
	S->Array[++S->TopOfStack] = X;
}

ElementType Top(Stack S)
{
	if (IsEmpty(S))
	{
		printf("Stack is empty !");
		return 0;
	}
	else
		return S->Array[S->TopOfStack];
}
