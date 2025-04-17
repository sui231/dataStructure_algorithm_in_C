#ifndef _GRAPH_H
#define _GRAPH_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 100//堆内存问题

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef enum { DG, DN, UDG, UDN } GraphKind;

typedef int Status;
typedef char VertexType;
typedef int ArcType;
typedef int InfoType;


/* 邻接矩阵 */
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];				//顶点信息
	ArcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	//边（弧）信息
	int vexNum, arcNum;		//顶点数，边数
}AMGraph;//邻接矩阵（adjacency matrix graph）


/* 邻接表 */
typedef struct _ALArcNode {
	int adjVex;					//所对应另一个顶点位置
	struct _ALArcNode* nextArc;	//下一个边（弧）节点指针
	InfoType info;				//边（弧）信息
}ALArcNode;//边（弧）节点

typedef struct _ALVexNode {
	VertexType data;			//顶点信息
	ALArcNode* firstArc;			//边界的指针
}ALVexNode, AdjList[MAX_VERTEX_NUM];//顶点数组（adjacency list）

typedef struct {
	AdjList vertices;			//邻接表
	int vexNum, arcNum;			//顶点数，边数
}ALGraph;//邻接表图（adjacency list graph）


/* 十字链表（有向图） */
typedef struct _OArcNode { // 弧节点
	int headVex, tailVex; // 该弧头（尾）节点位置
	struct _OArcNode* hlink, * tlink;// 弧头（尾）相同的链域 （连接下一个）
	InfoType info;
}OArcNode;

typedef struct _OVexNode { //节点
	VertexType data;
	OArcNode* firstIn, * firstOut; // 指向顶点的第一个出（入）弧
}OVexNode;

typedef struct {
	OVexNode vexList[MAX_VERTEX_NUM];
	int arcNum, vexNum;
}OLGraph;// 十字链表 (Othogonal List)


/* 邻接多重表（无向图） */
typedef enum { UNVISITED, VISITED }VisitIf;
typedef struct AMArcNode { // 弧节点
	VisitIf mark;
	int iVex, jVex; // 依附节点位置
	struct AMArcNode* iLink, * jLink;//依附节点相同的链域 （连接下一个依附相同节点的边）
	InfoType info;
}AMArcNode;

typedef struct AMVexNode { //节点
	VertexType data;
	AMArcNode* firstEdge; // 指向顶点的第一个边（相比十字链表少一个指针）
}AMVexNode;

typedef struct {
	AMArcNode* adjList[MAX_VERTEX_NUM];
	int arcNum, vexNum;
}AMLGraph;// 邻接多重表 (Adjacency Multilist)



//AMG
Status createAMG(AMGraph* G);
void printAMGragh(AMGraph G);
void DFS(AMGraph G, int v);
void BFS(AMGraph G);
#endif