/*中缀表达式 转 逆波兰表达式*/

// 数据输出，符号延后插入，数字通过符号链接
// 符号有 ( ) * / + -
// 中缀表达式从左往右运算顺序 正好符合 逆波兰表达式 对符号压栈后，打印数字，最后符号出栈的顺序（不考虑括号）
// 运算优先级考虑 + - 各种情况即可
// 注意括号在逆波兰表达式中的意义

#include<stdio.h>
#include<stdlib.h>
#include"practice.h"
#include<math.h>

int main(void) {
	sqStack s;//存符号
	char c, e;

	InitStack(&s);

	printf("输入中缀表达式:\n");
	scanf("%c", &c);
	while (c != '\n') {
		while (c >= '0' && c <= '9') {
			printf("%c", c);

			scanf("%c",&c);
			if (c < '0' || c > '9') {
				printf(" ");
			}	//多位数
		}	//数字直接输出


		if ('/' == c || '*' == c || '(' == c) {
				Push(&s, c);
		}	// 存于栈
			//'('在栈中意义为 括号内输出时取出终止的标志
		 
		else if (')' == c) {
			Pop(&s, &e);
			if ('(' != e) {
				printf("%c ", e);
				Pop(&s, &e);
			}
		}	//取出括号内的运算符号，匹配括号
		else if ('+' == c || '-' == c) {	//顺序最后，故需检查，存于括号上
			if (StackLen(s) == 0) {
				Push(&s, c);
			}	//空栈，即无乘除，最后运算，存
			else {
				do {
					Pop(&s, &e);
					if ('(' == e) {
						Pop(&s, &e);
					}	//括号内部最后运算，存
					else {
						printf("%c ", e);
					}	//乘除在前，优先输出
				} while (StackLen(s) != 0 && '(' != c);		//注意空栈的检查及'('的再次检查
				Push(&s, c);	//空栈或'('上
			}
		}
		else if ('\n' == c) {
			break;
		}
		else {
			printf("\n输入错误\n");
			return -1;
		}
		scanf("%c", &c);
	}

	while (StackLen(s) != 0) {
		Pop(&s, &e);
		printf("%c ", e);
	}//输出剩余符号

	return 0;
}
/*Run-Time Check Failure #2 - Stack around the variable 'e' was corrupted.*/
/*一般情况下，第一反应就是堆栈溢出、内存访问越界 …没错，这是第一个解决方案
【解决方案】如果提示中的变量是指针类型变量，则大概率的就是数组访问越界，需要反复检查数组下标访问的合法性


如果提示中的变量并不是指针，而是普通局部变量，在检查代码逻辑无误后，此时问题的解决方案如下（具体出错原因不太清楚，我认为是VS编译器的优化问题）
【解决方案】：
方法一：可以将该局部变量设置为全局变量即可
方法二：可以在“ 项目 ---- 属性 ---- 配置属性 ---- C/C++ ---- 代码生成 ---- 基本运行时检查：”设置为默认值，点击应用，确定后即可*/

/*https://www.cnblogs.com/cyds/p/15640768.html*/
