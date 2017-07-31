#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	Base(int)
	{
		cout << "Base��Ĺ��캯��!" << endl;
	}
	~Base()
	{
		cout << "Base�����������!" << endl;
	}
};

class Car
{
public:
	Car(int)
	{
		cout << "Car���캯��!" << endl;
	}

	~Car()
	{
		cout << "Car��������!" << endl;
	}
};

class Plane
{
public:
	Plane()
	{
		cout << "Plane���캯��!" << endl;
	}

	~Plane()
	{
		cout << "Plane��������!" << endl;
	}
};

//1. ����������󣬱�����Ĭ�ϵ��ø����Ĭ�Ϲ��캯��
//2. �������û��Ĭ�Ϲ��죬��Ҫʹ�ó�ʼ���б�ָ�����ø����Ǹ��汾�Ĺ��캯��
//3. ���������еĹ��캯��������д��ʼ���б�

class Derived : public Base
{
public:
	Derived() : Base(10), mCar(10)
	{
		cout << "Derived���캯��" << endl;
	}

	Derived(int) : Base(10), mCar(10)
	{
	}

	~Derived()
	{
		cout << "Derived��������" << endl;
	}
public:
	Car mCar;
	Plane mPlane;
};

void test1()
{
	Derived d;
}

//�̳к��������£������������˳��
//����->�����Ա->����  ������������˳��͹��캯������˳���෴

class A
{
public:
	A()
	{
		cout << "���캯��  A " << endl;
	}

	~A()
	{
		cout << "��������  A" << endl;
	}
};

class C
{
public:
	C()
	{
		cout << "���캯��  C " << endl;
	}
	~C()
	{
		cout << "��������  C" << endl;
	}
};

class B :public A
{
public:
	B()
	{
		cout << "���캯��  B " << endl;
	}
	~B()
	{
		cout << "��������  B" << endl;
	}
private:
	C c;
};

void test2()
{
	B b;
}
int main(void)
{
	test2();
	system("pause");
	return 0;
}