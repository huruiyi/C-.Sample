#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#if 0
class Person;

void SwapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void SwapDouble(double& a, double& b) {}
void SwapPerson(Person& a, Person& b) {}

#endif
//如果把数据类型可以当做参数传递给函数、或者类
//这种把数据类型当做参数传递的技术，叫做模板，类型参数化
//函数模板中出现的类型就不再是具体的类型，而是一个虚拟的类型

//template<typename T>

//template只对紧跟后面的函数或者类生效
//可以把T理解为形参，T只是个虚拟类型
//可以声明多个虚拟类型
//函数模板可以自动推导类型(类模板不可以)
//调用函数模板的时候必须要确定T的类型，即使程序并没有用这个虚拟类型T
//函数模板可以有默认值，默认值是个类型template<class T = int>
template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T = int, int n = 100>
void func()
{
	cout << "n = " << n << endl;
	cout << "func()" << endl;
}

void test()
{
	//函数模板如何调用
	int a = 10;
	int b = 20;
	double c = 3.14;
	//1. 显式指定模板参数列表
	mySwap<int>(a, b);

	//2. 自动推导类型
	mySwap(a, b);

	//func<int>();
	//func();
}

int main() {
	test();

	system("pause");
	return EXIT_SUCCESS;
}