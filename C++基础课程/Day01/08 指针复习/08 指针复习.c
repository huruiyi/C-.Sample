#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>

//1. 指针操作变量
void test01()
{
	int a = 10;
	int* p = (int*)& a;
	//指针的类型 1. 指针+1 移动多少字节 2.当解引用的时候，从你给定的首地址的地方取多少字节出来
	//内存
	char buf[1024] = { 0 };
	memcpy(buf, &a, sizeof(a));

	printf("ret = %d\n", *(int*)buf);
}

struct Person
{
	int age;
	int ID;
	double score;
	char buf[1024];
};

void test02()
{
	struct Person person = { 10, 20, 3.14, "hello world" };

	printf("person.ID:%d\n", *(int*)((char*)& person + offsetof(struct Person, ID)));
	printf("person.buf:%s\n", (char*)& person + offsetof(struct Person, buf));
}

void test03()
{
	//数组
	int arr[10];
	int(*pp)[10] = &arr;
	//sizeof 对数组名取地址，指向整个数组的指针
	//除了以上两种情况，指向数组首元素的指针

	int arr2[10][20];
	int(*p)[20] = arr2;

	*(arr + 1) = arr[1];
}

//指针操作函数
int func(int a, int b)
{
	return a + b;
}

void doLogic()
{
	int a = 10;
	int b = 20;

	int ret = a + b;

	printf("ret = %d\n", ret);
}

void test04()
{
	printf("addr = %p \n", test03);
	int(*pFunc)(int, int) = func;
}

int main() {
	test04();

	system("pause");
	return EXIT_SUCCESS;
}