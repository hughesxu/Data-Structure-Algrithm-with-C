#include <stdio.h>
#include <stdlib.h>
#include "queue_array.h"

struct QueueRecord
{
	int Front;
	int Rear;
	int Capacity;
	ElementType *Array;
};

int IsEmpty(Queue Q)
{
	return (Q->Front == Q->Rear);
}

/* 新建队列
** front == rear 表示队列满
*/
Queue CreateQueue(int MaxElement)
{
	Queue Q;
	Q = (Queue)malloc(sizeof(struct QueueRecord)); 
	if (Q == NULL)
	{
		printf("Out of Space!\n");
		return;
	}
	else
	{
		Q->Array = (ElementType *)malloc(sizeof(ElementType)*MaxElement);
		if (Q->Array == NULL)
			printf("Out of Space!\n");
		else
		{
			Q->Front = Q->Rear = 0;
			Q->Capacity = MaxElement;
		}
	}

	return Q;
}

void DisposeQueue(Queue Q)
{
	if (Q != NULL)
	{
		free(Q->Array);
		free(Q);
	}
}

void MakeEmpty(Queue Q)
{
	Q->Front = Q->Rear = 0;
}

void Enqueue(ElementType X, Queue Q)
{
	if ((Q->Rear + 1) % Q->Capacity == Q->Front)
	{
		printf("Queue is Full!\n");
	}
	else
	{
		Q->Array[Q->Rear] = X;
		Q->Rear = (Q->Rear + 1) % Q->Capacity;
	}
}

ElementType Dequeue(Queue Q)
{
	ElementType X;
	if (IsEmpty(Q))
	{
		printf("Queue is Empty!\n");
		return;
	}
	else
	{
		X = Q->Array[Q->Front];
		Q->Front = (Q->Front + 1) % Q->Capacity;
	}

	return X;
}