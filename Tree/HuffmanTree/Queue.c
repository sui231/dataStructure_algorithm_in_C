#include<stdio.h>
#include<stdlib.h>
#include"queue.h"


/*��������ʼ������*/
void initQueue(pQueue** queue) {
	(*queue) = (pQueue*)malloc(sizeof(pQueue));
	if (!*(queue)) exit(0);
	(*queue)->first = NULL;
	(*queue)->size = 0;
}



/*
��ϲ����½ڵ�
- queue		���ж���ָ��
- val			����ڵ�ָ��
- priority	�ڵ��ӦƵ��
*/
void addpQueue(pQueue** queue, TYPE val, unsigned int priority) {
	if ((*queue)->size == MAX_SZ) {	//������
		printf("\nQueue is full.\n");
		return;
	}

	pQueueNode* aux = (pQueueNode*)malloc(sizeof(pQueueNode));//���нڵ�
	if (!aux) exit(0);
	aux->priority = priority;
	aux->val = val;
	if ((*queue)->size == 0 || (*queue)->first == NULL) {	//����Ϊ�մ���
		aux->next = NULL;
		(*queue)->first = aux;
		(*queue)->size = 1;
		return;
	}
	else {
		pQueueNode* iterator = (*queue)->first;//������ʶ��нڵ㣬Ƶ��С�ķ���ͷ������ͷ����ʼ����
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

/*��ȡ����ͷ�ڵ㼴��С�ڵ�*/
TYPE getPQueue(pQueue** queue) {
	TYPE returnValue = NULL;

	if ((*queue)->size > 0) {
		pQueueNode* temp = (*queue)->first;
		returnValue = (*queue)->first->val;
		(*queue)->first = (*queue)->first->next;
		
		free(temp); // �ͷ�ȡ���Ľڵ��ڴ棨���������ڵ㲻�ᱻ�ͷţ�������ڶ��е�ָ��ᣩ
		(*queue)->size--;
	}
	else {
		printf("\nQueue is empty.\n");
	}
	return returnValue;
}