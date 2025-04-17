#include<stdio.h>
#include<stdlib.h>
/*一块板上插着三根针。其中一根针上从下到上穿好了由大到小的64片金片，这
就是所谓的汉诺塔。一次只移动一片，小片必须在大片上面，问移动过程。*/

void move(int n, char x, char y, char z);//将 n 片从 x 借助 y 移动到 z (y也可不定义)
//int main(void) {
//	int n;
//	printf("输入金片个数:\n");
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