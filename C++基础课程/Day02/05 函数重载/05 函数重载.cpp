#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//函数重载复用名字
//函数重载理解一种多态(静态多态)
//在C++中函数名是可以一样的

//函数重载的条件
//1. 同一个作用域下
//2. 函数的参数个数不同
//3. 函数的参数类型不同
//4. 函数参数的顺序不同
//5. 注意：函数返回类型不能作为重载依据

void func()
{
	cout << "void func()" << endl;
}

void func(int a)
{
	cout << "void func(int a)" << endl;
}

void func(double a)
{
	cout << "void func(double a)" << endl;
}

void func(int a, double b)
{
	cout << "func(int a, double b)" << endl;
}

void func(double a, int b)
{
	cout << "void func(double a,int b)" << endl;
}

//返回类型不能作为重载的依据
//因为函数的返回值可以忽略
#if 0
int func(double a, int b)
{
	cout << "void func(double a,int b)" << endl;
}
#endif

void test()
{
	int a = 10;
	int b = 20;
	double c = 3.14;

	//1. 函数调用首先严格匹配参数的类型，如果匹配成功则调用成功。
	//2. 如果没有严格类型的参数，那么编译器会对参数进行隐式类型转换，如果转换成功之后能
	//匹配调用，那么也视为函数调用成功
	func(b, c);
	//函数重载中使用默认参数可能会导致二义性
	//func(a);
}

int main() {
	test();

	system("pause");
	return EXIT_SUCCESS;
}