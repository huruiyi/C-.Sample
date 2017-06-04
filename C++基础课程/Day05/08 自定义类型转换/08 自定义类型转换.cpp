#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Student
{
public:
    Student(int a, int b)
    {
        mA = a;
        mB = b;
    }
public:
    int mA;
    int mB;
};

class Person
{
public:
    Person(int age)
    {
        mAge = age;
    }

    //定义如何将Person类型转换为Int类型
    operator int()
    {
        return 1000;
    }

    //如何将Person类型转换为Bool类型
    operator bool()
    {
        return mAge > 0;
    }

    //将Person类型转换为Student类型
    operator Student()
    {
        return Student(mAge, mAge);
    }

public:
    int mAge;
};

void test()
{
    Person p(100);
    int ret = p;
    cout << "ret = " << ret << endl;

    if (p)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    Student s = p;
}

int main() {
    test();

    system("pause");
    return EXIT_SUCCESS;
}