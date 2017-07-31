#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person默认构造函数!" << endl;
	}

	Person(int, int)
	{
		cout << "Person有参构造函数!" << endl;
	}

	Person(const Person &person)
	{
		cout << "Person拷贝构造函数!" << endl;
	}

	~Person()
	{
		cout << "Person析构函数" << endl;
	}
};

//匿名对象声明周期只在当前行
void test01()
{
	//创建匿名对象
	Person(10, 20);
	cout << "end!" << endl;
}

void test2()
{
	Person p(10, 20);
	cout << "end!" << endl;
}
//匿名对象不能调用拷贝构造函数
void test3()
{
	//int(a) = 123; //相当int a=123;
	//cout << a << endl;

	Person p;

	//Person(p); //相当于Person p;
	Person p1 = Person(p);
}

void printPerson(Person &person)
{
}

//在vs中，普通引用可以引用匿名对象，在Qt中则不可以
//Qt把匿名对象理解为右值

//右值只能在当前行使用
void test4()
{
	Person p1;
	Person() = p1;

	const Person &p = Person();

	printPerson(Person());

	//Person p = Person(10, 20);
}

//编译器 编译源代码 优化代码

int main()
{
	test2();
	system("pause");
	return EXIT_SUCCESS;
}