//#include<stdio.h>
//#include<stdlib.h>
//#include"practice.h"
//#include<math.h>
//
//-typedef char ElemType;
//
//int main(void) {
//	sqStack s;
//	ElemType c;
//	int len, i, sum;
//
//	InitStack(&s);
//
//	printf("Input number(0/1) and ended with enter.\n");
//	scanf("%c", &c);
//	while (c != '\n') {
//		Push(&s, c);
//		scanf("%c", &c);
//	}
//
//	len = s.top - s.base;
//	sum = 0;
//	for (i = 0; i < len; i++) {
//		Pop(&s, &c);
//		sum += (c - 48) * pow(2, i);//*²»ÒªÍü¼Ç
//	}
//	printf("%d", sum);
//	return 0;
//}