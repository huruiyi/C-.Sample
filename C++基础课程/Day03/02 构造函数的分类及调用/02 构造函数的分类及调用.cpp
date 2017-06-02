#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
    //构造函数一定要写public
public:
    Person()
    {
        cout << "默认构造函数!" << endl;
    }

    Person(int a)
    {
        cout << "有参构造函数" << endl;
    }

    Person(int a, int b)
    {
        cout << "两个参数的构造函数!" << endl;
    }

    //拷贝构造函数，注意const可以省略，但是&符号不能省略
    Person(const Person &person)
    {
        cout << "拷贝构造函数!" << endl;
    }

    Person& operator=(const Person &person)
    {
        cout << "赋值函数!" << endl;
        return *this;
    }

    ~Person()
    {
        cout << "析构函数!" << endl;
    }

public:
    int mA;
    int mB;
};

//构造函数调用
void test01()
{
    //调用无参构造函数
    Person p;

    //错误写法
    Person p2(); //编译器会理解为函数声明
}

void test02()
{
    //括号法(灰常常用)
    Person p1(10);
    Person p2(10, 20);
    Person p3(p2);

    //显式调用构造函数(就不要写了)
    Person p4 = Person(10);
    Person p5 = Person(10, 20);

    //隐式的调用构造函数
    Person p6 = 100; //Person p6 = Person(100)

    cout << "------------" << endl;
    Person p7 = p6; //Person p7 = Person(p6)  拷贝构造函数

    Person p8;
    p8 = p7; //赋值函数
}

int main() {
    test02();

    system("pause");
    return EXIT_SUCCESS;
}