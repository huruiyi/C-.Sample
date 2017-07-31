#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1. ����ģ�����ͨ�������𣺺���ģ�岻������ʽ����ת�� ��ͨ����������ʽ����ת
template<class T>
void func01(T a, T b)
{
	cout << "template<class T> void func01(T a, T b)" << endl;
}

void func02(int a, double b)
{
	cout << "void func02(int a,double b)" << endl;
}

void test01()
{
	int a = 10;
	double b = 3.14;

	//func01(a, b);
	func02(a, a);
}

//2. ����ģ�����ͨ������һ����ù���
template<class T>
void myFunc(T a, T b)
{
	cout << "void myFunc(T a,T b)" << endl;
}

//���α���
#if 0
void myFunc(int a, int b)
{
	cout << "void myFunc(T a,T b)" << endl;
}

void myFunc(double a, double b)
{
	cout << "void myFunc(T a,T b)" << endl;
}
#endif

template<class T>
void myFunc(T a, T b, T c)
{
	cout << "void myFunc(T a,T b)" << endl;
}

#if 0
void myFunc(int a, int b)
{
	cout << "void myFunc(int a,int b)" << endl;
}
#endif

void myFunc(int a, double b)
{
	cout << "void myFunc(int a,int b)" << endl;
}

void test02()
{
	int a = 10;
	int b = 20;
	double c = 3.14;

	//1. ����ģ�����ͨ���������ϸ�ƥ�亯�����õ�����£�����������ƥ����ͨ����
	myFunc(a, b);
	//2. ����ͨ��ģ��ղ����б���߱�����ƥ�亯��ģ��
	myFunc<>(a, b);
	//3. ���˵ģ���ܹ��������õ�ƥ�䣬��ô����ƥ��ģ��
	myFunc(a, b);
	//4. ����ģ���������ͨ������������
	myFunc(a, a, a);
}

int main() {
	test02();

	system("pause");
	return EXIT_SUCCESS;
}