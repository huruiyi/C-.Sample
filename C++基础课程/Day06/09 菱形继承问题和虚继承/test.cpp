#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	int mType;
};

//Animal��ͽ��������
class Sheep : virtual public Animal
{
public:
	int mMao;
};

class Tuo : virtual public Animal
{
public:
	int mFeng;
};

class SheepTuo : public Sheep, public Tuo {};

void test()
{
	//1. ������
	SheepTuo st;
	st.mType;
	st.Sheep::mType;
	st.Tuo::mType;

	//2. ��������ݱ��ظ��̳ж�Σ��˷��ڴ�
	//��̳��������μ̳л������ݵ�����
}

void test02()
{
	Sheep s;
	cout << ((Animal *)((char *)&s + *((int *)*(int *)&s + 1)))->mType << endl;
	cout << sizeof(Sheep) << endl;
	cout << sizeof(SheepTuo) << endl;
}

int main() {
	test02();

	system("pause");
	return EXIT_SUCCESS;
}