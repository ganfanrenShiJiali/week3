/*反转单链表*/
#include"head.h"
Position Rear;
List Initialize(List L)
{
	if (L == NULL)
	{
		L = malloc(sizeof(struct Node));
		if (L == NULL)
			printf("Out of space!!!");
		L->Next = NULL;
		MakeEmpty(L);
	}
	else
	{
		MakeEmpty(L);
	}
	return L;
}
List MakeEmpty(List L)
{
	Position P = L->Next, Tmp;
	if (L == NULL)
		printf("Initial list first");
	else if (L->Next != NULL)
	{
		Tmp = L->Next;
		L->Next = NULL;
		while (P != NULL)
		{
			P = Tmp->Next;
			free(Tmp);
			Tmp = P;
		}

	}
	return L;
}
List Insert(ElementType a[], int N, List L)
{
	Position TmpCell;
	Rear = NULL;
	int i;
	for (i = 0; i < N; i++)
	{
		TmpCell = malloc(sizeof(struct Node));
		TmpCell->Element = a[i];
		TmpCell->Next = NULL;
		if (L->Next == NULL)
		{
			L->Next = TmpCell;
		}
		else
		{
			Rear->Next = TmpCell;
		}
		Rear = TmpCell;
	}
	return L;
}
/*前面都一样，主要是反转函数*/
List reverse(List L)
{
	Position P = Rear,first=L->Next;
	Position Tmp;
	while (L->Next != P)
	{
		Tmp = L->Next;
		P->Next = Tmp;
		L->Next = Tmp->Next;
		Tmp->Next = Rear;
		Rear = Tmp;
	}
	first->Next = NULL;
	return L;
}
void print(List L)
{
	Position P;
	P = L->Next;
	while (P!= NULL)
	{
		printf("%d ", P->Element);
		P = P->Next;
	}
}
int main()
{
	int a[8] = { 1,2,3,4,5,6,7,8 };
	List L = NULL;
	L = Initialize(L);
	Insert(a, 8, L);
	print(L);
	printf("\n");
	L=reverse(L);
	print(L);
	return 0;
}
