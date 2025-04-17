#include"search1.h"

void printSSTable(SSTable ST) {
	printf("key:\n");
	for (int i = 1; i <= ST.length; i++) {
		printf("%d\t", ST.elem[i].key);
	}
	printf("\n");
}

int main(void) {
	SSTable ST;
	ST.length = 10;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * (ST.length + 1));
	srand(time(0));
	int r = rand() % 100 + 1;

	for (int i = 0; i <= ST.length; i++) {
		ST.elem[i].key = i;
	}

	printSSTable(ST);
	
	printf("%d\n", sequentialSearch(ST, 6));
	printf("%d\n", binarySearch(ST, 6));
	printf("%d\n", binarySearch1(ST, 6, 1, ST.length));

	return 0;
}