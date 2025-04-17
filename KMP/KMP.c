#include<stdio.h>

void get_next(char T[], int next[]) {
	int i, j;
	i = 1;			//后缀指针
	j = 0;			//前缀指针
	next[1] = 0;	//i=2,j=1,T[i]!=T[j]...
	while (i <= T[0]) {
		if (T[i] == T[j] || j == 0) {	//起始及next[j] = 1
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];//j回溯
	}
}

int KMP(char S[], char T[], int next[]) {
	int i = 1, j = 1;
	while (i <= S[0] && j <= T[0]) {
		if (S[i] == T[j] || j == 0) {
			++i;
			++j;
		}
		else
			j = next[j];//i不会减小
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}