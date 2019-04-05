#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdexcept>
using namespace std;

#if 0
class Person
{
public:
	Person()
	{
		mAge = 0;
	}

	void setAge(int age)
	{
		if (age < 0 || age > 100)
		{
			throw out_of_range("����Ӧ����0-100֮��!");
		}

		mAge = age;
	}
public:
	int mAge;
};

void test()
{
	Person person;

	try
	{
		person.setAge(1000);
	}
	catch (exception & ex)
	{
		cout << ex.what() << endl;
	}
}

#endif

class MyException : public exception
{
public:
	MyException(const char* msg)
	{
		pErrorMsg = new char[strlen(msg) + 1];
		strcpy(pErrorMsg, msg);
	}

	MyException(const MyException& ex)
	{
		pErrorMsg = new char[strlen(ex.pErrorMsg) + 1];
		strcpy(pErrorMsg, ex.pErrorMsg);
	}

	MyException& operator=(const MyException& ex)
	{
		if (pErrorMsg != NULL)
		{
			delete[] pErrorMsg;
			pErrorMsg = NULL;
		}

		pErrorMsg = new char[strlen(ex.pErrorMsg) + 1];
		strcpy(pErrorMsg, ex.pErrorMsg);

		return *this;
	}

	virtual const char* what() const
	{
		return pErrorMsg;
	}

	~MyException()
	{
		if (pErrorMsg != NULL)
		{
			delete[] pErrorMsg;
			pErrorMsg = NULL;
		}
	}
public:
	char* pErrorMsg;
};

class Person
{
public:
	Person()
	{
		mAge = 0;
	}

	void setAge(int age)
	{
		if (age < 0 || age > 100)
		{
			throw MyException("����Ӧ����0-100֮��!");
		}

		mAge = age;
	}
public:
	int mAge;
};

void test02()
{
	Person person;

	try
	{
		person.setAge(1000);
	}
	catch (exception & ex)
	{
		cout << ex.what() << endl;
	}
}

int main() {
	//test();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}