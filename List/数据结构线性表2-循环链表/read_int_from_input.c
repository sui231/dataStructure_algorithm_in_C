#include<stdio.h>
int read_int_from_input(int* value) {
    int result = scanf("%d", value);
    if (result != 1) {
        // ������뻺�����еĴ�������  
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return 0; // ������Ч  

        // ����б�Ҫ�����Խ�һ������scanf��״̬  
        // clearerr(stdin); 
    }
    return 1; // ������Ч  
}
//int input_valid;
//do {
//    printf("Input the value of node or input 0 to exit: ");
//    input_valid = read_int_from_input(&item);
//    if (!input_valid) {
//        printf("Invalid input. Please try again.\n");
//    }
//} while (!input_valid);