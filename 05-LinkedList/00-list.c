#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	ElementType Element;
	Position Next;
};

/** �ж������Ƿ�Ϊ��
 * @param 
 */
int IsEmpty(List L)
{
	return (L->Next == NULL);
}

/** �ж�Ԫ���Ƿ�Ϊ����β
 * @param
 */
int IsLast(Position P, List L)
{
	return (P->Next == NULL);
}

/** ����Ԫ���������е�λ��
 * @ret �����Ҳ���������NULL 
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

/** ����Ԫ����������λ�õ�ǰһ��λ��
 * @ret �����Ҳ����������һ��Ԫ��λ�� 
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

/** ɾ��������ĳ��Ԫ�أ����û���򲻴���
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

/** ��ָ��λ��P�����Ԫ��
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

/** ɾ������
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

/** ������ӡ��������Ԫ��
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