#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
	//���캯��һ��Ҫдpublic
public:
	Person()
	{
		cout << "Ĭ�Ϲ��캯��!" << endl;
	}

	Person(int a)
	{
		cout << "�вι��캯��" << endl;
	}

	Person(int a, int b)
	{
		cout << "���������Ĺ��캯��!" << endl;
	}

	//�������캯����ע��const����ʡ�ԣ�����&���Ų���ʡ��
	Person(const Person& person)
	{
		cout << "�������캯��!" << endl;
	}

	Person& operator=(const Person& person)
	{
		cout << "��ֵ����!" << endl;
		return *this;
	}

	~Person()
	{
		cout << "��������!" << endl;
	}

public:
	int mA;
	int mB;
};

//���캯������
void test01()
{
	//�����޲ι��캯��
	Person p;

	//����д��
	//Person p2(); //�����������Ϊ��������
}

void test02()
{
	//���ŷ�(�ҳ�����)
	Person p1(10);
	Person p2(10, 20);
	Person p3(p2);

	//��ʽ���ù��캯��(�Ͳ�Ҫд��)
	Person p4 = Person(10);
	Person p5 = Person(10, 20);

	//��ʽ�ĵ��ù��캯��
	Person p6 = 100; //Person p6 = Person(100)

	cout << "------------" << endl;
	Person p7 = p6; //Person p7 = Person(p6)  �������캯��

	Person p8;
	p8 = p7; //��ֵ����
}

void test03()
{
	char* ch1 = "Hello";
	char* ch2 = new char[strlen(ch1) + 1];

	strcpy(ch2, "Hello");
	cout << ch1 << "   " << ch2 << endl;
	delete ch2;
	cout << &ch1 << "   " << &ch2 << endl;
}

void test04()
{
	Person p1(10, 20);
	Person p2(10, 20);
}
int main()
{
	test01();

	system("pause");
	return EXIT_SUCCESS;
}