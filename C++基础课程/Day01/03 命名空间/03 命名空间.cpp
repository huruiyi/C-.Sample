#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
//using namespace std;

//1. ���������ռ�
namespace A
{
	int a = 10;
	void func()
	{
		std::cout << "void func()" << std::endl;
	}

	struct Person
	{
		std::string name;
		int age;
	};

	Person person;

	const int b = 100;
}

void test01()
{
	std::cout << A::a << std::endl;
	A::func();
	A::Person p;
	A::person;
}

//2. �����ռ�ֻ��ȫ�ַ�Χ�ڶ��壨���´���д����
void test02()
{
	//namespace B{}
}

//3.  �����ռ����Ƕ�������ռ�
namespace B
{
	int a = 10;
	namespace C
	{
		int b = 20;
	}
}
void test03()
{
	std::cout << B::C::b << std::endl;
}

//4. �����ռ��ǿ��ŵģ���ʱ���԰��µķ��ż��뵽�����ռ���
namespace D
{
	int a = 10;
}

namespace D
{
	void func()
	{
		std::cout << "func()!" << std::endl;
	}
}

void test04()
{
	D::a;
	D::func();
}

//5. ���������ռ�
namespace
{
	int p = 10;
	int q = 20;
}

#if 0
static int p = 10;
static int q = 20;
#endif

void test05()
{
	std::cout << p << std::endl;
}

//6. namespace����
namespace VeryLongName
{
	int a = 10;
}
void test06()
{
	namespace VeryShortName = VeryLongName;
	std::cout << VeryShortName::a << std::endl;
	std::cout << VeryLongName::a << std::endl;
}

//7. ���ļ�д
#include"MyNamespace.h"
void test07()
{
	MySpace::func1();
	MySpace::func2(10);
	MySpace::func3(10, 20);
}

int main() {
	test07();

	system("pause");
	return EXIT_SUCCESS;
}