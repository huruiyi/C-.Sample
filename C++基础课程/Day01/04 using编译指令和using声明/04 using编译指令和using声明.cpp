#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

//using namespace std; usingָ�� ָ�������ռ����еķ����ڵ�ǰ������������Ч
void test01()
{
	using namespace std;
	cout << "hello world!" << endl;
}

void test02()
{
	std::cout << "hello test02" << std::endl;
}

namespace A
{
	int a = 10;
}

namespace B
{
	int a = 100;
}

void test03()
{
	//usingָ������������ռ����ײ���������ͻ
	using namespace A;
	using namespace B;

	std::cout << "a = " << A::a << std::endl;

	//����ֲ����ź������ռ���з��ų�ͻ��������Ĭ�Ͼͽ�ƥ�����
	//int a = 20;
	//cout << "a = " << a << endl;
}

//2. using������ָ�������ռ���ĳ��������Ч
namespace C
{
	int a = 10;
}
void test04()
{
	//using�����;ֲ���������ͻ��������
	using std::cout;
	using std::endl;
	cout << "hello world" << endl;

	using C::a;
	//int a = 100;

	cout << "a = " << a << endl;
}

int main() {
	test03();

	system("pause");
	return EXIT_SUCCESS;
}