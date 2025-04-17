#include"BalancedBinaryTree.h"
BSTree insertAVL(BSTree tree, ElemType e, int* taller);
BSTree leftBalance(BSTree tree);
BSTree rightBalance(BSTree tree);


//// 查入e，已存在返回0
//// 若插入后失衡则旋转
//// taller表示树的高度是否增加
// 插入函数，返回新的子树根节点，以便上级调用可以更新连接
BSTree insertAVL(BSTree tree, ElemType e, int* taller) {
    if (!tree) {        // 插入
        tree = (BSTree)malloc(sizeof(BSTNode));
        if (!tree) return NULL;
        tree->data = e;
        tree->bf = 0;
        tree->lchild = tree->rchild = NULL;
        *taller = 1;
        return tree;	// 递归到达终点，不再递归
    }

    if (EQ(e.key, tree->data.key)) {    // 元素已存在
        *taller = 0;
        return tree;    // 递归到达终点，不再递归
    }

    if (LT(e.key, tree->data.key)) {
        tree->lchild = insertAVL(tree->lchild, e, taller);  // 递归插入左子树
        if (*taller) {  // 左子树增高
            switch (tree->bf) {
            case -1:
                tree->bf = 0;
                *taller = 0;
                break;
            case 0:
                tree->bf = 1;
                break;
            case 1:
                tree = leftBalance(tree);
                *taller = 0;
                break;
            }
        }
    }
    else {
        tree->rchild = insertAVL(tree->rchild, e, taller);  // 递归插入右子树
        if (*taller) {  // 右子树增高
            switch (tree->bf) {
            case 1:
                tree->bf = 0;
                *taller = 0;
                break;
            case 0:
                tree->bf = -1;
                break;
            case -1:
                tree = rightBalance(tree);
                *taller = 0;
                break;
            }
        }
    }
    return tree;  // 返回可能更新的当前根节点，完成递归并完成平衡
}

// 定义右旋
BSTree rRotate(BSTree tree) {
    BSTree lc = tree->lchild;
    tree->lchild = lc->rchild;
    lc->rchild = tree;
    return lc;
}

// 定义左旋
BSTree lRotate(BSTree tree) {
    BSTree rc = tree->rchild;
    tree->rchild = rc->lchild;
    rc->lchild = tree;
    return rc;
}

BSTree leftBalance(BSTree tree) {
    BSTree lc = tree->lchild;  // 左子节点
    if (lc->bf == 1) {  // LL型失衡
        // 进行右旋
        tree->bf = lc->bf = 0;
        tree = rRotate(tree);
    }
    else if (lc->bf == -1) {  // LR型失衡
        BSTree lr = lc->rchild;  // 左子的右子
        // 确定新的平衡因子
        if (lr->bf == 1) {
            tree->bf = -1;
            lc->bf = 0;
        }
        else if (lr->bf == 0) {
            tree->bf = lc->bf = 0;
        }
        else { // lr->bf == -1
            tree->bf = 0;
            lc->bf = 1;
        }
        lr->bf = 0;
        // 先对左子节点进行左旋
        lc = lRotate(lc);
        tree->lchild = lc;
        // 然后对整棵树进行右旋
        tree = rRotate(tree);
    }
    return tree;
}

BSTree rightBalance(BSTree tree) {
    BSTree rc = tree->rchild;  // 右子节点
    if (rc->bf == -1) {  // RR型失衡
        // 进行左旋
        tree->bf = rc->bf = 0;
        tree = lRotate(tree);
    }
    else if (rc->bf == 1) {  // RL型失衡
        BSTree rl = rc->lchild;  // 右子的左子
        // 确定新的平衡因子
        if (rl->bf == -1) {
            tree->bf = 1;
            rc->bf = 0;
        }
        else if (rl->bf == 0) {
            tree->bf = rc->bf = 0;
        }
        else { // rl->bf == 1
            tree->bf = 0;
            rc->bf = -1;
        }
        rl->bf = 0;
        // 先对右子节点进行右旋
        rc = rRotate(rc);
        tree->rchild = rc;
        // 然后对整棵树进行左旋
        tree = lRotate(tree);
    }
    return tree;
}

// 打印树的辅助函数，用于可视化树结构
void printTree(BSTree tree, int space) {
    int count = 10; // 控制节点之间的间距
    if (tree == NULL) {
        return;
    }

    space += count;
    printTree(tree->rchild, space);
    printf("\n");

    for (int i = count; i < space; i++) {
        printf(" ");
    }
    printf("%d(%c)\n", tree->data.key, tree->data.infol);
    printTree(tree->lchild, space);
}

int main() {
    BSTree root = NULL;
    int taller;

    // 插入数据用例
    ElemType elements[] = {
        {50, 'a'}, {30, 'b'}, {70, 'c'}, {20, 'd'}, {40, 'e'},
        {60, 'f'}, {80, 'g'}, {10, 'h'}, {25, 'i'}, {35, 'j'},
        {45, 'k'}, {55, 'l'}, {65, 'm'}, {75, 'n'}, {85, 'o'}
    };

    printf("Starting AVL Tree Insertions...\n");

    // 插入节点并检查树是否保持平衡
    for (int i = 0; i < sizeof(elements) / sizeof(elements[0]); i++) {
        printf("Inserting key: %d\n", elements[i].key);
        root = insertAVL(root, elements[i], &taller);
        // 这里可以添加函数来打印树的结构
    }

    printf("AVL Tree built successfully. Here are the details:\n");
    // 打印树的详细信息
    printTree(root, 0);

    return 0;
}




