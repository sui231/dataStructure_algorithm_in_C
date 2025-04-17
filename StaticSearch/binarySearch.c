#include"search1.h"

// 二分搜索，从小到大
int binarySearch(SSTable ST, KeyType key) {
	int left = 1, right = ST.length, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (LT(ST.elem[mid].key, key))
			left = mid + 1;
		else if (GT(ST.elem[mid].key, key))
			right = mid - 1;
		else
			return mid;
	}
	return 0;
}

int mid;
int binarySearch1(SSTable ST, KeyType key,int left, int right) {
	mid = (left + right) / 2;
	if (LT(ST.elem[mid].key, key))
		return binarySearch1(ST, key, mid, right);
	else if (GT(ST.elem[mid].key, key))
		right = mid - 1;
	else
		return mid;
}