#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		mAge = age;
		mName = name;
	}
	void printPerson()
	{
		cout << "Name:" << mName << " Age:" << mAge << endl;
	}
public:
	string mName;
	int mAge;
};

class SmartPointer
{
public:
	SmartPointer(Person *person)
	{
		pPerson = person;
	}

	Person* operator->()
	{
		return pPerson;
	}

	Person& operator*()
	{
		return *pPerson;
	}

	~SmartPointer()
	{
		if (pPerson != NULL)
		{
			delete pPerson;
			pPerson = NULL;
		}
	}
private:
	Person *pPerson;
};

void doLogic()
{
	//希望有一种方式，可以当我动态创建对象的时候，确保动态创建的对象一定会在合适的时机被释放
	//局部对象会自动在合适的时机调用析构函数
	//Person *person = new Person("aaa", 10);
	//person->printPerson();
	//delete person;

	//自动释放问题解决
	SmartPointer sp(new Person("aaa", 10));
	sp->printPerson();
	(*sp).printPerson();
}

void test()
{
	doLogic();
}

int main() {
	test();

	system("pause");
	return EXIT_SUCCESS;
}