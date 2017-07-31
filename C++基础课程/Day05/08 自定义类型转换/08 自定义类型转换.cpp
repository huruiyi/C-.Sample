#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Student
{
public:
	Student(int a, int b)
	{
		mA = a;
		mB = b;
	}
public:
	int mA;
	int mB;
};

class Person
{
public:
	Person(int age)
	{
		mAge = age;
	}

	//������ν�Person����ת��ΪInt����
	operator int()
	{
		return 1000;
	}

	//��ν�Person����ת��ΪBool����
	operator bool()
	{
		return mAge > 0;
	}

	//��Person����ת��ΪStudent����
	operator Student()
	{
		return Student(mAge, mAge);
	}

public:
	int mAge;
};

void test()
{
	Student s1 = Person(10);
	Person p(100);
	int ret = p;
	cout << "ret = " << ret << endl;

	if (p)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	Student s = p;
}

int main()
{
	test();

	system("pause");
	return EXIT_SUCCESS;
}