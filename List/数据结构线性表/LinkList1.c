/*单向链表基本操作*/

#include"List.h"

Status GetElem(LinkList L, int i, ElemType* e) {
	int j;
	LinkList p;

	p = L;
	j = 1;

	while (p && j < i) {//不用for
		p = p->next;
		j++;
	}
	if (!p || j > i) {
		return ERROR;
	}

	*e = p->data;
	return OK;
}//时d间复杂度O(n)


Status ListInsert(LinkList* L, int i, ElemType e) {//e为插入数据域
	int j;
	LinkList p, s;

	p = *L;
	j = 1;
	//*L 是对 L 的解引用。它表示 L 所指向的那个指针的值，即链表的头节点地址。
	//在函数内部，我们通过 *L 来访问和修改链表的头节点。
	
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
	s->data = e;//创建

	s->next = p->next;
	p->next = s;//连接

	return OK;
}

Status ListDelete(LinkList* L, int i, ElemType* e) {
	int j;
	LinkList p, q;//q为p的后一个
	
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
	//或者直接p = p->next->next;

	*e = q->data;//存储被删除数据
	free(q);

	return OK;
}// O(1)
