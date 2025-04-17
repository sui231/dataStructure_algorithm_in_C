#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkList.h"

/*0�������������ã�Ҫ�󲻸ı����ַ������2������2��*/
LinkList inversion(LinkList L) {
	LinkNode* target,* tail,* pL,* p1,* p2;
	LinkList L1;
	int i, j, len;
	ElemType temp;

	L1 = (LinkNode*)malloc(sizeof(LinkNode));
	if (!L1) exit(0);

	pL = L;
	tail = L1;
	L1->data = L->data;
	pL = pL->next;
	while (pL != NULL) {
		target = (LinkNode*)malloc(sizeof(LinkNode));
		if (!target) exit(0);

		target->next = NULL;
		tail->next = target;

		target->data = pL->data;
		tail = target;
		pL = pL->next;
	}

	len = LL_length(L1);
	p1 = L1;
	for (i = 0; i <= len / 2; i++) {
		p2 = p1;
		for (j = i; j < len - i - 1; j++) {
			p2 = p2->next;
		}
		temp = p2->data;
		p2->data = p1->data;
		p1->data = temp;
		p1 = p1->next;
	}
	return L1;
}

/*1���ҵ������е�*/
LinkNode* getMid(LinkList L) {
	LinkNode* mid, * tail;
	mid = L;
	tail = L->next;
	while (tail != NULL && tail->next != NULL) { //ע������˳��
		mid = mid->next;
		tail = tail->next->next;
	}
	return mid;
}

/*2���ҵ���������K����*/
LinkNode* getCountBack(LinkList L, int k) {
	LinkNode* kNode;
	kNode = L;
	for (int i = 0; i < LL_length(L) - k; i++) {
		kNode = kNode->next;
	}
	return kNode;
}

/*3��ɾ������������K����*/
void deleteCountBack(LinkList* L, int k) {
	LinkNode* pre = getCountBack(*L, k+1);
	LinkNode* temp = pre->next;
	pre->next = pre->next->next;
	free(temp);
}

/*4���жϵ������Ƿ��л������У��ҳ�����*/
int ifRing1(LinkList L) {
	LinkNode* p1, * p2;
	int n = 1;
	p1 = L->next;
	p2 = L->next->next;
	while (p2 != NULL && p2->next != NULL) {
		n++;
		p1 = p1->next;
		p2 = p2->next->next;
		if (p1 == p2) {
			return n;//���ػ��ĳ���
		}
	}
	return -1;
}
int ifRing2(LinkList L) {
	LinkNode* p1, * p2;
	int n1, n2;
	n2 = 0;
	p1 = p2 = L;
	while (p2 != NULL) {
		p2 = p2->next;
		n2++;
		n1 = 0;
		p1 = L;
		while (p1 != p2) {		
			p1 = p1->next;
			n1++;
		}
		if (n1 != n2) {
			return n1;//���ػ���λ�ã�����n2
		}
	}
	return -1;
}

/*5���ж������������Ƿ��ཻ������ཻ���ҳ�����*/
int ifIntersect(LinkList L1, LinkList L2) {
	LinkNode* p1, * p2;
	int n = 0;
	p2 = L2;
	while (p2 != NULL && p2->next != L2) {
		p2 = p2->next;
		n++;
		p1 = L1;
		for (int i = 0; i < n; i++) {
			p1 = p1->next;
		}
		if (p1 == p2) {
			return n;//���ػ���λ�ã�����n2
		}
	}
	if (p2->next == L2 && p2->next == p1->next)
		return n + 1;
	return -1;
}

