#ifndef _HUFFMAN_H
#define _HUFFMAN_H

#define TYPE htNode*
#define MAX_SZ 256

//节点
typedef struct _htNode {
	char symbol;
	struct _htNode* left, * right;
}htNode;
//树
typedef struct _htTree {
	htNode* root;
	//int length;
}htTree;


//huffman编码，链表的形式存储，每个节点存储一个符号及其对应编码
typedef struct _hlNode {
	char symbol;
	char* code;//编码
	struct _hlNode* next;
}hlNode;

typedef struct _hlTable {
	hlNode* first,* last;
}hlTable;

#endif