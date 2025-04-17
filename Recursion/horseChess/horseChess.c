/*
- 马踏棋盘问题 (又称骑士周游或骑士漫游问题)
- 国际象棋的棋盘为8*8的方格棋盘，现将“马”放在任意指定的方格中，
按照“马”走棋的规则将“马”进行移动。要求每个方格只能进入一次，
最终使得“马”走遍棋盘64个方格。
- 对于在 n * n 的棋盘上，当 n >= 5 且为偶数的时候，以任意点作点都有解。
*/

#include<stdio.h>
#include<time.h>

#define X 8
#define Y 8
int chess[X][Y];

int xyNext(int* x, int* y, int count) {
	switch (count) {
	case 0:
		if (*x + 2 <= X - 1 && *y - 1 >= 0 && chess[*x + 2][*y - 1] == 0) {
			*x += 2;
			*y -= 1;
			return 1;
		}
		break;
	case 1:
		if (*x + 2 <= X - 1 && *y + 1 <= Y - 1 && chess[*x + 2][*y + 1] == 0) {
			*x += 2;
			*y += 1;
			return 1;
		}
		break;
	case 2:
		if (*x - 2 >= 0 && *y - 1 >= 0 && chess[*x - 2][*y - 1] == 0) {
			*x -= 2;
			*y -= 1;
			return 1;
		}
		break;
	case 3:
		if (*x - 2 >= 0 && *y + 1 <= Y - 1 && chess[*x - 2][*y + 1] == 0) {
			*x -= 2;
			*y += 1;
			return 1;
		}
		break;
	case 4:
		if (*x + 1 < X - 1 && *y - 2 >= 0 && chess[*x + 1][*y - 2] == 0) {
			*x += 1;
			*y -= 2;
			return 1;
		}
		break;
	case 5:
		if (*x + 1 <= X - 1 && *y + 2 <= Y - 1 && chess[*x + 1][*y + 2] == 0) {
			*x += 1;
			*y += 2;
			return 1;
		}
		break;
	case 6:
		if (*x - 1 >= 0 && *y - 2 >= 0 && chess[*x - 1][*y - 2] == 0) {
			*x -= 1;
			*y -= 2;
			return 1;
		}
		break;
	case 7:
		if (*x - 1 >= 0 && *y + 2 <= Y - 1 && chess[*x - 1][*y + 2] == 0) {
			*x -= 1;
			*y += 2;
			return 1;
		}
		break;
	default:
		printf("Error.\n");
		break;
	}
	return 0;
}


void print(void) {
	for (int i = 0; i <= X - 1; i++) {
		for (int j = 0; j <= Y - 1; j++) {
			printf("%4d", chess[i][j]);
		}
		printf("\n\n");
	}
	printf("\n");
}


//走一步 tag+1
int TravelChessBoard(int x, int y, int tag) {

	chess[x][y] = tag; // 标记当前位置已被占据 

	if (tag == X * Y) { // 所有位置都被占据 ,递归结束  
		print(); 
		return 1;
	} 

	for (int count = 0; count < X; count++) { // 尝试所有可能的移动  
		int x1 = x, y1 = y;
		if (xyNext(&x1, &y1, count)) { // 如果成功移动  
			if (TravelChessBoard(x1, y1, tag + 1)) { // 递归尝试下一个位置  
				return 1; // 如果成功，返回1并结束递归  
			}
		}
	}
	chess[x][y] = 0; // 当前位置所有移动都已尝试，回溯，重置当前位置

	return 0; // 返回0并继续尝试其他可能的情况  
}


int main(void) {
	int i, j;
	clock_t start, finish;
	start = clock();

	for (i = 0; i <= X - 1; i++) {
		for (j = 0; j <= Y - 1; j++) {
			chess[i][j] = 0; // 初始化
		}
	}

	if (TravelChessBoard(2, 0, 1) == 0) {
		printf("Unsucessful.\n");
	}

	finish = clock();
	printf("%lf second.\n\n", (double)(finish - start) / CLOCKS_PER_SEC);

	return 0;
}