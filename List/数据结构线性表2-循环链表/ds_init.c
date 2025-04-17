/*初始化循环链表*/
//对于数据结构如链表来说，初始化通常涉及分配内存空间给其组成部分（如节点），并设置这些组成部分的初始状态。
#include"CirLL.h"
#include<stdio.h>
#include <stdlib.h>
//pNode第一个节点的二重指针
void ds_init(node** pNode) {
	int item;
	node* temp;
	node* target;

	while (1) {
		//printf("Input the value of node or input 0 to exit.");
		//scanf("%d", &item);
		//fflush(stdin);
		if (!read_int_from_input(&item)) {
			printf("Invalid input. Please enter an integer value.\n");
			continue; // 跳过当前循环迭代，继续下一次输入  
		}//亦有他法

		if (item == 0)
			return;
	
		if ((*pNode) == NULL) {
			*pNode = (node*)malloc(sizeof(node));
			if (!(*pNode))
				exit(0);
			
			(*pNode)->data = item;
			(*pNode)->next = *pNode;
		}//若即链表为空，则为它分配内存，设置其数据为item
		else {
			for (target = *pNode; target->next != target; target = target->next)
				;
			temp = (node*)malloc(sizeof(node));
			if (!temp) {
				exit(0); 
			}
			temp->data = item;
			temp->next = *pNode;
			target->next = *pNode;
		}//若为空，找到链表的尾节点，为新节点分配内存，设置其数据为item
	}
}
