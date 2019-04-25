//������
#pragma once
#include<stdio.h>

void Swap(int* a, int* b)
{
	int i = *a;
	*a = *b;
	*b = i;
}

//���µ���(�����)
void Heapify(int arr[], int size, int index)
{
	while (1)
	{
		int leftindex = (2 * index) + 1;
		int rightindex = (2 * index) + 2;
		//������Ӳ����ڣ����Һ���Ҳһ��������
		if (leftindex >= size)
		{
			return;
		}
		//�ж��Ƿ����Һ��Ӳ��ҵ������
		int maxindex = leftindex;
		if (rightindex < size && arr[rightindex] > arr[leftindex])
		{
			maxindex = rightindex;
		}
		//�Ƚ����������Ĵ�С
		if (arr[maxindex] >= arr[index])
		{
			Swap(&arr[maxindex], &arr[index]);
		}
		index = maxindex;
	}
}

//������
void CreatHeapify(int arr[], int size)
{
	//�������߼��ϵĴ��濴��������
	//�����һ����Ҷ�ӽڵ㿪ʼһ�δ��µ���һ�ε�����������ʹ����������ѵ��ص�

	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		//����Ĵ����е����⣿
		Heapify(arr, size, i);
	}
}

//�������Ķ���������
void Sort(int arr[], int size)
{
	//�����鴴����Ϊ��
	CreatHeapify(arr, size);
	//ÿ��ȡ���Ѷ�Ԫ�أ����ֵ�������һ��Ԫ�ػ�����size--
	//��һ�δ�������ĶѶ���ʼһ���µ��������¶�
	//ѭ����ֱ��size = 0
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




