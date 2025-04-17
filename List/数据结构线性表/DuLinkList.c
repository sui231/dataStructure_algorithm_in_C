#include"List.h"
#include<stdio.h>
typedef struct DuLinkList {
	ElemType data;
	struct DuLinkList* next;
	struct DuLinList* prior;
}DualNode,* DuLinkList;

Status ListInit(DuLinkList* L,int n) {
	DuLinkList p, q;
	int i;

	q = *L;

	for (i = 1;i <= n; i++) {
		p = (DuLinkList)malloc(sizeof(DualNode));
		if (!p)
			return ERROR;
		q->prior= q;
		p->next = q->next->next;
		p->next = q;
		q->next = NULL;
		q = p;
	}
	q->next = *L;
	(*L)->prior = q;
	return OK;
}