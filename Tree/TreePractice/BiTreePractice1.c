#include"QueueStack.h"

/*0.建立链式二叉树，递归方法前序、中序、后序遍历链式二叉树,
建立顺序二叉树，递归方法前序、中序、后序遍历存储二叉树*/
void BiTreeCreate(BiTree* T) {
	ElemType ch;
	scanf("%c", &ch);

	if (ch == ' ') {
		*T = NULL;
		return;
	}
	else {
		*T = (BiTree)malloc(sizeof(BiNode));
		if (!T) exit(0);

		(*T)->data = ch;
		BiTreeCreate(&(*T)->left);
		BiTreeCreate(&(*T)->right);
	}
}

void visit(ElemType data, int level) {
	printf("data:%c		level:%d\n", data, level);
}
void PreBiTreeTraverse(BiTree T, int level) {
	//前序遍历：根->左->右
	if (T != NULL) {
		visit(T->data, level);					//1
		PreBiTreeTraverse(T->left, level + 1);	//2
		PreBiTreeTraverse(T->right, level + 1);	//3
		//中序：左->根->右	213
		//后序：左->右->根	231
		//层序
	}
}


/* 1.将二叉树对称交换，即求二叉树镜像 */
void mirror(BiTree* T) {
	if (!*T) {
		return;
	}
	// 交换左右子树
	BiNode* temp = (*T)->left;
	(*T)->left = (*T)->right;
	(*T)->right = temp;

	// 递归处理左子树
	mirror(&(*T)->left);
	// 递归处理右子树
	mirror(&(*T)->right);
}

/* 2.求二叉树的高度，即深度 */
int Depth(BiTree root) {
	if (root == NULL) {
		return 0;
	}
	else {
		int leftDepth = Depth(root->left);
		int rightDepth = Depth(root->right); 
		return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1); // 返回左右子树中的最大深度加1  
	}
}

// 利用层序遍历
int Depth1(BiTree T) {
	if (!T)
		return 0;
	int front = -1, rear = -1;
	int last = 0; // last指向队列中 当前层的最右结点
	int level = 0;
	BiTree Q[MAXSIZE]; // 初始化队列Q,元素是二叉树结点指针
	Q[++rear] = T;     // 根结点入队
	BiTree p;
	while (front < rear) {
		p = Q[++front]; // 出队
		if (p->left)
			Q[++rear] = p->left; // 左子节点入队
		if (p->right)
			Q[++rear] = p->right; // 右子节点入队
		if (front == last) { // 处理该层的最右结点
			level++;
			last = rear;   // last指向下层
		}
	}
	return level;
}

/* 4.分层遍历二叉树，即按层次从上往下，从左往右顺序访问 */
void LevelTraversal(BiTree T) {
	Queue q;
	BiNode* node;
	InitQueue(&q);

	if (!T) return;  

	EnQueue(&q, T); // 根节点入队  

	while (!IsEmpty(&q)) { // 队列不为空时继续遍历  
		DeQueue(&q,&node); // 出队一个节点  
		printf("%c  \n", node->data); // 访问节点值  

		if (node->left) { // 如果左子节点存在  
			EnQueue(&q, node->left); // 左子节点入队  
		}
		if (node->right) { // 如果右子节点存在  
			EnQueue(&q, node->right); // 右子节点入队  
		}
	}
}

int depth = 0;
void LevelTraversal1(BiTree T) {
	int i = 0;
	while (1) {
		if (depth < i)
			break;
		_LevelTraversal(T, 1, i);
		i++;
	}
}

void _LevelTraversal(BiTree T, int level, int i) {
	if (!T) {
		if (level - 1 > depth)
			depth = level - 1;
		return;
	}
	else {
		if (level == i) {
			printf("data:%c          level:%d\n", T->data,level);
			if (level > depth)
				depth = level;
			return;
		}
		_LevelTraversal(T->left, level + 1, i);
		_LevelTraversal(T->right, level + 1, i);
	}
}


/* 5.求二叉树的宽度，即求最大结点数的层所具有的结点数 */
int WidthBiTree(BiTree T) {
	int width;
	Queue q;
	BiNode* node;
	InitQueue(&q);

	if (!T) return;

	EnQueue(&q, T); // 根节点入队  

	while (!IsEmpty(&q)) { // 队列不为空时继续遍历  
		DeQueue(&q, &node); // 出队一个节点  
		width = 0;

		if (node->left) { // 如果左子节点存在  
			EnQueue(&q, node->left); // 左子节点入队  
		}
		if (node->right) { // 如果右子节点存在  
			EnQueue(&q, node->right); // 右子节点入队  
		}
	}
	return width;
}

