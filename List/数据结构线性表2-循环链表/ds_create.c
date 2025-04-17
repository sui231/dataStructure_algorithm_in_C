
#include"CirLL.h"
#define NUM 10

Status CreateCircularList(node** head) {
    node* current = NULL;
    node* prev = NULL;
    node* temp = *head;
    int i;

    srand(time(0));

    for (i = 1; i <= NUM; i++) {
        current = (node*)malloc(sizeof(node));
        if (current == NULL) {
            // 处理内存分配失败的情况  
            // 需要释放之前分配的所有节点内存  
            while (temp != NULL && temp != *head) {
                node* next_node = temp->next;
                free(temp);
                temp = next_node;
            }
            return -1; // 假设 -1 表示错误状态  
        }
        current->data = rand();
        current->next = NULL; // 临时设置为 NULL，稍后会形成循环  

        if (prev != NULL) {
            prev->next = current;
        }
        else {
            *head = current; // 第一个节点  
        }
        prev = current;
    }

    // 最后一个节点的 next 指向第一个节点，形成循环  
    prev->next = *head;

    return 1;
}