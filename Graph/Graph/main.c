#include"Graph.h"

int main(void) {
	AMGraph G;
	createAMG(&G);

	printAMGragh(G);

	DFS(G, 0);

	BFS(G);

	return 0;
}
//6 8.ABCDEF.AB2 AF5 BC6 BD3 BE2 CD5 CF7 EF3.
//