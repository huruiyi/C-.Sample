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
	//ϣ����һ�ַ�ʽ�����Ե��Ҷ�̬���������ʱ��ȷ����̬�����Ķ���һ�����ں��ʵ�ʱ�����ͷ�
	//�ֲ�������Զ��ں��ʵ�ʱ��������������
	//Person *person = new Person("aaa", 10);
	//person->printPerson();
	//delete person;

	//�Զ��ͷ�������
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