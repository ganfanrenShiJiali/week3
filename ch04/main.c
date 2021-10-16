#include<stdio.h>
#define Max_ 10
typedef int ElementType;
typedef struct mama *PtrToList;
typedef PtrToList List;

struct mama
{
    ElementType data[Max_];
	int SizeOfList;
	int IsFind;
};
List CreateList(List L, ElementType a[], int n)

{
	int i;
	L = (List)malloc(sizeof(List));
	if (L == NULL)
		perror("Out Of Space!!!");
	if (n > Max_) n = Max_;

	for (i = 0; i < n; i++)

	{
		L->data[i] = a[i];

	}
	L->SizeOfList = n;
	L->IsFind = 0;
	return L;
}
/*自调整表的数组实现*/
List Find(ElementType x, List L)
{
	int i, Where;
	Where = 0;
	for (i = 0; i < L->SizeOfList; i++)
	{
		if (L->data[i] == x)
		{
			Where = i;
			break;
		}
	}
	if (Where)
	{
		for (i = Where; i > 0; i--)
		{
			L->data[i] = L->data[i - 1];
		}
		L->data[0] = x;
		L->IsFind = 1;
	}
	return L;	
}
void print(List L)
{
	int i;
	for (i = 0; i < L->SizeOfList; i++)
	{
		printf("%d  ", L->data[i]);
	}
}
int main()
{
	int a[Max_] = { 1,2,3,4,5,6,7,8,9,10 };
	List L = NULL;
	L = CreateList(L, a, Max_);
	print(L);
	L = Find(6, L);
	L->IsFind == 0 ? printf("\n没有找到该元素\n") : printf("\n找到该元素\n");
	print(L);
	return 0;
}
