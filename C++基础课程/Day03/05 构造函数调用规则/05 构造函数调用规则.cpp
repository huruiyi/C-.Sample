#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		mA = 0;
		mB = 0;
	}
	Person(int a, int b)
	{
		mA = a;
		mB = b;
	}
public:
	int mA;
	int mB;
};

//һ��������һ���ֽڴ�С
void test01()
{
	//Person person[10];
	cout << sizeof(Person) << endl;
}

void test02()
{
	//Ĭ�Ϲ��캯�� Ĭ���������� Ĭ��ʲô������
	//Ĭ�ϵĿ������캯�� �򵥵�ֵ����
	Person p(10, 20);
	Person p2(p); //p2.mA = p.mA p2.mB = p.mB;

	cout << p2.mA << " " << p2.mB << endl;
}

//��������ֶ�������κι��캯�����������������ṩĬ�Ϲ��캯��
//��������ֶ�����˷ǿ������캯�����������캯�����������ǻ�Ĭ�����

void test03()
{
	Person p;
	Person p2(p);
}

int main() {
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}