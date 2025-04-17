/*��8X8��Ĺ��������ϰڷŰ˸��ʺ�ʹ�䲻�ܻ��๥����
�����������ʺ󶼲��ܴ���ͬһ�С�ͬһ�л�ͬһб���ϣ�
���ж����ְڷ���*/
#include<stdio.h>
#include<stdlib.h>
#define N 8 

void EightQueen(int row, int(*chess)[N]);
int IfNotDanger(int row, int j, int(*chess)[N]);

int count��row;
count = 0;

int main(void) {
	int row;
	int chess[N][N] = { 0 };
	row = 0;

	EightQueen(row,chess);

	return 0;
}

// row			��ǰ���ڷ��ûʺ���к�
// n			���̵Ĵ�С
// chess		ָ���ά�����ָ�룬��ʾ��ǰ������״̬
void EightQueen(int row, int(*chess)[N]) {
	int chess2[N][N], i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			chess2[i][j] = chess[i][j];
		}
	}//��������ʱ�ռ�

	if (row == N) {
		printf("��%d��:\n", ++count);
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				printf("%d ", *(*(chess2 + i) + j));
			}
			printf("\n");
		}
		printf("\n");
	}//��ӡ���
	else {
		for (j = 0; j < N; j++) {
			if (IfNotDanger(row, j, chess2)) {
				for (i = 0; i < N; i++) {
					*(*(chess2 + row) + i) = 0;
				}//��ʼ������

				*(*(chess2 + row) + j) = 1;
				EightQueen(row + 1, chess2);//����һ��
			}
		}
	}
}

int IfNotDanger(int row, int j, int(*chess)[N]) {
	int i, k;
	//����
	for (i = row - 1; i >= 0; i--) {
		if (*(*(chess + i) + j) != 0) {
			return 0;
		}
	}

	//����
	for (i = row - 1, k = j - 1; i >= 0 && k >= 0; i--, k--) {
		if (*(*(chess + i) + k) != 0) {
			return 0;
		}
	}

	//����
	for (i = row - 1, k = j + 1; i >= 0 && k < N; i--, k++) {
		if (*(*(chess + i) + k) != 0) {
			return 0;
		}
	}
	return 1;
}