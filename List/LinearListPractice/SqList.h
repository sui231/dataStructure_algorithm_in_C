#ifndef _SQLIST_H
#define _SQLIST_H

#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define MAXSIZE 1000

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char ElemType;
typedef struct _sqlist {
	ElemType* data;
	int length;
}SqList;


void removeRepet(SqList* SL);
void removeRepet1(SqList* SL);
void removeZero(SqList* SL);
void range(SqList* SL);
int KMP(SqList* SL, ElemType* s);
void getNext(SqList* SL, int* next);
int bruteForce(SqList* SL, ElemType* s);




/*创建顺序表*/
SqList* SL_create(void) {
	SqList* SL;
	ElemType ch;
	int i;
	SL = (SqList*)malloc(sizeof(SqList));
	SL->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	if (!SL || !SL->data)
		exit(0);

	SL->length = 0;
	printf("Input the node ended with enter:\n");
	scanf("%c", &ch);
	while (ch == ' ')
		scanf("%c", &ch);
	for (i = 0; ch != '\n' && SL->length <= MAXSIZE; i++) {
		(*SL).data[i] = ch;
		SL->length++;
		scanf("%c", &ch);
		while (ch == ' ')
			scanf("%c", &ch);
	}
	SL->data[i] = '\0';
	return SL;
}

/*遍历顺序表*/
void SL_traverse(SqList* SL) {
	for (int i = 0; i < SL->length; i++) {
		printf("%c ", SL->data[i]);
	}
	printf("\nLength: %d", SL->length);
}
#endif