typedef char* SString;//SString[0]存储长度

int Index(SString S, SString T) {
	int i = 1, j = 1; // 主串S，模式串T的下标指示器
	while (i <= S[0] && j <= T[0]) {
		if (S[i] == T[j]) {
			++i;
			++j;
		}
		else {
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}