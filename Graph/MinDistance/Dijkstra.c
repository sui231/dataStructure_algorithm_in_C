#include <stdio.h>
#include <limits.h>

#define V 5

// �ҵ�dist����С�Ķ���
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

// src Ϊ��ʼ��
void dijkstra(int graph[V][V], int src) {
	int dist[V];     // �洢����ʼ�㵽�������̾���
	int visited[V];  // ��¼�����Ƿ��Ѿ�������

	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
		visited[i] = 0;
	}// ��ʼ��

	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, visited);

		visited[u] = 1;

		for (int v = 0; v < V; v++) {
			if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
			// δ���ʣ�����ʼ�㣬��Ϊ��Чֵ��dist[u] + weight(u, v)С������dist[v]
				dist[v] = dist[u] + graph[u][v]; //����
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
Dijkstra �㷨�ĺ���˼����ͨ����ȷ����Դ�㵽ͼ�и���������·�����ȡ�
1. ̰�Ĳ���
Dijkstra �㷨ʹ��̰�Ĳ��ԣ�Greedy Approach����ÿ��ѡ�����Դ�������δ���ʶ��㡣
ѡ����̾��붥�㱣֤��ÿ�μ���͸��¶��ǻ��ڵ�ǰ��֪�����·����

2. ���ȼ�����
Ϊ�˸�Ч���ҵ�ÿ�ε�������С�� dist[] ֵ��ͨ��ʹ�����ȼ����У���С�ѣ���ʵ�֡�
���������ڶ���ʱ���ڻ�ȡ�͸�����̾���Ķ��㣬��������㷨��Ч�ʡ�

3. �𲽸���
��Դ�㿪ʼ����ͨ��ÿ������Ķ���������ڽӶ���ľ��롣
���ͨ����ǰ���㵽��ĳ���ڽӶ����·������֪��·�����̣�������Ǹ��ڽӶ�������·��ֵ��

4. �ɳڲ���
��һ�����漰���¶�������ġ��ɳڣ�Relaxation�������̡�
������˵������ÿһ���ӵ�ǰ���� u ��ĳ�ڽӶ��� v �ı� (u, v)���㷨����Ƿ����һ�����̵�·������ v��
����ͨ���Ƚ� dist[v] �� dist[u] + weight(u, v) ����ɵġ�������߸�С���͸��� dist[v]��

5. ȷ�����ж�������·��
�㷨�ظ��������̣�ֱ��ͼ�����еĶ��㶼�����ʹ�����������Դ�㵽ÿһ����������·�������ҵ������洢�� dist[] �����С�
*/