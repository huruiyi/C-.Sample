#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1. C�����е�constĬ�����ⲿ��������
//2. const���ε�ȫ�ֱ���������ڳ�����(�����޸�),const���εľֲ������ջ�������޸ģ�
const int a = 0;

void test00()
{
	int* pa = (int*)& a;
	*pa = 100;
	printf("%d-%d", a, *pa);
}

void test01()
{
	const int b = 0;
	int* pb = (int*)& b;
	*pb = 100;
	printf("%d-%d", b, *pb);
}

void test02()
{
	//C��C++��ʹ�õ�һ�����ŵ�ʱ��Ҫ������
	extern const int a;
	printf("a = %d\n", a);
}
int main()
{
	test02();
	const char* p = "hello world";

	system("pause");
	return EXIT_SUCCESS;
}