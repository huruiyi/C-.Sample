#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#if 0
class Person;

void SwapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void SwapDouble(double& a, double& b) {}
void SwapPerson(Person& a, Person& b) {}

#endif
//������������Ϳ��Ե����������ݸ�������������
//���ְ��������͵����������ݵļ���������ģ�壬���Ͳ�����
//����ģ���г��ֵ����;Ͳ����Ǿ�������ͣ�����һ�����������

//template<typename T>

//templateֻ�Խ�������ĺ�����������Ч
//���԰�T���Ϊ�βΣ�Tֻ�Ǹ���������
//�������������������
//����ģ������Զ��Ƶ�����(��ģ�岻����)
//���ú���ģ���ʱ�����Ҫȷ��T�����ͣ���ʹ����û���������������T
//����ģ�������Ĭ��ֵ��Ĭ��ֵ�Ǹ�����template<class T = int>
template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T = int, int n = 100>
void func()
{
	cout << "n = " << n << endl;
	cout << "func()" << endl;
}

void test()
{
	//����ģ����ε���
	int a = 10;
	int b = 20;
	double c = 3.14;
	//1. ��ʽָ��ģ������б�
	mySwap<int>(a, b);

	//2. �Զ��Ƶ�����
	mySwap(a, b);

	//func<int>();
	//func();
}

int main() {
	test();

	system("pause");
	return EXIT_SUCCESS;
}