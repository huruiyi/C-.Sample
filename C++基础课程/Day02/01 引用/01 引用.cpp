#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//常量引用，加const的引用
//不用通过引用修改变量的值

void test01()
{
    int a = 10;
    const int &ret = a;

    //普通引用不能引用字面量
    //int &intRef = 10;
    //常量引用可以引用字面量,常量引用可以引用右值
    const int &intRef = 10; //int temp = 10; const int& intRef = temp;
}

struct Person
{
    string mName;
    int mAge;
};

void printPerson(const Person &person)
{
    cout << person.mName << " " << person.mAge << endl;
}

void test02()
{
    Person p;
    p.mName = "aaa";
    p.mAge = 20;
    printPerson(p);
}

//如果函数返回的是int& 那么return a返回的是a变量本身
//如果函数返回类型是int,那么return a返回的是a的值
int& func()
{
    static int a = 10;
    return a;
}

void test03()
{
    //不要返回局部变量的引用
    //编程的时候，一定要注意变量的生命周期
    int &ref = func();
    ref = 100;

    //一般情况下，如果函数的返回值是一个引用，那么可以当左值，也可以当右值
    func() = 100;
    int b = func();
    cout << "ref = " << ref << endl;
}

//普通引用不能引用字面量
void myFunc(const int &a)
{
    cout << "a = " << a << endl;
}

void test04()
{
    int a = 10;
    myFunc(20);
}

int main() {
    test03();

    system("pause");
    return EXIT_SUCCESS;
}