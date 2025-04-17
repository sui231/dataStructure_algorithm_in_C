#include <stdio.h>
#include <limits.h>

#define V 5

// 找到dist中最小的顶点
int minDistance(int dist[], int visited[]) {
	int min = INT_MAX, minIndex;

	for (int v = 0; v < V; v++) {
		if (visited[v] == 0 && dist[v] <= min) {
			min = dist[v];
			minIndex = v;
		}
	}

	return minIndex;
}

void printSolution(int dist[]) {
	printf("vex   minDistance\n");
	for (int i = 0; i < V; i++)
		printf("%d \t %d\n", i, dist[i]);
}

// src 为起始点
void dijkstra(int graph[V][V], int src) {
	int dist[V];     // 存储从起始点到顶点的最短距离
	int visited[V];  // 记录顶点是否已经被访问

	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
		visited[i] = 0;
	}// 初始化

	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, visited);

		visited[u] = 1;

		for (int v = 0; v < V; v++) {
			if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
			// 未访问，非起始点，边为有效值，dist[u] + weight(u, v)小于现有dist[v]
				dist[v] = dist[u] + graph[u][v]; //更新
		}
	}

	printSolution(dist);
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
//	dijkstra(graph, 0);
//
//	return 0;
//}

/*
Dijkstra 算法的核心思想是通过逐步确定从源点到图中各顶点的最短路径长度。
1. 贪心策略
Dijkstra 算法使用贪心策略（Greedy Approach）来每次选择距离源点最近的未访问顶点。
选择最短距离顶点保证了每次计算和更新都是基于当前已知的最短路径。

2. 优先级队列
为了高效地找到每次迭代中最小的 dist[] 值，通常使用优先级队列（最小堆）来实现。
这样可以在对数时间内获取和更新最短距离的顶点，大幅提升算法的效率。

3. 逐步更新
从源点开始，逐步通过每个最近的顶点更新其邻接顶点的距离。
如果通过当前顶点到达某个邻接顶点的路径比已知的路径更短，则更新那个邻接顶点的最短路径值。

4. 松弛操作
这一步骤涉及更新顶点间距离的“松弛（Relaxation）”过程。
具体来说，对于每一个从当前顶点 u 到某邻接顶点 v 的边 (u, v)，算法检查是否存在一条更短的路径到达 v。
这是通过比较 dist[v] 和 dist[u] + weight(u, v) 来完成的。如果后者更小，就更新 dist[v]。

5. 确定所有顶点的最短路径
算法重复上述过程，直到图中所有的顶点都被访问过。这样，从源点到每一个顶点的最短路径都被找到，并存储在 dist[] 数组中。
*/