#include<stdio.h>
#include"List.h"

/*������,���*/

/*ͷ�巨����������*/
void CreateListHead(LinkList* L, int n) {
	LinkList p;
	int i;

	srand(time(0));//��ʼ���������

	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;

	for (i = 0; i < n; i++) {		//���* pNodeΪNULL��������Ϊ�գ�����Ϊ�������ڴ棬������������Ϊitem��
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;//1~100����
		p->next = (*L)->next;
		(*L)->next = p;//�����½ڵ�
	}
}

/*β�巨����������*/
void ListCreateTail(LinkList* L, int n) {
	int i;
	LinkList p,r;//r

	srand(time(0));

	*L = (LinkList)malloc(sizeof(Node));
	r = *L;

	for (i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		//p->next = NULL;
		/*Ϊ�˰�ȫ���������ȷ������ṹ����ȷ�ԣ�������Ҫ��ʽ�ؽ� current->next ����Ϊ NULL*/

		r->next = p;
		r = p;//ͨ��r����
	}
	r->next = NULL;
}

Status ClearList(LinkList* L) {
	LinkList p, q;
	p = (*L)->next;

	while (p) {
		q = p->next;
		free(p);
		p = q;//��Ų��ҽ�
	}
	(*L)->next = NULL;
	return OK;
}