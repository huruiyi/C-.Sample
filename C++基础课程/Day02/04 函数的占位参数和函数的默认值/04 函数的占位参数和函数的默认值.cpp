#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void func(int a, int b = 0, int c = 0)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

void test01()
{
	func(10);
	func(10, 20);
}

//�����������Ͷ��岻��ͬʱ��Ĭ��ֵ
void myfcun(int a = 0);

void myfcun(int a)
{
}

//������ռλ����
void func01(int a, int = 0)
{
}
void test02()
{
	func01(10);
}
int main() {
	test01();

	system("pause");
	return EXIT_SUCCESS;
}