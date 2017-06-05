#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
    Base(int)
    {
        cout << "Base类的构造函数!" << endl;
    }
    ~Base()
    {
        cout << "Base类的析构函数!" << endl;
    }
};

class Car
{
public:
    Car(int)
    {
        cout << "Car构造函数!" << endl;
    }

    ~Car()
    {
        cout << "Car析构函数!" << endl;
    }
};

class Plane
{
public:
    Plane()
    {
        cout << "Plane构造函数!" << endl;
    }

    ~Plane()
    {
        cout << "Plane析构函数!" << endl;
    }
};

//1. 创建子类对象，编译器默认调用父类的默认构造函数
//2. 如果父类没有默认构造，需要使用初始化列表指定调用父类那个版本的构造函数
//3. 子类中所有的构造函数都必须写初始化列表

class Derived : public Base
{
public:
    Derived() : Base(10), mCar(10)
    {
        cout << "Derived构造函数" << endl;
    }

    Derived(int) : Base(10), mCar(10)
    {
    }

    ~Derived()
    {
        cout << "Derived析构函数" << endl;
    }
public:
    Car mCar;
    Plane mPlane;
};

void test1()
{
    Derived d;
}

//继承和组合情况下，对象构造和析构顺序
//父类->对象成员->子类  析构函数调用顺序和构造函数调用顺序相反

class A
{
public:
    A()
    {
        cout << "构造函数  A " << endl;
    }

    ~A()
    {
        cout << "析构函数  A" << endl;
    }
};

class C
{
public:
    C()
    {
        cout << "构造函数  C " << endl;
    }
    ~C()
    {
        cout << "析构函数  C" << endl;
    }
};

class B :public A
{
public:
    B()
    {
        cout << "构造函数  B " << endl;
    }
    ~B()
    {
        cout << "析构函数  B" << endl;
    }
private:
    C c;
};

void test2()
{
    B b;
}
int main(void)
{
    test2();
    system("pause");
    return 0;
}