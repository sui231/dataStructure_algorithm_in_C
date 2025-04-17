#include"Sort.h"

// ���Ŷ�ַ��ϣ��
int hashSize[] = { 7,11,13,17,19 }; // ��ϣ������������һ�����ʵ���������
typedef struct {
	ElemType* elem;
	int count; // ����Ԫ�ظ���
	int sizeIndex; // hashSize[]����
}HashTable;

#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1

int hash(KeyType key) {
	//return key;
	return 5 * key + 6;
	return key % 13; // 7 <= count
}


// *p Ϊ����λ��
// *c Ϊ��ͻ����
Status searchHash(HashTable H, KeyType key, int* p, int* c) {
	*p = hash(key); // ��ù�ϣ��ַ
	*c = 0;
	while (H.elem[*p].key != key && H.elem[*p].key != NULL_KEY) {
		(*c)++;
		*p = collision(*p, *c); // Ѱ����һ����ַ
	}
	if (H.elem[*p].key == key)
		return SUCCESS;
	else
		return UNSUCCESS;
}

Status insertHash(HashTable* H, ElemType elem) {
	int c;
	int p;
	if (searchHash(*H, elem.key, &p, &c)) // �Ѵ���
		return DUPLICATE;

	if (c < H->sizeIndex / 2) { // c δ�������ޣ��ɵ��ڣ�
		H->elem[p] = elem;
		H->count++;
		return SUCCESS;
	}
	else {
		recreateHashTable(H);
		return UNSUCCESS;
	}
}