/*删除第i个节点*/

#include"CirLL.h"

void ds_delete(node** pNode, int i) {
	node* target;
	node* temp;//交换中间变量
	int j;

	if (i == 1) {
		for (target = *pNode; target->next != *pNode; target = target->next)
			;
		target->next = (*pNode)->next;
		temp = *pNode;
		*pNode = (*pNode)->next;
		free(temp);
	}
	else {
		target = *pNode;
		for (j = 1; j < i - 1; j++)
			target = target->next;
		temp = target->next;
		target->next = temp->next;
		free(temp);
	}
}
