#include<stdio.h>
#include<stdlib.h>
#include"practice.h"
#include<math.h>

void InitStack(sqStack* s) {
	s->base = (ElemType*)malloc(sizeof(ElemType) * STACK_INT_MAXSIZE);
	if (!s->base)
		exit(0);
	s->top = s->base;
	s->StackSize = 0;
}

void Push(sqStack* s, ElemType e) {
	if (s->top - s->base >= STACK_INT_MAXSIZE) {
		s->base = (ElemType*)realloc(s->base, (s->StackSize + STACKINCREASEMENT) * sizeof(ElemType));
			exit(0);
		s->StackSize += STACKINCREASEMENT;
	}
	*(s->top) = e;
	s->top++;
}

void Pop(sqStack* s, ElemType* e) {
	if (s->base == s->top)
		return;
	s->top--;
	*e = *s->top;
	//*e = *--s->top;
}

int StackLen(sqStack s) {
	return s.top - s.base;
}