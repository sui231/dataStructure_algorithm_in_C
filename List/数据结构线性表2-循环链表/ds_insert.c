/*����ڵ�*/

#include"CirLL.h"
#include<stdio.h>
#include<stdlib.h>

//iΪλ��
void ds_insert(node** pNode, int i) {
	node* temp;//tempΪ����ڵ�
	node* target;//��λ����
	node* p;//pΪ�м�������ɲ���
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
	}//Ӧ���ȷ����ڴ棬��ʼ��temp


	if (i == 1) {	//����λ��Ϊ��һ��
		for (target = *pNode; target->next != target; target = target->next)
			;//targetΪָ���һ���ڵ�Ľڵ�,����д��һ����֧

		temp->next = *pNode;
		target->next = temp;
		*pNode = temp;
	}
	else {
		target = *pNode;
		for (j = 1; j < i - 1; j++) {//�Աȵ�������
			target = target->next;
		}//�ҵ���i-1��λ��

		temp->next = target->next;
		target->next = temp;
		//Ҳ�����м����pд�����ÿ���˳��
	}
}