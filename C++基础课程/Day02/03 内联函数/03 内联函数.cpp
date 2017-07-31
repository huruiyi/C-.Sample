#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//为什么使用宏函数?宏函数有什么好处?
//

int func(int a, int b)
{
	return a + b;
}

#define MyFunc(a, b) ((a) + (b))

//对于短小并且频繁使用的函数，一般会写称宏函数

int main() {
	func(10, 20);

	int a = MyFunc(10, 20);
	cout << a << endl;

	double d = MyFunc(1.8, 2.2);
	cout << d << endl;

	system("pause");
	return EXIT_SUCCESS;
}