#include"List.h"

Status GetElem(SqList L, int i, ElemType* e) {
	if (L.length == 0 || i<1 || i> L.length) {
		return ERROR;
	}
	*e = L.data[i - 1];
	return OK;
}

Status ListInsert(SqList* L, int i, ElemType e) {
	//0   ... i-2  *  i-1  i  ...  length-1
	int k;
	if (L->length == MAXSIZE) {
		return ERROR;
	}//��
	if (i<1 || i>L->length + 1) {
		return ERROR;
	}//���ڷ�Χ
	if (i <= L->length) {
		for (k = L->length - 1; k >= i - 1; k--) {
			L->data[k + 1] = L->data[k];
		}//i�����ݺ���
		L->data[i] = e;
		L->length++;
		return OK;
	}
}

//e Ϊ��ɾ������Ԫ��
Status ListDelete(SqList* L, int i, ElemType *e) {
	int k;
	if (L->length == 0) {
		return ERROR;
	}//�ձ�
	if (i<1 || i>L->length) {
		return ERROR;
	}//���ڷ�Χ
	if (i < L->length) {
		return OK;
		for (k = i; k < L->length; k++) {
			L->data[k - 1] = L->data[k];
		}
		L->length--;
		return OK;
	}
}//����ɾ��ʱ�临�Ӷ�O(n)
