#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person(int a, int b)
	{
		mA = a;
		mB = b;
	}
public:
	int mA;
	int mB;
};

void test01()
{
	//C++������Ĭ�ϸ��������˸�ֵ�����������Ĭ�ϵĸ�ֵ������������м�ֵ����

	Person p1(10, 100);
	Person p2(20, 200);

	cout << "A:" << p1.mA << " B:" << p1.mB << endl;
	cout << "A:" << p2.mA << " B:" << p2.mB << endl;
	p1 = p2; //p1.operator=(p2);

	cout << "--------------" << endl;
	cout << "A:" << p1.mA << " B:" << p1.mB << endl;
	cout << "A:" << p2.mA << " B:" << p2.mB << endl;
}

class Student
{
public:
	Student(const char* name, int age)
	{
		pName = new char[strlen(name) + 1];
		strcpy(pName, name);
		mAge = age;
	}

	//���±�д��ֵ��������
#if 1
	Student& operator=(const Student& person)
	{
		//�Ȱ�������ڴ��ͷŵ���
		if (this->pName != NULL)
		{
			delete[] this->pName;
			this->pName = NULL;
		}

		//��pName���¿����¿ռ�
		this->pName = new char[strlen(person.pName) + 1];
		strcpy(this->pName, person.pName);

		this->mAge = person.mAge;

		return *this;
	}
#endif

	Student(const Student& person)
	{
		this->pName = new char[strlen(person.pName) + 1];
		strcpy(this->pName, person.pName);
		this->mAge = person.mAge;
	}

	~Student()
	{
		if (pName != NULL)
		{
			delete[] this->pName;
			this->pName = NULL;
		}
	}

public:
	int mAge;
	char* pName;
};

void test02()
{
	Student s1("Edward", 22);
	Student s2("Trump", 33);

	cout << "Name:" << s1.pName << " Age:" << s1.mAge << endl;
	cout << "Name:" << s2.pName << " Age:" << s2.mAge << endl;

	//��ֵ����
	s1 = s2;

	cout << "---------------" << endl;
	cout << "&s1��" << &s1 << "   &s2��" << &s2 << endl;
	cout << "Name:" << s1.pName << " Age:" << s1.mAge << endl;
	cout << "Name:" << s2.pName << " Age:" << s2.mAge << endl;

	getchar();
}

//�Ժ�д�ֻ࣬Ҫ����ڲ���ָ��ָ����ڴ棬�������� �������캯�� ��ֵ��������� ��д��

int main() {
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}