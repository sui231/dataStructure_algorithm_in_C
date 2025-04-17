#include"Sort.h"

// straight inertion sort
void inertSort1(SqList* list) {
	int i, j;
	for (i = 2; i < list->length; i++) { // 从第二个开始
		list->r[0] = list->r[i]; // 暂存
		for (j = i - 1;/* j > 0 && */LT(list->r[i].key, list->r[j].key); j--) {
			list->r[j + 1] = list->r[j];
		}
		list->r[j + 1] = list->r[0];
	}
}


void inertSort(SqList* list) {
	int i, j;
	for (i = 2; i < list->length; i++) { // 从第二个开始
		if (LT(list->r[i].key, list->r[i - 1].key)) { // 先找到插入位置，相对于上一个减少了不必要的比较和赋值
			list->r[0] = list->r[i]; // 暂存
			list->r[i] = list->r[i - 1]; // 移动当前比较过的元素

			for (j = i - 2; /*j > 0 && */LT(list->r[0].key, list->r[j].key); j--) { // 从 i-2 开始， j > 0 && 不需要
				list->r[j + 1] = list->r[j];
			}
			list->r[j + 1] = list->r[0];
		} // if
	}
}

// Binary insertion sort，此方法为稳定的插入排序
void binaryInsertSort(SqList* list) {
	int i, j, left, right, mid;
	for (i = 2; i < list->length; i++) {
		list->r[0] = list->r[i]; // 暂存

		// 通过折半查找找到插入点
		left = 1;
		right = i - 1;
		while (left <= right) {
			mid = (left + right) / 2;
			if (LT(list->r[0].key, list->r[mid].key)) //小于中间值
				right = mid - 1;
			else // 大于中间值，等于中间值会经此退出循环
				left = mid + 1;
		}

		for (j = i - 1; j >= right + 1; j--) // 从 i-1 开始，一直到 right+1(或者left)后移
			list->r[j + 1] = list->r[j];

		list->r[right + 1] = list->r[0];
	}
}