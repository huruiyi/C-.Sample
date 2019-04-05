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

//比如说父类的成员是public权限，那么子类继承这个属性之后，也是Public权限吗？
//继承方式影响基类的成员被子类继承之后，在子类中的访问权限

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

//父类的私有成员被子类继承了，只是子类不能够使用而已

int main() {
	test01();

	system("pause");
	return EXIT_SUCCESS;
}