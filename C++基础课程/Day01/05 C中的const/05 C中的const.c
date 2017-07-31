#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1. C语言中的const默认是外部连接属性
//2. const修饰的全局变量，存放在常量区,const修饰的局部存放在栈区（可修改）
const int a = 0;

void test01()
{
	int *p = (int *)&a;
	*p = 100;
}

void test02()
{
	//C和C++中使用的一个符号的时候，要先声明
	extern const int a;
	printf("a = %d\n", a);
}
int main() {
	const char *p = "hello world";

	test01();

	system("pause");
	return EXIT_SUCCESS;
}