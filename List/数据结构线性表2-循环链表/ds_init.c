/*��ʼ��ѭ������*/
//�������ݽṹ��������˵����ʼ��ͨ���漰�����ڴ�ռ������ɲ��֣���ڵ㣩����������Щ��ɲ��ֵĳ�ʼ״̬��
#include"CirLL.h"
#include<stdio.h>
#include <stdlib.h>
//pNode��һ���ڵ�Ķ���ָ��
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
			continue; // ������ǰѭ��������������һ������  
		}//��������

		if (item == 0)
			return;
	
		if ((*pNode) == NULL) {
			*pNode = (node*)malloc(sizeof(node));
			if (!(*pNode))
				exit(0);
			
			(*pNode)->data = item;
			(*pNode)->next = *pNode;
		}//��������Ϊ�գ���Ϊ�������ڴ棬����������Ϊitem
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
		}//��Ϊ�գ��ҵ������β�ڵ㣬Ϊ�½ڵ�����ڴ棬����������Ϊitem
	}
}
