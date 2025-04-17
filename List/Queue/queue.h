#ifndef QUEUE_H
#define	QUEUE_H
#define MAXSIZE	10
#include <stdbool.h>
typedef int ElemType;

//链队列
typedef struct QNode {
	ElemType data;
	struct QNode* next;
}QNode,* QueuePrt;//单个元素及其指针
typedef struct {
	QueuePrt front, rear;
}LinkQueue;//描述
//对头（不）存元素
void initQueue(LinkQueue* q);
void insertQueue(LinkQueue* q, ElemType e);
void deleteQueue(LinkQueue* q, ElemType* e);//存
void deleteQueue1(LinkQueue* q, ElemType* e);//不存
void destroyQueue(LinkQueue* q);//存
void destroyQueue1(LinkQueue* q);//不存
bool QueueIsEmpty(LinkQueue* q) {
	return q->front == NULL;
}

//循环队列，队列的顺序存储结构
typedef struct {
	ElemType* base;//基地址(内存分配)，也可用数组
	int front, rear;
}CycleQueue;
//队尾为最后一个元素后一个位置
void init_queue(CycleQueue* q);
void insert_queue(CycleQueue* q, ElemType e);
void delete_queue(CycleQueue* q, ElemType* e);
void destroy_queue(CycleQueue* q);
#endif