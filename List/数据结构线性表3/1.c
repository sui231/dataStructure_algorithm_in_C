#include<stdio.h>
#include<stdlib.h>
#define NUM 41
#define GAP 3

typedef int Status;
typedef struct CLinkList {
	int num;
	struct CLinkList* next;
}node;

Status CreateList(node** pNode);
Status Traverse(node* pNode);
Status Kill(node** pNode);


int main(void) {
	node* pNode;

	if (CreateList(&pNode) == -1)
		exit(EXIT_FAILURE);
	Kill(&pNode);
	Traverse(pNode);

	return 0;
}



Status CreateList(node** pNode)
{
	node* current;
	node* prev;

	int i;

	*pNode = (node*)malloc(sizeof(node));
	if (!(*pNode))
		return -1;

	(*pNode)->num = 1;
	(*pNode)->next = NULL;

	prev = *pNode;
	for (i = 2; i <= NUM; i++) {
		current = (node*)malloc(sizeof(node));
		if (!current)
			return -1;

		current->num = i;
		current->next = NULL;

		prev->next = current;
		prev = current;
	};
	current->next = *pNode;
	return 1;
}


Status Traverse(node* pNode) {
	node* target = pNode;
	int loop_completed = 0;

	while (!loop_completed) {
		printf("%d\n", target->num);
		target = target->next;

		if (target == pNode) {
			loop_completed = 1;
		}
	}
	return 1;
}

Status Kill(node** pNode) {
	int i = 1; // 从1开始计数，因为我们要从第二个节点开始删除
	node* target = *pNode;
	node* temp;
	int length = NUM;
	while (length >= GAP ) { // 只删除多余的节点，直到链表中只剩下2个节点为止
		i++;
		if (i % GAP == 0) {
			temp = target->next;
			target->next = temp->next;
			free(temp);
			length--;
		}
		else {
			target = target->next;
		}
	}
	*pNode = target; // 将头节点指向当前节点，保留最后两个节点
	return 1;
}