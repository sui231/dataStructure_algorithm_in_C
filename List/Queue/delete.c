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
//    temp = q->front; // 保存队头节点的指针  
//    q->front = q->front->next;
//
//    if (q->rear == temp)
//        q->rear = q->front;  // 双重检查
//
//    free(temp);  
//}// 队头存数值
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
//		q->rear = q->front;//唯一个元素被删除
//	free(p);
//}//队头不存数值，别深究



void delete_queue(CycleQueue* q, ElemType* e) {

	if (q->front == q->rear)
		return;
	*e = q->base[q->front];
	q->front = (q->front + 1) % MAXSIZE;
}