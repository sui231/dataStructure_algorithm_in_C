/*寻找元素为 elem 的节点位置*/

#include"CirLL.h"
#include<stdio.h>

int ds_search(node* pNode, int elem) {
	node* target;
	int i = 1;//目标序号
	
	for (target = pNode; target->data!=elem && target->next != pNode; target = target->next) {
		i++;
	}

	if (target->next == pNode)/*元素不存在*/
		return EOF;
	else
		return i;
}