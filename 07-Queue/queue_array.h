#pragma once
#pragma once
#ifndef __QUEUE_ARRAY_H
#define __QUEUE_ARRAY_H

typedef int ElementType;
struct QueueRecord;
typedef struct QueueRecord *Queue;
  
int IsEmpty(Queue Q);
Queue CreateQueue(int MaxElement);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Dequeue(Queue Q);

#endif
