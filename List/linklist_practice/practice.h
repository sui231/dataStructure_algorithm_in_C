#ifndef PRACTICE_H
#define PRACTICE_H

typedef struct LinkList {
	int data;
	struct LinkList* next;
}node;
node* LL_create(int n);
node* CirLL_create(int n);
int IsRing1(node* L);
int IsRing2(node* L);
node* LatinSquare(node* L);
node* CirLL_create1(int n);
void CLL_traverse(node* L);
void Magician(node* Head);
node* CirLL_create0(int n);


#endif 