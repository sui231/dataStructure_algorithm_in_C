/*��������:ħ��ʦ����һ�����е�13�ź��ƣ�Ԥ
�Ƚ������źú������һ�����泯�¡��Թ���
˵:���Ҳ����ƣ�ֻ�����Ϳ��Բµ�ÿ������ʲ
ô���Ҵ���������������������?�ֳ���ʾ��
ħ��ʦ�����������������Ϊ1����������������
�Ǻ���A��������A���������ϣ��ڶ�����1,2,
����һ���Ʒ�����Щ�Ƶ����棬���ڶ����Ʒ���
���������Ǻ���2��Ҳ���������������������ν�
�н�13����ȫ��������׼ȷ����
����: �ƵĿ�ʼ˳������ΰ��ŵ�?*/

#include<stdio.h>
#include<stdlib.h>
#include"practice.h"

//int main(void) {
//	node* L;
//	L = CirLL_create0(13);
//	Magician(L);
//	CLL_traverse(L);
//	return 0;
//}



void Magician(node* Head) {
	node* p;
	int j, count;
	p = Head;

	Head->data = 1;

	count = 2;

	while (1) {
		for (j = 0; j < count; j++) {
			p = p->next;		
			if (p->data != 0) {
				p = p->next;
				j--;
			}			
		}	
		if (p->data == 0) {
			p->data = count;
			if (count == 13)
				break;
			count++;
		}
	}
}

node* CirLL_create0(int n) {
	//ȫΪ0
	node* current;
	node* prev;
	node* Head;
	int i;
	current = (node*)malloc(sizeof(node));//���ϱ����������������

	Head = (node*)malloc(sizeof(node));
	if (!Head)
		exit(EXIT_FAILURE);
	Head->data = 0;
	Head->next = NULL;

	prev = Head;
	for (i = 2; i <= n; i++) {
		current = (node*)malloc(sizeof(node));
		if (!current)
			exit(EXIT_FAILURE);
		current->next = NULL;
		current->data = 0;

		prev->next = current;
		prev = current;
	}
	current->next = Head;

	return Head;
}