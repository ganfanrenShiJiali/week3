#include<stdio.h>
#ifndef _list_h
#define _list_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

List Initial(List L,int n);
List MakeEmpty(List L);
void Win(List L, int M, int N);
#endif
struct Node
{
	int number;
	Position *Next;
};
