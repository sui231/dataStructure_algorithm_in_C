#include<stdio.h>
#include<stdlib.h>
void print(void);

//�����ַ�����enter�������룬�������

//int main(void) {
//	printf("�����ַ�����enter�������룬�������\n");
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