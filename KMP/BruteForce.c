typedef char* SString;//SString[0]�洢����

int Index(SString S, SString T) {
	int i = 1, j = 1; // ����S��ģʽ��T���±�ָʾ��
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