#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//1. ::�����������
int a = 10;
void test01()
{
	int a = 20;
	cout << "a = " << a << endl;
	cout << "ȫ�ֱ��� a = " << ::a << endl;
}

//2. struct������ǿ
//C++�� struct���Էź���
//C++�� struct�����������Ҫд�ؼ���struct
struct Person
{
	string name;
	int age;
	void printPerson()
	{
		cout << "Name:" << name << " Age:" << age << endl;
	}
};
void test02()
{
	Person person;
	person.name = "Obama";
	person.age = 99;

	person.printPerson();
}

//3. ���ϸ������ת��
//�κ�������һ�������Ͳ��ܹ�ֱ�Ӹ�ֵ��������ʽ������ǿת
void test03()
{
	char *p = (char *)malloc(sizeof(char) * 64);
}

//4. ������ǿ
#if 0
func()
{
	return 10;
}
#endif

//5. ��Ŀ�������ǿ
//C������Ŀ��������ص���ֵ
//C++��Ŀ��������ص��Ǳ�������
void test04()
{
	int a = 10;
	int b = 20;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	(a > b ? a : b) = 100;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

//5. ��ֵ����ֵ�ĸ���
void test05()
{
	//���a���ڵȺ���ߣ��õ���a��������
	int a = 10;
	//���a���ڵȺ����棬�õ���a��ֵ
	int b = a;
}

int main() {
	//test01();
	//test02();
	test04();

	system("pause");
	return EXIT_SUCCESS;
}