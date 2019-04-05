#include<iostream>
#include<string>

using namespace std;

void FunError()
{
	//throw "Char * Exception";
	//throw string("String Exception");
	//throw 23.456;
	throw 123;
}
void test0()
{
	try
	{
		FunError();
	}
	catch (const char* e)
	{
		cout << e;
		cout << "const char *类型异常！" << endl;
	}
	catch (string e)
	{
		cout << e;
		cout << "string类型异常！" << endl;
	}
	catch (double e)
	{
		cout << e;
		cout << "double类型异常！" << endl;
	}
	catch (...)
	{
		cout << "其他类型异常!" << endl;
	}
}

int IntException(int a, int b)
{
	if (b == 0)
	{
		throw - 111;
	}
	return a / b;
}
void test1()
{
	int result = -1;
	try
	{
		result = IntException(12, 0);
	}
	catch (int e)
	{
		cout << "错误码" << e << endl;
	}
}

void CharPException()
{
	throw "Char * Exception";
}
void test2()
{
	try
	{
		CharPException();
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
}

void StringException()
{
	throw string("String Exception");
}
void test3()
{
	try
	{
		StringException();
	}
	catch (const string error)
	{
		cout << error << endl;
	}
	//try
	//{
	//}
	//catch (CMemoryException* e)
	//{
	//
	//}
	//catch (CFileException* e)
	//{
	//}
	//catch (CException* e)
	//{
	//}
}

void IntStringException() throw(int, string)
{
}

void NotException() throw()
{
}

class BaseException
{
public:
	virtual void PrintError() = 0;
};

class NullException :public BaseException
{
public:
	virtual void PrintError()
	{
		cout << "NullException" << endl;
	}
};

class ZeroException :public BaseException
{
public:
	virtual void PrintError()
	{
		cout << "ZeroException" << endl;
	}
};

void test4()
{
	try
	{
		//throw NullException();
		throw ZeroException();
	}
	catch (BaseException & ex)
	{
		ex.PrintError();
	}
}

int main()
{
	test0();
	test1();
	return 0;
}