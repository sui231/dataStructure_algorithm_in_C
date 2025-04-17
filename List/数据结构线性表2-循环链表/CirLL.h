#ifndef CirLL_H
#define CirLL_H

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define NULL 0
#define MAXSIZE 1000

typedef int Status;

typedef int ElemType;
typedef struct CLinList{
	ElemType data;
	struct CLinlList* next;
}node;//


int read_int_from_input(int* value);
void ds_init(node** pNode);
void ds_insert(node** pNode, int i);
void ds_delete(node** pNode, int i);
int ds_search(node* pNode, int elem);
void ds_traverse(node* pNode);
int menu(void);

#endif