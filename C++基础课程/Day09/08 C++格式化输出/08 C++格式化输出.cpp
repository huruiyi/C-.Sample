#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
using namespace std;

//1. ��Ա����

void test00()
{
	int number = 666;

	cout.width(10);
	cout.fill('*');
	cout.setf(ios::left);   //666*******
	//cout.setf(ios::right); //*******666
	cout << number << endl;
}
void test01()
{
	int number = 666;
	// Ĭ����ʮ���ƣ�ios::oct����������ж�أ�����������������
	//ж��ʮ����
	cout.unsetf(ios::dec);
	//����ʮ������
	cout.setf(ios::hex);
	//cout.unsetf(ios::hex);
	//cout.setf(ios::oct);

	cout.setf(ios::showbase);
	cout << number << endl;
}

//2. ���Ʒ�
void test02()
{
	int number = 666;

	cout << setw(10)
		<< setfill('*')
		<< setiosflags(ios::left)
		<< setiosflags(ios::showbase)
		<< hex
		<< number
		<< endl;
}

int main()
{
	test01();

	system("pause");
	return EXIT_SUCCESS;
}