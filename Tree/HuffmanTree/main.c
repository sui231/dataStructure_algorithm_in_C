#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

char* getStr(void) {
	char str[10000];
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';//�Ƴ�ĩβ���з�
	//if (strlen(str) > 0 && str[strlen(str) - 1] == '\n')
	//	str[strlen(str) - 1] = '\0';
	return str;
}

int main(void) {

	printf("Input the initial string to build the tree.\n");
	//������
	htTree* codeTree = buildTree(getStr());
	//������
	hlTable* codeTable = buildTable(codeTree);

	printf("\nInput the string to be encoded.\n");
	encode(codeTable, getStr());

	printf("\nInput the string to be decoded.\n");
	decode(codeTree, getStr());

	return 0;
}

