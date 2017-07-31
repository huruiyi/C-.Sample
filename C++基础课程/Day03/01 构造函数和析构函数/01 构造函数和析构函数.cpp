#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//对象的初始化，给对象的成员变量赋初始值
//初始化的目的是为了减少不必要的程序问题
//注意：以后定义任何的变量都要都初始化

class Person
{
public:
	//函数名和类名一致
	//没有返回值，不能写void
	//构造函数可以有参数
	//构造函数可以重载
	//构造函数在创建对象的时候被自动调用
	//构造函数只会被调用一次,在对象从无到有创建的时候
	//只要构造函数调用，必定会产生一个新的对象
	//无参构造函数(默认构造函数)
	Person()
	{
		cout << "Person构造函数!" << endl;
		mA = 0;
		mB = 0;
	}

	//析构函数 ~类名
	//析构函数在对象内存真正销毁之前调用
	//析构函数也是被自动调用的
	//析构函数不能有参数
	//析构函数不能够被重载
	~Person()
	{
		cout << "Person析构函数被调用" << endl;
	}

	//一般情况下，调用几次构造函数就会调用几次析构函数
	//构造函数和析构函数，如果手动添加，编译器会增加一个默认的构造函数 一个默认的析构函数
	//默认的析构和构造，默认什么都不做

public:
	int mA;
	int mB;
};

void test()
{
	Person person;
}

//一般情况下，只要类的内部有指针，并且指针指向了堆内存，析构函数必须要写
class Student
{
public:
	Student(const char *name, int age)
	{
		cout << "Student构造函数!" << endl;
		pName = (char *)malloc(sizeof(char)* strlen(name) + 1);
		strcpy(pName, name);
		mAge = age;
	}

	void printPerson()
	{
		cout << "Name:" << pName << " Age:" << mAge << endl;
	}

	~Student()
	{
		if (pName != NULL)
		{
			cout << "Student析构函数被调用" << endl;
			free(pName);
			pName = NULL;
		}
	}

public:
	char *pName;
	int mAge;
};

void test02()
{
	Student s("Trump", 88);
	s.printPerson();
}

int main() {
	//test();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}