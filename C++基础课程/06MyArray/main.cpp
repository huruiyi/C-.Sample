#include<iostream>
#include<string>
#include "MyArray.h"

void ���������������()
{
	MyArray arr = { 1,2,3,4,5,6,7,8,9 };
	arr.foreach();
}
void  �ӵ������������()
{
	MyArray arr;
	arr += 1, 2, 3, 4, 5, 6, 7, 8, 9;
	arr.foreach();
}

int main()
{
	���������������();
	�ӵ������������();
	return 0;
}