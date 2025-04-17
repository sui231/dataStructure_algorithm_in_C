#include"sqStack.h"
#include<stdio.h>
#include<stdlib.h>

void StackPop(sqStack *s,ElemType* e) {
	if (s->base == s->top)
		return;
	*e = *--s->top;//s.top--;*e = *s->top;
}
