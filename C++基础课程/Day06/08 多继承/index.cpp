#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base1
{
public:
    void func01()
    {
        cout << "Base1::func01()" << endl;
    }

public:
    int mA;
};

class Base2
{
public:
    void func02()
    {
        cout << "Base2::func02()" << endl;
    }
public:
    int mA;
};

class Derived : public Base1, public Base2
{
public:
    void func03()
    {
        cout << "Derived::func03()" << endl;
    }
public:
    int mC;
};

void test()
{
    //多继承容易出现二义性问题
    Derived d;
    d.Base1::mA;
    d.Base2::mA;
}

int main() {
    test();

    system("pause");
    return EXIT_SUCCESS;
}