#ifndef _QUEUE_H
#define _QUEUE_H

#include"huffman.h"

//��ʽ���У��ö���Ϊ���ȶ��У�ͨ�����ȼ���ȷ��Ԫ�ص�˳��
typedef struct _pQueueNode {
	struct _pQueueNode* next;
	TYPE val;				//���ڵ�ָ�루�����������ָ�룩
	unsigned int priority;	//Ƶ��
}pQueueNode;//�ڵ�

typedef struct _pQueue {
	unsigned int size;
	pQueueNode* first;
}pQueue;//����


//����
htTree* buildTree(char* inputString);

void initQueue(pQueue** queue);
void addpQueue(pQueue** queue, TYPE val, unsigned int priority);
TYPE getPQueue(pQueue** queue);

hlTable* buildTable(htTree* huffmanTree);
void traverseTree(htNode* treeNode, hlTable** table, int k, char* code);
void encode(hlTable* table, char* stringToEncode);
void decode(htTree* tree, char* stringToDecode);
#endif