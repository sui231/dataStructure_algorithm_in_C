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
//	int i;//����
//	char str[10];
//	double d,d1;//�м�ֵ
//
//	InitStack(&s);
//
//	i = 0;
//	printf("�밴�沨�����ʽ�������������,�����������֮���ÿո����,����enter����\n");
//	
//
//	scanf("%c", &c);
//	while (c != '\n') {
//		//����
//		while ((c >= '0' && c <= '9') || c == '.') {
//			str[i++] = c;
//			//str[i] = '\n';���ں������
//			if (i == 10) {
//				printf("����̫��\n");
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
//		//����
//		switch (c) {
//		case '+':
//			Pop(&s, &d);
//			Pop(&s, &d1);
//			Push(&s, d + d1);
//			break;
//		case'-':
//			Pop(&s, &d);
//			Pop(&s, &d1);
//			Push(&s, d1 - d);//ע��˳��
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
//				printf("��������Ϊ0\n");
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