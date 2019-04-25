#pragma once

#include<stdio.h>

void Swap2(int* a, int* b)
{
	int i = *a;
	*a = *b;
	*b = i;
}

//9, 5, 2, 7, 4, 1
void Select(int arr[], int size)
{
	for (int i = 0; i < size; i++) {
		// 有序 [size - i, size - 1]
		// 无序 [0, size - 1 - i]
		int max = 0;
		// 要查找整个无序区间的最大值的下标
		int j = 0;
		for (j; j <= size - 1 - i; j++) {
			if (arr[j] >= arr[max]) {
				max = j;
			}
		}
		// maxIdx 记录着无序区间部分最大的数的下标
		// 和无序区间的最后一个位置的数进行交换
		Swap2(&arr[max], &arr[size - 1 - i]);
	}
	
	//在这里用while也可以
	//while (size > 0)
	//{
	//	int max = 0;
	//	for (int j = 0; j < size; j++)
	//	{
	//		if (arr[max] < arr[j])
	//		{
	//			max = j;
	//		}
	//	}
	//	Swap2(&arr[max], &arr[size - 1]);
	//	size--;
	//}
}

void Print2(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Text2()
{
	int arr[] = { 199,84,3,77,4,6,2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Print2(arr, size);
	Select(arr, size);
	Print2(arr, size);
}