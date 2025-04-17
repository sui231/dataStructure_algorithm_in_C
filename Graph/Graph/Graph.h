#ifndef _GRAPH_H
#define _GRAPH_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 100//���ڴ�����

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef enum { DG, DN, UDG, UDN } GraphKind;

typedef int Status;
typedef char VertexType;
typedef int ArcType;
typedef int InfoType;


/* �ڽӾ��� */
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];				//������Ϣ
	ArcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	//�ߣ�������Ϣ
	int vexNum, arcNum;		//������������
}AMGraph;//�ڽӾ���adjacency matrix graph��


/* �ڽӱ� */
typedef struct _ALArcNode {
	int adjVex;					//����Ӧ��һ������λ��
	struct _ALArcNode* nextArc;	//��һ���ߣ������ڵ�ָ��
	InfoType info;				//�ߣ�������Ϣ
}ALArcNode;//�ߣ������ڵ�

typedef struct _ALVexNode {
	VertexType data;			//������Ϣ
	ALArcNode* firstArc;			//�߽��ָ��
}ALVexNode, AdjList[MAX_VERTEX_NUM];//�������飨adjacency list��

typedef struct {
	AdjList vertices;			//�ڽӱ�
	int vexNum, arcNum;			//������������
}ALGraph;//�ڽӱ�ͼ��adjacency list graph��


/* ʮ����������ͼ�� */
typedef struct _OArcNode { // ���ڵ�
	int headVex, tailVex; // �û�ͷ��β���ڵ�λ��
	struct _OArcNode* hlink, * tlink;// ��ͷ��β����ͬ������ ��������һ����
	InfoType info;
}OArcNode;

typedef struct _OVexNode { //�ڵ�
	VertexType data;
	OArcNode* firstIn, * firstOut; // ָ�򶥵�ĵ�һ�������룩��
}OVexNode;

typedef struct {
	OVexNode vexList[MAX_VERTEX_NUM];
	int arcNum, vexNum;
}OLGraph;// ʮ������ (Othogonal List)


/* �ڽӶ��ر�����ͼ�� */
typedef enum { UNVISITED, VISITED }VisitIf;
typedef struct AMArcNode { // ���ڵ�
	VisitIf mark;
	int iVex, jVex; // �����ڵ�λ��
	struct AMArcNode* iLink, * jLink;//�����ڵ���ͬ������ ��������һ��������ͬ�ڵ�ıߣ�
	InfoType info;
}AMArcNode;

typedef struct AMVexNode { //�ڵ�
	VertexType data;
	AMArcNode* firstEdge; // ָ�򶥵�ĵ�һ���ߣ����ʮ��������һ��ָ�룩
}AMVexNode;

typedef struct {
	AMArcNode* adjList[MAX_VERTEX_NUM];
	int arcNum, vexNum;
}AMLGraph;// �ڽӶ��ر� (Adjacency Multilist)



//AMG
Status createAMG(AMGraph* G);
void printAMGragh(AMGraph G);
void DFS(AMGraph G, int v);
void BFS(AMGraph G);
#endif