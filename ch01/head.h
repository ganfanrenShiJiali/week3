#include<stdio.h>

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
void PrintLots(List L, List P);
