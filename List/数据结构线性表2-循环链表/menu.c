/*·µ»Ø±àºÅ*/
#include<stdio.h>
#include"CirLL.h"

int menu(void) {
	int select;
	printf("1.Traverse list");
	printf("2.Create list");
	printf("3.Leangth of list");
	printf("4.The midian of the list");
	printf("5.");
	printf("6.");
	printf("7.exit");
	printf("Choose the number:\n");
	scanf("%d", &select);

	int input_valid;
	do {
		printf("Input the value of node or input 0 to exit: ");
		input_valid = read_int_from_input(&select);
		if (!(input_valid && select < 1 && select > 7)) {
			printf("Invalid input. Please try again.\n");
    }
	} while (!(input_valid && select < 1 && select > 7));

	printf("\n");
	return select;
}