#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class BMW
{
public:
	BMW(int a)
	{
		cout << "BMW���캯��!" << endl;
	}
	BMW(int a, int b)
	{
		cout << "BMW(int a,int b)���캯��!" << endl;
	}
	BMW(int a, double b)
	{
		cout << "BMW(int a,double b)���캯��!" << endl;
	}
	~BMW()
	{
		cout << "BMW��������!" << endl;
	}
};

class BYD
{
public:
	BYD(int a)
	{
		cout << "BYD���캯��!" << endl;
	}
	~BYD()
	{
		cout << "BYD��������!" << endl;
	}
};

//һ����Ķ����Ϊ����һ������ĳ�Ա�����
//���� ������չ

class Person
{
public:
	//ÿһ��Person���캯������Ҫд�ϳ�ʼ���б�
	//��ʼ���б�ֻ�����ڹ��캯����
	Person(int a, double b, int c) : mBmw(a, b), mByd(c)
	{
		cout << "Person���캯��!" << endl;
	}

	Person() : mBmw(10, 11.11), mByd(20)
	{
	}

	~Person()
	{
		cout << "Person��������!" << endl;
	}
public:
	//������
	BMW mBmw;
	//���ǵ�
	BYD mByd;
};

//�ȹ�������Ա���ٹ����������
//Person�����ڹ�������У����õ��Ƕ����ԱĬ�ϵĹ��캯��
//ͨ����ʼ���б��﷨ָ�������Ա�����Ǹ����캯����ɶ����ʼ��

void test()
{
	Person person(10, 3.14, 20);
}

class Student
{
public:
	Student(int a, int b, int c) : mA(a), mB(b), mC(c) {}

#if 0
	Student(int a, int b, int c)
	{
		mA = a;
		mB = b;
		mC = c;
	}
#endif

public:
	int mA;
	int mB;
	int mC;
};

class A
{
public:
	A(int a, int b) :_b(b), _a(_b)
	{}
	void show()
	{
		cout << "a = " << this->_a << " b = " << this->_b << endl;
	}
private:
	int _a;
	int _b;
};

int main() {
	A a(3, 4);
	a.show();

	//α����
	int b(10);
	double c(3.14);

	system("pause");
	return EXIT_SUCCESS;
}