#include"search1.h"

int sequentialSearch(SSTable ST, KeyType key) {
	int i;
	ST.elem[0].key = key; // �ڱ�
	for (i = ST.length; !EQ(ST.elem[i].key, key) ; --i);
	return i; // δ�ҵ���Ϊ0
}