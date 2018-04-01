#pragma once

#ifndef __STACK_ARRAY_H
#define __STACK_ARRAY_H

typedef int ElementType;

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Pop(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);

#endif
