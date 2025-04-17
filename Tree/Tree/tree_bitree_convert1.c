#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
typedef struct BinaryTreeNode {
    int val;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BinaryTreeNode;

// 定义多叉树节点结构体
typedef struct TreeNode {
    int val;
    struct TreeNode** children;
    int child_count;
} TreeNode;

// 创建新的二叉树节点
BinaryTreeNode* createBinaryTreeNode(int val) {
    BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 创建新的多叉树节点
TreeNode* createTreeNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

// 将二叉树转换为多叉树
TreeNode* convert_binary_to_tree(BinaryTreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    // 创建多叉树节点
    TreeNode* tree_node = createTreeNode(root->val);

    // 处理左子树（第一个子节点）
    if (root->left) {
        tree_node->child_count = 1;
        tree_node->children = (TreeNode**)malloc(tree_node->child_count * sizeof(TreeNode*));
        tree_node->children[0] = convert_binary_to_tree(root->left);
    }

    // 处理右子树（兄弟节点）
    BinaryTreeNode* current = root->right;
    TreeNode* last_child = tree_node; // 初始为当前节点本身
    while (current) {
        // 创建兄弟节点
        TreeNode* sibling = createTreeNode(current->val);
        // 扩展父节点的子节点数组
        last_child->child_count++;
        last_child->children = realloc(last_child->children, last_child->child_count * sizeof(TreeNode*));
        last_child->children[last_child->child_count - 1] = sibling;
        // 处理兄弟节点的左子树
        if (current->left) {
            sibling->child_count = 1;
            sibling->children = (TreeNode**)malloc(sibling->child_count * sizeof(TreeNode*));
            sibling->children[0] = convert_binary_to_tree(current->left);
        }
        // 移动到下一个兄弟
        current = current->right;
        last_child = sibling;
    }

    return tree_node;
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
    // 构建一个简单的二叉树（对应原树的结构）
    BinaryTreeNode* root = createBinaryTreeNode(1);
    root->left = createBinaryTreeNode(2);
    root->left->left = createBinaryTreeNode(4);
    root->left->right = createBinaryTreeNode(5);
    root->right = createBinaryTreeNode(3);
    root->right->left = createBinaryTreeNode(6);

    // 转换为多叉树
    TreeNode* tree_root = convert_binary_to_tree(root);

    // 释放内存
    freeBinaryTree(root);
    freeTree(tree_root);

    return 0;
}