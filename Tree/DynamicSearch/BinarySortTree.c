#include"Tree.h"
#include "BinarySortTree.h"

// 无序树查找
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

// 有序树查找
struct TreeNode* searchBST(struct TreeNode* t, KeyType key) {
	//if (!t)
	//	return NULL;
	//if (EQ(t->elem.key, key))
	//	return t;
	if (!t || EQ(t->elem.key, key))
		return t;// 综合上面的
	else if (LT(t->elem.key, key))
		return searchBST(t->left, key);
	else
		return searchBST(t->right, key);
}
