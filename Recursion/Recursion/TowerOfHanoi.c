#include<stdio.h>
#include<stdlib.h>
/*һ����ϲ��������롣����һ�����ϴ��µ��ϴ������ɴ�С��64Ƭ��Ƭ����
������ν�ĺ�ŵ����һ��ֻ�ƶ�һƬ��СƬ�����ڴ�Ƭ���棬���ƶ����̡�*/

void move(int n, char x, char y, char z);//�� n Ƭ�� x ���� y �ƶ��� z (yҲ�ɲ�����)
//int main(void) {
//	int n;
//	printf("�����Ƭ����:\n");
//	scanf("%d", &n);
//	move(n, 'x', 'y', 'z');
//	return 0;
//}

void move(int n, char x, char y, char z) {
	if (n <= 0)
		return;
	if (n == 1) {
		printf("%c --> %c\n", x, z);
		return;
	}

	move(n - 1, x, z, y);
	printf("%c --> %c\n", x, z);
	move(n - 1, y, x, z);
}