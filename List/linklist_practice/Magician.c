/*问题描述:魔术师利用一副牌中的13张黑牌，预
先将他们排好后叠放在一起，牌面朝下。对观众
说:“我不看牌，只数数就可以猜到每张牌是什
么，我大声数数，你们听，不信?现场演示。
魔术师将最上面的那张牌数为1，把他翻过来正好
是黑桃A，将黑桃A放在桌子上，第二次数1,2,
将第一张牌放在这些牌的下面，将第二张牌翻过
来，正好是黑桃2，也将它放在桌子上这样依次进
行将13张牌全部翻出，准确无误。
问题: 牌的开始顺序是如何安排的?*/

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
	//全为0
	node* current;
	node* prev;
	node* Head;
	int i;
	current = (node*)malloc(sizeof(node));//智障编译器，必须加这行

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