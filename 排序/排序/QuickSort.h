#pragma once

#include<stdio.h>

void Swap4(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void Print4(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//挖坑
//思想：
//1.为数组找一个基准值并保存下来（我们取最右边的数字） 
//2.begin找大于基准值的数并赋值给end下标所在的数
//3.end找小于基准值的数并赋值给begin下标所在的数
//4.当begin 与 end 的值相等的时候，退出循环
//5.将保存的基准值赋值给 begin 下标所在数字，并返回下标的值，就为分割的下标
int Partition_1(int arr[], int left, int right)
{
	//找基准值（以最右边的right作为基准值）
	int begin = left;
	int end = right;
	int temp = arr[right];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= temp)
		{
			begin++;
		}
		//这里找到比基准值大的数
		arr[end] = arr[begin];
		while (begin < end && arr[end] >= temp)
		{
			end--;
		}
		//这里找到比基准值小的数
		arr[begin] = arr[end];
	}
	arr[begin] = temp;
	return begin;
}

//Hover
//思想：
//1.与挖坑相同，需要先定义一个基准值（我们取最右边的数字）
//2.由 begin 开始寻找大于基准值的数
//3.end 寻找小于基准值的数字
//4.将 begin 与 end 交换，确保大于基准值的数字在右边，小于基准值的在左边
//5.当 begin 与 end 相等的时候退出循环并 将基准值与 begin 下标所在数字与基准值交换
//6.返回下标，就是分割的下标
int Partition_2(int arr[], int left, int right)
{
	int begin = left;
	int end = right;
	int temp = arr[right];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= temp)
		{
			begin++;
		}
		//这里保证了出来的arr[begin]值一定大于基准值temp
		while (begin < end && arr[end] >= temp)
		{
			end--;
		}
		//这里保证了出来的arr[end]值一定小于基准值temp
		//交换这两个值，保证大于基准值的在右边，小于基准值的在左边
		Swap4(&arr[begin], &arr[end]);
	}
	//当 begin 与 end 的值相等的时候退出循环，
	//及保证了分治的条件，在将基准值与 begin 下标的数字交换位置
	Swap(&arr[begin], &arr[right]);
	//这里的基准值必须取rihgt下标所在数，不能用保存的变量temp，否则就会改变数组中的元素
	return begin;
}
//前后下标
//思想：
//9 5 2 7 4 1
//1.同样的，需要先定义一个基准值（我们取最右边的数字）
//2.由 i 开始寻找小于基准值的数，index 作为标记，在 index 的左边都是小于基准值的
//3.找到后将 i 与 index 交换，后 ++index ,确保小于基准值的数字在左边，大于于基准值的在右边
//5.将数组内的数字都寻找完的时候退出循环并 将基准值与 index 下标所在数字交换
//6.返回下标，就是分割的下标
int Partition_3(int arr[], int left, int right)
{
	int index = left;
	for (int i = left; i < right; i++) 
	{
		if (arr[i] < arr[right]) 
		{
			Swap(&arr[i], &arr[index]);
			index++;
		}
	}

	Swap(&arr[index], &arr[right]);

	return index;
}

void Sort4(int arr[], int left, int right)
{
	if (left == right)
	{
		return;
	}
	if (left > right)
	{
		return;
	}
	int index = Partition_2(arr, left, right);
	//这里自己写的时候出错了，原因：
	//分治的时候没有找准边界，边界应该是 左闭右开 的范围

	//（可以这样理解，当我们分割的时候，下标为 idex 的数字已经在它应该存在的位置了，所以不必在进行排序）

	//将index - 1 / index + 1 直接写为 idex
	//导致程序进入了循环状态
	Sort4(arr, left, index - 1);
	Sort4(arr, index + 1, right);
}

void Text4()
{
	int arr[] = { 9,5,2,7,4,1,3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Print4(arr, size);
	Sort4(arr, 0, size - 1);
	Print4(arr, size);
}












