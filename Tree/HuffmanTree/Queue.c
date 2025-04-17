#include<stdio.h>
#include<stdlib.h>
#include"queue.h"


/*创建并初始化队列*/
void initQueue(pQueue** queue) {
	(*queue) = (pQueue*)malloc(sizeof(pQueue));
	if (!*(queue)) exit(0);
	(*queue)->first = NULL;
	(*queue)->size = 0;
}



/*
存合并的新节点
- queue		队列二级指针
- val			传入节点指针
- priority	节点对应频率
*/
void addpQueue(pQueue** queue, TYPE val, unsigned int priority) {
	if ((*queue)->size == MAX_SZ) {	//队列满
		printf("\nQueue is full.\n");
		return;
	}

	pQueueNode* aux = (pQueueNode*)malloc(sizeof(pQueueNode));//队列节点
	if (!aux) exit(0);
	aux->priority = priority;
	aux->val = val;
	if ((*queue)->size == 0 || (*queue)->first == NULL) {	//队列为空传入
		aux->next = NULL;
		(*queue)->first = aux;
		(*queue)->size = 1;
		return;
	}
	else {
		pQueueNode* iterator = (*queue)->first;//逐个访问队列节点，频率小的放在头部，从头部开始遍历
		if ((*queue)->size == 1 && priority < iterator->priority) {
			aux->next = (*queue)->first->next;
			(*queue)->first = aux;
			(*queue)->size++;
			return;
		}
		while (iterator->next != NULL && priority > iterator->next->priority)
			iterator = iterator->next;
		aux->next = iterator->next;
		iterator->next = aux;
		(*queue)->size++;
	}
}

/*获取队列头节点即最小节点*/
TYPE getPQueue(pQueue** queue) {
	TYPE returnValue = NULL;

	if ((*queue)->size > 0) {
		pQueueNode* temp = (*queue)->first;
		returnValue = (*queue)->first->val;
		(*queue)->first = (*queue)->first->next;
		
		free(temp); // 释放取出的节点内存（队列内树节点不会被释放，但其存在队列的指针会）
		(*queue)->size--;
	}
	else {
		printf("\nQueue is empty.\n");
	}
	return returnValue;
}