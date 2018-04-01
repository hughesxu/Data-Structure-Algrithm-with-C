#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

struct Node
{
	ElementType Element;
	PtrToNode Next;
};

Stack CreateStack(void)
{
	Stack S;
	S = (Stack)malloc(sizeof(struct Node));
	if (S == NULL)
		printf("Out of space !");
	S->Next = NULL;
	return S;
}

int IsEmpty(Stack S)
{
	return (S->Next == NULL);
}

ElementType Pop(Stack S)
{
	ElementType TopElem;
	PtrToNode FirstCell;
	if (IsEmpty(S))
		printf("Stack is Empty!\n");
	else
	{
		FirstCell = S->Next;
		TopElem = FirstCell->Element;
		S->Next = FirstCell->Next;
		free(FirstCell);
	}
	return TopElem;
}

void Push(ElementType X, Stack S)
{
	PtrToNode NewCell;
	NewCell = (PtrToNode)malloc(sizeof(struct Node));
	if (NewCell == NULL)
		printf("Out of space !\n");
	else
	{
		NewCell->Element = X;
		NewCell->Next = S->Next;
		S->Next = NewCell;
	}
}



void DisposeStack(Stack S)
{
	PtrToNode Ptr, FirstCell;
	Ptr = S;
	while (Ptr != NULL)
	{
		FirstCell = Ptr;
		Ptr = Ptr->Next;
		free(FirstCell);
	}
}

ElementType Top(Stack S)
{
	if (S->Next != NULL)
		return S->Next->Element;
	else
		return '\0';
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

int Result(char *ptr)
{
	int i = 0, data = 0;
	int data_a, data_b;
	int result = 0;
	Stack PostArray = CreateStack();
	for (i = 0; ptr[i] != '\0'; i++)
	{
		if (ptr[i] <= '9' && ptr[i] >= '0')
		{
			data = data * 10 + ptr[i] - '0';
		}
		else if (ptr[i] == ' ')
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
			data = Caculate(ptr[i], data_a, data_b);
			Push(data, PostArray);
			data = 0;
		}
	}
	if (i != 0)
	{
		result = Pop(PostArray);
	}
	DisposeStack(PostArray);
	return result;
}


int main(void)
{
	int i = 0, k = 0;
	char s[100], res[100];
	memset(res, '\0', 100);
	memset(s, '\0', 100);

	while (gets_s(s, 50) != NULL)
	{
		Stack Array = CreateStack();
		for (i = 0,k = 0; s[i] != '\0'; i++)
		{
			
			if (s[i] >= '0' && s[i] <= '9')
				res[k++] = s[i];
			else if (s[i] == '*' || s[i] == '/')
			{
				while (Top(Array) == '*' || Top(Array) == '/')
				{
					res[k++] = ' ';
					res[k++] = Pop(Array);
				}
				res[k++] = ' ';
				Push(s[i], Array);
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				while (Top(Array) == '+' || Top(Array) == '-' || Top(Array) == '*' || Top(Array) == '/')
				{
					res[k++] = ' ';
					res[k++] = Pop(Array);
				}
				res[k++] = ' ';
				Push(s[i], Array);
			}
			else if (s[i] == '(')
			{
				//res[k++] = ' ';
				Push(s[i], Array);
			}
			else if (s[i] == ')')
			{
				while (Top(Array) != '(')
				{
					res[k++] = ' ';
					res[k++] = Pop(Array);
				}
				Pop(Array);
			}
		}
		while (! IsEmpty(Array))
		{
			res[k++] = ' ';
			res[k++] = Pop(Array);
		}
		puts(res);
		
		DisposeStack(Array);

		printf("The result is :%d\n", Result(res));
		memset(s, '\0', 100);
		memset(res, '\0', 100);
	}
}