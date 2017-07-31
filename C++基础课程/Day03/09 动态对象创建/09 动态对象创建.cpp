#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person���캯��!" << endl;
		pName = (char *)malloc(64);
		strcpy(pName, "Hello world!");
	}

	void init()
	{
		cout << "Person��ʼ��" << endl;
	}
	~Person()
	{
		cout << "Person��������!" << endl;
		if (pName != NULL)
		{
			free(pName);
		}
	}
public:
	char *pName;
};

void test()
{
	//C++�������� 1.�����ڴ� 2.��ʼ��
	//�ͷŶ��� 1. ������ 2.�ڴ��ͷ�
	Person *person = (Person *)malloc(sizeof(Person));
	if (person == NULL)
	{
		return;
	}
	person->init();

	free(person);

	//��C++�ж�̬����������ʹ��malloc free,ʹ��new delete�����������̬����
}

//1. new��delete�������ʹ��
void test02()
{
	//�ȷ����ڴ棬�ٵ��ù��캯��
	Person *person = new Person;

	//�ȵ����������������ͷ��ڴ�
	delete person;
}

//2. new��delete������������
void test03()
{
	//1. new��������������������
	int *pp = new int(10);
	int *p1 = new int[10];
	char *p2 = new char[64];
	char **p3 = new char*[10];

	//2. new�����Զ����������
	//new���������ʱ�򣬱�������Ҫ���ö����Ĭ�Ϲ��캯��,���Ա����ṩĬ�Ϲ��캯��
	Person *persons = new Person[10];
	delete[] persons;

	//���new��ʱ�����[],��ôdeleteʱ��һ��Ҫ����[]

	//delete void*������ö������������
	cout << "---------" << endl;
	void *ps = new Person;
	delete ps;
}
class Print
{
public:
	int pA;
	Print()
	{
		cout << "A" << endl;
	}
};
int main()
{
	Person a, b[2], *c;

	a.pName = "abc";
	b[0].pName = "abc";
	b[1].pName = "def";

	c = &a;
	c->pName = "def";
	system("pause");
	return EXIT_SUCCESS;
}