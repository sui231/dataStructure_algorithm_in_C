#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

//void deleteQueue(LinkQueue* q, ElemType* e) {
//    QueuePrt temp;
//
//    if (q->front == q->rear)
//        return;
//
//    *e = q->front->data;
//    temp = q->front; // �����ͷ�ڵ��ָ��  
//    q->front = q->front->next;
//
//    if (q->rear == temp)
//        q->rear = q->front;  // ˫�ؼ��
//
//    free(temp);  
//}// ��ͷ����ֵ
//void deleteQueue1(LinkQueue* q, ElemType* e) {
//	QueuePrt p;
//
//	if (q->front == q->rear)
//		return;
//
//	p = q->front->next;
//	*e = p->data;
//
//	q->front->next = p->next;
//	if (q->rear == p)
//		q->rear = q->front;//Ψһ��Ԫ�ر�ɾ��
//	free(p);
//}//��ͷ������ֵ�����



void delete_queue(CycleQueue* q, ElemType* e) {

	if (q->front == q->rear)
		return;
	*e = q->base[q->front];
	q->front = (q->front + 1) % MAXSIZE;
}