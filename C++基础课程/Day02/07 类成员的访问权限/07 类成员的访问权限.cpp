#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	void func()
	{
		mPublic;
		mPrivate;
		mProtected;
	}
public:
	//��������Ȩ��
	string mPublic;
private:
	//˽��Ȩ��
	string mPrivate;
protected:
	//����Ȩ��
	string mProtected;
};

//������ڲ���û��Ȩ��֮��
//����Ȩ�޿�����������ʣ�˽��Ȩ�޺ͱ���Ȩ�޵ĳ�Ա�������޷�����
//˽������ֻ���ڵ�ǰ���ڲ�ʹ�ã����������ⲿ������ʹ��
//��������ֻ��������ڲ���������ʹ�ã�����������ⲿ����
//����Ȩ�ޣ����� ���� ���඼���Է���

class Student
{
public:
	string mName;
	void func()
	{
	}
};

struct Teacher
{
	string mName;
	void func()
	{
	}
};

void test02()
{
	//struct��class��һ���ģ����ܶ���һ����
	//����Ψһ���������Ĭ�ϵķ���Ȩ�޲�ͬ��structĬ�ϵķ���Ȩ����public classĬ�Ϸ���Ȩ����private

	Student s;
	s.mName;

	Teacher t;
	t.mName;
}

void test()
{
	Person person;
	person.mPublic;
}

int main() {
	system("pause");
	return EXIT_SUCCESS;
}