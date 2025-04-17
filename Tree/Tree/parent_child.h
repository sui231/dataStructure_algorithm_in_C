#define MAX_TREE_SIZE 100
typedef int ElemType;


/*		����parent_child����		*/
//child
typedef struct CTNode{
	int child;
	struct CTNode* next;
} *ChildPtr;

//Ԫ�أ�parent��
typedef struct {
	ElemType data;
	int parent;
	ChildPtr firstchild;
} CTBox;

//���ṹ
typedef struct {
	CTBox nodes[MAX_TREE_SIZE];
	int r, n;
} BiTree;



/*		����parent����			*/	
typedef struct PTNode {
	ElemType data;
	int parent;
} PTNode;

typedef struct {
	PTNode nodes[MAX_TREE_SIZE];
	int r;		//��λ��
	int n;		//�ڵ���
} PTree;