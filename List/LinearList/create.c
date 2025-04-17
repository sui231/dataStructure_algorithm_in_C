/*创建随机链表*/

#include<stdio.h>
#include<stdlib.h>
#include"List.h"


/*创建顺序表*/
SqList* SL_create(int n) {
	//直接返回结构效率低
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



/*头插法创建随机单向链表*/
node* LL_head_create(int n) {
	node* Head;
	node* current;
	int i;
	srand(time(0));

	Head = (node*)malloc(sizeof(node));
	if (!Head)
		exit(EXIT_FAILURE);
	Head->data = 0;//头节点赋值为0
	Head->next = NULL;

	for (i = 1; i <= n; i++) {
		current = (node*)malloc(sizeof(node));
		if (!current)
			exit(EXIT_FAILURE);
		current->next = NULL;

		current->next = Head->next;//核心
		Head->next = current;	
		current->data = rand() % 100 + 1;
	}
	return Head;
}



/*尾插法创建随机单向链表*/
node* LL_tail_create(int n) {
	node* Head;
	node* current;
	node* prev;
	int i;
	srand(time(0));

	Head = (node*)malloc(sizeof(node));
	if (!Head)
		exit(EXIT_FAILURE);
	Head->data = 0;//头节点赋值为0
	Head->next = NULL;

	prev = Head;
	for (i = 1; i <= n; i++) {
		current = (node*)malloc(sizeof(node));
		if (!current)
			exit(EXIT_FAILURE);
		current->next = NULL;
		current->data = rand() % 100 + 1;

		prev->next = current;//核心
		prev = current;
	}
	return Head;
}



/*创建单向循环链表*/
node* CirLL_create(int n) {
	node* current;
	node* prev;
	node* Head;
	int i;

	srand(time(0));

	//current = (node*)malloc(sizeof(node));
	//if (!current)
	//	exit(EXIT_FAILURE);//防报错

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



/*创建静态单向链表*/
//数组不能作为返回值
struct StaticLinkList* SLL_create(int n) {
	StaticLinkList L =(Component*)malloc(sizeof(Component) * MAXSIZE);

	if (n < 1 || n >= MAXSIZE - 1)
		return NULL;

	//L = (StaticLinkList*)malloc(sizeof(StaticLinkList) * MAXSIZE);
	//if (!L)
	//	exit(EXIT_FAILURE);//用指针定义

	srand(time(0));
	
	for (i = 1; i <= n; i++) {	
		L[i].data = rand() % 100 + 1;
		if(i < n)
			L[i].cur = i + 1;
		if(i == n)
			L[n].cur = 0;
	}

	L[0].cur = n + 1;//存储备用空间
	L[MAXSIZE - 1].cur = 1;//存储第一个节点

	return L;
}