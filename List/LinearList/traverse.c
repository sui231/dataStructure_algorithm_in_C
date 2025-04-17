/*遍历*/

#include<stdio.h>
#include<stdlib.h>
#include"List.h"

void SL_traverse(SqList* SL) {
	int i;
	
	for (i = 1; i <= SL->length; i++)
		printf("%d\t", SL->data[i]);
}

void LL_CLL_traverse(node* pNode) {
	node* current;
	
	for (current = pNode->next; current->next != pNode && current->next != NULL; current = current->next)
		printf("%d  -->  ", current->data);
	if(current->next == NULL)
		printf("%d", current->data);
	if (current->next == pNode)
		printf("%d  -->  ...(loop)", current->data);//循环链表的最后一项
	return;
}

void SLL_traverse(struct StaticLinkList* L) {
	int i;
	for (i = 1; L[i].cur != 0; i++)
		printf("%d\t", L[i].data);
	printf("%d\t", L[i].data);
	return;
}

