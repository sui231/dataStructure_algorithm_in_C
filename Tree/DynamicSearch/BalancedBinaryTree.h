#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EQ(a, b) ((a) == (b))
#define LT(a, b) ((a) < (b))
#define LQ(a, b) ((a) <= (b))
#define GT(a, b) ((a) > (b))
#define GQ(a, b) ((a) >= (b))

#define SEQ(a, b) (!strcmp(a,b))
#define SLT(a, b) (strcmp(a,b) < 0)
#define SLQ(a, b) (strcmp(a,b) <= 0)
#define SGT(a, b) (strcmp(a,b) > 0)
#define SGQ(a, b) (strcmp(a,b) >= 0)

#define LH 1	// ������
#define EH 0	// �ȸ�
#define RH -1	// �Ҹ�
#define TRUE 1
#define OK 1
#define ERROR 0
#define FALSE 0

typedef int KeyType;
typedef char InfolType;
typedef int Status;
typedef struct {
	KeyType key;
	InfolType infol;
}ElemType;

typedef struct BSTNode {
	ElemType data;
	int bf;			// �ڵ�ƽ�����ӣ��������߶�-�������߶ȣ�
	struct BSTNode* lchild, * rchild;
} BSTNode, * BSTree;
