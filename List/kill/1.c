/*
约瑟夫环问题，即有NUM个人围成一圈，从第一个人开始报数，报到 3 的人出列，然后从出列的下一个人重新开始报数，直到所有人都出列。
*/
#include<stdio.h>
#include<stdlib.h>
#define NUM 41

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

//Status Kill(node** pNode) {
//	int loop = 0, i = 2;
//	node* target = *pNode;
//	node* temp = NULL;
//	while (!loop) {
//		target = target->next;
//		i++;
//		if (i%3 == 0) {
//			temp = target->next;
//			target->next = temp->next;
//			free(temp);
//			i++;
//		}	
//		if (target == pNode) {
//			loop = 1;
//		}
//	}
//	return 1;
//}
int Length(node* pNode) {
	int length = 1;
	node* target;
	for (target = pNode; target->next != target; target = target->next)
		length++;
	return length;
}

Status Kill(node** pNode) {
	int i = 1; // 从1开始计数，因为我们要从第二个节点开始删除
	node* target = *pNode;
	node* temp;
	int length = Length(*pNode);
	while (length >= 3) {
		i++;
		length--;
		if (i % 3 == 0) {
			temp = target->next;
			target->next = temp->next;
			free(temp);
		}
		else {
			target = target->next;
		}
	}

	// 处理最后一个节点
	temp = target->next;
	target->next = temp->next;
	free(temp);

	*pNode = target->next; // 更新头节点
	return 1;
}

