#ifndef QUEUE_H
#define	QUEUE_H
#define MAXSIZE	10
#include <stdbool.h>
typedef int ElemType;

//������
typedef struct QNode {
	ElemType data;
	struct QNode* next;
}QNode,* QueuePrt;//����Ԫ�ؼ���ָ��
typedef struct {
	QueuePrt front, rear;
}LinkQueue;//����
//��ͷ��������Ԫ��
void initQueue(LinkQueue* q);
void insertQueue(LinkQueue* q, ElemType e);
void deleteQueue(LinkQueue* q, ElemType* e);//��
void deleteQueue1(LinkQueue* q, ElemType* e);//����
void destroyQueue(LinkQueue* q);//��
void destroyQueue1(LinkQueue* q);//����
bool QueueIsEmpty(LinkQueue* q) {
	return q->front == NULL;
}

//ѭ�����У����е�˳��洢�ṹ
typedef struct {
	ElemType* base;//����ַ(�ڴ����)��Ҳ��������
	int front, rear;
}CycleQueue;
//��βΪ���һ��Ԫ�غ�һ��λ��
void init_queue(CycleQueue* q);
void insert_queue(CycleQueue* q, ElemType e);
void delete_queue(CycleQueue* q, ElemType* e);
void destroy_queue(CycleQueue* q);
#endif