#define MAX_TREE_SIZE 100
typedef int ElemType;


/*		树的parent_child定义		*/
//child
typedef struct CTNode{
	int child;
	struct CTNode* next;
} *ChildPtr;

//元素（parent）
typedef struct {
	ElemType data;
	int parent;
	ChildPtr firstchild;
} CTBox;

//树结构
typedef struct {
	CTBox nodes[MAX_TREE_SIZE];
	int r, n;
} BiTree;



/*		树的parent定义			*/	
typedef struct PTNode {
	ElemType data;
	int parent;
} PTNode;

typedef struct {
	PTNode nodes[MAX_TREE_SIZE];
	int r;		//根位置
	int n;		//节点数
} PTree;