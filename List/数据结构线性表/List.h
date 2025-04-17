#ifndef LIST_H
#define LIST_H

#define LIST_INT_SIZE 100
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define NULL 0
#define MAXSIZE 1000
#define OK	1
#define ERROR 0

typedef int Status;//�������ͣ�����״̬
typedef int ElemType;//Ԫ����������


//����˳�����Ա���
typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SqList;


//�����㼰��ָ�붨��
typedef struct Node {
	ElemType data;			//������
	struct Node* next;		//ָ����
}Node;						//�ڵ�ṹ��
typedef struct Node* LinkList;//
//�ڵ�ṹ��ָ��
//��Ҫ����ָ��ʱ������Node**�ͣ���LinkList*��



#endif