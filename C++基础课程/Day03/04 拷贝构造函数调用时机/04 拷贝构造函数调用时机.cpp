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

	Person(const Person& person)
	{
		cout << "Person�������캯��!" << endl;
	}

	~Person()
	{
		cout << "Person��������" << endl;
	}
public:
	char* pName;
};

//������ֵ���ݵķ�ʽ������������

void doLogic(Person person)
{
}

void test01()
{
	Person person;
	doLogic(person);
}

//�����ֲ�������ֵ���ݵķ�ʽ�Ӻ�������(vs debugģʽ�µ���һ�ο������죬qt�������κι���)
//RVO

Person CreatePerson()
{
	cout << "-----------------" << endl;
	Person person;
	cout << "CreatePerson:" << (int)& person << endl;
	return person;
}

void test02()
{
	Person person = CreatePerson();
	cout << "-----------------" << endl;
	cout << "test02:" << (int)& person << endl;
}

#if 0
void CreatePerson(Person* person)
{
	//��person����
	*person

		return;
}
void test02()
{
	//ֻ�Ƿ����ڴ�
	Person person;
	CreatePerson(person);
	cout << (int)& person << endl;
}
#endif

//��һ�������ʼ����һ������
void test03()
{
	Person p1;
	Person p2 = p1;
	Person p3(p2);
	//p2 = p1;

	//1. �������û�д�������ô=�ű�ʾ�������캯������
	//2. ��������Ѿ�������ϣ���ô=�ű�ʾ��ֵ��Ϊ
}

int main() {
	test02();

	system("pause");
	return EXIT_SUCCESS;
}