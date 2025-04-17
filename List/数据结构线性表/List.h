#ifndef LIST_H
#define LIST_H

#define LIST_INT_SIZE 100
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define NULL 0
#define MAXSIZE 1000
#define OK	1
#define ERROR 0

typedef int Status;//函数类型，返回状态
typedef int ElemType;//元素数据类型


//单向顺序线性表定义
typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SqList;


//链表结点及其指针定义
typedef struct Node {
	ElemType data;			//数据域
	struct Node* next;		//指针域
}Node;						//节点结构体
typedef struct Node* LinkList;//
//节点结构体指针
//需要更改指针时，传参Node**型，即LinkList*型



#endif