#pragma once
#define STACK_INT_MAXSIZE	200
#define STACKINCREASEMENT	100

typedef int ElemType;
typedef struct sqStack {
	ElemType* top;
	ElemType* base;
	int StackSize;
}sqStack;

void InitStack(sqStack* s);
void Push(sqStack* s, ElemType e);
void Pop(sqStack* s, ElemType* e);
int StackLen(sqStack s);