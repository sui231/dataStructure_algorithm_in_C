/*����ʵ��*/

#include<stdio.h>
#include<stdlib.h>
#include"List.h"

int main(void) {

	node* pNode;
	struct StaticLinkList* L;
	int	n=5;//dataԪ����

	pNode = CirLL_create(n);
	LL_insert(&pNode, 3, 999);
	LL_traverse(pNode);
	return 0;
}