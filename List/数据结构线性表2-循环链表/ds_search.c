/*Ѱ��Ԫ��Ϊ elem �Ľڵ�λ��*/

#include"CirLL.h"
#include<stdio.h>

int ds_search(node* pNode, int elem) {
	node* target;
	int i = 1;//Ŀ�����
	
	for (target = pNode; target->data!=elem && target->next != pNode; target = target->next) {
		i++;
	}

	if (target->next == pNode)/*Ԫ�ز�����*/
		return EOF;
	else
		return i;
}