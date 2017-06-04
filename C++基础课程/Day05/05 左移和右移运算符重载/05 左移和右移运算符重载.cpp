#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Person
{
    friend ostream& operator<<(ostream &out, Person &person);
public:
    Person(int a, int b)
    {
        mA = a;
        mB = b;
    }
private:
    int mA;
    int mB;
};

ostream& operator<<(ostream &out, Person &person)
{
    out << person.mA << " " << person.mB;
    return out;
}

void test01()
{
#if 0
    int a = 10;
    cout << a;
    cout.operator<<(a);//int

    const char *str = "hello world!";
    cout << str;
    cout.operator<<(str); //const char *

    double b = 3.14;
    cout << b << endl;
    cout.operator<<(b); //double

    string s = "aaa";
    cout << s;

#endif

    //ostream对象没有重载重载适合Person的左移运算符函数
    //ostream类不能改变
    //运算符重载  一种成员函数 一种是全局函数
    Person p(10, 20);
    cout << p << endl << " aaaa" << 100 << endl; //operator<<(cout,p);
}

int main() {
    test01();

    system("pause");
    return EXIT_SUCCESS;
}