int Max = 0;
int conut_[MAXSIZE];
int GetWidth(BiTree T, int k) { //k变量为当前层数 默认从第一层开始
	if (T == NULL)// T为空直接返回
		return;
	else
		conut_[k]++;// T不为空conut_[k]++
	if (conut_[k] > Max)
		Max = conut_[k];	//Max为数组的最大值
	GetWidth(T->left, k + 1);
	GetWidth(T->right, k + 1);
	return Max;
}

/*6.求二叉树中叶子结点的个数*/
int leafNodesNum = 0;
void GetLeafNodesNum(BiTree T) {

	if (!T)
		return;

	if (!T->left && !T->right) {
		++leafNodesNum;
	}
	if(T) {
		GetLeafNodesNum(T->left);
		GetLeafNodesNum(T->right);
	}
}

int GetLeafNodesNum1(BiTree T) {
	Queue q;
	BiTree p;
	int leafNodesNum1 = 0;

	InitQueue(&q);
	if (T) EnQueue(&q, T);
	while (!IsEmpty(&q)){
		DeQueue(&q, &p);
		if (p->left) {
			EnQueue(&q, p->left);
		}
		if (p->right) {
			EnQueue(&q, p->right);
		}
		if (!p->left && !p->right) {
			leafNodesNum1++;
		}
	}
	return leafNodesNum1;
}

/*7.非递归方法前序、中序、后序遍历二叉树*/
//前序
void PreOrderTraverse2(BiTree T) {
	sqStack s;
	BiNode* current = T;
	s.top = -1;
	while (current || s.top != -1) {
		while (current) {// 若当前节点存在，则向左遍历至最底层的左子树，将沿途节点入栈
			s.data[++s.top] = current;
			printf("%c\n", current->data);
			current = current->left;
		}
		if (s.top > -1) {// 栈不为空弹栈，向右节点移动
			current = s.data[s.top--];
			current = current->right;
		}
	}//栈空，节点为空退出循环
}
//中序
void InOrderTraverse2(BiTree T) {
	sqStack s;
	BiNode* current = T;
	s.top = -1;
	while (current || s.top != -1) {
		while (current) {
			s.data[++s.top] = current;
			current = current->left;
		}	
		if (s.top > -1) {
			current = s.data[s.top--];
			printf("%c\n", current->data);
			current = current->right;
		}
	}
}
//后序
void PostOrderTraverse2(BiTree T) {
	sqStack s;
	BiNode* current = T;
	s.top = -1;
	BiNode* lastVisited = NULL;//上次访问的节点lastVisited，用于辅助判断右节点是否已经访问过

	while (current || s.top != -1) {
		while (current) {
			s.data[++s.top] = current;
			current = current->left;
		}

		current = s.data[s.top];// 取出栈顶节点，但不弹出

		if (current->right && current->right != lastVisited) {// 如果当前节点存在右子树且右子树未被访问
			current = current->right;
		}
		else { //右节点不存在右子树或右子树已经被访问
			printf("%c\n", current->data);
			lastVisited = current;// 将当前节点标记为已访问
			current = NULL;
			s.top--;// 将当前节点置为NULL，强制从栈中弹出
		}
	}
}

/*8.二叉树中的结点个数*/	//略
/*9.求二叉树第K层的结点个数*/	//略

/*10.判断两棵二叉树是否结构相同*/
bool isSameStructure(BiTree T1, BiTree T2) {
	// 如果两棵树的根节点都为空，则该分支结构相同
	if (T1 == NULL && T2 == NULL) {
		return true;
	}
	// 如果一棵树为空而另一棵不为空，或者它们的根节点的值不相等，它们结构不同
	if (T1 == NULL || T2 == NULL || T1->data != T2->data) {
		return false;
	}
	// 递归比较左子树和右子树的结构
	return isSameStructure(T1->left, T2->left) && isSameStructure(T1->right, T2->right);
}

/*11.求二叉树中两个结点的最低公共祖先结点*/
BiNode* lowestCommonAncestor(BiNode* root, BiNode* p, BiNode* q) {
	// 如果树为空，或者找到了p或q节点，直接返回当前节点
	if (root == NULL || root == p || root == q) {
		return root;
	}
	// 寻找p或q的最低公共祖先
	BiNode* left_lca = lowestCommonAncestor(root->left, p, q);
	BiNode* right_lca = lowestCommonAncestor(root->right, p, q);

	// 如果左右子树分别找到了p和q，则当前节点即为最低公共祖先
	if (left_lca && right_lca) {
		return root;
	}
	// 如果只在子树中找到了最低公共祖先，则返回子树中的结果
	if (left_lca) {
		return left_lca;
	}
	if (right_lca) {
		return right_lca;
	}
	// 如果左右子树都没有找到最低公共祖先，则返回NULL
	return NULL;
}
