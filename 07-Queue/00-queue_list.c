#include <stdio.h>
#include <stdlib.h>
#include "queue_list.h"

struct Node
{
	ElementType Element;
	struct Node *Next;
};

struct QNode
{
	struct Node *Rear;
	struct Node *Front;
};

/* �ж϶����Ƿ�Ϊ��
*/
int IsEmpty(Queue Q)
{
	return (Q->Front->Next == NULL);
}

/* ��������
 * @ ��ͷ���Ķ���
*/
Queue CreateQueue(void)
{
	Queue Q;
	Q = (Queue)malloc(sizeof(struct QNode));
	if (Q == NULL)
		printf("Out of Space!\n");
	Q->Rear = Q->Front = (PtrToNode)malloc(sizeof(struct Node));
	Q->Front->Next = NULL;
}

/* �ͷ��������
*/
void DisposeQueue(Queue Q)
{
	PtrToNode Cell;
	Cell = Q->Front->Next;
	while (Cell != NULL)
	{
		Q->Front->Next = Cell->Next;
		free(Cell);
		Cell = Q->Front->Next;
	}
	free(Q->Front);
	free(Q);
}

void MakeEmpty(Queue Q)
{
	while (!IsEmpty(Q))
	{
		Dequeue(Q);
	}
}

/* ���
*/
void Enqueue(ElementType X, Queue Q)
{
	PtrToNode NewCell;
	NewCell = (PtrToNode)malloc(sizeof(struct Node));
	if (NewCell == NULL)
		printf("Out of space !");
	NewCell->Element = X;
	NewCell->Next = NULL;
	Q->Rear->Next = NewCell;
	Q->Rear = NewCell;
}

/* ����
*/
ElementType Dequeue(Queue Q)
{
	ElementType FirstElem;
	PtrToNode FirstCell;
	FirstCell = Q->Front->Next;
	FirstElem = FirstCell->Element;
	Q->Front->Next = FirstCell->Next;
	free(FirstCell);

	return FirstElem;
}
