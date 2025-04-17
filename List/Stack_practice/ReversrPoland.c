//#include<stdio.h>
//#include<stdlib.h>
//#include"practice.h"
//#include<math.h>
//#include<ctype.h>
//
////-typedef int ElemType;
//
//int main(void) {
//	sqStack s;
//	char c;
//	int i;//计数
//	char str[10];
//	double d,d1;//中间值
//
//	InitStack(&s);
//
//	i = 0;
//	printf("请按逆波兰表达式输入待计算数据,数据与运算符之间用空格隔开,输入enter结束\n");
//	
//
//	scanf("%c", &c);
//	while (c != '\n') {
//		//数据
//		while ((c >= '0' && c <= '9') || c == '.') {
//			str[i++] = c;
//			//str[i] = '\n';可在后面添加
//			if (i == 10) {
//				printf("数据太长\n");
//				return;
//			}
//			scanf("%c", &c);
//			if (c == ' ') {
//				str[i] = '\0';
//				d = atof(str);
//				Push(&s, d);
//				i = 0;
//				break;
//			}
//		}
//		//符号
//		switch (c) {
//		case '+':
//			Pop(&s, &d);
//			Pop(&s, &d1);
//			Push(&s, d + d1);
//			break;
//		case'-':
//			Pop(&s, &d);
//			Pop(&s, &d1);
//			Push(&s, d1 - d);//注意顺序
//			break;
//		case'*':
//			Pop(&s, &d);
//			Pop(&s, &d1);
//			Push(&s, d * d1);
//			break;
//		case'/':
//			Pop(&s, &d);
//			Pop(&s, &d1);
//			if (d1 == 0) {
//				printf("除数不能为0\n");
//				return -1;
//			}
//			Push(&s, d1 / d);
//			break;
//		}
//		scanf("%c", &c);
//	}
//
//	Pop(&s, &d);
//	printf("%.4lf", d);
//
//	return 0;
//}