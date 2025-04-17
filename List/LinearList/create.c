/*�����������*/

#include<stdio.h>
#include<stdlib.h>
#include"List.h"


/*����˳���*/
SqList* SL_create(int n) {
	//ֱ�ӷ��ؽṹЧ�ʵ�
	SqList* SL;
	int i;

	if (n < 0 || n > MAXSIZE - 1)
		return ;

	srand(time(0));
	
	SL = (SqList*)malloc(sizeof(SqList));
	if (!SL)
		exit(EXIT_FAILURE);

	(*SL).data[0] = 0;
	for (i = 1; i <= n; i++)
		(*SL).data[i] = rand() % 100 + 1;
	(*SL).length = n;
	return SL;
}



/*ͷ�巨���������������*/
node* LL_head_create(int n) {
	node* Head;
	node* current;
	int i;
	srand(time(0));

	Head = (node*)malloc(sizeof(node));
	if (!Head)
		exit(EXIT_FAILURE);
	Head->data = 0;//ͷ�ڵ㸳ֵΪ0
	Head->next = NULL;

	for (i = 1; i <= n; i++) {
		current = (node*)malloc(sizeof(node));
		if (!current)
			exit(EXIT_FAILURE);
		current->next = NULL;

		current->next = Head->next;//����
		Head->next = current;	
		current->data = rand() % 100 + 1;
	}
	return Head;
}



/*β�巨���������������*/
node* LL_tail_create(int n) {
	node* Head;
	node* current;
	node* prev;
	int i;
	srand(time(0));

	Head = (node*)malloc(sizeof(node));
	if (!Head)
		exit(EXIT_FAILURE);
	Head->data = 0;//ͷ�ڵ㸳ֵΪ0
	Head->next = NULL;

	prev = Head;
	for (i = 1; i <= n; i++) {
		current = (node*)malloc(sizeof(node));
		if (!current)
			exit(EXIT_FAILURE);
		current->next = NULL;
		current->data = rand() % 100 + 1;

		prev->next = current;//����
		prev = current;
	}
	return Head;
}



/*��������ѭ������*/
node* CirLL_create(int n) {
	node* current;
	node* prev;
	node* Head;
	int i;

	srand(time(0));

	//current = (node*)malloc(sizeof(node));
	//if (!current)
	//	exit(EXIT_FAILURE);//������

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



/*������̬��������*/
//���鲻����Ϊ����ֵ
struct StaticLinkList* SLL_create(int n) {
	StaticLinkList L =(Component*)malloc(sizeof(Component) * MAXSIZE);

	if (n < 1 || n >= MAXSIZE - 1)
		return NULL;

	//L = (StaticLinkList*)malloc(sizeof(StaticLinkList) * MAXSIZE);
	//if (!L)
	//	exit(EXIT_FAILURE);//��ָ�붨��

	srand(time(0));
	
	for (i = 1; i <= n; i++) {	
		L[i].data = rand() % 100 + 1;
		if(i < n)
			L[i].cur = i + 1;
		if(i == n)
			L[n].cur = 0;
	}

	L[0].cur = n + 1;//�洢���ÿռ�
	L[MAXSIZE - 1].cur = 1;//�洢��һ���ڵ�

	return L;
}