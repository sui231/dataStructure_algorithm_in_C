#include<stdio.h>
#include"List.h"

/*链表创建,清空*/

/*头插法建立单链表*/
void CreateListHead(LinkList* L, int n) {
	LinkList p;
	int i;

	srand(time(0));//初始化随机种子

	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;

	for (i = 0; i < n; i++) {		//如果* pNode为NULL（即链表为空），则为它分配内存，并设置其数据为item。
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;//1~100整数
		p->next = (*L)->next;
		(*L)->next = p;//生成新节点
	}
}

/*尾插法建立单链表*/
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
		/*为了安全起见，并且确保链表结构的正确性，我们需要显式地将 current->next 设置为 NULL*/

		r->next = p;
		r = p;//通过r后移
	}
	r->next = NULL;
}

Status ClearList(LinkList* L) {
	LinkList p, q;
	p = (*L)->next;

	while (p) {
		q = p->next;
		free(p);
		p = q;//左脚踩右脚
	}
	(*L)->next = NULL;
	return OK;
}