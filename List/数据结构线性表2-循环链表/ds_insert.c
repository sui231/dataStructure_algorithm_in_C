/*插入节点*/

#include"CirLL.h"
#include<stdio.h>
#include<stdlib.h>

//i为位置
void ds_insert(node** pNode, int i) {
	node* temp;//temp为插入节点
	node* target;//找位置用
	node* p;//p为中间变量，可不用
	int item, j;

	int input_valid;
	do {
		printf("Input a new node.\n");
		input_valid = read_int_from_input(&item);
		if (!input_valid) {
			printf("Invalid input. Please try again.\n");
		}
	} while (!input_valid);
	//printf("Input a node.\n");
	//scanf("%d", &item);
	//fflush(stdin);


	temp = (node*)malloc(sizeof(node));
	if (temp) {
		temp->data = item;
	}
	else {
		exit(EXIT_FAILURE);
	}//应该先分配内存，初始化temp


	if (i == 1) {	//插入位置为第一个
		for (target = *pNode; target->next != target; target = target->next)
			;//target为指向第一个节点的节点,用于写第一个分支

		temp->next = *pNode;
		target->next = temp;
		*pNode = temp;
	}
	else {
		target = *pNode;
		for (j = 1; j < i - 1; j++) {//对比单向链表
			target = target->next;
		}//找到第i-1的位置

		temp->next = target->next;
		target->next = temp;
		//也可用中间变量p写，不用考虑顺序
	}
}