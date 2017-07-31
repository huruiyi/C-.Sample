#include <iostream>
#include <string>

using namespace std;

int a = 10;

namespace CAndCPP
{
	void test1()
	{
		a = 100;
		cout << "局部 a =  " << a << endl;
		cout << "全局 a = " << ::a << endl;
	}

	void test2()
	{
		//C++必须显示的类型转化
		//char *p = malloc(sizeof(char) * 10); //C可以
		char *p = (char *)malloc(sizeof(char) * 10);
	}

	/*
	三目运算符：
	C:返回的是变量的值
	C++:返还的是变量
	*/
	void test3()
	{
		int a = 10;
		int b = 20;
		cout << "a =" << a << ",b= " << b << endl;
		(a > b ? a : b) = 100;
		cout << "a =" << a << ",b= " << b << endl;
	}

#if  0/*C语言函数返回值必须和定义的一致*/
	//
	void test4()
	{
		return 123;
	}
#endif //

	struct  Person
	{
		string Name;
		int Age;
		void PrintInfo()
		{
			cout << "Name= " << Name << ",Age= " << Age;
		}
	};
	void test5()
	{
		Person p;
		p.Name = "Obama";
		p.Age = 100;
		p.PrintInfo();
	}
}