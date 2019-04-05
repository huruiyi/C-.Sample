#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int doLogic(int a, int b)
{
	if (b == 0)
	{
		throw 10; //throw一个Int类型的异常
	}

	return  a / b;
}

//1. 错误码本身没有含义
//2. -1 1...任何数都可以作为错误码，那么就不统一
//3. C语言返回错误码的方式是逐层依赖的，并且返回值是可以忽略的，不能跨函数
//4. C语言的异常是可以忽略的，C++异常不可忽略的

void test()
{
	try
	{
		doLogic(10, 0);
	}
	catch (int)
	{
		throw;
	}
}

void test01()
{
	//试着去执行可能会抛出异常的代码
	try
	{
		test();
	}
	//如果try块中的语句真的抛出了异常，在这里捕获
	//匹配异常通过异常类型
	catch (int e)
	{
		cout << "除0错误:" << e << endl;
	}
}

void myFunc()
{
	//抛出const char *类型异常
	throw "hello exception!";

	//抛出string类型异常
	//throw string("hello exception1");

	//抛出double类型异常
	//throw 3.14;

	//抛出Int类型异常
	//throw 10;
}

//2. 异常是严格类型匹配
void test02()
{
	try
	{
		myFunc();
	}
	catch (const char* e)
	{
		cout << e;
		cout << "const char *类型异常！" << endl;
	}
	catch (string e)
	{
		cout << e;
		cout << "string类型异常！" << endl;
	}
	catch (double e)
	{
		cout << e;
		cout << "double类型异常！" << endl;
	}
	catch (...)
	{
		cout << "其他类型异常!" << endl;
	}
}

int main() {
	test02();

	system("pause");
	return EXIT_SUCCESS;
}