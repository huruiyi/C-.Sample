#pragma once

/*
	功能：
	生成随机的100个数，范围为100到200之间的随机数，存入一个数组，实现从大到小排序
	与从小到大排序。
	然后设计一个查找函数，查找出最小的数。
	然后设计一个查找函数，查找出最大的数。
	实现输入一个数，检测是否存在

	思路：
	用rand函数生成100以内的随机数然后加上100，然后存进去就OK了
	然后是GetMaxNum函数，得到最大值
	然后是GetMinNum函数，得到最大值
	然后用二分法查找
*/
void PrintArray(int a[], int n);
void bubble_sort_ascend(int a[], int n);
void bubble_sort_descend(int a[], int n);
int GetMaxNum(int a[], int n);
int GetMinNum(int a[], int n);
int BinarySearch(int a[], int n, int elem);

const int ArraySize = 100;