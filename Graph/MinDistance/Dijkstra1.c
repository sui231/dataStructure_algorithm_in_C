#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9  // Number of vertices

typedef struct {
    int vertex;
    int dist;
} MinHeapNode;

typedef struct {
    MinHeapNode* array;
    int size;
    int capacity;
    int* pos; // Needed to decrease key
} MinHeap;

//3. 堆操作函数
//实现创建堆、插入元素、提取最小元素（堆顶）和减少键值的函数
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode*)malloc(capacity * sizeof(MinHeapNode));
    return minHeap;
}

void swapMinHeapNode(MinHeapNode* a, MinHeapNode* b) {
    MinHeapNode t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left].dist < minHeap->array[smallest].dist)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right].dist < minHeap->array[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        // Swap positions
        MinHeapNode smallestNode = minHeap->array[smallest];
        MinHeapNode idxNode = minHeap->array[idx];

        // Swap nodes
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

MinHeapNode extractMin(MinHeap* minHeap) {
    if (minHeap->size == 0) return (MinHeapNode) { -1, 0 };

    MinHeapNode root = minHeap->array[0];
    MinHeapNode lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->size--;
    minHeapify(minHeap, 0);

    return root;
}

void decreaseKey(MinHeap* minHeap, int v, int dist) {
    // Get the index of v in heap array
    int i = minHeap->pos[v];

    // Get the node and update its dist value
    minHeap->array[i].dist = dist;

    // Travel up while the complete tree is not heapified.
    // This is a O(Logn) loop
    while (i && minHeap->array[i].dist < minHeap->array[(i - 1) / 2].dist) {
        // Swap this node with its parent
        minHeap->pos[minHeap->array[i].vertex] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2].vertex] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

        // move to parent index
        i = (i - 1) / 2;
    }
}

int isInMinHeap(MinHeap* minHeap, int v) {
    if (minHeap->pos[v] < minHeap->size)
        return 1;
    return 0;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];      // dist values used to pick minimum weight edge in cut
    MinHeap* minHeap = createMinHeap(V);

    // Initialize min heap with all vertices. dist value of all vertices
    for (int v = 0; v < V; ++v) {
        dist[v] = INT_MAX;
        minHeap->array[v].vertex = v;
        minHeap->array[v].dist = dist[v];
        minHeap->pos[v] = v;
    }

    // Make dist value of src vertex as 0 so that it is extracted first
    minHeap->array[src].dist = 0;
    decreaseKey(minHeap, src, 0);

    // Initially size of min heap is equal to V
    minHeap->size = V;

    // In the following loop, min heap contains all nodes
    // whose shortest distance is not yet finalized.
    while (minHeap->size != 0) {
        // Extract the vertex with minimum distance value
        MinHeapNode minHeapNode = extractMin(minHeap);
        int u = minHeapNode.vertex; // Store the extracted vertex number

        // Traverse through all adjacent vertices of u (the extracted
        // vertex) and update their distance values
        for (int v = 0; v < V; ++v) {
            // Only if the extracted vertex is not in the processed set.
            if (isInMinHeap(minHeap, v) && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                // update distance value in min heap also
                decreaseKey(minHeap, v, dist[v]);
            }
        }
    }

    // print the calculated shortest distances
    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 0, 0},
        {2, 0, 6, 3, 2},
        {0, 6, 0, 5, 0},
        {0, 3, 5, 0, 0},
        {0, 2, 0, 0, 0}
    };

    dijkstra(graph, 0);
    return 0;
}