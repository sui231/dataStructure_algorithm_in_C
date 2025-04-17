#include"Tree.h"
#include "BinarySortTree.h"

// ����������
struct TreeNode* unsortedSearchTree(struct TreeNode* t, KeyType key) {
	if (!t)
		return NULL;
	if (EQ(t->elem.key, key))
		return t;

	if (t->left)
		return unsortedSearchTree(t->left, key);
	else if (t->right)
		return unsortedSearchTree(t->right, key);
}

// ����������
struct TreeNode* searchBST(struct TreeNode* t, KeyType key) {
	//if (!t)
	//	return NULL;
	//if (EQ(t->elem.key, key))
	//	return t;
	if (!t || EQ(t->elem.key, key))
		return t;// �ۺ������
	else if (LT(t->elem.key, key))
		return searchBST(t->left, key);
	else
		return searchBST(t->right, key);
}
