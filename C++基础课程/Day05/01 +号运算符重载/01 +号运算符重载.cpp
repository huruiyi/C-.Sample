#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void test01()
{
	//�����ڽ����������ͣ�������֪���������
	int a = 10;
	int b = 20;

	int ret = a + b;
}

class Person
{
public:
	Person(int a, int b)
	{
		mA = a;
		mB = b;
	}

	Person operator+(const Person &person)
	{
		Person ret(this->mA + person.mA, this->mB + person.mB);

		return ret;
	}

	Person operator+(int val)
	{
		Person ret(this->mA + val, this->mB + val);

		return ret;
	}

	Person& operator,(int val)
	{
		cout << val << " ";
		return *this;
	}

public:
	int mA;
	int mB;
};

#if 0
Person operator+(const Person &p1, const Person &p2)
{
	Person person(p1.mA + p2.mA, p1.mB + p2.mB);

	return person;
}
#endif

Person operator+(int val, const Person &p2)
{
	Person person(val + p2.mA, val + p2.mB);

	return person;
}

void test02()
{
	Person p1(10, 20);
	Person p2(30, 40);

	//��������֪������Person����������
	//�������: ���߱���������Person������������
	Person person = p1 + p2; // ת��Ϊ p1.operator+(p2)
	cout << person.mA << " " << person.mB << endl;

	Person ret = p1 + 100; //p1.operator+(100)
	Person ret2 = 100 + p1;
}

int main() {
	test02();

	system("pause");
	return EXIT_SUCCESS;
}