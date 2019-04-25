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

//�ڿ�
//˼�룺
//1.Ϊ������һ����׼ֵ����������������ȡ���ұߵ����֣� 
//2.begin�Ҵ��ڻ�׼ֵ��������ֵ��end�±����ڵ���
//3.end��С�ڻ�׼ֵ��������ֵ��begin�±����ڵ���
//4.��begin �� end ��ֵ��ȵ�ʱ���˳�ѭ��
//5.������Ļ�׼ֵ��ֵ�� begin �±��������֣��������±��ֵ����Ϊ�ָ���±�
int Partition_1(int arr[], int left, int right)
{
	//�һ�׼ֵ�������ұߵ�right��Ϊ��׼ֵ��
	int begin = left;
	int end = right;
	int temp = arr[right];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= temp)
		{
			begin++;
		}
		//�����ҵ��Ȼ�׼ֵ�����
		arr[end] = arr[begin];
		while (begin < end && arr[end] >= temp)
		{
			end--;
		}
		//�����ҵ��Ȼ�׼ֵС����
		arr[begin] = arr[end];
	}
	arr[begin] = temp;
	return begin;
}

//Hover
//˼�룺
//1.���ڿ���ͬ����Ҫ�ȶ���һ����׼ֵ������ȡ���ұߵ����֣�
//2.�� begin ��ʼѰ�Ҵ��ڻ�׼ֵ����
//3.end Ѱ��С�ڻ�׼ֵ������
//4.�� begin �� end ������ȷ�����ڻ�׼ֵ���������ұߣ�С�ڻ�׼ֵ�������
//5.�� begin �� end ��ȵ�ʱ���˳�ѭ���� ����׼ֵ�� begin �±������������׼ֵ����
//6.�����±꣬���Ƿָ���±�
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
		//���ﱣ֤�˳�����arr[begin]ֵһ�����ڻ�׼ֵtemp
		while (begin < end && arr[end] >= temp)
		{
			end--;
		}
		//���ﱣ֤�˳�����arr[end]ֵһ��С�ڻ�׼ֵtemp
		//����������ֵ����֤���ڻ�׼ֵ�����ұߣ�С�ڻ�׼ֵ�������
		Swap4(&arr[begin], &arr[end]);
	}
	//�� begin �� end ��ֵ��ȵ�ʱ���˳�ѭ����
	//����֤�˷��ε��������ڽ���׼ֵ�� begin �±�����ֽ���λ��
	Swap(&arr[begin], &arr[right]);
	//����Ļ�׼ֵ����ȡrihgt�±��������������ñ���ı���temp������ͻ�ı������е�Ԫ��
	return begin;
}
//ǰ���±�
//˼�룺
//9 5 2 7 4 1
int Partition_3(int arr[], int left, int right)
{

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
	//�����Լ�д��ʱ������ˣ�ԭ��
	//���ε�ʱ��û����׼�߽磬�߽�Ӧ���� ����ҿ� �ķ�Χ

	//������������⣬�����Ƿָ��ʱ���±�Ϊ idex �������Ѿ�����Ӧ�ô��ڵ�λ���ˣ����Բ����ڽ�������

	//��index - 1 / index + 1 ֱ��дΪ idex
	//���³��������ѭ��״̬
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












