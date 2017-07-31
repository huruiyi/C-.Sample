#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	void func()
	{
		mPublic;
		mPrivate;
		mProtected;
	}
public:
	//公共访问权限
	string mPublic;
private:
	//私有权限
	string mPrivate;
protected:
	//保护权限
	string mProtected;
};

//在类的内部，没有权限之分
//公共权限可以在类外访问，私有权限和保护权限的成员在类外无法访问
//私有属性只能在当前类内部使用，子类和类的外部都不能使用
//保护属性只能在类的内部和子类中使用，不能在类的外部访问
//公共权限，类内 类外 子类都可以访问

class Student
{
public:
	string mName;
	void func()
	{
	}
};

struct Teacher
{
	string mName;
	void func()
	{
	}
};

void test02()
{
	//struct和class是一样的，都能定义一个类
	//两者唯一的区别就是默认的访问权限不同，struct默认的访问权限是public class默认访问权限是private

	Student s;
	s.mName;

	Teacher t;
	t.mName;
}

void test()
{
	Person person;
	person.mPublic;
}

int main() {
	system("pause");
	return EXIT_SUCCESS;
}