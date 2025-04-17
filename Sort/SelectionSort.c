#include"Sort.h"

// ≤ªŒ»∂®
void selectSort(SqList* list, int m, int n) {
	for (int i = m; i < n; i++) {
		for (int j = i; j <= n; j++) {
			if (list->r[j].key < list->r[i].key) {
				swap(&list->r[i], &list->r[j]);
			}
		}
	}
}