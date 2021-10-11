#include"head.h"
#include<stdio.h>
#include<time.h>
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
	Position P=L->Next, Tmp;
	if (L == NULL)
		printf("Initial list first");
	else if(L->Next!=NULL)
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
List Insert(ElementType a[], int N,List L)
{
	Position TmpCell, Rear=NULL;
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
void PrintLots(List L, List P)
{
	Position PosL, PosP;
	ElementType x;
	int count=1,i;
	PosL = L->Next;
	PosP = P->Next;
	while (PosL != NULL && PosP!=NULL)
	{
		x = PosL->Element;
		for (i = count; i < x; i++)
		{
			PosP = PosP->Next;
			count++;
		}
		printf("%d  ", PosP->Element);
		PosL = PosL->Next;
	}
	if (PosP == NULL)
	{
		printf("\nList P is end\n");
	}
	if (PosL == NULL)
	{
		printf("\nList L is end\n");
	}
}
int main()
{
	time_t begin, finish;
	double total_time;
	int a[4] = { 1,3,4,6 };
	int b[10] = { 4,2,6,8,2,7,9,23,67,12 };
	List L = NULL;
	List P = NULL;
	L=Initialize(L);
	P=Initialize(P);
	L = Insert(a, 4, L);
	P = Insert(b, 10, P);
	begin = clock();
	PrintLots(L, P);
	finish = clock();
	total_time = (double)(finish - begin) / CLOCKS_PER_SEC;
	printf("运行时间是：%0.3fms", total_time);
	return 0;
}
