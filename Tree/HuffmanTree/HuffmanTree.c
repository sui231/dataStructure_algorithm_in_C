#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
	int weight;
	int parent;
	int lchild;
	int rchild;
}TreeNode;

typedef struct HFTree {
	TreeNode* data;//视为数组
	int length;
}HFTree;



HFTree* initTree(int* weight, int length) {
	HFTree* T = (HFTree*)malloc(sizeof(HFTree));
	T->data = (TreeNode*)malloc(sizeof(TreeNode) * (2 * length - 1));
	if (!T || !T->data)
		exit(0);
	T->length = length;
	for (int i = 0; i < length; i++) {
		T->data[i].weight = weight[i];
		T->data[i].parent = 0;
		T->data[i].lchild = T->data[i].rchild = -1;
	}
	return T;
}

int* selectMin(HFTree* T) {
	int min = 10000;
	int secondMin = 10000;
	int minIndex = -1, secondIndex = -1;
	int i;
	for (i = 0; i < T->length; i++) {
		if (T->data[i].parent == 0) {
			if (T->data[i].weight < min) {
				min = T->data[i].weight;
				minIndex = i;
			}
		}
	}
	for (i = 0; i < T->length; i++) {
		if (T->data[i].parent == 0 && i != minIndex) {
			if (T->data[i].weight < secondMin) {
				secondMin = T->data[i].weight;
				secondIndex = i;
			}
		}
	}
	int* res = (int*)malloc(sizeof(int) * 2);
	if (!res)
		exit(0);
	res[0] = minIndex;
	res[1] = secondIndex;
	return res;
}

void createHFTree(HFTree* T) {
	int* res;
	int min, secondMin;
	int length = T->length * 2 - 1;
	for (int i = T->length; i < length; i++) {
		res = selectMin(T);
		min = res[0];
		secondMin = res[1];
		T->data[i].weight = T->data[min].weight + T->data[secondMin].weight;
		T->data[i].lchild = min;
		T->data[i].rchild = secondMin;
		T->data[i].parent = 0;
		T->data[min].parent = i;
		T->data[secondMin].parent = i;
		T->length++;
	}
}

void visit(int weight) {
	printf("%d\t", weight);
}

void preOrder(HFTree* T, int index) {
	if (index != -1) {
		visit(T->data[index].weight);
		preOrder(T, T->data[index].lchild);
		preOrder(T, T->data[index].rchild);
	}
}

//int main(void) {
//	int weight[4] = { 1,2,3,4 };
//	HFTree* T = initTree(weight, 4);
//	createHFTree(T);
//	preOrder(T, T->length-1);
//	return 0;	
//}