#include"others.h"
char scanfChar(void) {
	char elem;
	scanf("%c", &elem);
	while (elem == ' ')
		scanf("%c", &elem);
	return elem;
}

int scanfNum(void) {
	int elem;
	scanf("%d", &elem);
	while (elem == ' ')
		scanf("%d", &elem);
	return elem;
}

int ifVisitedList[MAX_VERTEX_NUM] = { 0 }; // 全局变量
void DFS(AMGraph G, int v) {
	//v < G.vexnum
	ifVisitedList[v] = 1;
	printf("%c\n", G.vexs[v]);
	for (int w = 0; w < G.vexNum; w++) {
		if (ifVisitedList[w] == 0 && G.arcs[v][w] != INFINITY) { // G.arcs[v][w] != 0 ***** G.arcnum[v][w] != INFINITY
			printf("  %c-->%c %d\n", G.vexs[v], G.vexs[w], G.arcs[v][w]);
			DFS(G, w);
		}
	}
}

void printAMGragh(AMGraph G) {
	printf("\t");
	for (int i = 0; i < G.vexNum; i++) {
		printf("%c\t", G.vexs[i]);
	}
	printf("\n");
	for (int i = 0; i < G.vexNum; i++) {
		printf("%c\t", G.vexs[i]);
		for (int j = 0; j < G.vexNum; j++) {
			if (G.arcs[i][j] == INFINITY) {
				printf("MAX\t");
			}
			else {
				printf("%d\t", G.arcs[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

int ifVisitedList1[MAX_VERTEX_NUM];
/* 邻接矩阵广度遍历 */

void BFS(AMGraph G) {
	int i, j, k;
	Queue Q;
	//初始化
	for (i = 0; i < G.vexNum; i++)
		ifVisitedList1[i] = FALSE;
	InitQueue(&Q);

	for (i = 0; i < G.vexNum; i++) {										//依次访问节点
		if (!ifVisitedList1[i]) {		//未遍历该节点=
			ifVisitedList1[i] = TRUE;
			EnQueue(&Q, i);		//存入 节点数组的编号

			while (!IsEmpty(Q)) {	//队列非空
				k = DeQueue(&Q);	//取出									//访问该节点的所有邻接节点
				printf("%c\n", G.vexs[k]);
				for (j = 0; j < G.vexNum; j++) {
					if (G.arcs[k][j] != INFINITY && !ifVisitedList1[j]) { //找到i未访问的邻接点j// G.arcs[k][j] != 0 ***** G.arcnum[k][j] != INFINITY
						printf("enqueue:%c-->%c %d\n", G.vexs[k],G.vexs[j], G.arcs[k][j]);
						ifVisitedList1[j] = TRUE;
						EnQueue(&Q, j);//继续存入该点未访问的邻接点			//利用队列和 while循环访问 邻接节点的邻接节点
					}														//不断深入直至结束
				}
			}
		}
	}
}