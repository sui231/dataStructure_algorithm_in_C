/*���������������*/

#include"List.h"

Status GetElem(LinkList L, int i, ElemType* e) {
	int j;
	LinkList p;

	p = L;
	j = 1;

	while (p && j < i) {//����for
		p = p->next;
		j++;
	}
	if (!p || j > i) {
		return ERROR;
	}

	*e = p->data;
	return OK;
}//ʱd�临�Ӷ�O(n)


Status ListInsert(LinkList* L, int i, ElemType e) {//eΪ����������
	int j;
	LinkList p, s;

	p = *L;
	j = 1;
	//*L �Ƕ� L �Ľ����á�����ʾ L ��ָ����Ǹ�ָ���ֵ���������ͷ�ڵ��ַ��
	//�ں����ڲ�������ͨ�� *L �����ʺ��޸������ͷ�ڵ㡣
	
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i) {
		return ERROR;
	}

	s = (LinkList)malloc(sizeof(Node));
	if (s == NULL) {
		printf("Memory allocation failed!\n");
		return ERROR;
	}
	s->data = e;//����

	s->next = p->next;
	p->next = s;//����

	return OK;
}

Status ListDelete(LinkList* L, int i, ElemType* e) {
	int j;
	LinkList p, q;//qΪp�ĺ�һ��
	
	p = *L;
	j = 1;
	while (p->next && j < i) {
		p = p->next;
		j++;
	}
	if (!p->next || j > i ) {
		return ERROR;
	}

	q = p->next;
	p->next = q->next;
	//����ֱ��p = p->next->next;

	*e = q->data;//�洢��ɾ������
	free(q);

	return OK;
}// O(1)
