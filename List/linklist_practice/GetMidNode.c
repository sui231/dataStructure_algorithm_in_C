#include<stdio.h>
#include<stdlib.h>
#include"practice.h"

int main(void) {


	return 0;
}

node* GetMidNode1(node* L) {
	node* p1, * p2;
	p1 = L;
	p2 = L;
	while (p1->next != NULL || p1->next != NULL) {
		p1 = p1->next->next;
		p2 = p2->next;
	}
	if (p1->next->next == NULL)
		p2 = p2->next;

	return p2;
}

