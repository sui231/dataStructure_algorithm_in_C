#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

//void insertQueue(LinkQueue* Q, ElemType e) {
//	QueuePrt p = (QueuePrt)malloc(sizeof(QNode));
//	if (!p)	exit(0);
//	p->data = e;
//	p->next = NULL;
//	if (Q->rear == NULL) {
//		Q->front = Q->rear = p;
//	}
//	else {
//		Q->rear->next = p;
//		Q->rear = p;
//	}
//}



void insert_queue(CycleQueue* q, ElemType e) {
	if ((q->rear + 1) % MAXSIZE >= 1)
		return;//¶ÓÁÐÂú
	q->base[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
}//Î²²»´æ