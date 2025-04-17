/*
- ��̤�������� (�ֳ���ʿ���λ���ʿ��������)
- �������������Ϊ8*8�ķ������̣��ֽ�������������ָ���ķ����У�
���ա�������Ĺ��򽫡��������ƶ���Ҫ��ÿ������ֻ�ܽ���һ�Σ�
����ʹ�á����߱�����64������
- ������ n * n �������ϣ��� n >= 5 ��Ϊż����ʱ������������㶼�н⡣
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


//��һ�� tag+1
int TravelChessBoard(int x, int y, int tag) {

	chess[x][y] = tag; // ��ǵ�ǰλ���ѱ�ռ�� 

	if (tag == X * Y) { // ����λ�ö���ռ�� ,�ݹ����  
		print(); 
		return 1;
	} 

	for (int count = 0; count < X; count++) { // �������п��ܵ��ƶ�  
		int x1 = x, y1 = y;
		if (xyNext(&x1, &y1, count)) { // ����ɹ��ƶ�  
			if (TravelChessBoard(x1, y1, tag + 1)) { // �ݹ鳢����һ��λ��  
				return 1; // ����ɹ�������1�������ݹ�  
			}
		}
	}
	chess[x][y] = 0; // ��ǰλ�������ƶ����ѳ��ԣ����ݣ����õ�ǰλ��

	return 0; // ����0�����������������ܵ����  
}


int main(void) {
	int i, j;
	clock_t start, finish;
	start = clock();

	for (i = 0; i <= X - 1; i++) {
		for (j = 0; j <= Y - 1; j++) {
			chess[i][j] = 0; // ��ʼ��
		}
	}

	if (TravelChessBoard(2, 0, 1) == 0) {
		printf("Unsucessful.\n");
	}

	finish = clock();
	printf("%lf second.\n\n", (double)(finish - start) / CLOCKS_PER_SEC);

	return 0;
}