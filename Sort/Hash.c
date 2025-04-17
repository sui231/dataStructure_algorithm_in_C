#include"Sort.h"

// 开放定址哈希表
int hashSize[] = { 7,11,13,17,19 }; // 哈希表容量递增表，一个合适的素数序列
typedef struct {
	ElemType* elem;
	int count; // 数据元素个数
	int sizeIndex; // hashSize[]容量
}HashTable;

#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1

int hash(KeyType key) {
	//return key;
	return 5 * key + 6;
	return key % 13; // 7 <= count
}


// *p 为插入位置
// *c 为冲突次数
Status searchHash(HashTable H, KeyType key, int* p, int* c) {
	*p = hash(key); // 获得哈希地址
	*c = 0;
	while (H.elem[*p].key != key && H.elem[*p].key != NULL_KEY) {
		(*c)++;
		*p = collision(*p, *c); // 寻找下一个地址
	}
	if (H.elem[*p].key == key)
		return SUCCESS;
	else
		return UNSUCCESS;
}

Status insertHash(HashTable* H, ElemType elem) {
	int c;
	int p;
	if (searchHash(*H, elem.key, &p, &c)) // 已存在
		return DUPLICATE;

	if (c < H->sizeIndex / 2) { // c 未到达上限（可调节）
		H->elem[p] = elem;
		H->count++;
		return SUCCESS;
	}
	else {
		recreateHashTable(H);
		return UNSUCCESS;
	}
}