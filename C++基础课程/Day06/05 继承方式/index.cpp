#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		mPublic = 10;
		mPrivate = 20;
		mProtected = 30;
	}
public:
	int mPublic;
private:
	int mPrivate;
protected:
	int mProtected;
};

//����˵����ĳ�Ա��publicȨ�ޣ���ô����̳��������֮��Ҳ��PublicȨ����
//�̳з�ʽӰ�����ĳ�Ա������̳�֮���������еķ���Ȩ��

//private > protected > public

class Son : private Base
{
public:
	Son()
	{
		mC = 40;
	}
public:
	void func()
	{
		mPublic;
		mProtected;
	}
public:
	int mC;
};

class SonDeSon : public Son
{
public:
	int mD;
};

void test01()
{
	Son s;
	//s.mPublic;

	cout << *(int*)((char*)& s + 12) << endl;
}

//�����˽�г�Ա������̳��ˣ�ֻ�����಻�ܹ�ʹ�ö���

int main() {
	test01();

	system("pause");
	return EXIT_SUCCESS;
}