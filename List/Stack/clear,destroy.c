#include"sqStack.h"
#include<stdio.h>
#include<stdlib.h>

void StackClear(sqStack* s) {
	s->base = s->top;
}

void StackDestroy(sqStack* s) {
	int i,len;
	len = s->StackSize;
	for (i = 0; i < len; i++) {
		free(s->base);
		s->base++;
	}
	s->base = s->top = NULL;
	s->StackSize = 0;
}