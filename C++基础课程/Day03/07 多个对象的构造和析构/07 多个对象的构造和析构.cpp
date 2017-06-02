#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class BMW
{
public:
    BMW(int a)
    {
        cout << "BMW构造函数!" << endl;
    }
    BMW(int a, int b)
    {
        cout << "BMW(int a,int b)构造函数!" << endl;
    }
    BMW(int a, double b)
    {
        cout << "BMW(int a,double b)构造函数!" << endl;
    }
    ~BMW()
    {
        cout << "BMW析构函数!" << endl;
    }
};

class BYD
{
public:
    BYD(int a)
    {
        cout << "BYD构造函数!" << endl;
    }
    ~BYD()
    {
        cout << "BYD析构函数!" << endl;
    }
};

//一个类的对象成为另外一个对象的成员，组合
//复用 功能扩展

class Person
{
public:
    //每一个Person构造函数都需要写上初始化列表
    //初始化列表只能用在构造函数上
    Person(int a, double b, int c) : mBmw(a, b), mByd(c)
    {
        cout << "Person构造函数!" << endl;
    }

    Person() : mBmw(10, 11.11), mByd(20)
    {
    }

    ~Person()
    {
        cout << "Person析构函数!" << endl;
    }
public:
    //别摸我
    BMW mBmw;
    //比亚迪
    BYD mByd;
};

//先构造对象成员，再构造对象自身
//Person对象在构造过程中，调用的是对象成员默认的构造函数
//通过初始化列表语法指定对象成员调用那个构造函数完成对象初始化

void test()
{
    Person person(10, 3.14, 20);
}

class Student
{
public:
    Student(int a, int b, int c) : mA(a), mB(b), mC(c) {}

#if 0
    Student(int a, int b, int c)
    {
        mA = a;
        mB = b;
        mC = c;
    }
#endif

public:
    int mA;
    int mB;
    int mC;
};

class A
{
public:
    A(int a, int b) :_b(b), _a(_b)
    {}
    void show()
    {
        cout << "a = " << this->_a << " b = " << this->_b << endl;
    }
private:
    int _a;
    int _b;
};

int main() {
    A a(3, 4);
    a.show();

    //伪构造
    int b(10);
    double c(3.14);

    system("pause");
    return EXIT_SUCCESS;
}