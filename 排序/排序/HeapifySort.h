//堆排序
#pragma once
#include<stdio.h>

void Swap(int* a, int* b)
{
	int i = *a;
	*a = *b;
	*b = i;
}

//向下调整(找最大)
void Heapify(int arr[], int size, int index)
{
	while (1)
	{
		int leftindex = (2 * index) + 1;
		int rightindex = (2 * index) + 2;
		//如果左孩子不存在，则右孩子也一定不存在
		if (leftindex >= size)
		{
			return;
		}
		//判断是否有右孩子并找到最大孩子
		int maxindex = leftindex;
		if (rightindex < size && arr[rightindex] > arr[leftindex])
		{
			maxindex = rightindex;
		}
		//比较最大孩子与根的大小
		if (arr[maxindex] >= arr[index])
		{
			Swap(&arr[maxindex], &arr[index]);
		}
		index = maxindex;
	}
}

//创建堆
void CreatHeapify(int arr[], int size)
{
	//将数组逻辑上的储存看作二叉树
	//从最后一个非叶子节点开始一次从下到上一次调整二叉树，使二叉树满足堆的特点

	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		//这里的传参有点问题？
		Heapify(arr, size, i);
	}
}

//二叉树的堆排序（升序）
void Sort(int arr[], int size)
{
	//将数组创建成为堆
	CreatHeapify(arr, size);
	//每次取出堆顶元素（最大值）与最后一个元素互换，size--
	//在一次从新数组的堆顶开始一次下调，建成新堆
	//循环，直到size = 0
	while (size > 0)
	{
		Swap(&arr[0], &arr[size - 1]);
		size--;
		Heapify(arr, size, 0);
	}
}

void Print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Text1()
{
	int arr[] = { 9,3,1,2,6,5,7,4,9,0,3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Print(arr, size);
	Sort(arr, size);
	Print(arr, size);
}




