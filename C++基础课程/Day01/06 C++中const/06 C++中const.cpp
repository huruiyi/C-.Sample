#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1. C�����е�const�����Ϊ"ֻ���ı���"����Ȼ�Ǳ��������Ƿ����ڴ�

//2. C++�е�constȫ�ֱ������ڲ����ӵģ�Ĭ��ֻ���ڵ�ǰ�ļ��ڷ���
void test01()
{
	extern const int a;
	cout << "a = " << a << endl;
}
//3. C++�е�const�Ƿ�����ڴ棬Ҫ����ôʹ��
//�����const int a = 10;
const int num = 10; //������
//1.��Ҫ֪��num�ĵ�ַ
//2.��const��������Ϊextern��������ڴ�
void test02()
{
	int* p = (int*)& num;
	//�����������޸�
	*p = 100;
}

int b = 10;
const int c = b; //ȫ�־�̬��
//3.�����ڴ�
void test03()
{
	cout << "c = " << c << endl;
	int* p = (int*)& c;
	*p = 100;

	cout << "c = " << c << endl;
}

void test04()
{
	//ջ��
	volatile const int a = 10;

	int* p = (int*)& a;
	*p = 100;
	//*p��ʵ�Ѿ��ı��˱���a��ֵ����������a�ķ��������Ż�����
	//volatile�ؼ��ָ��߱���������Ҫ��a�������Ż���ÿ�η���a��ʱ�򣬴�a�ڴ��з���

	cout << "a = " << a << endl;
	cout << "*p = " << *p << endl;
}

int main() {
	test04();

	system("pause");
	return EXIT_SUCCESS;
}