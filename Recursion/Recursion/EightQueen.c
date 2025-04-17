/*在8X8格的国际象棋上摆放八个皇后，使其不能互相攻击，
即任意两个皇后都不能处于同一行、同一列或同一斜线上，
问有多少种摆法。*/
#include<stdio.h>
#include<stdlib.h>
#define N 8 

void EightQueen(int row, int(*chess)[N]);
int IfNotDanger(int row, int j, int(*chess)[N]);

int count，row;
count = 0;

int main(void) {
	int row;
	int chess[N][N] = { 0 };
	row = 0;

	EightQueen(row,chess);

	return 0;
}

// row			当前正在放置皇后的行号
// n			棋盘的大小
// chess		指向二维数组的指针，表示当前的棋盘状态
void EightQueen(int row, int(*chess)[N]) {
	int chess2[N][N], i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			chess2[i][j] = chess[i][j];
		}
	}//函数内临时空间

	if (row == N) {
		printf("第%d种:\n", ++count);
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				printf("%d ", *(*(chess2 + i) + j));
			}
			printf("\n");
		}
		printf("\n");
	}//打印情况
	else {
		for (j = 0; j < N; j++) {
			if (IfNotDanger(row, j, chess2)) {
				for (i = 0; i < N; i++) {
					*(*(chess2 + row) + i) = 0;
				}//初始化该行

				*(*(chess2 + row) + j) = 1;
				EightQueen(row + 1, chess2);//找下一行
			}
		}
	}
}

int IfNotDanger(int row, int j, int(*chess)[N]) {
	int i, k;
	//列上
	for (i = row - 1; i >= 0; i--) {
		if (*(*(chess + i) + j) != 0) {
			return 0;
		}
	}

	//左上
	for (i = row - 1, k = j - 1; i >= 0 && k >= 0; i--, k--) {
		if (*(*(chess + i) + k) != 0) {
			return 0;
		}
	}

	//右上
	for (i = row - 1, k = j + 1; i >= 0 && k < N; i--, k++) {
		if (*(*(chess + i) + k) != 0) {
			return 0;
		}
	}
	return 1;
}