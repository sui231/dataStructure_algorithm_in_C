#include<stdio.h>
int read_int_from_input(int* value) {
    int result = scanf("%d", value);
    if (result != 1) {
        // 清除输入缓冲区中的错误输入  
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return 0; // 输入无效  

        // 如果有必要，可以进一步重置scanf的状态  
        // clearerr(stdin); 
    }
    return 1; // 输入有效  
}
//int input_valid;
//do {
//    printf("Input the value of node or input 0 to exit: ");
//    input_valid = read_int_from_input(&item);
//    if (!input_valid) {
//        printf("Invalid input. Please try again.\n");
//    }
//} while (!input_valid);