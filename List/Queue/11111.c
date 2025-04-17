#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000

typedef int Type;


typedef struct _queue {
	Type data;
	struct _queue* next;
}qNode, * qNodePrt;
typedef struct {
	qNode* front, * rear;
}Queue;


typedef struct _sqStack {
	Type data[MAXSIZE];
	int top; //栈顶指针 base = 0 
}sqStack;


int isEmpty(Queue* q) {
	return q->front == NULL;
}
void initQueue(Queue* q) {
	q->front = q->rear = NULL;
}
void enQueue(Queue* Q, Type e) {
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
void deQueue(Queue* q, Type* e) {
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
}// 队头队尾存数值