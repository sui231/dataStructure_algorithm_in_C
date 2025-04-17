#include <stdio.h>
#include <stdlib.h>

struct _subset {
    int parent;
    int rank;
};

// ���Ҵ�·��ѹ���ļ��ϵĸ��ڵ�
/*������һ��Ԫ�صĸ�Ԫ��ʱ��·��ѹ���Ὣ����·���ϵ����нڵ�ֱ�����ӵ���Ԫ�أ��Ӷ����ٽ�����·���ϵĲ���ʱ�䡣*/
int find(struct _subset subsets[], int i) {
    // ·��ѹ��
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent); 
    return subsets[i].parent;
}


// ���Ⱥϲ���������
/*���Ⱥϲ���ָ�ںϲ���������ʱ�����ǽ���С�����ĸ�ָ��ϴ�����ĸ�������ġ��ȡ�ͨ��ָ�������ĸ߶Ȼ��С��
���ֲ��Կ��Է�ֹ���ṹ��ù��ߣ��Ӷ����ֲ�����Ч�ʡ�*/
void Union(struct _subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    // ���Ⱥϲ�
    if (xroot != yroot) {
        if (subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;
        else if (subsets[xroot].rank > subsets[yroot].rank)
            subsets[yroot].parent = xroot;
        else {
            subsets[xroot].parent = yroot;
            subsets[yroot].rank++;
        }
    }
}


//ʹ��ʾ��
int main() {
    int n = 5;  // ������5��Ԫ��
    struct _subset* subsets = (struct _subset*)malloc(n * sizeof(struct _subset));

    // ��ʼ�����鼯
    for (int i = 0; i < n; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // ִ��һЩ�ϲ�����
    Union(subsets, 0, 2);
    Union(subsets, 4, 2);
    Union(subsets, 3, 1);

    // ���Ҳ���ӡÿ��Ԫ�صĸ��ڵ�
    for (int i = 0; i < n; ++i) {
        printf("Element %d -> root %d\n", i, find(subsets, i));
    }

    // ������Դ
    free(subsets);
    return 0;
}