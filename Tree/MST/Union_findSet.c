#include <stdio.h>
#include <stdlib.h>

struct _subset {
    int parent;
    int rank;
};

// 查找带路径压缩的集合的根节点
/*当查找一个元素的根元素时，路径压缩会将查找路径上的所有节点直接连接到根元素，从而减少将来该路径上的查找时间。*/
int find(struct _subset subsets[], int i) {
    // 路径压缩
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent); 
    return subsets[i].parent;
}


// 按秩合并两个集合
/*按秩合并是指在合并两个集合时，总是将较小的树的根指向较大的树的根。这里的“秩”通常指的是树的高度或大小。
这种策略可以防止树结构变得过高，从而保持操作的效率。*/
void Union(struct _subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    // 按秩合并
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


//使用示例
int main() {
    int n = 5;  // 假设有5个元素
    struct _subset* subsets = (struct _subset*)malloc(n * sizeof(struct _subset));

    // 初始化并查集
    for (int i = 0; i < n; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // 执行一些合并操作
    Union(subsets, 0, 2);
    Union(subsets, 4, 2);
    Union(subsets, 3, 1);

    // 查找并打印每个元素的根节点
    for (int i = 0; i < n; ++i) {
        printf("Element %d -> root %d\n", i, find(subsets, i));
    }

    // 清理资源
    free(subsets);
    return 0;
}