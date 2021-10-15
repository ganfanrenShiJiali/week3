#include"head.h"
#include<errno.h>
List Initial(List L,int n)
{
	int i;
	Position P;
	Position Tmp;
	if (L == NULL)
	{
		L = malloc(sizeof(struct Node));
		if (L == NULL)
			perror("Out of space!!");
		L->Next = NULL;
		MakeEmpty(L);
	}
	else
		MakeEmpty(L);
	P = L;
	for (i = 1; i <=n; i++)
	{
		Tmp = malloc(sizeof(struct Node));
		if (Tmp == NULL)
			perror("Out of space!!");
;		Tmp->number = i;
		Tmp->Next = NULL;
		P->Next = Tmp;
		P = Tmp;
	}
	P->Next = L->Next;
	return L;
}
List MakeEmpty(List L)
{
	Position P,Tmp;
	if (L == NULL)
		perror("initial list first");
	else if (L->Next != NULL)
	{
		Tmp = L->Next;
		P = Tmp->Next;
		L->Next = NULL;
		while (P != NULL)
		{	
			free(Tmp);
			Tmp = P;
			P = Tmp->Next;
		}
	}
	return L;
}
void Win(List L,int M,int N)
{
	int num = -1;
	Position P,Tmp;
	P = L;
	Tmp = P->Next;
	int count = N;
	int i;
	while(count!=1)
	{
		num++;
		if (num == M)
		{   
			P->Next = Tmp->Next;
			printf("第%d个被淘汰出局的人的编号：%d\n", N - count + 1, Tmp->number);
			free(Tmp);
			Tmp = P->Next;
			count--;
			num = -1;
		}
		else
		{
			P = P->Next;
			Tmp = Tmp->Next;
		}
	}
	printf("最后获胜的人的编号为:%d\n", Tmp->number);
}
int main()
{
	int n, m;
	printf("开始进行约瑟夫环游戏···\n");
	printf("请输入玩家总数：");
	scanf_s("%d", &n);
	printf("请输入多少次传递后出列一个人：");
	scanf_s("%d", &m);
	List L = NULL;
	L = Initial(L, n);
	Win(L, m, n);
	printf("游戏结束");
	return 0;
}
