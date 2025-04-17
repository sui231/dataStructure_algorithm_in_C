#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

void initQueue(LinkQueue* q) {
	q->front = q->rear = NULL;
}



void init_queue(CycleQueue* q) {
	q->base = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	if (!q->base) exit(0);
	q->front = q->rear = NULL;
}
