#pragma once
#ifndef __STACK_H
#define __STACK_H

typedef int ElementType;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Pop(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);

#endif
