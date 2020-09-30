#include "arr_op.h"
#include <stdio.h>

typedef int Status;

#define TRUE 1
#define FALSE 0

void PrintArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
}

void bubble_sort_ascend(int a[], int n)
{ // 将a中整数序列重新排列成自小至大有序的整数序列(冒泡排序)
	int i, j, t;
	Status change;
	for (i = n - 1, change = TRUE; i > 1 && change; --i)
	{
		change = FALSE;
		for (j = 0; j < i; ++j)
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				change = TRUE;
			}
	}
}

void bubble_sort_descend(int a[], int n)
{ // 将a中整数序列重新排列成自大至小有序的整数序列(冒泡排序)
	int i, j, t;
	Status change;
	for (i = n - 1, change = TRUE; i > 0 && change; --i)
	{
		change = FALSE;
		for (j = 0; j < i; ++j)
		{
			if (a[j] < a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				change = TRUE;
			}
		}
	}
}

int GetMaxNum(int a[], int n)
{
	int Max = a[1];

	for (int i = 1; i < n; i++)
	{
		if (Max < a[i])
		{
			Max = a[i];
		}
	}

	return Max;
}

int GetMinNum(int a[], int n)
{
	int Min = a[1];

	for (int i = 1; i < n; i++)
	{
		if (Min > a[i])
		{
			Min = a[i];
		}
	}

	return Min;
}
///*****************二分算法 另一个函数***********必须是顺序排列****
int BinarySearch(int a[], int n, int elem)
{
	int low = 0;
	int high = n;
	int middle = (low + high) / 2;

	while (low <= high)
	{
		if (elem == a[middle])
		{
			return middle;
		}
		else if (elem > a[middle])
		{
			low = middle + 1;
			middle = (low + high) / 2;
		}
		else if (elem < a[middle])
		{
			high = middle - 1;
			middle = (low + high) / 2;
		}
	}

	return -1;
}