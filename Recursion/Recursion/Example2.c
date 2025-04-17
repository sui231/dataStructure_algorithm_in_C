#include<stdio.h>
#include<stdlib.h>
void print(void);

//数入字符串，enter结束输入，倒序输出

//int main(void) {
//	printf("数入字符串，enter结束输入，倒序输出\n");
//	print();
//	return 0;
//}

void print(void) {
	char ch;
	scanf("%c", &ch);

	if (ch == '\n')
		return;
	if (ch != '\n')
		print();

	printf("%c", ch);
}