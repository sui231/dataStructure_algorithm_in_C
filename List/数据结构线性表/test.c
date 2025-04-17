#include<stdio.h>

#define LIST_INT_SIZE 100
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define NULL 0

typedef struct {
	int a;
}ElemType;
typedef struct{
	ElemType elem[LIST_INT_SIZE];
	int length;
}SqList;
//线性表定义


//例1:Pn(x)=p1 * x^e1 + ... + pn * x^en
#define MAXSIZE 100
typedef struct {
	float p;
	int e;
}Polynomial;
typedef struct {
	Polynomial *elem;
	int length;
}s1;
//例2
typedef struct {
	char no[20];
	char name[20];
	float price;
}Book;
typedef struct {
	Book *elem;
	int length;
}s2;


