#include <iostream>
#include <string>

using namespace std;

int a = 10;

namespace CAndCPP
{
	void test1()
	{
		a = 100;
		cout << "�ֲ� a =  " << a << endl;
		cout << "ȫ�� a = " << ::a << endl;
	}

	void test2()
	{
		//C++������ʾ������ת��
		//char *p = malloc(sizeof(char) * 10); //C����
		char *p = (char *)malloc(sizeof(char) * 10);
	}

	/*
	��Ŀ�������
	C:���ص��Ǳ�����ֵ
	C++:�������Ǳ���
	*/
	void test3()
	{
		int a = 10;
		int b = 20;
		cout << "a =" << a << ",b= " << b << endl;
		(a > b ? a : b) = 100;
		cout << "a =" << a << ",b= " << b << endl;
	}

#if  0/*C���Ժ�������ֵ����Ͷ����һ��*/
	//
	void test4()
	{
		return 123;
	}
#endif //

	struct  Person
	{
		string Name;
		int Age;
		void PrintInfo()
		{
			cout << "Name= " << Name << ",Age= " << Age;
		}
	};
	void test5()
	{
		Person p;
		p.Name = "Obama";
		p.Age = 100;
		p.PrintInfo();
	}
}