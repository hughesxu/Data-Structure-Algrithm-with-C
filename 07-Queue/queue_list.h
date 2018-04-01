#pragma once
#ifndef __QUEUE_LIST_H
#define __QUEUE_LIST_H

typedef int ElementType;
struct Node;
typedef struct Node *PtrToNode;

struct QNode;

typedef struct QNode *Queue;


int IsEmpty(Queue Q);
Queue CreateQueue(void);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Dequeue(Queue Q);

#endif