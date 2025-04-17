#include <stdio.h>
#include <stdlib.h>

// edge
struct Edge {
	int src, dest, weight;// souce, destination 
};

// graph
struct Graph {
	int V, E;
	struct Edge* edge;
};

// union-find _subset
struct _subset {
	int parent;
	int rank;
};

//vertex edge num
struct Graph* createGraph(int V, int E) {
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;
	graph->E = E;
	graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
	return graph;
}

// A utility function to find set of an element i (uses path compression)
// 路径压缩
int find(struct _subset subsets[], int i) {
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}

// A function to do union of two subsets x and y (uses union by rank)
// 按秩合并
void Union(struct _subset subsets[], int x, int y) {
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if (xroot != yroot) {
		if (subsets[xroot].rank < subsets[yroot].rank)
			subsets[xroot].parent = yroot;
		else if (subsets[xroot].rank > subsets[yroot].rank)
			subsets[yroot].parent = xroot;
		else {
			subsets[yroot].parent = xroot;
			subsets[xroot].rank++;
		}
	}
}

// Compare two edges according to their weights. Used in qsort()
int compareEdges(const void* a, const void* b) {
	struct Edge* a1 = (struct Edge*)a;
	struct Edge* a2 = (struct Edge*)b;
	return a1->weight - a2->weight;
}

// Function to construct MST using Kruskal's algorithm
void KruskalMST(struct Graph* graph) {
	int V = graph->V;
	struct Edge* result = malloc((V - 1) * sizeof(struct Edge)); // Tnis will store the resultant MST
	int e = 0; // An index variable, used for result[]
	int i = 0; // An index variable, used for sorted edges

	// Step 1: Sort all the edges in non-decreasing order of their weight
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdges);

	// Allocate memory for creating V ssubsets
	struct _subset* subsets = (struct _subset*)malloc(V * sizeof(struct _subset));

	// Create V subsets with single elements
	for (int v = 0; v < V; ++v) {
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	// Number of edges to be taken is equal to V-1
	while (e < V - 1 && i < graph->E) {
		// Step 2: Pick the smallest edge and increment the index for next iteration
		struct Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		// If including this edge does not cause a cycle
		if (x != y) {
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
		// Else discard the next_edge
	}

	// Print the resultant MST
	printf("Following are the edges in the constructed MST\n");
	for (i = 0; i < e; ++i)
		printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);

	// Free allocated memory
	free(result);
	free(subsets);
}

/*
rank:
高度的估计：它不一定是树的精确高度，而是一个上界估计。在没有路径压缩的情况下，它可以理解为树的最大高度。
合并的优化：在合并两个集合时，按秩合并（Union by rank）策略是将rank较小的树的根节点指向rank较大的树的根节点。
这样做的原因是保持树的平衡，避免形成高度很大的树，这样可以减少查找操作的时间。主要反映的是最坏情况下的树高。
*/


int main() {
	int V = 4;  // Number of vertices in graph
	int E = 5;  // Number of edges in graph
	struct Graph* graph = createGraph(V, E);

	// add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 10;

	// add edge 0-2
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 6;

	// add edge 0-3
	graph->edge[2].src = 0;
	graph->edge[2].dest = 3;
	graph->edge[2].weight = 5;

	// add edge 1-3
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 15;

	// add edge 2-3
	graph->edge[4].src = 2;
	graph->edge[4].dest = 3;
	graph->edge[4].weight = 4;

	KruskalMST(graph);

	free(graph->edge);
	free(graph);

	return 0;
}
