#ifndef SQSTACK_H
#define SQSTACK_H

#define STACK_INT_SIZE		20
#define STACKINCREASEMENT	10

typedef int ElemType;
typedef struct Stack {
	ElemType* top;
	ElemType* base;
	int StackSize;
}sqStack;

void StackInit(sqStack* s);
void StackPop(sqStack* s, ElemType* e);
void StackPush(sqStack* s, ElemType e);

#endif