#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person���캯����" << endl;
	}

	~Person()
	{
		cout << "Person��������!" << endl;
	}
};

void doLogic()
{
	Person p1;
	Person p2;
	//Person *p = new Person;

	throw 10;
}

//�׳��쳣֮ǰ�Ὣջ�����ͷ�
int main() {
	try
	{
		doLogic();
	}
	catch (...)
	{
		cout << "�����쳣��" << endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}