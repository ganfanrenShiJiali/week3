#ifndef _stack_h
#define _stack_h

struct StackRecord;
typedef struct StackRecord *Stack;
typedef int ElementType;

Stack CreateStack(int MaxElements);
ElementType TopAndPop(Stack S);
void Push(ElementType x,Stack S);
int IsEmpty(Stack S);
int IsFull(Stack S);
ElementType getResult(Stack S, char a[]);

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};
#endif
