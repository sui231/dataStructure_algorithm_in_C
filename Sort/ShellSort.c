#include"Sort.h"


// ���ȶ�
// dataΪ��������
// dlta[k] �������л��ʣ��ݼ����������Ϊ1
void shellSort(SqList* list, int dlta[], int t) {
	for (int k = 0; k < t; ++k) {
		shellInsert(list, dlta[k]);
	}
}

void shellInsert(SqList* list, int dk) {
	// list->r[0]Ϊ�ݴ�ڵ�
	int i, j;
	for (i = dk + 1; i < list->length; ++i) {
		if (list->r[i].key < list->r[i - dk].key) {
			list->r[0] = list->r[i];
			for (j = i - dk; j > 0 && (list->r[0].key < list->r[j].key); j -= dk)
				list->r[j + dk] = list->r[j];
			list->r[j] = list->r[0];
		}
	}
}