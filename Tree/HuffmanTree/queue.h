#ifndef _QUEUE_H
#define _QUEUE_H

#include"huffman.h"

//链式队列，该队列为优先队列，通过优先级来确定元素的顺序
typedef struct _pQueueNode {
	struct _pQueueNode* next;
	TYPE val;				//树节点指针（区别队列自身指针）
	unsigned int priority;	//频率
}pQueueNode;//节点

typedef struct _pQueue {
	unsigned int size;
	pQueueNode* first;
}pQueue;//队列


//函数
htTree* buildTree(char* inputString);

void initQueue(pQueue** queue);
void addpQueue(pQueue** queue, TYPE val, unsigned int priority);
TYPE getPQueue(pQueue** queue);

hlTable* buildTable(htTree* huffmanTree);
void traverseTree(htNode* treeNode, hlTable** table, int k, char* code);
void encode(hlTable* table, char* stringToEncode);
void decode(htTree* tree, char* stringToDecode);
#endif