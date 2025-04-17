#pragma once
#include"Tree.h"

struct TreeNode* unsortedSearchTree(struct TreeNode* t, KeyType key);

struct TreeNode* searchBST(struct TreeNode* t, KeyType key);

Status searchBST1(struct TreeNode* t, KeyType key, struct TreeNode* f, struct TreeNode** p);

Status insertBST(TreeNode* t, ElemType e);

void deleteNode(TreeNode* p, TreeNode* pParent, int leftOrRight);;

void _delete(TreeNode* p);