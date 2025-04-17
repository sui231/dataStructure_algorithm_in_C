#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SqList.h"


/*0、对于有序顺序表，去除重复数据，如1 2 3 3 4 4 5 —> 1 2 3 4 5*/
void removeRepet(SqList* SL) {
	ElemType* s;//s用于存储已出现数据类型
	int i, j, k ,flag, len;
	//flag 用于检测是否已经去除当前数据
	s = (ElemType*)malloc(sizeof(ElemType) * SL->length);
	if (!s) exit(0);

	s[0] = '\0';
	for (i = 0; i < SL->length; i++) {
		flag = 0;
		for (j = 0; j < strlen(s); j++) {
			if (SL->data[i] == s[j]) {
				for (k = i; k < SL->length; k++)
					SL->data[k] = SL->data[k + 1];
				SL->length--;
				flag = 1;
				i--;//易忘
				break;
			}
		}
		if (flag == 0) {
			s[j] = SL->data[i];
			s[j + 1] = '\0';
		}
	}
}
/*去除重复相邻数据*/
/*
int main()
{
	int i,length=10,index=0,a[length];
	for(i=0;i<length;i++)
			scanf("%d",&a[i]);
	printf("\n ");
	for(i=0;i<length;i++)
			printf("%d ",a[i]);
	printf("\n ");
	for(i=1;i<length;i++)
		{
			if(a[index]!=a[i])
				a[++index]=a[i];
		}
	length=index+1;
	for(i=0;i<length;i++)
			printf("%d ",a[i]);
	printf("\n ");
}
*/

/*1、排除所有0元素,如 2 0 0 3 1 0 0 4 —> 2 3 1 4 */
void removeZero(SqList* SL) {
	for (int i = 0; i < SL->length; i++) {
		if (SL->data[i] == '0') {
			for (int j = i; j < SL->length; j++) {
				SL->data[j] = SL->data[j + 1];
				i--;
			}
		}
	}
}


/*2、三个基本排序算法：冒泡、插入、选择，如 1 3 2 4 6 5 7 9 8  —> 1 2 3 4 5 6 7 8 9*/
void range(SqList* SL) {
	int i, j, temp, flag;
	char ch;

	printf("\nChoose the sorting method:(a.bubble sort\tb.selection sort\tc.insertion sort)\n");
	scanf("%c", &ch);
	while (ch != 'a' && ch != 'b' && ch != 'c') {
		printf("Please re-enter the right char.(a.bubble sort\tb.selection sort\tc.insertion sort)\n");
		getchar();
		scanf("%c", &ch);
	}

	if (ch == 'a') { //冒泡
		flag = 0;
		for (i = 0; i < SL->length - 1; i++) {
			for (j = i; j < SL->length - 1; j++) {
				if (SL->data[j] > SL->data[j + 1]) {
					temp = SL->data[j];
					SL->data[j] = SL->data[j + 1];
					SL->data[j + 1] = temp;
					flag = 1;
				}
			}
			if (flag == 0) break;
		}
	}
	else if (ch == 'b') { //选择
		for (i = 0; i < SL->length - 1; i++) {
			for (j = i + 1; j < SL->length; j++) {
				if (SL->data[i] > SL->data[j]) {
					temp = SL->data[j];
					SL->data[j] = SL->data[i];
					SL->data[i] = temp;
				}
			}
		}
	}
	else if (ch == 'c') { //插入
		ElemType* s = (ElemType*)malloc(sizeof(ElemType) * (SL->length));
		if (!s) exit(0);
		int i, j;
		for (i = 0; i < SL->length; i++) {
			j = i - 1;//最后一个元素位置
			while (j >= 0 && s[j] > SL->data[i]) {
				s[j + 1] = s[j];
				j--;
			}
			s[j + 1] = SL->data[i];
		}
		SL->data = s;
	}
}

/*3、模式匹配问题
a b a b c d
a b c 
—> Position : 2 */
/*暴力算法*/
int bruteForce(SqList* SL, ElemType* T) {
	int i = 0;//主串
	int j = 0;//模式串
	while (j < strlen(T) && i < SL->length) {
		if (SL->data[i] == T[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	if(j == strlen(T)){
		return i - j;
	}
	else {
		return 0;
	}
}
/*KMP算法*/
int KMP(SqList* SL, ElemType* T){
	int i = 0;//主串
	int j = 0;//模式串

	int* next = (int*)malloc(sizeof(int) * SL->length);
	if (!next) exit(0);

	getNext(SL,next);

	while (j < strlen(T) && i < SL->length) {
		if (SL->data[i] == T[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j == strlen(T)) {
		return i - j;
	}
	else {
		return 0;
	}
}
/*next 数组创建*/
void getNext(SqList* SL, int* next) {
	int i = 1;//指向后缀
	int j = 0;//指向前缀

	next[0] = 0;
	while(i < SL->length) {
		while (j == 0 && SL->data[i] != SL->data[j] && i < SL->length) {
			next[i] = 0;
			i++;
		}
		if (j == 0 && SL->data[i] == SL->data[j]) {
			next[i] = 0;
		}

		if (SL->data[i] == SL->data[j]) {
			++i;
			++j;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}


//int main(void) {
//	int n ;
//	SqList* SL = SL_create();
//	ElemType T[MAXSIZE] = {'a','b','c','\0'};
//	n = KMP(SL, T);
//	printf("%d\n", n);
//
//	//SL_traverse(SL);
//}
