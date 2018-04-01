#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Node
{
	ElementType Element;
	PtrToNode Next;
};

/** �ж�ջ�Ƿ�Ϊ��
 */
int IsEmpty(Stack S)
{
	return (S->Next == NULL);
}

/** ����ջ 
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

/** ����ջ
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

/** ���ջ
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

/** ��ջ����ջΪ�գ�����
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

/** ѹջ
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

/** ����ջ��Ԫ��
*/
ElementType Top(Stack S)
{
	if (!IsEmpty(S))
		return S->Next->Element;
	printf("Error!");
	return 0;
}