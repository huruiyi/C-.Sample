#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "PersonĬ�Ϲ��캯��!" << endl;
	}

	Person(int, int)
	{
		cout << "Person�вι��캯��!" << endl;
	}

	Person(const Person &person)
	{
		cout << "Person�������캯��!" << endl;
	}

	~Person()
	{
		cout << "Person��������" << endl;
	}
};

//����������������ֻ�ڵ�ǰ��
void test01()
{
	//������������
	Person(10, 20);
	cout << "end!" << endl;
}

void test2()
{
	Person p(10, 20);
	cout << "end!" << endl;
}
//���������ܵ��ÿ������캯��
void test3()
{
	//int(a) = 123; //�൱int a=123;
	//cout << a << endl;

	Person p;

	//Person(p); //�൱��Person p;
	Person p1 = Person(p);
}

void printPerson(Person &person)
{
}

//��vs�У���ͨ���ÿ�����������������Qt���򲻿���
//Qt�������������Ϊ��ֵ

//��ֵֻ���ڵ�ǰ��ʹ��
void test4()
{
	Person p1;
	Person() = p1;

	const Person &p = Person();

	printPerson(Person());

	//Person p = Person(10, 20);
}

//������ ����Դ���� �Ż�����

int main()
{
	test2();
	system("pause");
	return EXIT_SUCCESS;
}