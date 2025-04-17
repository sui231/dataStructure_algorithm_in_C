/*²åÈëÔªËØ*/

#include<stdio.h>
#include<stdlib.h>
#include"List.h"

Status SL_insert(SqList* SL, int i, ElemType e) {
	if (i<1 || i>SL->length)
		return ERROR;
	for (int j = SL->length - 1; j >= i - 1; j--) {
		SL->data[j + 1] = SL->data[j];
	}
	SL->data[i - 1] = e;
	SL->length++;
	return OK;
}


Status LL_CLL_insert(node** L, int i, ElemType e) {
	node* target;
	node* temp;
	int j;

	//if (i < 1 || i > LL_lengthof(*L))
	//	return ERROR;
	
	temp = (node*)malloc(sizeof(node));
	if (!temp)
		exit(EXIT_FAILURE);
	temp->data = e;
	temp->next = NULL;

	
	if (i == 0){
		for (target = *L; target != (*L); target = target->next)
			;
		target->next = temp;
		temp->next = target->next;
	}
	else {
		target = *L;
		for (j = 1; j < i; j++) {
			target = target->next;
		
			if (target == target->next || target == NULL)
				return ERROR;
		}
		temp->next = target->next;
		target->next = temp;	
	}
	return OK;
}