/*6��������������ɾ���ظ��ڵ㣨����һ��/�ޱ�����*/
void deleteRepeatNode(LinkList* L) {
	/* 1.��֧ѡ�� */
	char ch;
	printf("If reserving the repeating node appearing firstly:(input Y or N )\n");
	scanf("%c", &ch);
	while (ch != 'N' && ch != 'Y') scanf("%c", &ch);
	if (ch != 'N' && ch != 'Y') {
		printf("Re-enter the right char:(input Y or N )\n");
		scanf("%c", &ch);
		while (ch != 'N' && ch != 'Y') scanf("%c", &ch);
	}

	/* 2.��������ʼ�� */
	int i, j, k, flag, len, sLen;
	len = LL_length(*L);
	LinkNode* current,* temp, *pre,* repeat, *head;
	ElemType* data = (ElemType*)malloc(sizeof(ElemType) * len * 2);	//����������������� * 2 ��ֹ����
	/* !!!!!! position ֻ��ͨ�������±��¼λ�ã����������ڵ�ַ���޷���ȷִ��ɾ������ */
	int* position = (int*)malloc(sizeof(ElemType) * len * 2);
	int* repeatFlag = (int*)malloc(sizeof(int) * len * 2);
	if (!data&&!position) exit(0);
	/*
	data		���ڴ洢 �״λ��ظ��������� ������
	position	���ڴ洢 �״λ��ظ��������� ��ǰһ�����ݵı��
	repeatFlag	Ϊ��Ӧ position �Ľڵ��ظ���ʶ

	len			Ϊ L ����
	sLen		Ϊ s ����,����ȷ����Ч�洢����
	flag		Ϊɾ����ɱ�ʶ
	repeat		ָ���״γ��ֵ��ظ�Ԫ�أ��ޱ����ظ��ڵ�ʱʹ��
	*/

	data[0] = '\0';
	for (i = 0; i < len; i++) {
		repeatFlag[i] = 0;
		position[i] = -1;
	}
	sLen = 0;
	k = 0;
	head = (LinkNode*)malloc(sizeof(LinkNode));//��㸳��ֵ������ΪNULL �� *L
	if (!head) exit(0);
	current = head;
	current->data = '*';//��㸳��ֵ
	current->next = *L;
	pre = repeat = NULL;

	/* 3.ɾ���³��ֵ��ظ��ڵ㣬��current->next�Ƚϣ�����ɾ���������� */
	for (i = 0; current->next != NULL; i++) {
		flag = 0;
		/* ��ƥ�䣬ɾ��ͬʱ��ɺ��� */
		for (j = 0; j < sLen && current->next != NULL; j++) { //�Ա�sL����
			if (current->next->data == data[j]) { //���ظ��ڵ�
				temp = current->next;				
				current->next = current->next->next;					
				free(temp);

				flag = 1;
				repeatFlag[j] = 1;
				//repeatFlag[j+1] = '\0';
				break;
			}
		}
		/* ��ӣ����� */
		if (flag == 0 && current->next != NULL) { //�����ظ��ڵ�
			sLen++;
			data[sLen - 1] = current->next->data;
			//data[j + 1] = '\0';
			position[sLen - 1] = i;
			//position[j+1] = '\0';

			current = current->next;//!!!!ע��Ӧ����if�ڣ�ɾ���Ѿ��������ƶ�����
		}
	}

	/* 4.ɾ���״γ��ֵ��ظ��ڵ� */
	k = 0;//k Ϊɾ������
	for (i = 0; i < sLen && ch == 'N'; i++) {
		if (repeatFlag[i] == 1) {
			repeat = head;
			for (j = 0; j < position[i] - k; j++) { //!!!!!!!ע��� k
				repeat = repeat->next;
			}//��λ
			if (repeat->next == (*L))	*L = (*L)->next;//!!!!!!!ͷ�ڵ㱻ɾ��
			temp = repeat->next;
			repeat->next = repeat->next->next;
			free(temp);
			//sLen--;//!!!!�������
			k++;
			/*��Ҫ����ʹ�ã���i��Ԫ����ǰ��*/
		}
	}
}

/*7��Լɪ������(����/����)*/
//��

/*8���ϲ�������������(�����ظ���)���ϲ���Ϊ����*/
LinkList* combine1(LinkList* L1, LinkList* L2) {

}

/*9���ϲ�������������(�����ظ���)���ϲ���Ϊ����*/
LinkList* combine2(LinkList* L1, LinkList* L2) {


}

int main(void) {
	LinkList L;
	L = LL_create();

	deleteRepeatNode(&L);
	//printf("%d", IfRing2(L));
	LL_traverse(L);
	return 0;
}