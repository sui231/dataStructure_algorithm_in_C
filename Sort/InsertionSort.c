#include"Sort.h"

// straight inertion sort
void inertSort1(SqList* list) {
	int i, j;
	for (i = 2; i < list->length; i++) { // �ӵڶ�����ʼ
		list->r[0] = list->r[i]; // �ݴ�
		for (j = i - 1;/* j > 0 && */LT(list->r[i].key, list->r[j].key); j--) {
			list->r[j + 1] = list->r[j];
		}
		list->r[j + 1] = list->r[0];
	}
}


void inertSort(SqList* list) {
	int i, j;
	for (i = 2; i < list->length; i++) { // �ӵڶ�����ʼ
		if (LT(list->r[i].key, list->r[i - 1].key)) { // ���ҵ�����λ�ã��������һ�������˲���Ҫ�ıȽϺ͸�ֵ
			list->r[0] = list->r[i]; // �ݴ�
			list->r[i] = list->r[i - 1]; // �ƶ���ǰ�ȽϹ���Ԫ��

			for (j = i - 2; /*j > 0 && */LT(list->r[0].key, list->r[j].key); j--) { // �� i-2 ��ʼ�� j > 0 && ����Ҫ
				list->r[j + 1] = list->r[j];
			}
			list->r[j + 1] = list->r[0];
		} // if
	}
}

// Binary insertion sort���˷���Ϊ�ȶ��Ĳ�������
void binaryInsertSort(SqList* list) {
	int i, j, left, right, mid;
	for (i = 2; i < list->length; i++) {
		list->r[0] = list->r[i]; // �ݴ�

		// ͨ���۰�����ҵ������
		left = 1;
		right = i - 1;
		while (left <= right) {
			mid = (left + right) / 2;
			if (LT(list->r[0].key, list->r[mid].key)) //С���м�ֵ
				right = mid - 1;
			else // �����м�ֵ�������м�ֵ�ᾭ���˳�ѭ��
				left = mid + 1;
		}

		for (j = i - 1; j >= right + 1; j--) // �� i-1 ��ʼ��һֱ�� right+1(����left)����
			list->r[j + 1] = list->r[j];

		list->r[right + 1] = list->r[0];
	}
}