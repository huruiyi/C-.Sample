#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        mA = 0;
        mB = 0;
    }
    Person(int a, int b)
    {
        mA = a;
        mB = b;
    }
public:
    int mA;
    int mB;
};

//一个空类是一个字节大小
void test01()
{
    //Person person[10];
    cout << sizeof(Person) << endl;
}

void test02()
{
    //默认构造函数 默认析构函数 默认什么都不做
    //默认的拷贝构造函数 简单的值拷贝
    Person p(10, 20);
    Person p2(p); //p2.mA = p.mA p2.mB = p.mB;

    cout << p2.mA << " " << p2.mB << endl;
}

//如果我们手动添加了任何构造函数，编译器都不会提供默认构造函数
//如果我们手动添加了非拷贝构造函数，拷贝构造函数编译器还是会默认添加

void test03()
{
    Person p;
    Person p2(p);
}

int main() {
    //test01();
    test02();

    system("pause");
    return EXIT_SUCCESS;
}