#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"queue.h"

/*
通过遍历哈夫曼树，生成每个字符的哈夫曼编码，存储在编码表中。
*/
hlTable* buildTable(htTree* huffmanTree) {
	hlTable* table = (hlTable*)malloc(sizeof(hlTable));
	if (!table) exit(0);
	table->first = table->last = NULL;
	
	char code[MAX_SZ];
	int k = 0;//编码最后一个数位置/当前编码长度
	traverseTree(huffmanTree->root, &table, k, code);
	return table;
}


/*
通过迭代遍历哈夫曼树，生成每个字符的哈夫曼编码，并将编码存储在编码表中。
参数：
- treeNode: 当前遍历的节点指针
- table: 指向哈夫曼编码表指针的指针，用于存储生成的编码
- k: 编码最后一个数位置/当前编码长度
- code: 当前编码的字符串数组
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
		// 如果当前节点为叶子节点，则将当前编码存储在编码表中
		code[k] = '\0';
		hlNode* aux = (hlNode*)malloc(sizeof(hlNode));
		aux->code=(char*)malloc(sizeof(char) * (strlen(code) + 1));
		if (!aux || !aux->code) exit(0);

		strcpy(aux->code,code);
		aux->symbol = treeNode->symbol;
		aux->next = NULL;
		// 将新节点加入到编码表中
		if ((*table)->first == NULL) { // 编码表为空
			(*table)->first = aux;
			(*table)->last = aux;
		}
		else {
			(*table)->last->next = aux;
			(*table)->last = aux;
		}
	}
}


/*匹配输出编码*/
void encode(hlTable* table, char* stringToEncode) {
	hlNode* traversal;
	
	printf("\nEncoding......\nInput string:\n%s\n", stringToEncode);
	printf("Encoded string:\n");

	for (int i = 0; stringToEncode[i] != '\0'; i++) {
		traversal = table->first;
		while (traversal != NULL && traversal->symbol != stringToEncode[i]) {
			traversal = traversal->next;
		}
		if (traversal != NULL) { // 如果找到了字符对应的编码
			printf("%s", traversal->code); // 输出当前字符的编码
		}
		else { // 如果在编码表中找不到字符
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