//// 更新父节点的指针以指向新的子节点
//void updateParent(BSTree root, BSTree target, BSTree newChild) {
//	BSTree temp = root, parent = NULL;
//	// 遍历树以找到目标节点的父节点
//	while (temp != NULL && temp != target) {
//		parent = temp;  // 记录当前节点为后续可能的父节点
//		if (LT(target->data.key, temp->data.key)) {  // 判断目标节点是在左子树还是右子树
//			temp = temp->lchild;
//		}
//		else {
//			temp = temp->rchild;
//		}
//	}
//	// 若找到父节点，根据目标节点是父节点的左子节点还是右子节点来更新相应的指针
//	if (parent != NULL) {
//		if (parent->lchild == target) {
//			parent->lchild = newChild;  // 如果目标节点是左子节点，更新父节点的左子节点指针
//		}
//		else {
//			parent->rchild = newChild;  // 如果目标节点是右子节点，更新父节点的右子节点指针
//		}
//	}
//}
//
//// 右旋，处理LL型
//void rightRotate(BSTree* root, BSTree* target) {
//	if (*target == NULL || (*target)->lchild == NULL)
//		return; // 检查target及其左子节点是否为空
//
//	// 旋转节点及其子树
//	BSTree lc = (*target)->lchild;
//	(*target)->lchild = lc->rchild;
//	lc->rchild = *target;
//
//	// 更新父节点的子节点指针
//	if (*root == *target) {
//		*root = lc; // 如果target是根节点，则更新根指针
//	}
//	else {
//		// 如果target不是根节点，我们需要找到target的父节点并更新其子节点指针
//		updateParent(*root, *target, lc);
//	}
//	*target = lc; // 完成旋转后更新target指针
//}
//
//// 左旋，处理RR型
//void leftRotate(BSTree* root, BSTree* target) {
//	if (*target == NULL || (*target)->rchild == NULL)
//		return;
//
//	BSTree leftChild = (*target)->rchild;
//	(*target)->rchild = leftChild->lchild;
//	leftChild->lchild = *target;
//
//	// 更新父节点的子节点指针
//	if (*root == *target) {
//		*root = leftChild;
//	}
//	else {
//		updateParent(*root, *target, leftChild);
//	}
//	*target = leftChild;
//}




//Status InsertAVL(BSTree* tree, ElemType e, int* taller) {
//	if (!tree) {	// 成功找到插入位置
//		*tree = (BSTree)malloc(sizeof(BSTNode));
//		(*tree)->lchild = (*tree)->rchild = NULL;
//		(*tree)->bf = EH;
//		*taller = TRUE;
//		return 1;
//		/*return 1;*/
//	}
//	else {
//		if (EQ(e.key, (*tree)->data.key)) {	// 已存在
//			*taller = FALSE;
//			return 0;	// 递归到达终点，不再递归
//		}
//
//		if (LT(e.key, (*tree)->data.key)) {	// 向左子树
//			if (!InsertAVL(&(*tree)->lchild, e, taller)) {	// 向左递归并判断
//				*taller = FALSE;
//				return 0;	// 结束递归
//			}
//
//			if (*taller) {
//				switch ((*tree)->bf) {
//				case LH:	// 失衡
//					leftBalance(tree);
//					*taller = FALSE;
//					break;
//				case EH:
//					*taller = TRUE;
//					break;
//				case RH:
//					*taller = FALSE;
//					break;
//				}
//			}
//		} // end if
///*		else {*/	// 向右子树
//			if (!InsertAVL(&(*tree)->rchild, e, taller)) {
//				*taller = FALSE;
//				return 0;
//			}
//			if (*taller) {
//				switch ((*tree)->bf) {
//				case LH:
//					*taller = FALSE;
//					break;
//				case EH:
//					*taller = TRUE;
//					break;
//				case RH:	// 失衡
//					*taller = FALSE;
//					rightBalance(tree);
//					break;
//				}
//			}
///*		}*/// end if
//	}
//	return 1; // 完成递归并完成平衡
//}

//// 以*tree为根的树右旋，*tree会更新为新节点，LL型
//void rRotate(BSTree* tree) {
//    BSTree lc = (*tree)->lchild;
//    (*tree)->lchild = lc->rchild;
//    lc->rchild = *tree;
//    *tree = lc;
//}
//// 左旋，RR型
//void lRotate(BSTree* tree) {
//    BSTree rc = (*tree)->rchild;
//    (*tree)->rchild = rc->lchild;
//    rc->lchild = *tree;
//    *tree = rc;
//}
//
//// 左平衡
//void leftBalance(BSTree* tree) {
//	BSTree lc = (*tree)->lchild;
//	BSTree rd;
//
//	switch (lc->bf) {
//	case LH:	// LL失衡
//		(*tree)->bf = EH;
//		lc->bf = EH;
//		rRotate(tree);
//		break;
//	case RH:	// LR失衡
//		rd = lc->rchild;	// tree->lchild->rchild
//
//		switch (rd->bf) {
//		case LH:
//			(*tree)->bf = RH;
//			lc->bf = EH;
//			break;
//		case EH:
//			(*tree)->bf = EH;
//			lc->bf = EH;
//			break;
//		case RH:
//			(*tree)->bf = EH;
//			lc->bf = LH;
//			break;
//		}
//
//		rd->bf = EH;
//		lRotate(&(*tree)->lchild); // 左旋左子的右子树，转化为LL失衡
//		rRotate(tree);
//	} // switch lc->bf
//}
//
//// 右平衡以p所指节点tree为根的树
//void rightBalance(BSTree* tree) {
//
//}
