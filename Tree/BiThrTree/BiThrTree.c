#include<stdio.h>
#include<stdlib.h>
#include"BiThrTree.h"

int main(void) {
	BiThrTree T;//根节点
	BiThrTree p;//若更改T根节点则直接声明;//头节点
	printf("Create.\n");
	CreateBiThrTree(&T);/*ABC  D  E F  _*/

	printf("Thread.\n");
	InOrderThreading(&T, &p);

	printf("Print.\n");
	InOrderTraverse(p);

	
	return 0;
}


//前序遍历创建
//此时仍是未线索化状态
void CreateBiThrTree(BiThrTree* T) {
	char c;
	scanf("%c", &c);
	while (c == '\n');//清空回车

	if (' ' == c) {
		*T = NULL;
	}
	else {
		*T = (BiThrNode*)malloc(sizeof(BiThrNode));
		if (!(*T))
			exit(0);
		(*T)->data = c;
		(*T)->ltag = Link;
		(*T)->rtag = Link;

		CreateBiThrTree(&(*T)->lchild);
		CreateBiThrTree(&(*T)->rchild);
	}
}


/*异常 0xC00000FD: Stack overflow 是一个运行时错误，
通常发生在程序试图使用比分配给它的栈空间更多的栈内存时
这通常是由于递归函数没有正确的退出条件或递归的层数太多导致的。*/

//中序遍历线索化二叉树
//线索化，起于最左叶，终于最右叶（或根）
void InThreading(BiThrTree T) {
	if (T != NULL) {
		//左子树递归
		InThreading(T->lchild);	

		//递归终止条件
		if (NULL == T->lchild) {			
			T->ltag = Thread;
			T->lchild = pre;//存储前驱
		}

		// 如果pre的rchild为空，设置pre的后继为当前节点
		if (pre != NULL && pre->rchild == NULL) { //pre != NULL为保障
			pre->rtag = Thread;
			pre->rchild = T; //存储上一个节点的后继
		}
		pre = T; //存储前驱					

		//右子树递归
		InThreading(T->rchild);	
	}
}

//创建 线索化二叉树的头结点或哨兵节点，它用于简化遍历过程
void InOrderThreading(BiThrTree* T, BiThrTree* head) {
	*head = (BiThrNode*)malloc(sizeof(BiThrNode));//若更改T根节点则直接声明
	if (!head) exit(0);
	(*head)->data = '*';
	(*head)->ltag = Link;
	(*head)->rtag = Thread;
	(*head)->rchild = (*head); // 头节点的后继指向自己(也可能指向最后一个节点)  

	if (*T != NULL) {
		(*head)->lchild = *T; // 头节点 lchild 指向根节点  
		pre = (*head);

		InThreading(*T); // 线索化二叉树

		pre->rchild = (*head); // 线索化后pre为最后一个节点，其后继指向头节点  
		pre->rtag = Thread;
		//head->rchild = pre; 
	}
	else {
		(*head)->lchild = (*head); // 如果二叉树为空，头节点的前驱指向自己  
	}
	//*T = (*head);   
}

void visit(ElemType e) {
	printf("%c\t", e);
}

// 遍历线索二叉树
void InOrderTraverse(BiThrTree Head) {
	BiThrTree p;
	p = Head->lchild;

	while (p != Head) {
		while (p->ltag == Link) {
			p = p->lchild;
		}
		visit(p->data);//lchild

		while (p->rtag == Thread && p->rchild != Head) {
			p = p->rchild;//p移动到后继
			visit(p->data);
		}
		p = p->rchild;//p移动到 后继 的 后继或者rchild
	}
}