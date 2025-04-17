#ifndef BITREE_H
#define BITREE_H
typedef char ElemType;

//¶þ²æÁ´±í
typedef struct BiNode {
	ElemType data;
	struct BiNode* lchild;
	struct BiNode* rchild;
}BiNode, * BiTree;


void CreateBiTree(BiTree* T);
void PreOrderTraverse(BiTree T, int level);
void visit(ElemType data, int level);

#endif