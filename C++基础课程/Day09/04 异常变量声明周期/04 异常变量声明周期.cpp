#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1. �쳣��������������
class MyException
{
public:
	MyException()
	{
		cout << "MyException ���캯��!" << endl;
	}

	MyException(const MyException&)
	{
		cout << "MyException �������캯��!" << endl;
	}

	void printError()
	{
		cout << "����������!" << endl;
	}

	~MyException()
	{
		cout << "MyException ����������" << endl;
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

//2. �̳����쳣�е�ʹ��
class BaseException
{
public:
	//��ӡ������Ϣ
	virtual void printError() = 0;
};

//��ָ�����
class NullPointerException : public BaseException
{
public:
	virtual void printError()
	{
		cout << "��ָ���쳣!" << endl;
	}
};

//��0�Ƴ��쳣
class ZeroException : public BaseException
{
public:
	virtual void printError()
	{
		cout << "��0����쳣!" << endl;
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
		cout << "�����쳣��" << endl;
	}
}

int main() {
	test02();

	system("pause");
	return EXIT_SUCCESS;
}