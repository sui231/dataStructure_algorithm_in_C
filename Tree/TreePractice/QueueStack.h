#ifndef _QUEUE_STACK_H
#define _QUEUE_STACK_H
#include"BiTree.h"
#define MAXSIZE 1000

typedef BiNode* ElemType1;


typedef struct _queue {
	ElemType1 data;
	struct _queue* next;
}qNode, * qNodePrt;
typedef struct{
	qNode* front, * rear;
}Queue;


typedef struct _sqStack {
	ElemType1 data[MAXSIZE];
	int top; //栈顶指针 base = 0 
}sqStack;


int IsEmpty(Queue* q) {
	return q->front == NULL;
}
void InitQueue(Queue* q) {
	q->front = q->rear = NULL;
}
void EnQueue(Queue* Q, ElemType1 e) {
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
void DeQueue(Queue* q, ElemType1* e) {
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

#endif // !_LINKQUEUE_H