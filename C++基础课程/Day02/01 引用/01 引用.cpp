#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//�������ã���const������
//����ͨ�������޸ı�����ֵ

void test01()
{
	int a = 10;
	const int& ret = a;

	//��ͨ���ò�������������
	//int &intRef = 10;
	//�������ÿ�������������,�������ÿ���������ֵ
	const int& intRef = 10; //int temp = 10; const int& intRef = temp;
}

struct Person
{
	string mName;
	int mAge;
};

void printPerson(const Person& person)
{
	cout << person.mName << " " << person.mAge << endl;
}

void test02()
{
	Person p;
	p.mName = "aaa";
	p.mAge = 20;
	printPerson(p);
}

//����������ص���int& ��ôreturn a���ص���a��������
//�����������������int,��ôreturn a���ص���a��ֵ
int& func()
{
	static int a = 10;
	return a;
}

void test03()
{
	//��Ҫ���ؾֲ�����������
	//��̵�ʱ��һ��Ҫע���������������
	int& ref = func();
	ref = 100;

	//һ������£���������ķ���ֵ��һ�����ã���ô���Ե���ֵ��Ҳ���Ե���ֵ
	func() = 100;
	int b = func();
	cout << "ref = " << ref << endl;
}

//��ͨ���ò�������������
void myFunc(const int& a)
{
	cout << "a = " << a << endl;
}

void test04()
{
	int a = 10;
	myFunc(20);
}

int main() {
	test03();

	system("pause");
	return EXIT_SUCCESS;
}