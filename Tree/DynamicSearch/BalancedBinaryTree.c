#include"BalancedBinaryTree.h"
BSTree insertAVL(BSTree tree, ElemType e, int* taller);
BSTree leftBalance(BSTree tree);
BSTree rightBalance(BSTree tree);


//// ����e���Ѵ��ڷ���0
//// �������ʧ������ת
//// taller��ʾ���ĸ߶��Ƿ�����
// ���뺯���������µ��������ڵ㣬�Ա��ϼ����ÿ��Ը�������
BSTree insertAVL(BSTree tree, ElemType e, int* taller) {
    if (!tree) {        // ����
        tree = (BSTree)malloc(sizeof(BSTNode));
        if (!tree) return NULL;
        tree->data = e;
        tree->bf = 0;
        tree->lchild = tree->rchild = NULL;
        *taller = 1;
        return tree;	// �ݹ鵽���յ㣬���ٵݹ�
    }

    if (EQ(e.key, tree->data.key)) {    // Ԫ���Ѵ���
        *taller = 0;
        return tree;    // �ݹ鵽���յ㣬���ٵݹ�
    }

    if (LT(e.key, tree->data.key)) {
        tree->lchild = insertAVL(tree->lchild, e, taller);  // �ݹ����������
        if (*taller) {  // ����������
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
        tree->rchild = insertAVL(tree->rchild, e, taller);  // �ݹ����������
        if (*taller) {  // ����������
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
    return tree;  // ���ؿ��ܸ��µĵ�ǰ���ڵ㣬��ɵݹ鲢���ƽ��
}

// ��������
BSTree rRotate(BSTree tree) {
    BSTree lc = tree->lchild;
    tree->lchild = lc->rchild;
    lc->rchild = tree;
    return lc;
}

// ��������
BSTree lRotate(BSTree tree) {
    BSTree rc = tree->rchild;
    tree->rchild = rc->lchild;
    rc->lchild = tree;
    return rc;
}

BSTree leftBalance(BSTree tree) {
    BSTree lc = tree->lchild;  // ���ӽڵ�
    if (lc->bf == 1) {  // LL��ʧ��
        // ��������
        tree->bf = lc->bf = 0;
        tree = rRotate(tree);
    }
    else if (lc->bf == -1) {  // LR��ʧ��
        BSTree lr = lc->rchild;  // ���ӵ�����
        // ȷ���µ�ƽ������
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
        // �ȶ����ӽڵ��������
        lc = lRotate(lc);
        tree->lchild = lc;
        // Ȼ�����������������
        tree = rRotate(tree);
    }
    return tree;
}

BSTree rightBalance(BSTree tree) {
    BSTree rc = tree->rchild;  // ���ӽڵ�
    if (rc->bf == -1) {  // RR��ʧ��
        // ��������
        tree->bf = rc->bf = 0;
        tree = lRotate(tree);
    }
    else if (rc->bf == 1) {  // RL��ʧ��
        BSTree rl = rc->lchild;  // ���ӵ�����
        // ȷ���µ�ƽ������
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
        // �ȶ����ӽڵ��������
        rc = rRotate(rc);
        tree->rchild = rc;
        // Ȼ�����������������
        tree = lRotate(tree);
    }
    return tree;
}

// ��ӡ���ĸ������������ڿ��ӻ����ṹ
void printTree(BSTree tree, int space) {
    int count = 10; // ���ƽڵ�֮��ļ��
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

    // ������������
    ElemType elements[] = {
        {50, 'a'}, {30, 'b'}, {70, 'c'}, {20, 'd'}, {40, 'e'},
        {60, 'f'}, {80, 'g'}, {10, 'h'}, {25, 'i'}, {35, 'j'},
        {45, 'k'}, {55, 'l'}, {65, 'm'}, {75, 'n'}, {85, 'o'}
    };

    printf("Starting AVL Tree Insertions...\n");

    // ����ڵ㲢������Ƿ񱣳�ƽ��
    for (int i = 0; i < sizeof(elements) / sizeof(elements[0]); i++) {
        printf("Inserting key: %d\n", elements[i].key);
        root = insertAVL(root, elements[i], &taller);
        // ���������Ӻ�������ӡ���Ľṹ
    }

    printf("AVL Tree built successfully. Here are the details:\n");
    // ��ӡ������ϸ��Ϣ
    printTree(root, 0);

    return 0;
}




//// ���¸��ڵ��ָ����ָ���µ��ӽڵ�
//void updateParent(BSTree root, BSTree target, BSTree newChild) {
//	BSTree temp = root, parent = NULL;
//	// ���������ҵ�Ŀ��ڵ�ĸ��ڵ�
//	while (temp != NULL && temp != target) {
//		parent = temp;  // ��¼��ǰ�ڵ�Ϊ�������ܵĸ��ڵ�
//		if (LT(target->data.key, temp->data.key)) {  // �ж�Ŀ��ڵ���������������������
//			temp = temp->lchild;
//		}
//		else {
//			temp = temp->rchild;
//		}
//	}
//	// ���ҵ����ڵ㣬����Ŀ��ڵ��Ǹ��ڵ�����ӽڵ㻹�����ӽڵ���������Ӧ��ָ��
//	if (parent != NULL) {
//		if (parent->lchild == target) {
//			parent->lchild = newChild;  // ���Ŀ��ڵ������ӽڵ㣬���¸��ڵ�����ӽڵ�ָ��
//		}
//		else {
//			parent->rchild = newChild;  // ���Ŀ��ڵ������ӽڵ㣬���¸��ڵ�����ӽڵ�ָ��
//		}
//	}
//}
//
//// ����������LL��
//void rightRotate(BSTree* root, BSTree* target) {
//	if (*target == NULL || (*target)->lchild == NULL)
//		return; // ���target�������ӽڵ��Ƿ�Ϊ��
//
//	// ��ת�ڵ㼰������
//	BSTree lc = (*target)->lchild;
//	(*target)->lchild = lc->rchild;
//	lc->rchild = *target;
//
//	// ���¸��ڵ���ӽڵ�ָ��
//	if (*root == *target) {
//		*root = lc; // ���target�Ǹ��ڵ㣬����¸�ָ��
//	}
//	else {
//		// ���target���Ǹ��ڵ㣬������Ҫ�ҵ�target�ĸ��ڵ㲢�������ӽڵ�ָ��
//		updateParent(*root, *target, lc);
//	}
//	*target = lc; // �����ת�����targetָ��
//}
//
//// ����������RR��
//void leftRotate(BSTree* root, BSTree* target) {
//	if (*target == NULL || (*target)->rchild == NULL)
//		return;
//
//	BSTree leftChild = (*target)->rchild;
//	(*target)->rchild = leftChild->lchild;
//	leftChild->lchild = *target;
//
//	// ���¸��ڵ���ӽڵ�ָ��
//	if (*root == *target) {
//		*root = leftChild;
//	}
//	else {
//		updateParent(*root, *target, leftChild);
//	}
//	*target = leftChild;
//}




//Status InsertAVL(BSTree* tree, ElemType e, int* taller) {
//	if (!tree) {	// �ɹ��ҵ�����λ��
//		*tree = (BSTree)malloc(sizeof(BSTNode));
//		(*tree)->lchild = (*tree)->rchild = NULL;
//		(*tree)->bf = EH;
//		*taller = TRUE;
//		return 1;
//		/*return 1;*/
//	}
//	else {
//		if (EQ(e.key, (*tree)->data.key)) {	// �Ѵ���
//			*taller = FALSE;
//			return 0;	// �ݹ鵽���յ㣬���ٵݹ�
//		}
//
//		if (LT(e.key, (*tree)->data.key)) {	// ��������
//			if (!InsertAVL(&(*tree)->lchild, e, taller)) {	// ����ݹ鲢�ж�
//				*taller = FALSE;
//				return 0;	// �����ݹ�
//			}
//
//			if (*taller) {
//				switch ((*tree)->bf) {
//				case LH:	// ʧ��
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
///*		else {*/	// ��������
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
//				case RH:	// ʧ��
//					*taller = FALSE;
//					rightBalance(tree);
//					break;
//				}
//			}
///*		}*/// end if
//	}
//	return 1; // ��ɵݹ鲢���ƽ��
//}

//// ��*treeΪ������������*tree�����Ϊ�½ڵ㣬LL��
//void rRotate(BSTree* tree) {
//    BSTree lc = (*tree)->lchild;
//    (*tree)->lchild = lc->rchild;
//    lc->rchild = *tree;
//    *tree = lc;
//}
//// ������RR��
//void lRotate(BSTree* tree) {
//    BSTree rc = (*tree)->rchild;
//    (*tree)->rchild = rc->lchild;
//    rc->lchild = *tree;
//    *tree = rc;
//}
//
//// ��ƽ��
//void leftBalance(BSTree* tree) {
//	BSTree lc = (*tree)->lchild;
//	BSTree rd;
//
//	switch (lc->bf) {
//	case LH:	// LLʧ��
//		(*tree)->bf = EH;
//		lc->bf = EH;
//		rRotate(tree);
//		break;
//	case RH:	// LRʧ��
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
//		lRotate(&(*tree)->lchild); // �������ӵ���������ת��ΪLLʧ��
//		rRotate(tree);
//	} // switch lc->bf
//}
//
//// ��ƽ����p��ָ�ڵ�treeΪ������
//void rightBalance(BSTree* tree) {
//
//}
