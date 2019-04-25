#pragma once

#include<stdio.h>

void Print3(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Swap3(int* a, int* b)
{
	int i = *a;
	*a = *b;
	*b = i;
}

//9, 5, 2, 7, 4, 1
//5, 9, 2, 7, 4, 1

void Insert(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j > 0 ; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				Swap(&arr[j], &arr[j - 1]);
			}
			else
			{
				break;
			}
		}
	}
}

void Text3()
{
	int arr[] = { 9, 5, 2, 7, 4, 1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Print3(arr, size);
	Insert(arr, size);
	Print3(arr, size);
}