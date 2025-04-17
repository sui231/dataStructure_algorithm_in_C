/*���Ա�ľ�̬����洢�ṹ*/

#include<stdio.h>
#include"List.h"

typedef struct {
	ElemType data;	//����
	int cur;		//�α�cursor
}Component,StaticLinkList[MAXSIZE];
//ComponentΪ�ṹ�����
//StaticLinkList����һ������Ľṹ�����飬���ǽṹ������������ʶ��


/*��̬�����ʼ��*/
Status InitList(StaticLinkList space) {
	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;

	return OK;
}


//space[0].cur��� �������� ��һ��Ԫ�� �±�
//space[MAXSIZE-1].cur�������ֵ�ĵ�һ��Ԫ���±꣬��ͷ�ڵ�����
//�������һ��Ԫ���α�Ϊ0



int ListLength(StaticLinkList L) {
	int i = L[MAXSIZE-1].cur, j = 0;//i��λ��j����
	while (i) {
		i = L[i].cur;
		j++;
	}
	return j;
}



/*��̬�������*/

//��ÿ��з����±�
int Malloc_SLL(StaticLinkList space) {//ֻ���޸�cur���ʾ�̬����������ָ��
	int i = space[0].cur;
	if (space[0].cur) {
		space[0].cur = space[i].cur;
	}//����һ��������������
	return i;
}
//���뵽��i��Ԫ��ǰ
Status StaticListInsert(StaticLinkList L, int i, ElemType e) {
	int l, j, k;		//lΪ����
	k = MAXSIZE - 1;	//��λ��i-1��Ԫ�أ���ʼΪ�������һ��Ԫ��
	j = Malloc_SLL(L);	//����Ԫ���±�

	if (i < 1 || i > ListLength(L) + 1) {
		return ERROR;
	}//�����ж�

	if (j) {
		L[j].data = e;

		for (l = 1; l < i; l++) {
			k = L[k].cur;//i-1Ϊ�ƶ�������kΪ��i-1��Ԫ���±�
		}//Ѱ�ҵ�i-1��Ԫ���±�

		L[j].cur = L[k].cur;
		L[k].cur = j;

		return OK;
	}
}



/*��̬����ɾ��*/
Status StaticListInsert(StaticLinkList L, int i) {
	int k, j;//kΪ��λ��jΪ����
	k = MAXSIZE - 1;
	
	if (i<1 || i> ListLength(L)) {
		return ERROR;
	}

	for (j = 1; j < i; j++) {
		k = L[k].cur;//kΪ��i-1���±�
	}
	
	j = L[k].cur;//����ת�䣬Ϊ��i��Ԫ���±�
	L[k].cur = L[j].cur;
	//����ֱ��L[k].cur = L[L[k].cur].cur;
	
	Free_SLL(L,j);

	return OK;
}
//���±�Ϊk�Ŀ��нڵ�ع鵽��������
Status Free_SLL(StaticLinkList L, int k) {
	L[k].cur = L[0].cur;
	L[0].cur = k;	
}