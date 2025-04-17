#include"Sort.h"

// ÎÈ¶¨µÄ
void bubbleSort(SqList* list, int m, int n) {
	int i, j, flag = 1;
	RecordType temp;
	for (i = n; i < m - 1 && flag; ++i) {
		flag = 0;
		for (j = 1; j <= n - i - 1; ++j) {
			flag = 1;
			if (list->r[j].key > list->r[j + 1].key) {
				swap(&list->r[j], &list->r[j + 1]);
			}
		}

	}
}

