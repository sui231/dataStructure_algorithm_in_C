#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"queue.h"

/*
ͨ��������������������ÿ���ַ��Ĺ��������룬�洢�ڱ�����С�
*/
hlTable* buildTable(htTree* huffmanTree) {
	hlTable* table = (hlTable*)malloc(sizeof(hlTable));
	if (!table) exit(0);
	table->first = table->last = NULL;
	
	char code[MAX_SZ];
	int k = 0;//�������һ����λ��/��ǰ���볤��
	traverseTree(huffmanTree->root, &table, k, code);
	return table;
}


/*
ͨ������������������������ÿ���ַ��Ĺ��������룬��������洢�ڱ�����С�
������
- treeNode: ��ǰ�����Ľڵ�ָ��
- table: ָ������������ָ���ָ�룬���ڴ洢���ɵı���
- k: �������һ����λ��/��ǰ���볤��
- code: ��ǰ������ַ�������
*/
void traverseTree(htNode* treeNode, hlTable** table, int k, char* code){
	if (treeNode->left != NULL) {
		code[k] = '0';
		traverseTree(treeNode->left, table, k + 1, code);
	}
	if (treeNode->right != NULL) {
		code[k] = '1';
		traverseTree(treeNode->right, table, k + 1, code);
	}
	if (treeNode->left == NULL && treeNode->right == NULL) {
		// �����ǰ�ڵ�ΪҶ�ӽڵ㣬�򽫵�ǰ����洢�ڱ������
		code[k] = '\0';
		hlNode* aux = (hlNode*)malloc(sizeof(hlNode));
		aux->code=(char*)malloc(sizeof(char) * (strlen(code) + 1));
		if (!aux || !aux->code) exit(0);

		strcpy(aux->code,code);
		aux->symbol = treeNode->symbol;
		aux->next = NULL;
		// ���½ڵ���뵽�������
		if ((*table)->first == NULL) { // �����Ϊ��
			(*table)->first = aux;
			(*table)->last = aux;
		}
		else {
			(*table)->last->next = aux;
			(*table)->last = aux;
		}
	}
}


/*ƥ���������*/
void encode(hlTable* table, char* stringToEncode) {
	hlNode* traversal;
	
	printf("\nEncoding......\nInput string:\n%s\n", stringToEncode);
	printf("Encoded string:\n");

	for (int i = 0; stringToEncode[i] != '\0'; i++) {
		traversal = table->first;
		while (traversal != NULL && traversal->symbol != stringToEncode[i]) {
			traversal = traversal->next;
		}
		if (traversal != NULL) { // ����ҵ����ַ���Ӧ�ı���
			printf("%s", traversal->code); // �����ǰ�ַ��ı���
		}
		else { // ����ڱ�������Ҳ����ַ�
			printf("[Not Found]");
		}
	}
	printf("\n\n");
}


void decode(htTree* tree, char* stringToDecode) {
	htNode* traversal = tree->root;

	printf("\nDecoding......\nInput string:\n%s\nDecoded string:\n", stringToDecode);
	
	for (int i = 0; stringToDecode[i] != '\0'; i++) {
		if (stringToDecode[i] == '0') {
			traversal = traversal->left;
		}
		if (stringToDecode[i] == '1') {
			traversal = traversal->right;
		}
		if (traversal->left == NULL || traversal->right == NULL) {
			printf("%c", traversal->symbol);
			traversal = tree->root;
		}
		if (stringToDecode[i] != '0' && stringToDecode[i] != '1') {
			printf("\nThe inputed string is not coded correctly.");
			return;
		}
	}
	if (traversal != tree->root) {
		printf("\nThe input string is not encoded correctly or the tree is not correctly built.\n");
	}
	else {  
		printf("\nDecoding completed successfully.\n");
	}
}