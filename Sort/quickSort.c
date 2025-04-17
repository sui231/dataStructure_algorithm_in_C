#include"Sort.h"

/*
快速排序的基本思想是通过选择一个基准值（pivot）
将数组分为两部分，使得左边部分的所有元素都小于等于基准值，右边部分的所有元素都大于等于基准值
然后分别对左右两部分递归地进行快速排序，最终得到一个有序的数组。
*/

// 更改线性表，确定pivot左右分隔[low, high]区段
int partition(SqList* list, int low, int high) {
	list->r[0] = list->r[low];	// 记 list->r[low] 为中心，用 list->r[0] 暂存，将原来位置空出来
	KeyType pivotKey = list->r[low].key;
	while (low < high) {	// 由两端向中间
		while (low < high && list->r[high].key >= pivotKey)
			--high;
		list->r[low] = list->r[high];	// key比pivotKey小的移动到低端，high空置

		while (low < high && list->r[high].key <= pivotKey)
			++low;
		list->r[high] = list->r[low];	// key比pivotKey大的移动到高端，low空置
	}
	list->r[low] = list->r[0];	// 最后空置位置 pivotKey 填入
	return low;
}

void quickSort(SqList* list, int low, int high) {
	if (low < high) {
		int pivotloc = partition(list, low, high);
		quickSort(list, low, pivotloc - 1);	// 高低子表递归
		quickSort(list, pivotloc + 1, high);
	}
}
/* qsort 是 C 标准库 <stdlib.h> 中提供的一个函数，用于对数组进行快速排序。
这个函数是一个通用的排序函数，可以接受任何数据类型的数组，但是你需要提供一个比较函数来确定元素之间的顺序。
void qsort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));
参数说明：
base：指向要排序数组第一个元素的指针。
nmemb：数组中要排序的元素数量。
size：数组中每个元素的大小（以字节为单位）。
compare：一个函数指针，指向一个由用户提供的比较函数。这个函数负责定义两个数组元素之间的顺序关系。
如果第一个元素小于第二个元素，返回负值。
如果两个元素相等，返回零。
如果第一个元素大于第二个元素，返回正值。
比较函数 compare 的典型实现如下：
int compare(const void* a, const void* b) {
	// 假设数组是 int 类型的
	int arg1 = *((int*)a);
	int arg2 = *((int*)b);

	if (arg1 < arg2) return -1;
	if (arg1 > arg2) return 1;
	return 0;
}
然后你可以这样使用 qsort 函数对数组进行排序：
int main() {
	int nums[] = { 5, 3, 8, 4, 1 };
	int n = sizeof(nums) / sizeof(nums[0]);
	qsort(nums, n, sizeof(int), compare);
	for (int i = 0; i < n; i++)
		printf("%d ", nums[i]);
	return 0;
}
上面的代码将输出排序后的数组：1 3 4 5 8。
注意：在使用 qsort 时，你需要确保你的比较函数 compare 能够正确处理数组中的元素类型，并且在排序过程中不要修改 base 指针指向的数组内容。
*/