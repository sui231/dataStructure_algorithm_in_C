#ifndef _BITREE_H
#define _BITREE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

typedef char ElemType;

typedef struct BiTreeNode {
	ElemType data;
	struct BiTreeNode* left, * right;
}BiNode,* BiTree;


//0.建立链式二叉树，递归方法前序、中序、后序遍历链式二叉树
//建立顺序二叉树，递归方法前序、中序、后序遍历存储二叉树
void BiTreeCreate(BiTree* T);
void visit(ElemType data, int level);
void PreBiTreeTraverse(BiTree T, int level);

//1.将二叉树对称交换，即求二叉树镜像
void mirror(BiTree* T);

//2.求二叉树的高度，即深度
// 分治和递归
int Depth(BiTree root);
// 利用层序遍历
int Depth1(BiTree T);

//3.已知前序序列和中序序列，构造二叉树
// 分治与递归
void CreateTree1(BiTree* T, char* PreStr, char* InStr, int L1, int R1, int L2, int R2);
void print1(int L1, int root, int L2, char* PreStr, char* InStr);
void print2(int L1, int root, int L2, int R1, int R2, char* PreStr, char* InStr);

//4.分层遍历二叉树，即按层次从上往下，从左往右顺序访问
void LevelTraversal(BiTree T);
void LevelTraversal1(BiTree T);
void _LevelTraversal(BiTree T, int level, int i);

//5.求二叉树的宽度，即求最大结点数的层所具有的结点数
int WidthBiTree(BiTree T);
int GetWidth(BiTree T, int k);

//6.求二叉树中叶子结点的个数
void GetLeafNodesNum(BiTree T);
int GetLeafNodesNum1(BiTree T);

//7.非递归方法前序、中序、后序遍历二叉树
void PreOrderTraverse2(BiTree T);
void InOrderTraverse2(BiTree T);
void PostOrderTraverse2(BiTree T);

//8.求二叉树第K层的结点个数
//9.求二叉树中叶子结点的个数
//略

bool isSameStructure(BiTree T1, BiTree T2);
//10.判断两棵二叉树是否结构相同

BiNode* lowestCommonAncestor(BiNode* root, BiNode* p, BiNode* q);
//11.求二叉树中两个结点的最低公共祖先结点

#endif