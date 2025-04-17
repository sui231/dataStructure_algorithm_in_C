/*线性表的静态链表存储结构*/

#include<stdio.h>
#include"List.h"

typedef struct {
	ElemType data;	//数据
	int cur;		//游标cursor
}Component,StaticLinkList[MAXSIZE];
//Component为结构体别名
//StaticLinkList不是一个具体的结构体数组，而是结构体数组声明标识符


/*静态链表初始化*/
Status InitList(StaticLinkList space) {
	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;

	return OK;
}


//space[0].cur存放 备用链表 第一个元素 下标
//space[MAXSIZE-1].cur存放有数值的第一个元素下标，即头节点作用
//链表最后一个元素游标为0



int ListLength(StaticLinkList L) {
	int i = L[MAXSIZE-1].cur, j = 0;//i定位，j计数
	while (i) {
		i = L[i].cur;
		j++;
	}
	return j;
}



/*静态链表插入*/

//获得空闲分量下标
int Malloc_SLL(StaticLinkList space) {//只需修改cur，故静态链表无需用指针
	int i = space[0].cur;
	if (space[0].cur) {
		space[0].cur = space[i].cur;
	}//将下一个分量用作备用
	return i;
}
//插入到第i个元素前
Status StaticListInsert(StaticLinkList L, int i, ElemType e) {
	int l, j, k;		//l为计数
	k = MAXSIZE - 1;	//定位第i-1个元素，起始为数组最后一个元素
	j = Malloc_SLL(L);	//插入元素下标

	if (i < 1 || i > ListLength(L) + 1) {
		return ERROR;
	}//条件判断

	if (j) {
		L[j].data = e;

		for (l = 1; l < i; l++) {
			k = L[k].cur;//i-1为移动次数，k为第i-1个元素下标
		}//寻找第i-1个元素下标

		L[j].cur = L[k].cur;
		L[k].cur = j;

		return OK;
	}
}



/*静态链表删除*/
Status StaticListInsert(StaticLinkList L, int i) {
	int k, j;//k为定位，j为记数
	k = MAXSIZE - 1;
	
	if (i<1 || i> ListLength(L)) {
		return ERROR;
	}

	for (j = 1; j < i; j++) {
		k = L[k].cur;//k为第i-1个下标
	}
	
	j = L[k].cur;//作用转变，为第i个元素下标
	L[k].cur = L[j].cur;
	//或者直接L[k].cur = L[L[k].cur].cur;
	
	Free_SLL(L,j);

	return OK;
}
//将下标为k的空闲节点回归到备用链表
Status Free_SLL(StaticLinkList L, int k) {
	L[k].cur = L[0].cur;
	L[0].cur = k;	
}