#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkList.h"

/*0、将单链表逆置，要求不改变结点地址（建表2，倒置2）*/
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

/*1、找单链表中点*/
LinkNode* getMid(LinkList L) {
	LinkNode* mid, * tail;
	mid = L;
	tail = L->next;
	while (tail != NULL && tail->next != NULL) { //注意条件顺序
		mid = mid->next;
		tail = tail->next->next;
	}
	return mid;
}

/*2、找单链表倒数第K个点*/
LinkNode* getCountBack(LinkList L, int k) {
	LinkNode* kNode;
	kNode = L;
	for (int i = 0; i < LL_length(L) - k; i++) {
		kNode = kNode->next;
	}
	return kNode;
}

/*3、删除单链表倒数第K个点*/
void deleteCountBack(LinkList* L, int k) {
	LinkNode* pre = getCountBack(*L, k+1);
	LinkNode* temp = pre->next;
	pre->next = pre->next->next;
	free(temp);
}

/*4、判断单链表是否有环，如有，找出交点*/
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
			return n;//返回环的长度
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
			return n1;//返回环的位置，长度n2
		}
	}
	return -1;
}

/*5、判断两个单链表是否相交，如果相交，找出交点*/
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
			return n;//返回环的位置，长度n2
		}
	}
	if (p2->next == L2 && p2->next == p1->next)
		return n + 1;
	return -1;
}

/*6、对于有序单链表，删除重复节点（保留一个/无保留）*/
void deleteRepeatNode(LinkList* L) {
	/* 1.分支选择 */
	char ch;
	printf("If reserving the repeating node appearing firstly:(input Y or N )\n");
	scanf("%c", &ch);
	while (ch != 'N' && ch != 'Y') scanf("%c", &ch);
	if (ch != 'N' && ch != 'Y') {
		printf("Re-enter the right char:(input Y or N )\n");
		scanf("%c", &ch);
		while (ch != 'N' && ch != 'Y') scanf("%c", &ch);
	}

	/* 2.声明及初始化 */
	int i, j, k, flag, len, sLen;
	len = LL_length(*L);
	LinkNode* current,* temp, *pre,* repeat, *head;
	ElemType* data = (ElemType*)malloc(sizeof(ElemType) * len * 2);	//报错，缓冲区溢出，故 * 2 防止报错
	/* !!!!!! position 只能通过储存下标记录位置，若储存相邻地址则无法正确执行删除操作 */
	int* position = (int*)malloc(sizeof(ElemType) * len * 2);
	int* repeatFlag = (int*)malloc(sizeof(int) * len * 2);
	if (!data&&!position) exit(0);
	/*
	data		用于存储 首次或重复出现数据 的数据
	position	用于存储 首次或重复出现数据 的前一个数据的编号
	repeatFlag	为对应 position 的节点重复标识

	len			为 L 长度
	sLen		为 s 长度,用于确定有效存储长度
	flag		为删除完成标识
	repeat		指向首次出现的重复元素，无保留重复节点时使用
	*/

	data[0] = '\0';
	for (i = 0; i < len; i++) {
		repeatFlag[i] = 0;
		position[i] = -1;
	}
	sLen = 0;
	k = 0;
	head = (LinkNode*)malloc(sizeof(LinkNode));//随便赋的值，不能为NULL 和 *L
	if (!head) exit(0);
	current = head;
	current->data = '*';//随便赋的值
	current->next = *L;
	pre = repeat = NULL;

	/* 3.删除新出现的重复节点，用current->next比较，方便删除操作进行 */
	for (i = 0; current->next != NULL; i++) {
		flag = 0;
		/* 若匹配，删除同时完成后移 */
		for (j = 0; j < sLen && current->next != NULL; j++) { //对比sL数组
			if (current->next->data == data[j]) { //是重复节点
				temp = current->next;				
				current->next = current->next->next;					
				free(temp);

				flag = 1;
				repeatFlag[j] = 1;
				//repeatFlag[j+1] = '\0';
				break;
			}
		}
		/* 添加，后移 */
		if (flag == 0 && current->next != NULL) { //不是重复节点
			sLen++;
			data[sLen - 1] = current->next->data;
			//data[j + 1] = '\0';
			position[sLen - 1] = i;
			//position[j+1] = '\0';

			current = current->next;//!!!!注意应当在if内，删除已经进行了移动操作
		}
	}

	/* 4.删除首次出现的重复节点 */
	k = 0;//k 为删除次数
	for (i = 0; i < sLen && ch == 'N'; i++) {
		if (repeatFlag[i] == 1) {
			repeat = head;
			for (j = 0; j < position[i] - k; j++) { //!!!!!!!注意减 k
				repeat = repeat->next;
			}//定位
			if (repeat->next == (*L))	*L = (*L)->next;//!!!!!!!头节点被删除
			temp = repeat->next;
			repeat->next = repeat->next->next;
			free(temp);
			//sLen--;//!!!!不能添加
			k++;
			/*若要后续使用，则i后元素需前移*/
		}
	}
}

/*7、约瑟夫问题(无损/有损)*/
//略

/*8、合并两个升序单链表(保留重复点)，合并后为升序*/
LinkList* combine1(LinkList* L1, LinkList* L2) {

}

/*9、合并两个升序单链表(保留重复点)，合并后为降序*/
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