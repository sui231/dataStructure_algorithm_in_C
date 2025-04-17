/*判断单链表中是否有环*/
/*LatinSquare*/

#include<stdio.h>
#include<stdlib.h>
#include"practice.h"

//int main(void) {
//	node* L;
//	int i;
//	int n = 5;
//	L = CirLL_create1(n);
//	for (i = 0; i < n - 1; i++) {
//		CLL_traverse(L);
//		L = LatinSquare(L);
//	}	
//	return 0;
//}

//1 2 3 4
//2 3 4 1
//3 4 1 2
//4 1 2 3
node* LatinSquare(node* L) {
	node* p;
	p = L;
	p = p->next;
	return p;
}

void CLL_traverse(node* L) {
	node* current;
	current = L;
	for (; current->next != L; current = current->next) 
		printf("%d ", current->data);
	printf("%d\n", current->data);
}

int IsRing2(node* L) {
	node* p1, * p2;//run/run after
	int i,j;
	p1 = L;
	p2 = L;

	i = 0;
	while (p1->next != 0) {
		p1 = p1->next;
		i++;
		for (j = 0; p2 == p1; j++) {
			p2 = L;
			p2 = p2->next;
			if (i != j) {
				return 1;
				printf("Located at %d", j);
			}
		}
	}
	return 0;
}

int IsRing1(node* L) {
	node* pfa, * psl;//fast/slowly
	int i;
	psl = L;
	pfa = L->next;
	while (pfa != psl) {
		pfa = pfa->next->next;
		psl = psl->next;
		if (pfa->next == NULL||pfa->next->next == NULL)
			return 0;
	}
	return 1;
}



node* LL_create(int n) {
	node* Head;
	node* current;
	node* prev;
	int i;
	srand(time(0));

	Head = (node*)malloc(sizeof(node));
	if (!Head)
		exit(EXIT_FAILURE);
	Head->data = 0;//头节点赋值为0
	Head->next = NULL;

	prev = Head;
	for (i = 1; i <= n; i++) {
		current = (node*)malloc(sizeof(node));
		if (!current)
			exit(EXIT_FAILURE);
		current->next = NULL;
		current->data = i;

		prev->next = current;//核心
		prev = current;
	}
	return Head;
}

node* CirLL_create(int n) {
	node* current;
	node* prev;
	node* Head;
	int i;
	current = (node*)malloc(sizeof(node));//智障编译器，必须加这行
	srand(time(0));

	Head = (node*)malloc(sizeof(node));
	if (!Head)
		exit(EXIT_FAILURE);
	Head->data = rand() % 100 + 1;
	Head->next = NULL;

	prev = Head;
	for (i = 1; i <= n; i++) {
		current = (node*)malloc(sizeof(node));
		if (!current)
			exit(EXIT_FAILURE);
		current->next = NULL;
		current->data = rand() % 100 + 1;

		prev->next = current;
		prev = current;
	}
	current->next = Head;

	return Head;
}

node* CirLL_create1(int n) {
	node* current;
	node* prev;
	node* Head;
	int i;
	current = (node*)malloc(sizeof(node));//智障编译器，必须加这行

	Head = (node*)malloc(sizeof(node));
	if (!Head)
		exit(EXIT_FAILURE);
	Head->data = 1;
	Head->next = NULL;

	prev = Head;
	for (i = 2; i <= n; i++) {
		current = (node*)malloc(sizeof(node));
		if (!current)
			exit(EXIT_FAILURE);
		current->next = NULL;
		current->data = i;

		prev->next = current;
		prev = current;
	}
	current->next = Head;

	return Head;
}