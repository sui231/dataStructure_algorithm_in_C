#include"sqStack.h"
#include<stdio.h>
#include<stdlib.h>

void StackInit(sqStack* s) {
	s->base = (ElemType*)malloc(sizeof(ElemType) * STACK_INT_SIZE);
	if (!s->base)
		exit(0);
	s->top = s->base;
	s->StackSize = STACK_INT_SIZE;
}