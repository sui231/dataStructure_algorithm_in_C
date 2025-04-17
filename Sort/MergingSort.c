#include"Sort.h"

//归并排序（稳定）

// 将SR[i...m]与SR[m+1...n]归并为有序的TR[i...n]
void merge(RecordType* SR, RecordType* TR, int i, int m, int n) {
	int j, k;
	for (j = m + 1, k = i; i <= m && j <= n; k++) {
		if (SR[j].key <= SR[k].key)
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	} // for
	// 将剩余的元素拷贝到TR
	while (i <= m)
		TR[k++] = SR[i++];

	while (j <= n)
		TR[k++] = SR[j++];
}

// 递归，将无序的SR归并为有序的TR1, s，t为归并的始末位置
void MSort(RecordType* SR, RecordType* TR1, int s, int t) {
	if (s == t) {
		TR1[s] = SR[s]; // 递归结束
	}
	else {
		int m = (s + t) / 2;
		RecordType* TR2 = (RecordType*)malloc(sizeof(RecordType) * MAXSIZE); // 该次迭代的临数数组
		// 下一层的迭代归并
		MSort(SR, TR2, s, m);		// 递归将无序的SR前半部分归并为有序的TR2
		MSort(SR, TR2, m + 1, t);	// 后半部分归并
		// 该层的归并
		merge(TR2, TR1, s, m, t);	// 将TR2[s...m]与TR2[m + 1...t]归并为有序的TR1[s...t]，每一次迭代的核心
	}
}

void mergeSort(SqList* list) {
	MSort(list->r, list->r, 1, list->length);
}