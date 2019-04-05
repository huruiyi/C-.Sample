#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1. 异常变量额声明周期
class MyException
{
public:
	MyException()
	{
		cout << "MyException 构造函数!" << endl;
	}

	MyException(const MyException&)
	{
		cout << "MyException 拷贝构造函数!" << endl;
	}

	void printError()
	{
		cout << "发生错误了!" << endl;
	}

	~MyException()
	{
		cout << "MyException 析构函数！" << endl;
	}
};

void doLogic()
{
	throw MyException();
	//throw new MyException;
}

void test01()
{
	try
	{
		doLogic();
	}
	catch (MyException & ex)
	{
		ex.printError();
	}
}

//2. 继承在异常中的使用
class BaseException
{
public:
	//打印错误信息
	virtual void printError() = 0;
};

//空指针错误
class NullPointerException : public BaseException
{
public:
	virtual void printError()
	{
		cout << "空指针异常!" << endl;
	}
};

//除0移出异常
class ZeroException : public BaseException
{
public:
	virtual void printError()
	{
		cout << "除0溢出异常!" << endl;
	}
};

void myFunc()
{
	throw NullPointerException();
	//throw ZeroException();
}

void test02()
{
	try
	{
		myFunc();
	}
	catch (BaseException & ex)
	{
		ex.printError();
	}
	catch (...)
	{
		cout << "其他异常！" << endl;
	}
}

int main() {
	test02();

	system("pause");
	return EXIT_SUCCESS;
}