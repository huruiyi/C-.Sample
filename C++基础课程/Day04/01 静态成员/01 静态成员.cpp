#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//实例化 Person p;
//静态成员被所有由Person创建的对象共享

class Person
{
public:
	static int getNum()
	{
		return mNum;
	}
private:
	//静态成员变量
	static int mNum;  //编译器会把这行代码当做静态变量的声明
	int mAge;
};

int Person::mNum = 100; //类外初始化，类外定义

void test01()
{
	//1. 直接通过类名来访问
	cout << Person::getNum() << endl;

	//2. 通过对象来访问
	Person p1, p2, p3;

	//p2.mNum = 200;

	cout << p1.getNum() << endl;
	cout << p2.getNum() << endl;
	cout << p3.getNum() << endl;

	//3. 静态成员也有访问权限
}

//静态成员变量目的是为了共享数据
//静态成员函数目的是为了访问静态成员变量

int main() {
	test01();

	system("pause");
	return EXIT_SUCCESS;
}