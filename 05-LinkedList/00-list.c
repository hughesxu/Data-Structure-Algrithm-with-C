#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	ElementType Element;
	Position Next;
};

/** 判断链表是否为空
 * @param 
 */
int IsEmpty(List L)
{
	return (L->Next == NULL);
}

/** 判断元素是否为链表尾
 * @param
 */
int IsLast(Position P, List L)
{
	return (P->Next == NULL);
}

/** 查找元素在链表中的位置
 * @ret 若查找不到，返回NULL 
 */
Position Find(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while ((P->Element != X) && (P != NULL))
	{
		P = P->Next;
	}
	return P;
}

/** 查找元素在链表中位置的前一个位置
 * @ret 若查找不到返回最后一个元素位置 
*/
Position FindPrevious(ElementType X, List L);
{
	Position P;
	P = L;

	while ( P->Next->Element != X && P->Next != NULL)
	{
		P = P->Next;
	}
	return P;
}

/** 删除链表中某个元素，如果没有则不处理
 */
void Delete(ElementType X, List L)
{
	Position P, PToDel;

	P = FindPrevious(X, L);

	if (!IsLast(P, L))
	{
		PToDel = P->Next;
		P->Next = PToDel->Next;
		free(PToDel);
	}
}

/** 在指定位置P后插入元素
*/
void Insert(ElementType X, Position P, List L)
{
	Position NewElem;
	NewElem = (Position)malloc(sizeof(struct Node));

	if (NewElem == NULL)
		printf("OutofSpace!");

	NewElem->Element = X;
	NewElem->Next = P->Next;
	P->Next = NewElem;
}

/** 删除链表
*/
void DeleteList(List L)
{
	Position P, PToDel;
	P = L->Next;
	while (P != NULL)
	{
		PToDel = P;
		P = P->Next;
		free(PToDel);
	}
	L->Next = NULL;
}

/** 遍历打印链表所有元素
*/
void PrintList(List L)
{
	Position P;
	P = L->Next;
	while (P != NULL)
	{
		printf("%d\n", P->Element);
		P = P->Next;
	}
}