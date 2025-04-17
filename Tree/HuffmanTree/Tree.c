#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

/*
ͳ�������ַ�����ÿ���ַ���Ƶ�ʣ���������Ƶ�ʵ��ַ�����ΪҶ�ӽڵ㣬�������ȶ��С�
ͨ��ѭ���������ȶ�����ȡ���������ȼ���͵Ľڵ㣬�ϲ���һ���µĽڵ㣬�ٴμ�����С�
�ظ��������裬ֱ��������ֻʣ��һ���ڵ㣬����ڵ㼴Ϊ���������ĸ��ڵ㡣

������		inputString: ������ַ��������ڼ����ַ���Ƶ��
����ֵ��	���ع����õĹ���������ָ��
*/
htTree* buildTree(char* inputString) {
	
	//��������ͳ���ַ����ֵ�Ƶ��	
	int* probability = (int*)malloc(sizeof(int) * MAX_SZ);
	if (!probability) exit(0);
	for (int i = 0; i < MAX_SZ; i++) {
		probability[i] = 0;
	}//��ʼ��	
	for (int j = 0; inputString[j] != '\0'; j++) {	// '\n'Ϊ������־
		probability[(unsigned char)inputString[j]]++;//unsigned charһ���ֽڴ�С�������λ������λ����������ʾ��ֵ��unsigned charȡֵ��0��255
	}// ͳ���ַ�	(unsigned char)inputString[j]Ϊ�ַ�ASCII��


	//����huffman���ڵ㣬���нڵ��Ƶ����ӵ�����
	pQueue* huffmanQueue;//����
	initQueue(&huffmanQueue);
	for (int k = 0; k < MAX_SZ; k++) {
		if (probability[k] != 0) {
			TYPE aux = (htNode*)malloc(sizeof(htNode));//���ڵ�
			if (!aux) exit(0);

			aux->left = NULL;
			aux->right = NULL;
			aux->symbol = (char)k;

			addpQueue(&huffmanQueue, aux, probability[k]);
		}
	}
	free(probability);


	//�Ӷ�����ȡ���������ȼ���͵Ľڵ㣬�ϲ���һ���µĽڵ㣬�ٴμ������
	while (huffmanQueue->size != 1) {
		int priority = huffmanQueue->first->priority;//�½ڵ�Ƶ��
		priority += huffmanQueue->first->next->priority;

		htNode* left = getPQueue(&huffmanQueue);
		htNode* right = getPQueue(&huffmanQueue);
		htNode* newNode = (htNode*)malloc(sizeof(htNode));//�½ڵ�
		if (!newNode) exit(0);
		newNode->left = left;
		newNode->right = right;
		newNode->symbol = '*';

		addpQueue(&huffmanQueue, newNode, priority);
	}
	htTree* tree = (htTree*)malloc(sizeof(htTree));
	if (!tree) exit(0);
	tree->root = getPQueue(&huffmanQueue);//������Ĵ���
	return tree;
}