#include"BinarySortTree.h"

// 有序树查找（用于插入删除）
// f为*p父节点，初始为NULL，为中间变量，参与迭代过程
// 查找成功, Status返回1，p为所查节点指针，f为*p父节点
// 查找失败, Status返回0，*p与f相同，为查找的最后一个节点
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


// t不存在e则插入e，返回1
// 存在则返回0
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


// 在searchBST1基础上增加
// 传回p父节点的信息，用于删除
// pParent为最终的f，只需最终返回
// leftOrRight表示p是f的left（0）还是right（1）
// 若查找失败leftOrRight为-1，若p为根节点leftOrRight则为起始值（一开始赋值为2）
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


//e为所需删除元素，不存在则返回0
Status deleteBST(TreeNode* t, ElemType e) {
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* pParent = (TreeNode*)malloc(sizeof(TreeNode));
	int leftOrRight = 2;
	if (searchBST2(t, e.key, NULL, &p, &pParent, &leftOrRight)) {
		deleteNode(p, pParent, leftOrRight);
	}
}



// 删除p，pParent为p父节点
// 对于左右子树非空的情况：
// 用p的前趋current的内容（右子树为空）替换p（指针不改变），current左子树换到原来current位置（pre右子树位置）
// 另一种：用p->right直接替换p，p->left接到p原来的前趋current右子树
void deleteNode(TreeNode* p, TreeNode* pParent, int leftOrRight) {
	TreeNode* pre,* current;	// pre为current父节点
	if (!p->right) {	// p右子树为空，左子树替换
		current = p;
		p = p->left;
		if (leftOrRight == 0)
			pParent->left = p;
		else if(leftOrRight == 1)
			pParent->right = p;
		free(current);
	}
	else if (!p->left) {	// p左子树为空
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
		
		current = p->left;	// 找到p的前趋
		while (current->right) {
			pre = current;
			current = current->right;
		}	// 向左然后向右到尽头

		p->elem = current->elem;
		if (pre != p)		// p的右子树不能改变，pre的右子树接current左子树
			pre->right = current->left;
		else
			pre->left = current->left;
		free(pre);
		free(current);
	}
}
// 书上没写全的delete，意思和上面一样，少了一步没连接p
void _delete(TreeNode* p) {
	TreeNode* pre, * current;	// pre为current父节点
	if (!p->right) {	// p右子树为空，左子树替换
		current = p;
		p = p->left;
		//没连接p
		free(current);
	}
	else if (!p->left) {	// p左子树为空
		current = p;
		p = p->right;
		free(current);
	}
	else {
		pre = p;
		current = p->left;	// 找到p的前趋
		while (current->right) {
			pre = current;
			current = current->right;
		}
		p->elem = current->elem;
		if (pre != p)		// p的右子树不能改变，pre的右子树接current左子树
			pre->right = current->left;
		else
			pre->left = current->left;
		free(pre);
		free(current);
	}
}
