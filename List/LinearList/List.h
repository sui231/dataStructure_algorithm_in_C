#ifndef LIST_H
#define LIST_H

#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define MAXSIZE 1000

typedef int Status;
typedef int ElemType;

//À≥–Ú±ÌSL
typedef struct SqList {
	ElemType data[MAXSIZE];
	int length;
}SqList;


//æ≤Ã¨¡¥±ÌSSL
typedef struct StaticLinkList {
	ElemType data;
	int cur;
}Component,* StaticLinkList;//StaticLinkList[MAXSIZE]


//¡¥±ÌLL
typedef struct LinkList {
	ElemType data;
	struct LinkList* next;
}node;


//SL
SqList* SL_create(int n);
Status SL_insert(SqList* SL, int i, ElemType e);
Status SL_delete(SqList* SL, int i, ElemType* e);
Status SL_traverse(SqList* SL);
//LL  CLL
node* LL_head_create(int n);
node* LL_tail_create(int n);
node* CirLL_create(int n);
void LL_CLL_traverse(node* pNode);
Status LL_CLL_insert(node** L, int i, ElemType e);
Status LL_CLL_delete(node** L, int i, ElemType* e);
//SLL
struct StaticLinkList* SLL_create(int n);
void SLL_traverse(StaticLinkList* L);
Status SLL_insert(StaticLinkList* L, int i, ElemType e);
Status SLL_delete(StaticLinkList* L, int i, ElemType* e);


#endif