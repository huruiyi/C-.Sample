#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1. C�����е�constĬ�����ⲿ��������
//2. const���ε�ȫ�ֱ���������ڳ�����,const���εľֲ������ջ�������޸ģ�
const int a = 0;

void test01()
{
	int *p = (int *)&a;
	*p = 100;
}

void test02()
{
	//C��C++��ʹ�õ�һ�����ŵ�ʱ��Ҫ������
	extern const int a;
	printf("a = %d\n", a);
}
int main() {
	const char *p = "hello world";

	test01();

	system("pause");
	return EXIT_SUCCESS;
}