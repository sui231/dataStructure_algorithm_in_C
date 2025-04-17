#include <stdio.h>
#include <stdlib.h>

// 定义多叉树节点结构体
typedef struct TreeNode {
    int val;
    struct TreeNode** children;
    int child_count;
} TreeNode;

// 定义二叉树节点结构体
typedef struct BinaryTreeNode {
    int val;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BinaryTreeNode;

// 创建新的多叉树节点
TreeNode* createTreeNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

// 创建新的二叉树节点
BinaryTreeNode* createBinaryTreeNode(int val) {
    BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 将多叉树转换为二叉树
BinaryTreeNode* convert_tree_to_binary(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    // 创建二叉树节点
    BinaryTreeNode* binary_node = createBinaryTreeNode(root->val);

    // 递归处理第一个子节点（左孩子）
    if (root->child_count > 0) {
        binary_node->left = convert_tree_to_binary(root->children[0]);
    }

    // 处理兄弟节点（右孩子）
    if (binary_node->left && root->child_count > 1) {
        BinaryTreeNode* current = binary_node->left;
        for (int i = 1; i < root->child_count; i++) {
            current->right = convert_tree_to_binary(root->children[i]);
            current = current->right;
        }
    }

    return binary_node;
}

// 释放二叉树的内存
void freeBinaryTree(BinaryTreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeBinaryTree(root->left);
    freeBinaryTree(root->right);
    free(root);
}

// 释放多叉树的内存
void freeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < root->child_count; i++) {
        freeTree(root->children[i]);
    }
    if (root->children != NULL) {
        free(root->children);
    }
    free(root);
}

int main() {
    // 构建一个简单的多叉树
    TreeNode* root = createTreeNode(1);
    root->child_count = 3;
    root->children = (TreeNode**)malloc(root->child_count * sizeof(TreeNode*));
    root->children[0] = createTreeNode(2);
    root->children[1] = createTreeNode(3);
    root->children[2] = createTreeNode(4);

    // 转换为二叉树
    BinaryTreeNode* binary_root = convert_tree_to_binary(root);

    // 释放内存
    freeTree(root);
    freeBinaryTree(binary_root);

    return 0;
}