#ifndef _LINKQUEUE_H
#define _LINKQUEUE_H
#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;

typedef struct _queue {
	ElemType data;
	struct _queue* next;
}qNode, * qNodePrt;
typedef struct {
	qNode* front, * rear;
}Queue;

void InitQueue(Queue* q) {
	q->front = q->rear = NULL;
}
void EnQueue(Queue* Q, ElemType e) {
	qNodePrt p = (qNodePrt)malloc(sizeof(qNode));
	if (!p)	exit(0);
	p->data = e;
	p->next = NULL;
	if (Q->rear == NULL) {
		Q->front = Q->rear = p;
		//Q->front->next = Q->rear;
	}
	else {
		Q->rear->next = p;
		Q->rear = p;
	}
}
void DeQueue(Queue* q, ElemType* e) {
	qNodePrt temp;

	if (!q->front)
		return;

	*e = q->front->data;
	temp = q->front;

	if (q->front == q->rear) {
		q->rear = q->front = NULL;
	}
	else {
		q->front = q->front->next;
	}
	free(temp);
}// 队头存数值

#endif // !_LINKQUEUE_H