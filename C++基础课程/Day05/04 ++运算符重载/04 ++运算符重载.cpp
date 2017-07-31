#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyInteger
{
public:
	MyInteger()
	{
		mNum = 0;
	}
public:
	MyInteger& operator++()
	{
		++mNum;
		return *this;
	}

	//仅仅是语法上区别而已，就是为了和前置++区分
	MyInteger operator++(int)
	{
		//先保存当前对象
		MyInteger temp(*this);
		//再对当前对象++
		++mNum;
		//返回temp
		return temp;
	}

public:
	int mNum;
};

void test01()
{
	int a = 10;
	//1. 前置++ 先对a递增1，再返回a
	//2. 后置++ 先返回a的拷贝，再对a递增1
	//cout << (++a) << endl;
	cout << (a++) << endl;
	cout << a << endl;
}

//如果重载的是前置++ ,那么引用返回
//如果重载的是后置++，那么值返回
//前置++ operator++() ,后置++是 operator++(int)
void test02()
{
	MyInteger myint;
	//MyInteger myint2 =  (++myint);
	//cout << myint.mNum << endl;
	//++(++myint);
	//cout << myint.mNum << endl;

	cout << (myint++).mNum << endl;
	cout << myint.mNum << endl;
}

int main() {
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}