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
List Insert_null(ElementType x,List L)//给一个空链表里面逐个添加元素
{
	Position TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	if (TmpCell == NULL)
		printf("Out of space!!!");
	
	TmpCell->Element = x;
	if (L->Next == NULL)
		TmpCell->Next = NULL;
	else
		TmpCell->Next = L->Next;
	L->Next = TmpCell;
	return L;
}
void PrintLots(List L,List P)
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
List intersection(List T, List P,List U)
{
	Position TmpT, TmpP;
	TmpT = T->Next;
	TmpP = P->Next;
	U = malloc(sizeof(struct Node));
	U->Next = NULL;
	if (U == NULL)
		printf("Out of space!!!");
	while (TmpT != NULL && TmpP != NULL)
	{
		if (TmpT->Element > TmpP->Element)
		{
			TmpP = TmpP->Next;
		}
		else if (TmpT->Element < TmpP->Element)
		{
			TmpT = TmpT->Next;
		}
		else
		{
			U = Insert_null(TmpT->Element, U);
			TmpT = TmpT->Next;
			TmpP = TmpP->Next;
		}
	}
	return U;
}
List unionset(List T, List P, List U)
{
	Position TmpT, TmpP;
	TmpT = T->Next;
	TmpP = P->Next;
	U = malloc(sizeof(struct Node));
	U->Next = NULL;//很重要，不然会出现访问异常
	if (U == NULL)
		printf("Out of space!!!");
	while (TmpT != NULL && TmpP != NULL)
	{
		if (TmpT->Element > TmpP->Element)
		{
			U=Insert_null(TmpP->Element, U);
			TmpP = TmpP->Next;
		}
		else if (TmpT->Element < TmpP->Element)
		{
			U=Insert_null(TmpT->Element, U);
			TmpT = TmpT->Next;
		}
		else
		{
			U = Insert_null(TmpT->Element, U);
			TmpT = TmpT->Next;
			TmpP = TmpP->Next;
		}
	}
	if (TmpT == NULL)
	{
		while (TmpP != NULL)
		{
			U = Insert_null(TmpP->Element, U);
			TmpP = TmpP->Next;
		}

	}
	if (TmpP == NULL)
	{
		while (TmpT != NULL)
		{
			U = Insert_null(TmpT->Element, U);
			TmpT = TmpT->Next;
		}

	}
	return U;
}
void printSet(List L)
{
	Position P;
	P = L->Next;
	printf("{");
	while (P->Next != NULL)
	{
		printf("%d, ", P->Element);
		P = P->Next;
	}
	printf("%d", P->Element);
	printf("}");
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
	printf("运行时间是：%0.3fms\n", total_time);
	int c[10] = { 1,3,4,5,8,12,14,19,21,25 };
	int d[9] = { 0,4,6,9,12,13,17,19,21 };
	List L1 = NULL;
	List P1 = NULL;
	List U = NULL;
	List S = NULL;
	L1 = Initialize(L1);
	P1 = Initialize(P1);
	L1 = Insert(c, 10, L1);
	P1 = Insert(d, 9, P1);
	U = Initialize(U);
	S = Initialize(S);
	S = intersection(L1, P1, S);
	U = unionset(L1, P1, U);
	printf("两表并集：");
	printSet(U);
	printf("\n");
	printf("两表交集：");
	printSet(S);
	return 0;
}
