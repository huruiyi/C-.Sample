#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyInteger
{
public:
	MyInteger()
	{
		mNum = 0;
	}
public:
	MyInteger& operator++()
	{
		++mNum;
		return *this;
	}

	//�������﷨��������ѣ�����Ϊ�˺�ǰ��++����
	MyInteger operator++(int)
	{
		//�ȱ��浱ǰ����
		MyInteger temp(*this);
		//�ٶԵ�ǰ����++
		++mNum;
		//����temp
		return temp;
	}

public:
	int mNum;
};

void test01()
{
	int a = 10;
	//1. ǰ��++ �ȶ�a����1���ٷ���a
	//2. ����++ �ȷ���a�Ŀ������ٶ�a����1
	//cout << (++a) << endl;
	cout << (a++) << endl;
	cout << a << endl;
}

//������ص���ǰ��++ ,��ô���÷���
//������ص��Ǻ���++����ôֵ����
//ǰ��++ operator++() ,����++�� operator++(int)
void test02()
{
	MyInteger myint;
	//MyInteger myint2 =  (++myint);
	//cout << myint.mNum << endl;
	//++(++myint);
	//cout << myint.mNum << endl;

	cout << (myint++).mNum << endl;
	cout << myint.mNum << endl;
}

int main() {
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}