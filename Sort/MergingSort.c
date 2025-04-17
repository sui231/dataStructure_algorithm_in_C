#include"Sort.h"

//�鲢�����ȶ���

// ��SR[i...m]��SR[m+1...n]�鲢Ϊ�����TR[i...n]
void merge(RecordType* SR, RecordType* TR, int i, int m, int n) {
	int j, k;
	for (j = m + 1, k = i; i <= m && j <= n; k++) {
		if (SR[j].key <= SR[k].key)
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	} // for
	// ��ʣ���Ԫ�ؿ�����TR
	while (i <= m)
		TR[k++] = SR[i++];

	while (j <= n)
		TR[k++] = SR[j++];
}

// �ݹ飬�������SR�鲢Ϊ�����TR1, s��tΪ�鲢��ʼĩλ��
void MSort(RecordType* SR, RecordType* TR1, int s, int t) {
	if (s == t) {
		TR1[s] = SR[s]; // �ݹ����
	}
	else {
		int m = (s + t) / 2;
		RecordType* TR2 = (RecordType*)malloc(sizeof(RecordType) * MAXSIZE); // �ôε�������������
		// ��һ��ĵ����鲢
		MSort(SR, TR2, s, m);		// �ݹ齫�����SRǰ�벿�ֹ鲢Ϊ�����TR2
		MSort(SR, TR2, m + 1, t);	// ��벿�ֹ鲢
		// �ò�Ĺ鲢
		merge(TR2, TR1, s, m, t);	// ��TR2[s...m]��TR2[m + 1...t]�鲢Ϊ�����TR1[s...t]��ÿһ�ε����ĺ���
	}
}

void mergeSort(SqList* list) {
	MSort(list->r, list->r, 1, list->length);
}