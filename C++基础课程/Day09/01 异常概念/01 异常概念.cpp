#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int doLogic(int a, int b)
{
	if (b == 0)
	{
		throw 10; //throwһ��Int���͵��쳣
	}

	return  a / b;
}

//1. �����뱾��û�к���
//2. -1 1...�κ�����������Ϊ�����룬��ô�Ͳ�ͳһ
//3. C���Է��ش�����ķ�ʽ����������ģ����ҷ���ֵ�ǿ��Ժ��Եģ����ܿ纯��
//4. C���Ե��쳣�ǿ��Ժ��Եģ�C++�쳣���ɺ��Ե�

void test()
{
	try
	{
		doLogic(10, 0);
	}
	catch (int)
	{
		throw;
	}
}

void test01()
{
	//����ȥִ�п��ܻ��׳��쳣�Ĵ���
	try
	{
		test();
	}
	//���try���е��������׳����쳣�������ﲶ��
	//ƥ���쳣ͨ���쳣����
	catch (int e)
	{
		cout << "��0����:" << e << endl;
	}
}

void myFunc()
{
	//�׳�const char *�����쳣
	throw "hello exception!";

	//�׳�string�����쳣
	//throw string("hello exception1");

	//�׳�double�����쳣
	//throw 3.14;

	//�׳�Int�����쳣
	//throw 10;
}

//2. �쳣���ϸ�����ƥ��
void test02()
{
	try
	{
		myFunc();
	}
	catch (const char* e)
	{
		cout << e;
		cout << "const char *�����쳣��" << endl;
	}
	catch (string e)
	{
		cout << e;
		cout << "string�����쳣��" << endl;
	}
	catch (double e)
	{
		cout << e;
		cout << "double�����쳣��" << endl;
	}
	catch (...)
	{
		cout << "���������쳣!" << endl;
	}
}

int main() {
	test02();

	system("pause");
	return EXIT_SUCCESS;
}