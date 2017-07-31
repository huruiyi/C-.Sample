#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1. 函数模板和普通函数区别：函数模板不允许隐式类型转换 普通函数允许隐式类型转
template<class T>
void func01(T a, T b)
{
	cout << "template<class T> void func01(T a, T b)" << endl;
}

void func02(int a, double b)
{
	cout << "void func02(int a,double b)" << endl;
}

void test01()
{
	int a = 10;
	double b = 3.14;

	//func01(a, b);
	func02(a, a);
}

//2. 函数模板和普通函数在一起调用规则
template<class T>
void myFunc(T a, T b)
{
	cout << "void myFunc(T a,T b)" << endl;
}

//二次编译
#if 0
void myFunc(int a, int b)
{
	cout << "void myFunc(T a,T b)" << endl;
}

void myFunc(double a, double b)
{
	cout << "void myFunc(T a,T b)" << endl;
}
#endif

template<class T>
void myFunc(T a, T b, T c)
{
	cout << "void myFunc(T a,T b)" << endl;
}

#if 0
void myFunc(int a, int b)
{
	cout << "void myFunc(int a,int b)" << endl;
}
#endif

void myFunc(int a, double b)
{
	cout << "void myFunc(int a,int b)" << endl;
}

void test02()
{
	int a = 10;
	int b = 20;
	double c = 3.14;

	//1. 函数模板和普通函数都能严格匹配函数调用的情况下，编译器优先匹配普通函数
	myFunc(a, b);
	//2. 可以通过模板空参数列表告诉编译器匹配函数模板
	myFunc<>(a, b);
	//3. 如果说模板能够产生更好的匹配，那么优先匹配模板
	myFunc(a, b);
	//4. 函数模板可以像普通函数那样重载
	myFunc(a, a, a);
}

int main() {
	test02();

	system("pause");
	return EXIT_SUCCESS;
}