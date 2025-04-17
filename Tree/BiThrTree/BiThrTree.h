#ifndef BITHRTREE_H
#define BITHRTREE_H

typedef char ElemType;

//�����洢��־λ
//0	����childָ��
//1	ǰ���������
typedef enum { Link, Thread }PointerTag;

typedef struct BiThrNode {
	ElemType data;
	struct BiThrNode* lchild, * rchild;
	PointerTag ltag;
	PointerTag rtag;
}BiThrNode, * BiThrTree;

BiThrTree pre;//ȫ�ֱ���

void CreateBiThrTree(BiThrTree* T);
void InThreading(BiThrTree T);
void InOrderThreading(BiThrTree* T, BiThrTree* head);
void visit(ElemType e);
void InOrderTraverse(BiThrTree Head);

#endif