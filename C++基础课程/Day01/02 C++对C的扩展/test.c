#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

func()
{
	return 10;
}

//1. �ɶ��� 2.Ч��

int main01() {
	//printf("ret = %d\n", func(10,20,30));

	//���10���ڴ�  �ڴ�����10
	int a = 10;
	int b = 20;

	printf("ret = %d\n", a > b ? a : b);

	//(a > b ? a : b) = 100;

	//10����������������ڴ�����
	//10 = 100;

	system("pause");
	return EXIT_SUCCESS;
}