#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Circle
{
public:
	//��ֵ���� ��Ա���� ��Ա����
	//������ڲ�����Ա��������ֱ�ӷ�����ĳ�Ա����
	void setR(int r)
	{
		if (r <= 0)
		{
			return;
		}
		mR = r;
	}
	int getZhouLength()
	{
		return (int)(2 * mR *3.14);
	}
public:
	//�뾶
	int mR; //��Ա���� ��Ա����
};

void test()
{
	Circle c;
	c.setR(10);
	cout << "�ܳ���:" << c.getZhouLength() << endl;
}

//1. �������Щ����(ֻ����ҵ������Ҫ������)
//2. �����Щ���ԵĲ���(����)

class Student
{
public:
	void setName(string name)
	{
		mName = name;
	}
	void setAge(int age)
	{
		if (age < 0 || age > 100)
		{
			return;
		}

		mAge = age;
	}

	void printStudent()
	{
		cout << "Name:" << mName << " Age:" << mAge << endl;
	}
public:
	string mName;
	int mAge;
};

void test02()
{
	Student s;
	s.setName("aaa");
	s.setAge(10);
	s.printStudent();
}

//����������һ��������������
//��������ֻ�н�����������Ż��滻���������õĵط����Ż�ʡȥ�������ÿ���
//inline�ؼ��ֽ������������������룬���Ǳ������ܾ�����
//��Щ�ȽϺõı���������ʹ���ǲ�дinline�ؼ��֣�Ҳ��������Ż����򣬶Ժ���������������

int main() {
	//test();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}