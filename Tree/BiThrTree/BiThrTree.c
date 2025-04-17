#include<stdio.h>
#include<stdlib.h>
#include"BiThrTree.h"

int main(void) {
	BiThrTree T;//���ڵ�
	BiThrTree p;//������T���ڵ���ֱ������;//ͷ�ڵ�
	printf("Create.\n");
	CreateBiThrTree(&T);/*ABC  D  E F  _*/

	printf("Thread.\n");
	InOrderThreading(&T, &p);

	printf("Print.\n");
	InOrderTraverse(p);

	
	return 0;
}


//ǰ���������
//��ʱ����δ������״̬
void CreateBiThrTree(BiThrTree* T) {
	char c;
	scanf("%c", &c);
	while (c == '\n');//��ջس�

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


/*�쳣 0xC00000FD: Stack overflow ��һ������ʱ����
ͨ�������ڳ�����ͼʹ�ñȷ��������ջ�ռ�����ջ�ڴ�ʱ
��ͨ�������ڵݹ麯��û����ȷ���˳�������ݹ�Ĳ���̫�ർ�µġ�*/

//�������������������
//����������������Ҷ����������Ҷ�������
void InThreading(BiThrTree T) {
	if (T != NULL) {
		//�������ݹ�
		InThreading(T->lchild);	

		//�ݹ���ֹ����
		if (NULL == T->lchild) {			
			T->ltag = Thread;
			T->lchild = pre;//�洢ǰ��
		}

		// ���pre��rchildΪ�գ�����pre�ĺ��Ϊ��ǰ�ڵ�
		if (pre != NULL && pre->rchild == NULL) { //pre != NULLΪ����
			pre->rtag = Thread;
			pre->rchild = T; //�洢��һ���ڵ�ĺ��
		}
		pre = T; //�洢ǰ��					

		//�������ݹ�
		InThreading(T->rchild);	
	}
}

//���� ��������������ͷ�����ڱ��ڵ㣬�����ڼ򻯱�������
void InOrderThreading(BiThrTree* T, BiThrTree* head) {
	*head = (BiThrNode*)malloc(sizeof(BiThrNode));//������T���ڵ���ֱ������
	if (!head) exit(0);
	(*head)->data = '*';
	(*head)->ltag = Link;
	(*head)->rtag = Thread;
	(*head)->rchild = (*head); // ͷ�ڵ�ĺ��ָ���Լ�(Ҳ����ָ�����һ���ڵ�)  

	if (*T != NULL) {
		(*head)->lchild = *T; // ͷ�ڵ� lchild ָ����ڵ�  
		pre = (*head);

		InThreading(*T); // ������������

		pre->rchild = (*head); // ��������preΪ���һ���ڵ㣬����ָ��ͷ�ڵ�  
		pre->rtag = Thread;
		//head->rchild = pre; 
	}
	else {
		(*head)->lchild = (*head); // ���������Ϊ�գ�ͷ�ڵ��ǰ��ָ���Լ�  
	}
	//*T = (*head);   
}

void visit(ElemType e) {
	printf("%c\t", e);
}

// ��������������
void InOrderTraverse(BiThrTree Head) {
	BiThrTree p;
	p = Head->lchild;

	while (p != Head) {
		while (p->ltag == Link) {
			p = p->lchild;
		}
		visit(p->data);//lchild

		while (p->rtag == Thread && p->rchild != Head) {
			p = p->rchild;//p�ƶ������
			visit(p->data);
		}
		p = p->rchild;//p�ƶ��� ��� �� ��̻���rchild
	}
}