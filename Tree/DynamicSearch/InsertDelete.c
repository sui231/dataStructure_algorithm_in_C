#include"BinarySortTree.h"

// ���������ң����ڲ���ɾ����
// fΪ*p���ڵ㣬��ʼΪNULL��Ϊ�м�����������������
// ���ҳɹ�, Status����1��pΪ����ڵ�ָ�룬fΪ*p���ڵ�
// ����ʧ��, Status����0��*p��f��ͬ��Ϊ���ҵ����һ���ڵ�
Status searchBST1(struct TreeNode* t, KeyType key, struct TreeNode* f, struct TreeNode** p) {
	if (!t) {
		*p = f;
		return 0;
	}

	if (EQ(t->elem.key, key)) {
		*p = t;
		return 1;
	}
	else if (LT(t->elem.key, key))
		return searchBST1(t->left, key, t, p);
	else
		return searchBST1(t->right, key, t, p);
}


// t������e�����e������1
// �����򷵻�0
Status insertBST(TreeNode* t, ElemType e) {
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* pParent = (TreeNode*)malloc(sizeof(TreeNode));
	if (!searchBST1(t, e.key, NULL, &p, &pParent)) {
		TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
		newNode->elem = e;
		if (LT(e.key, p->elem.key))
			p->right = newNode;
		else
			p->right = newNode;
		return 1;
	}
	return 0;
}


// ��searchBST1����������
// ����p���ڵ����Ϣ������ɾ��
// pParentΪ���յ�f��ֻ�����շ���
// leftOrRight��ʾp��f��left��0������right��1��
// ������ʧ��leftOrRightΪ-1����pΪ���ڵ�leftOrRight��Ϊ��ʼֵ��һ��ʼ��ֵΪ2��
Status searchBST2(struct TreeNode* t, KeyType key, struct TreeNode* f, struct TreeNode** p, TreeNode** pParent, int* leftOrRight) {
	if (!t) {
		*p = f;
		*pParent = f;
		leftOrRight = -1;
		return 0;
	}

	if (EQ(t->elem.key, key)) {
		*p = t;
		*pParent = f;
		return 1;
	}
	else if (LT(t->elem.key, key))
		return searchBST2(t->left, key, t, p, pParent, (leftOrRight = 0));
	else
		return searchBST2(t->right, key, t, p, pParent, (leftOrRight = 1));
}


//eΪ����ɾ��Ԫ�أ��������򷵻�0
Status deleteBST(TreeNode* t, ElemType e) {
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* pParent = (TreeNode*)malloc(sizeof(TreeNode));
	int leftOrRight = 2;
	if (searchBST2(t, e.key, NULL, &p, &pParent, &leftOrRight)) {
		deleteNode(p, pParent, leftOrRight);
	}
}



// ɾ��p��pParentΪp���ڵ�
// �������������ǿյ������
// ��p��ǰ��current�����ݣ�������Ϊ�գ��滻p��ָ�벻�ı䣩��current����������ԭ��currentλ�ã�pre������λ�ã�
// ��һ�֣���p->rightֱ���滻p��p->left�ӵ�pԭ����ǰ��current������
void deleteNode(TreeNode* p, TreeNode* pParent, int leftOrRight) {
	TreeNode* pre,* current;	// preΪcurrent���ڵ�
	if (!p->right) {	// p������Ϊ�գ��������滻
		current = p;
		p = p->left;
		if (leftOrRight == 0)
			pParent->left = p;
		else if(leftOrRight == 1)
			pParent->right = p;
		free(current);
	}
	else if (!p->left) {	// p������Ϊ��
		current = p;
		p = p->right;
		if (leftOrRight == 0)
			pParent->left = p;
		else if (leftOrRight == 1)
			pParent->right = p;
		free(current);
	}
	else {
		pre = p;
		
		current = p->left;	// �ҵ�p��ǰ��
		while (current->right) {
			pre = current;
			current = current->right;
		}	// ����Ȼ�����ҵ���ͷ

		p->elem = current->elem;
		if (pre != p)		// p�����������ܸı䣬pre����������current������
			pre->right = current->left;
		else
			pre->left = current->left;
		free(pre);
		free(current);
	}
}
// ����ûдȫ��delete����˼������һ��������һ��û����p
void _delete(TreeNode* p) {
	TreeNode* pre, * current;	// preΪcurrent���ڵ�
	if (!p->right) {	// p������Ϊ�գ��������滻
		current = p;
		p = p->left;
		//û����p
		free(current);
	}
	else if (!p->left) {	// p������Ϊ��
		current = p;
		p = p->right;
		free(current);
	}
	else {
		pre = p;
		current = p->left;	// �ҵ�p��ǰ��
		while (current->right) {
			pre = current;
			current = current->right;
		}
		p->elem = current->elem;
		if (pre != p)		// p�����������ܸı䣬pre����������current������
			pre->right = current->left;
		else
			pre->left = current->left;
		free(pre);
		free(current);
	}
}
