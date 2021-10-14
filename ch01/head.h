#include<stdio.h>
#ifndef _List_h
#define _List_h
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

struct Node
{
	ElementType Element;
	PtrToNode Next;
};
List Initialize(List L);
List MakeEmpty(List L);
List Insert(ElementType a[], int N, List L);
List Insert_null(ElementType x, List L);
void PrintLots(List L, List P);
List intersection(List T, List P,List U);
List unionset(List T, List P, List U);
void printSet(List L);
#endif
