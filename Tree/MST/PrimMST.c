#include <stdio.h>
#include <limits.h>

#define V 5  // 定义顶点的数量

// 现有MST外的最小key
int minKey(int key[], int mstSet[]) {
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (mstSet[v] == 0 && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
}

void printMST(int parent[], int graph[V][V]) {
	printf("Edge   Weight\n");
	for (int i = 1; i < V; i++)
		printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V]) {
	int key[V];    // 下标节点连接的最小边权重
	// (MST内的key不用管，key是MST新增节点连接时更新，未被连接时为INT_MAX)
	int parent[V]; // 下标对应父节点，与next对应，不再更改后构建为MST
	int mstSet[V]; // 表示已经包括在MST中的顶点集

	// 初始化 key，mstSet
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = 0;

	// 从第一个顶点开始
	key[0] = 0;
	parent[0] = -1; // 第一个顶点总是MST的根

	for (int count = 0; count < V - 1; count++) {
		int u = minKey(key, mstSet);
		mstSet[u] = 1;
		// 更新与新增节点相连节点的 key，parent
		for (int v = 0; v < V; v++)
			if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
	printMST(parent, graph);
}


//int main() {
//	int graph[V][V] = {
//		{0, 2, 0, 0, 0},
//		{2, 0, 6, 3, 2},
//		{0, 6, 0, 5, 0},
//		{0, 3, 5, 0, 0},
//		{0, 2, 0, 0, 0}
//	};
//
//
//	primMST(graph);
//
//	return 0;
//}