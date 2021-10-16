#include"head.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define EmptyTos -1
Stack CreateStack(int MaxElements)
{
	Stack S;
	int i;
	S = malloc(sizeof(struct StackRecord));
	if (S == NULL)
		perror("Out of space!!!");
	S->Array = malloc(sizeof(ElementType)*MaxElements);
	if (S->Array == NULL)
		perror("Out of space!!!");
	S->Capacity = MaxElements;
	S->TopOfStack = EmptyTos;
	/*for (i = 0; i < MaxElements; i++)
	{
		S->Array[i] = a[i];
	}*/
	return S;
}
int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTos;
}
int IsFull(Stack S)
{
	return S->TopOfStack == S->Capacity - 1;
}
ElementType TopAndPop(Stack S)
{
	if (!IsEmpty(S))
	{
		return S->Array[S->TopOfStack--];
	}
	else
		return 0;
}
void Push(ElementType x, Stack S)
{
	if (!IsFull(S))
	{
		S->Array[++S->TopOfStack] = x;
	}
	else
		perror("Full Stack!!!");
}
ElementType getResult(Stack S, char a[])
{
	int i = 0;
	int num1, num2;
	int result;
	while (a[i] != '\0')
	{
		if (a[i] >= 48 && a[i] <= 57)//48-57对应0-9
		{
			Push(a[i]-48, S);//一种将字符数字转化为整型，查了有一个atoi()函数，但是不管用
		}
		else
		{
			num1 = TopAndPop(S);
			num2 = TopAndPop(S);
			switch (a[i])
			{
			case '+':
				Push(num1 + num2, S);
				break;
			case '-':
				Push(num1 - num2, S);
				break;
			case '*':
				Push(num1 * num2, S);
				break;
			case '/':
				if (fabs(num2) < 1e-6)
				{
					perror("Divided by 0!");
				}
				else
				{
					Push(num1 / num2, S);
				}
				break;
			default:
				break;
			}
		}
		i++;
	}
	return TopAndPop(S);
}
int main()
{
	Stack S=NULL;
	S = CreateStack(50);
	int result;
	printf("请输入一个后缀表达式：");
	char string[50];
	gets(string);//回车键结束，一种输入得到字符串的方法
	result = getResult(S, string);
	printf("结果为：%d",result);
	return 0;
}
