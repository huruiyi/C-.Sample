#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		mA = 100;
	}
public:
	static void myfunc()
	{
		cout << "static void myfunc" << endl;
	}
	void func()
	{
		cout << "Base::func()" << endl;
	}
	void func(int)
	{
		cout << "Base::func(int)" << endl;
	}
public:
	int mA;
};

class Derived : public Base
{
public:
	Derived()
	{
		mA = 200;
	}
public:
	static void myfunc()
	{
		cout << "Derived static void myfunc" << endl;
	}
	void func()
	{
		cout << "Derived::func()" << endl;
	}
public:
	int mA;
};

//如果子类的成员和父类成员同名，那么自动隐藏父类成员
//如果子类中和父类中重载的函数重名，父类中所有重载函数被隐藏
//静态成员也会被子类继承

void test()
{
	Derived d;
	cout << d.mA << endl;
	cout << d.Base::mA << endl;

	d.func();
	d.Base::func();

	Derived::Base::myfunc();
}

int main() {
	test();

	system("pause");
	return EXIT_SUCCESS;
}