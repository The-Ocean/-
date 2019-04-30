#pragma once

#include<stdio.h>

void Swap6(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void Print6(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//希尔排序
//思路：
//把记录按下标的一定增量分组，对每组使用直接插入排序算法排序。
//随着增量逐渐减少，每组包含的关键词越来越多。
//当增量减至1时，整个文件恰被分成一组，算法便终止。
void InsertSortWithGap(int array[], int size, int gap) {
	for (int i = 0; i < size; i++) {
		int key = array[i];
		int j;
		for (j = i - gap; j >= 0 && array[j] > key; j -= gap) {
			array[j + gap] = array[j];
		}

		array[j + gap] = key;
	}
}

void Sort6(int array[], int size) {
	int gap = size;
	while (1) {
		gap = gap / 3 + 1;
		// gap = gap / 2;

		InsertSortWithGap(array, size, gap);

		if (gap == 1) {
			break;
		}
	}
}

void Text6()
{
	int arr[] = { 9,5,2,7,4,1,3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Print6(arr, size);
	Sort6(arr, size);
	Print6(arr, size);
}
