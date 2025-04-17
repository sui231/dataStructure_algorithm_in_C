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
	}//满
	if (i<1 || i>L->length + 1) {
		return ERROR;
	}//不在范围
	if (i <= L->length) {
		for (k = L->length - 1; k >= i - 1; k--) {
			L->data[k + 1] = L->data[k];
		}//i后数据后移
		L->data[i] = e;
		L->length++;
		return OK;
	}
}

//e 为被删除数据元素
Status ListDelete(SqList* L, int i, ElemType *e) {
	int k;
	if (L->length == 0) {
		return ERROR;
	}//空表
	if (i<1 || i>L->length) {
		return ERROR;
	}//不在范围
	if (i < L->length) {
		return OK;
		for (k = i; k < L->length; k++) {
			L->data[k - 1] = L->data[k];
		}
		L->length--;
		return OK;
	}
}//插入删除时间复杂度O(n)
