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

int ifVisitedList[MAX_VERTEX_NUM] = { 0 }; // ȫ�ֱ���
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
/* �ڽӾ����ȱ��� */

void BFS(AMGraph G) {
	int i, j, k;
	Queue Q;
	//��ʼ��
	for (i = 0; i < G.vexNum; i++)
		ifVisitedList1[i] = FALSE;
	InitQueue(&Q);

	for (i = 0; i < G.vexNum; i++) {										//���η��ʽڵ�
		if (!ifVisitedList1[i]) {		//δ�����ýڵ�=
			ifVisitedList1[i] = TRUE;
			EnQueue(&Q, i);		//���� �ڵ�����ı��

			while (!IsEmpty(Q)) {	//���зǿ�
				k = DeQueue(&Q);	//ȡ��									//���ʸýڵ�������ڽӽڵ�
				printf("%c\n", G.vexs[k]);
				for (j = 0; j < G.vexNum; j++) {
					if (G.arcs[k][j] != INFINITY && !ifVisitedList1[j]) { //�ҵ�iδ���ʵ��ڽӵ�j// G.arcs[k][j] != 0 ***** G.arcnum[k][j] != INFINITY
						printf("enqueue:%c-->%c %d\n", G.vexs[k],G.vexs[j], G.arcs[k][j]);
						ifVisitedList1[j] = TRUE;
						EnQueue(&Q, j);//��������õ�δ���ʵ��ڽӵ�			//���ö��к� whileѭ������ �ڽӽڵ���ڽӽڵ�
					}														//��������ֱ������
				}
			}
		}
	}
}