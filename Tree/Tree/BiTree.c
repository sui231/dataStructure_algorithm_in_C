#include<stdio.h>
#include<stdlib.h>
#include"BiTree.h"

void CreateBiTree(BiTree* T) {	//BiNode**
	char c;
	scanf("%c", &c);//��һ���������꣬���⻻�з�

	if (' ' == c) {
		*T = NULL;
	}
	else {
		*T = (BiNode*)malloc(sizeof(BiNode));
		if (!(*T))
			exit(0);
		//root
		(*T)->data = c;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}


//ǰ���������->��->��
void PreOrderTraverse(BiTree T, int level) {	//level
	if (T != NULL) {
		visit(T->data, level);					//1
		PreOrderTraverse(T->lchild, level + 1);	//2
		PreOrderTraverse(T->rchild, level + 1);	//3
		//������->��->��	213
		//������->��->��	231
		//����
	}
}


void visit(ElemType data, int level) {
	printf("data:%c		level:%d\n", data, level);
}

int main(void) {
	int level = 0;
	BiTree T;
	printf("Input node in prface order.\n");
	CreateBiTree(&T);
	PreOrderTraverse(T, level);
}
