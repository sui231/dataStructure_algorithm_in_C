#ifndef _HUFFMAN_H
#define _HUFFMAN_H

#define TYPE htNode*
#define MAX_SZ 256

//�ڵ�
typedef struct _htNode {
	char symbol;
	struct _htNode* left, * right;
}htNode;
//��
typedef struct _htTree {
	htNode* root;
	//int length;
}htTree;


//huffman���룬�������ʽ�洢��ÿ���ڵ�洢һ�����ż����Ӧ����
typedef struct _hlNode {
	char symbol;
	char* code;//����
	struct _hlNode* next;
}hlNode;

typedef struct _hlTable {
	hlNode* first,* last;
}hlTable;

#endif