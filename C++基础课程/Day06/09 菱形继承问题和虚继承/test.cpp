#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	int mType;
};

//Animal类就叫做虚基类
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
	//1. 二义性
	SheepTuo st;
	st.mType;
	st.Sheep::mType;
	st.Tuo::mType;

	//2. 基类的数据被重复继承多次，浪费内存
	//虚继承来解决多次继承基类数据的问题
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