#ifndef BITHRTREE_H
#define BITHRTREE_H

typedef char ElemType;

//线索存储标志位
//0	左右child指针
//1	前驱后继线索
typedef enum { Link, Thread }PointerTag;

typedef struct BiThrNode {
	ElemType data;
	struct BiThrNode* lchild, * rchild;
	PointerTag ltag;
	PointerTag rtag;
}BiThrNode, * BiThrTree;

BiThrTree pre;//全局变量

void CreateBiThrTree(BiThrTree* T);
void InThreading(BiThrTree T);
void InOrderThreading(BiThrTree* T, BiThrTree* head);
void visit(ElemType e);
void InOrderTraverse(BiThrTree Head);

#endif