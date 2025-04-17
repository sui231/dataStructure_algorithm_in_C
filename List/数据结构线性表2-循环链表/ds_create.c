
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
            // �����ڴ����ʧ�ܵ����  
            // ��Ҫ�ͷ�֮ǰ��������нڵ��ڴ�  
            while (temp != NULL && temp != *head) {
                node* next_node = temp->next;
                free(temp);
                temp = next_node;
            }
            return -1; // ���� -1 ��ʾ����״̬  
        }
        current->data = rand();
        current->next = NULL; // ��ʱ����Ϊ NULL���Ժ���γ�ѭ��  

        if (prev != NULL) {
            prev->next = current;
        }
        else {
            *head = current; // ��һ���ڵ�  
        }
        prev = current;
    }

    // ���һ���ڵ�� next ָ���һ���ڵ㣬�γ�ѭ��  
    prev->next = *head;

    return 1;
}