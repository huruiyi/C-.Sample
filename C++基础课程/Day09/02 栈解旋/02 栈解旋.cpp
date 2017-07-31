#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person构造函数！" << endl;
	}

	~Person()
	{
		cout << "Person析构函数!" << endl;
	}
};

void doLogic()
{
	Person p1;
	Person p2;
	//Person *p = new Person;

	throw 10;
}

//抛出异常之前会将栈变量释放
int main() {
	try
	{
		doLogic();
	}
	catch (...)
	{
		cout << "捕获异常！" << endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}