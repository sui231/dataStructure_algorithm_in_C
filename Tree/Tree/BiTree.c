#include<stdio.h>
#include<stdlib.h>
#include"BiTree.h"

void CreateBiTree(BiTree* T) {	//BiNode**
	char c;
	scanf("%c", &c);//需一次性输入完，避免换行符

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


//前序遍历：根->左->右
void PreOrderTraverse(BiTree T, int level) {	//level
	if (T != NULL) {
		visit(T->data, level);					//1
		PreOrderTraverse(T->lchild, level + 1);	//2
		PreOrderTraverse(T->rchild, level + 1);	//3
		//中序：左->根->右	213
		//后序：左->右->根	231
		//层序
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
