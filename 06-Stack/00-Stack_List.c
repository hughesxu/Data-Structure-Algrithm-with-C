#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Node
{
	ElementType Element;
	PtrToNode Next;
};

/** ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
 */
int IsEmpty(Stack S)
{
	return (S->Next == NULL);
}

/** Éú³ÉÕ» 
 */
Stack CreateStack(void)
{
	Stack S;
	S = (Stack)malloc(sizeof(struct Node));
	if (S == NULL)
		printf("Out of Space!");
	S->Next = NULL;
	MakeEmpty(S);
	return S;
}

/** Ïú»ÙÕ»
*/
void DisposeStack(Stack S);
{
	PtrToNode FirstCell;

	while (!IsEmpty(S))
	{
		FirstCell = S->Next;
		S->Next = FirstCell->Next;
		free(FirstCell);
	}
	free(S);
}

/** Çå¿ÕÕ»
 */
void MakeEmpty(Stack S)
{
	if (S == NULL)
		printf("Stack is Not Existing!");
	else
	{
		while (!IsEmpty(S))
			Pop(S);
	}
}

/** ³öÕ»£¬ÈôÕ»Îª¿Õ£¬±¨´í
 */
void Pop(Stack S)
{
	PtrToNode FirstCell;
	if (IsEmpty(S))
		printf("Stack is Empty!");
	else
	{
		FirstCell = S->Next;
		S->Next = FirstCell->Next;
		free(FirstCell);
	}
}

/** Ñ¹Õ»
*/
void Push(ElementType X, Stack S)
{
	PtrToNode NewElem;
	NewElem = (Stack)malloc(sizeof(struct Node));
	if (NewElem == NULL)
		printf("Out of Space!");
	else
	{
		NewElem->Element = X;
		NewElem->Next = S->Next;
		S->Next = NewElem;
	}
}

/** ·µ»ØÕ»¶¥ÔªËØ
*/
ElementType Top(Stack S)
{
	if (!IsEmpty(S))
		return S->Next->Element;
	printf("Error!");
	return 0;
}