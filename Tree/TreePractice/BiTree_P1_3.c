#include"BiTree.h"
/* 3.已知前序序列和中序序列，构造二叉树 */
/*
[L1,L2]		先序遍历左/右子树区间
[L2,R2]		后序遍历左/右子树区间
*/
void CreateTree1(BiTree* T, char* PreStr, char* InStr, int L1, int R1, int L2, int R2) {
	// 创建新的结点
	(*T) = (BiTree*)malloc(sizeof(BiTree));
	(*T)->data = PreStr[L1];

	// 据先序第一个元素为根结点元素，根寻找中序序列中的根结点位置
	int root;
	for (root = 0; root <= R2; root++) {
		if (PreStr[L1] == InStr[root]) {
			printf("先序序列根节点(%c)在中序的位置 = %d\n", PreStr[L1], root);
			break;
		}
	}

	// 划分两个区间，先序序列左子树区间 和 中序序列左子树区间，递归构建左子树
	if (root - L2 != 0) {	
		print1(L1, root, L2, PreStr, InStr);
		CreateTree1(&(*T)->left, PreStr, InStr, L1 + 1, L1 + (root - L2), L2, root - 1);
	}
	else {
		(*T)->left = NULL;
	}

	if (R2 - root != 0) {	
		print2(L1, root, L2, R1, R2, PreStr, InStr);
		CreateTree1(&(*T)->right, PreStr, InStr, R1 - (R2 - root) + 1, R1, root + 1, R2);
	}
	else {
		(*T)->right = NULL;
	}
}

void print2(int L1, int root, int L2, int R1, int R2, char* PreStr, char* InStr)
{
	int i, j;
	printf("\t划分先序序列的右子树区间：[%d, %d] = > ", L1 + 1, L1 + (root - L2));
	for (i = R1 - (R2 - root) + 1; i <= R1; i++) { printf("%c ", PreStr[i]); }
	printf("\n");
	printf("\t划分中序序列的右子树区间：[%d, %d] = > ", L2, root - 1);
	for (i = root + 1; i <= R2; i++) { printf("%c ", InStr[i]); }
	printf("\n");
}

void print1(int L1, int root, int L2, char* PreStr, char* InStr)
{
	int i, j;
	printf("\t划分先序序列的左子树区间：[%d, %d] = > ", L1 + 1, L1 + (root - L2));
	for (i = L1 + 1; i <= L1 + (root - L2); i++) { printf("%c ", PreStr[i]); }
	printf("\n");
	printf("\t划分中序序列的左子树区间：[%d, %d] = > ", L2, root - 1);
	for (i = L2; i <= root - 1; i++) { printf("%c ", InStr[i]); }
	printf("\n");
}



//int main(void) {
//	char PreStr[] = "ABDCEFG";
//	char InStr[] = "DBACFEG";
//
//	int len1 = strlen(PreStr);
//	int len2 = strlen(InStr);
//
//	BiTree T;
//	CreateTree1(&T, PreStr, InStr, 0, len1 - 1, 0, len2 - 1);
//	PreBiTreeTraverse(T, 1);
//	printf("\n\n\n");
//
//	printf("%d", Depth(T));
//	return 0;
//}