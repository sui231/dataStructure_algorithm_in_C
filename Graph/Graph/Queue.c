#include"others.h"
int IsEmpty(Queue q) {
	return q.front == NULL;
}
void InitQueue(Queue* q) {
	q->front = q->rear = NULL;
}
void EnQueue(Queue* Q, QueueType e) {
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
QueueType DeQueue(Queue* q) {
	QueueType e;
	qNodePrt temp;

	if (!q->front)
		return;

	e = q->front->data;
	temp = q->front;

	if (q->front == q->rear) {
		q->rear = q->front = NULL;
	}
	else {
		q->front = q->front->next;
	}
	free(temp);

	return e;
}// 队头队尾存数值
