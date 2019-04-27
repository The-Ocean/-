#pragma once
#include<stdio.h>

void Swap5(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void Print5(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//冒泡排序
//思想：
//9 5 2 7 4 1 3 
//1.两个数之间相互比较大小，每次将较大的值的数字放在后面
//2.循环整个数组，一次遍历后就将最大值放在了最后
//3.在--size,在次循环
void Sort5(int arr[], int size)
{
	while (size)
	{
		for (int i = 1; i < size; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				Swap5(&arr[i - 1], &arr[i]);
			}
		}
		size--;
	}
}

void Text5()
{
	int arr[] = { 9,5,2,7,4,1,3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Print5(arr, size);
	Sort5(arr, size);
	Print5(arr, size);
}
