#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//�������ظ�������
//�����������һ�ֶ�̬(��̬��̬)
//��C++�к������ǿ���һ����

//�������ص�����
//1. ͬһ����������
//2. �����Ĳ���������ͬ
//3. �����Ĳ������Ͳ�ͬ
//4. ����������˳��ͬ
//5. ע�⣺�����������Ͳ�����Ϊ��������

void func()
{
	cout << "void func()" << endl;
}

void func(int a)
{
	cout << "void func(int a)" << endl;
}

void func(double a)
{
	cout << "void func(double a)" << endl;
}

void func(int a, double b)
{
	cout << "func(int a, double b)" << endl;
}

void func(double a, int b)
{
	cout << "void func(double a,int b)" << endl;
}

//�������Ͳ�����Ϊ���ص�����
//��Ϊ�����ķ���ֵ���Ժ���
#if 0
int func(double a, int b)
{
	cout << "void func(double a,int b)" << endl;
}
#endif

void test()
{
	int a = 10;
	int b = 20;
	double c = 3.14;

	//1. �������������ϸ�ƥ����������ͣ����ƥ��ɹ�����óɹ���
	//2. ���û���ϸ����͵Ĳ�������ô��������Բ���������ʽ����ת�������ת���ɹ�֮����
	//ƥ����ã���ôҲ��Ϊ�������óɹ�
	func(b, c);
	//����������ʹ��Ĭ�ϲ������ܻᵼ�¶�����
	//func(a);
}

int main() {
	test();

	system("pause");
	return EXIT_SUCCESS;
}