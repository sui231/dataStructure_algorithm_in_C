#ifndef _OTHERS
#define _OTHERS
#include"Graph.h"
#define MAXSIZE MAX_VERTEX_NUM

typedef int QueueType;

typedef struct _queue {
	QueueType data;
	struct _queue* next;
}qNode, * qNodePrt;
typedef struct {
	qNode* front, * rear;
}Queue;

typedef struct _sqStack {
	QueueType data[MAXSIZE];
	int top; //’ª∂•÷∏’Î base = 0 
}sqStack;

int IsEmpty(Queue q);
void InitQueue(Queue* q);
void EnQueue(Queue* Q, QueueType e);
QueueType DeQueue(Queue* q);
int LocateVex(VertexType* pVex, VertexType vex, int vexNum);
#endif