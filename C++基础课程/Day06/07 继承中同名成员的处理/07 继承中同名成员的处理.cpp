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

//�������ĳ�Ա�͸����Աͬ������ô�Զ����ظ����Ա
//��������к͸��������صĺ����������������������غ���������
//��̬��ԱҲ�ᱻ����̳�

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