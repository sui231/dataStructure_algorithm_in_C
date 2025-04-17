#include<stdio.h>
#include<stdlib.h>
int Factorial(int n);
int FibonacciSequence(int n);

//int main(void) {
//	printf("%d  ", Factorial(4));
//}

int Factorial(int n) {
	if (n == 0)
		return 1;
	return Factorial(n - 1) * n;
}
int FibonacciSequence(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return FibonacciSequence(n - 1) + FibonacciSequence(n - 2);
}
