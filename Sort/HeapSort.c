#include"Sort.h"
/*
1. 构建最大堆
从最后一个非叶子节点开始，逐个向上调整节点，使其满足最大堆的性质。最后一个非叶子节点的索引为n // 2 - 1，其中n是数组的长度。
2. 交换元素并调整堆
将堆顶元素（最大值）与堆的最后一个元素交换。
排除最后一个元素，对剩余的元素重新调整为最大堆。
重复上述步骤，直到整个数组有序。
*/


typedef SqList HeapType;
// 左子节点的位置是 2 * j
// 右子节点的位置是 2 * j + 1

void swap(RecordType* a, RecordType* b) {
	RecordType temp = *a;
	*a = *b;
	*b = temp;
}

// 建立大顶堆
// 通过交换堆顶元素（最大值）到数组末尾，并缩小堆大小进行排序
// s 为子堆的根节点位置
// m 调整的最后一个元素的位置
void heapAdjust(HeapType* heap, int s, int n) {
	RecordType rc = heap->r[s]; // rc为子堆的根节点，临时存储开始时位于 s 的元素，heap->r[s]空置

	for (int j = 2 * s; j <= n; j *= 2) { // 从 s 的左子节点开始，不断向下
		if (j < n && heap->r[j].key < heap->r[j + 1].key)
			j++; // left < right，指向右子节点

		if (rc.key >= heap->r[j].key)
			break; // left >= right，不需要调整

		heap->r[s] = heap->r[j]; // 将较大的子节点提升到 s
		s = j; // 更新 s，继续向下调整
	}

	heap->r[s] = rc; // 将最开始的根节点值放到最终确定的位置
}

void heapSort(HeapType* heap) {
	for (int i = heap->length / 2; i > 0; i--) {
		// 从最后一个非叶子节点开始向根节点调整，确保每个子堆都是大顶堆
		// length / 2 节点后都是叶子节点，不需要调整
		heapAdjust(heap, i, heap->length);
	}

	for (int i = heap->length; i > 1; i--) {
		// 将当前堆中最大的元素（堆顶元素，即数组的第一个元素）与堆的最后一个元素交换
		swap(&heap->r[1], &heap->r[i]);
		// 交换后，最大元素位于其最终位置
		// 现在需要重新调整堆，但是排除已经排好的最大元素（位于数组末尾）
		heapAdjust(heap, 1, i - 1);
	}
}


// 递归实现
void heapAdjust(HeapType* heap, int rootIndex, int n) {
	int largest = rootIndex;  // 初始化最大元素索引为当前根节点
	int leftChild = 2 * rootIndex;  // 计算左子节点的索引
	int rightChild = 2 * rootIndex + 1;  // 计算右子节点的索引

	// 检查左子节点是否存在并且是否大于当前根节点的值
	if (leftChild <= n && heap->r[leftChild].key > heap->r[largest].key) {
		largest = leftChild;
	}

	// 检查右子节点是否存在并且是否大于当前最大值
	if (rightChild <= n && heap->r[rightChild].key > heap->r[largest].key) {
		largest = rightChild;
	}

	// 如果最大值不是根节点，交换并递归调整
	if (largest != rootIndex) {
		swap(&heap->r[rootIndex], &heap->r[largest]);  // 交换根节点与最大子节点
		heapAdjust(heap, largest, n);  // 递归调整下沉的子堆
	}
}




//#include <stdio.h>
//
//void swap(int* a, int* b) {
//    int t = *a;
//    *a = *b;
//    *b = t;
//}
//
//void heapify(int arr[], int n, int i) {
//    int largest = i;
//    int left = 2 * i + 1;
//    int right = 2 * i + 2;
//
//    // 如果左子节点大于根节点
//    if (left < n && arr[left] > arr[largest])
//        largest = left;
//
//    // 如果右子节点比最大的还大
//    if (right < n && arr[right] > arr[largest])
//        largest = right;
//
//    // 如果最大不是根节点
//    if (largest != i) {
//        swap(&arr[i], &arr[largest]);
//
//        // 递归地定义子堆
//        heapify(arr, n, largest);
//    }
//}
//
//void heapSort(int arr[], int n) {
//    // 建立堆
//    for (int i = n / 2 - 1; i >= 0; i--)
//        heapify(arr, n, i);
//
//    // 一个个从堆顶取出元素
//    for (int i = n - 1; i >= 0; i--) {
//        // 移动当前根到堆的末尾
//        swap(&arr[0], &arr[i]);
//
//        // 调用 max heapify 在减小的堆上
//        heapify(arr, i, 0);
//    }
//}
//
//int main() {
//    int arr[] = { 12, 11, 13, 5, 6, 7 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    heapSort(arr, n);
//
//    printf("Sorted array is \n");
//    for (int i = 0; i < n; ++i)
//        printf("%d ", arr[i]);
//    printf("\n");
//
//    return 0;
//}


