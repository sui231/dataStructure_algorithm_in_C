#include"Graph.h"

//无向网
Status createAMG(AMGraph* G) {
	//顶点数，边数
	printf("Input vexnum and arcnum.\n");
	scanf("%d%d", &G->vexNum, &G->arcNum);
	getchar();

	//顶点名
	int i, j;
	printf("Input vex type.\n");
	for (i = 0; i < G->vexNum; i++) {
		G->vexs[i] = scanfChar();
	}
	getchar();

	//初始化
	for (i = 0; i < G->vexNum; i++) {
		for (j = 0; j < G->vexNum; j++) {
			G->arcs[i][j] = INT_MAX;
			if (i == j) {
				G->arcs[i][j] = 0;
			}
		}
	}
	//边、弧
	char v1, v2;
	char ch;
	printf("Input arc and arcinfo.\n");
	for (int k = 0; k < G->arcNum; k++) {
		v1 = scanfChar();
		v2 = scanfChar();
		i = LocateVex(G->vexs, v1, G->vexNum);
		j = LocateVex(G->vexs, v2, G->vexNum);
		G->arcs[i][j] = scanfNum();
		G->arcs[j][i] = G->arcs[i][j];//有向网不需要
		ch = scanfChar();
		if (ch == '\n')
			break;
		else
			ungetc(ch, stdin);
	}
	return OK;
}


Status createALG(ALGraph* G) {
	int i, j;
	char v1, v2;//边的权值及位置
	//顶点数，边数
	printf("Input vexnum and arcnum.\n");
	scanf("%d%d", &G->vexNum, &G->arcNum);
	getchar();
	//顶点名
	printf("Input vex type.\n");
	char elem;
	for (i = 0; i < G->vexNum; i++) {
		G->vertices[i].data = scanfChar();
		G->vertices[i].firstArc = NULL;
	}
	getchar();

	char ch;
	printf("Input arc and arcinfo.\n");
	for (int k = 0; k < G->vexNum; k++) {
		scanf("%c%c", &v1, &v2);
		v1 = scanfChar();
		v2 = scanfChar();

		ALArcNode* p1 = (ALArcNode*)malloc(sizeof(ALArcNode));
		if (!p1) exit(0);

		p1->adjVex = j;
		p1->info = scanfNum();
		p1->nextArc = G->vertices[i].firstArc->nextArc;
		G->vertices[i].firstArc->nextArc = p1;//头插法

		//*
		ALArcNode* p2 = (ALArcNode*)malloc(sizeof(ALArcNode));
		if (!p2) exit(0);
		p2->adjVex = i;
		p2->info = p1->info;
		p2->nextArc = G->vertices[j].firstArc->nextArc;
		G->vertices[j].firstArc->nextArc = p2;//对应另一个边节点，有向图无需

		ch = scanfChar();
		if (ch == '\n')
			break;
		else
			ungetc(ch, stdin);
	}
	return OK;
}

int LocateVex(VertexType* pVex, VertexType vex, int vexNum) {
	int i;
	for (i = 0; i < vexNum; i++) {
		if (vex == pVex[i]) {
			return i;
		}
	}
	return EOF;
}