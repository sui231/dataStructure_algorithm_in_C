#include"sqStack.h"
#include<stdio.h>
#include<stdlib.h>

void StackPush(sqStack* s, ElemType e) {
	if (s->top - s->base >= STACK_INT_SIZE) {
        if (s->top - s->base >= s->StackSize) {
            ElemType* newBase = (ElemType*)realloc(s->base, (s->StackSize + STACKINCREASEMENT) * sizeof(ElemType));
            if (!newBase)
                exit(EXIT_FAILURE);
            s->base = newBase;
            s->top = s->base + (s->top - s->base);
            s->StackSize += STACKINCREASEMENT;
        }

		s->top = s->base + STACKINCREASEMENT;
		s->StackSize += STACKINCREASEMENT;
	}
	s->top = e;
	s->top++;
}