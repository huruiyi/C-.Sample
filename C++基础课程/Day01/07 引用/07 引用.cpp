#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1. ���û����﷨
void test01()
{
	//���﷨�Ƕȣ����õ��﷨���Ǹ�һ�����б���ȡһ������
	int a = 10;
	int &b = a;
	int &d = b;

	d = 100;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "d = " << d << endl;

	cout << "a = " << &a << endl;
	cout << "b = " << &b << endl;
	cout << "d = " << &d << endl;

	double c = 3.14;
	double &ref = c;
}

//2. ʹ������ע���
void test02()
{
	//1. ����һ����ʼ���������޸�
	int a = 10;
	int c = 20;
	int &b = a;
	b = c; //��ֵ

	//2. ����һ��Ҫ����һ��Ϸ����ڴ棬�мǲ��ܷ��ؾֲ�����������
	//3. ���ܴ���������
	//4. ���������������
	int arr[10];
	int(&pArr)[10] = arr;
	pArr[0] = 100;
	cout << "Arr[0]:" << arr[0] << endl;

	typedef int(ARR_TYPE)[10];
	ARR_TYPE &arrRef = arr;
	cout << arrRef[0] << endl;
}

int main() {
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}