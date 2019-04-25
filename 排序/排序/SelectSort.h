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
		// ���� [size - i, size - 1]
		// ���� [0, size - 1 - i]
		int max = 0;
		// Ҫ��������������������ֵ���±�
		int j = 0;
		for (j; j <= size - 1 - i; j++) {
			if (arr[j] >= arr[max]) {
				max = j;
			}
		}
		// maxIdx ��¼���������䲿�����������±�
		// ��������������һ��λ�õ������н���
		Swap2(&arr[max], &arr[size - 1 - i]);
	}
	
	//��������whileҲ����
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