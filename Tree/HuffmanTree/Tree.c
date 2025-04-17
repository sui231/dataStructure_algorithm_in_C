#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

/*
统计输入字符串中每个字符的频率，并将非零频率的字符创建为叶子节点，加入优先队列。
通过循环，从优先队列中取出两个优先级最低的节点，合并成一个新的节点，再次加入队列。
重复上述步骤，直到队列中只剩下一个节点，这个节点即为哈夫曼树的根节点。

参数：		inputString: 输入的字符串，用于计算字符的频率
返回值：	返回构建好的哈夫曼树的指针
*/
htTree* buildTree(char* inputString) {
	
	//利用数组统计字符出现的频率	
	int* probability = (int*)malloc(sizeof(int) * MAX_SZ);
	if (!probability) exit(0);
	for (int i = 0; i < MAX_SZ; i++) {
		probability[i] = 0;
	}//初始化	
	for (int j = 0; inputString[j] != '\0'; j++) {	// '\n'为结束标志
		probability[(unsigned char)inputString[j]]++;//unsigned char一个字节大小，其最高位（符号位）被用来表示数值，unsigned char取值是0到255
	}// 统计字符	(unsigned char)inputString[j]为字符ASCII码


	//创建huffman树节点，所有节点和频率添加到队列
	pQueue* huffmanQueue;//队列
	initQueue(&huffmanQueue);
	for (int k = 0; k < MAX_SZ; k++) {
		if (probability[k] != 0) {
			TYPE aux = (htNode*)malloc(sizeof(htNode));//树节点
			if (!aux) exit(0);

			aux->left = NULL;
			aux->right = NULL;
			aux->symbol = (char)k;

			addpQueue(&huffmanQueue, aux, probability[k]);
		}
	}
	free(probability);


	//从队列中取出两个优先级最低的节点，合并成一个新的节点，再次加入队列
	while (huffmanQueue->size != 1) {
		int priority = huffmanQueue->first->priority;//新节点频率
		priority += huffmanQueue->first->next->priority;

		htNode* left = getPQueue(&huffmanQueue);
		htNode* right = getPQueue(&huffmanQueue);
		htNode* newNode = (htNode*)malloc(sizeof(htNode));//新节点
		if (!newNode) exit(0);
		newNode->left = left;
		newNode->right = right;
		newNode->symbol = '*';

		addpQueue(&huffmanQueue, newNode, priority);
	}
	htTree* tree = (htTree*)malloc(sizeof(htTree));
	if (!tree) exit(0);
	tree->root = getPQueue(&huffmanQueue);//完成树的创建
	return tree;
}