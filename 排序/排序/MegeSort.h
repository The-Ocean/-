#pragma once
#include<stdio.h>
#include<stdlib.h>


void Swap7(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void Print7(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//归并排序
//思想：
//1.将数组分成已经有序的两个数组，在合并这两个数组
//2.如果整个数组都是无序的，就在将两个数组分别分为两个数组，
//3.直到所分的数组中只有一个元素的时候，那么它肯定是有序的
//4.然后在一次合并这些分开的数组
void Merge(int array[], int low, int mid, int high, int extra[]) {
	// [low, high)

	int i = low;	// [low, mid)
	int j = mid;	// [mid, high)
	int k = low;	// extra[low, high)

	while (i < mid && j < high) {
		if (array[i] <= array[j]) {	// = 保证了稳定性
			extra[k++] = array[i++];
		}
		else {
			extra[k++] = array[j++];
		}
	}

	while (i < mid) {
		extra[k++] = array[i++];
	}

	while (j < high) {
		extra[k++] = array[j++];
	}

	for (int x = low; x < high; x++) {
		array[x] = extra[x];
	}
}

// [low, high)
void MergeSortInner(int array[], int low, int high, int extra[]) {
	// 2. 直到 size == 1 || size == 0
	if (low >= high) {
		// size == 0
		return;
	}

	if (low + 1 == high) {	// [3, 4)
		// size == 1
		return;
	}

	// 1. 平均切割
	int mid = low + (high - low) / 2;
	// 2. 分治处理左右两个小区间
	MergeSortInner(array, low, mid, extra);	// [low, mid)
	MergeSortInner(array, mid, high, extra);	// [mid, high)
	// 3. 合并两个有序数组
	Merge(array, low, mid, high, extra);
}

void Sort7(int array[], int size) {
	int *extra = (int *)malloc(sizeof(int)* size);
	MergeSortInner(array, 0, size, extra);
	free(extra);
}

void Text7()
{
	int arr[] = { 9,5,2,7,4,1,3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Print7(arr, size);
	Sort7(arr, size);
	Print7(arr, size);
}
