#ifndef _LINKLIST_H
#define _LINKLIST_H

#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define MAXSIZE 1000

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char ElemType;
typedef struct _linklist {
	ElemType data;
	struct _linklist* next;
}LinkNode, * LinkList;



LinkList inversion(LinkList L);
LinkNode* getMid(LinkList L);
LinkNode* getCountBack(LinkList L, int k);
void deleteCountBack(LinkList* L, int k);
int ifRing1(LinkList L);
int ifRing2(LinkList L);
int ifIntersect(LinkList L1, LinkList L2);
void deleteRepeatNode(LinkList* L);
LinkList* combine1(LinkList* L1, LinkList* L2);
LinkList* combine2(LinkList* L1, LinkList* L2);


ElemType scanfElem(void) {
	ElemType elem;
	scanf("%c", &elem);
	while (elem == ' ')
		scanf("%c", &elem);
	return elem;
}

LinkList LL_create(void) {
	ElemType elem;
	LinkNode* L;
	LinkNode* tail,* target;

	L = (LinkNode*)malloc(sizeof(LinkNode));
	if (!L) exit(0);


	printf("Input the node ended with enter:\n");
	elem = scanfElem();
	L->data = elem;

	tail = L;
	elem = scanfElem();
	for (int i = 0; elem != '\n' && i <= MAXSIZE; i++) {
		target = (LinkNode*)malloc(sizeof(LinkNode));
		if (!target) exit(0);

		target->next = NULL;
		tail->next = target;

		target->data = elem;
		tail = target;

		elem = scanfElem();
	}
	return L;
}

LinkList CLL_create(void) {
	LinkList tail,L = LL_create();
	for (tail = L; tail->next != NULL; tail = tail->next)
		;
	tail->next = L;
	return L;
}

void LL_traverse(LinkList L) {
	LinkNode* p;
	if (L == NULL || L == L->next) {
		printf("Empety.\n");
		return;
	}
		for (p = L; p->next != NULL && p->next != L; p = p->next) {
		printf("%c --> ", p->data);
	}
	if (p->next == L)
		printf("%c --> ......(loop)");
	printf("%c", p->data);
}

int LL_length(LinkList L) {
	LinkNode* p = L;
	int len = 0;
	while (p != NULL && p->next != L) {
		p = p->next;
		len++;
	}
	return len;
}
#endif