#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

void destroyQueue(LinkQueue* q) {
    QueuePrt p, temp;
 
    while (q->front != NULL) { 
        p = q->front;
        q->front = q->front->next;  
        free(p);
        if (p == q->rear) {
            q->rear = NULL; // ����βָ����ΪNULL  
        }
    } 
    q->front = q->rear = NULL;
}//��ͷ��
void destroyQueue1(LinkQueue* q) {
	while (q->front) {
		q->front->next = q->rear;
		free(q->front);
		q->front = q->rear;
	}
}//��ͷ����



void destroy_queue(CycleQueue* q) {
    while(q->base)
        free(q->base);
    q->front = q->rear = 0;
}