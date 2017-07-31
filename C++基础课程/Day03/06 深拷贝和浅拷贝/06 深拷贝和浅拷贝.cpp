#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

namespace ԭʼ������ֵ
{
	class Person
	{
	public:
		Person() {    }
		Person(int a, int b, const char *pname)
		{
			this->mA = a;
			this->mB = b;
			this->pName = new char[strlen(pname) + 1];
			strcpy(pName, pname);
		}
		Person(const Person &person)
		{
			this->pName = person.pName;

			this->mA = person.mA;
			this->mB = person.mB;
			cout << "�������캯��!" << endl;
		}

		Person& operator=(const Person &person)
		{
			this->pName = person.pName;

			this->mA = person.mA;
			this->mB = person.mB;
			cout << "��ֵ����!" << endl;
			return *this;
		}
		~Person()
		{
			if (this->pName != NULL)
			{
				delete this->pName;
				this->pName = NULL;
			}
		}
	public:
		char *pName;
		int mA;
		int mB;
	};

	void test01()
	{
		Person p1(100, 200, "Name");

		Person p2 = p1;

		Person p3;
		p3 = p1;
		/*
		0x00ef8ab0�洢����
		0x009DFD94  b0
		0x009DFD95  8a
		0x009DFD96  ef
		0x009DFD97  00

		0x00ef8ab0 "Name"�洢����
		0x00EF8AB0  4e  N
		0x00EF8AB1  61  a
		0x00EF8AB2  6d  m
		0x00EF8AB3  65  e
		*/
		cout << "A = " << p2.mA << " B:" << p2.mB << endl;
		cout << "&p1��" << &p1 << "   " << "p1.pName����Ӧ�ѿռ䣩��" << &p1.pName << endl;
		cout << "&p2��" << &p2 << "   " << "p2.pName����Ӧ�ѿռ䣩��" << &p2.pName << endl;
		cout << "&p3��" << &p3 << "   " << "p3.pName����Ӧ�ѿռ䣩��" << &p3.pName << endl;

		cout << p1.pName << endl;
		cout << p2.pName << endl;
		cout << p3.pName << endl;
		int a = 123;
		int *p = &a;
		int &r = a;

		printf("&p1.pName=%p��%s\n", p1.pName, p1.pName);
		printf("&p2.pName=%p��%s\n", p2.pName, p2.pName);
		printf("&p3.pName=%p��%s\n", p3.pName, p3.pName);
	}
}

namespace �Զ��忽����ֵ
{
	class Person
	{
	public:
		Person() {    }
		Person(int a, int b, const char *pname)
		{
			this->mA = a;
			this->mB = b;
			this->pName = new char[strlen(pname) + 1];
			strcpy(pName, pname);
		}
		Person(const Person &person)
		{
			//�ڽ��п���ǰ����û����Ч��ֵ��û�й�����ϣ����̲�������ͷ�
			this->pName = new char[strlen(person.pName) + 1];
			strcpy(this->pName, person.pName);

			this->mA = person.mA;
			this->mB = person.mB;
			cout << "�������캯��!" << endl;
		}

		Person& operator=(const Person &person)
		{
			//�ڸ�ֵ֮ǰ������ĵ��ڿؿռ��ֵ��Ҫ����
			if (this->pName != NULL)
			{
				delete this->pName;//���ֵ
				this->pName = NULL; //���ַ
			}

			this->pName = new char[strlen(person.pName) + 1];
			strcpy(this->pName, person.pName);

			this->mA = person.mA;
			this->mB = person.mB;

			return *this;
		}
		~Person()
		{
			if (this->pName != NULL)
			{
				delete this->pName;
				this->pName = NULL;
			}
		}
	public:
		char *pName;
		int mA;
		int mB;
	};

	void test01()
	{
		Person p1(100, 200, "Name1");

		Person p2 = p1;

		Person p3(300, 400, "Name2");
		cout << p3.pName << "  " << p3.mA << "   " << p3.mB << endl;

		p3 = p1;
		/*
			&p1.pName
			&p2.pName
			&p3.pName
		*/
		printf("&p1=%p    &p1.pName=%p    %s\n", &p1, p1.pName, p1.pName);

		printf("&p2=%p    &p2.pName=%p    %s\n", &p2, p2.pName, p2.pName);

		printf("&p3=%p    &p3.pName=%p    %s\n", &p3, p3.pName, p3.pName);
	}
}

class Student
{
public:
	Student(const char *str, int age)
	{
		pName = (char *)malloc(sizeof(char)* strlen(str) + 1);
		strcpy(pName, str);
		mAge = age;
	}

	Student(const Student &stu)
	{
		this->pName = new char[strlen(stu.pName) + 1];

		strcpy(pName, stu.pName);
		mAge = stu.mAge;
	}

	Student &operator=(const Student &stu)
	{
		if (this->pName)
		{
			delete this->pName;
			this->pName = NULL;
		}
		this->pName = new char[strlen(stu.pName) + 1];
		strcpy(this->pName, stu.pName);

		this->mAge = stu.mAge;
		return *this;
	}

	~Student()
	{
		if (pName != NULL)
		{
			delete this->pName;
			pName = NULL;
		}
	}

public:
	char *pName;
	int mAge;
};

void test02()
{
	//���
	Student s1("trump", 88);

	Student s2(s1);
}

void test03()
{
	Student s1("����", 77);
	Student s2("����", 88);
	cout << s1.pName << "   " << s1.mAge << endl;
	cout << s2.pName << "   " << s2.mAge << endl;

	//��ֵ
	s1 = s2;

	cout << s1.pName << "   " << s1.mAge << endl;
	cout << s2.pName << "   " << s2.mAge << endl;
}
//����������ָ���ʱ����������ǳ��������
//
//�ṩĬ�ϵĿ�����������һ�����岻���ṩ,Ĭ���ǵ�λ������Ҳ����ͨ�������ϵ�ǳ����(Ĭ��ֵ����)
//�������ڲ���ָ��ָ����ڴ棬��ô�����ֶ��ṩ�������캯��
//�������ڲ���ָ��ָ����ڴ棬��ô��ʱ���ֻ�ǵ���Ĭ�ϵĿ������캯�������м򵥵�ָ��ֵ����������ǳ����
//�����д�Զ��忽�����̣����ڴ���п������������

int main()
{
	�Զ��忽����ֵ::test01();
	system("pause");
	return EXIT_SUCCESS;
}