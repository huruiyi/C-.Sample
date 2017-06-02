#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//1. ::作用域运算符
int a = 10;
void test01()
{
    int a = 20;
    cout << "a = " << a << endl;
    cout << "全局变量 a = " << ::a << endl;
}

//2. struct功能增强
//C++中 struct可以放函数
//C++中 struct定义变量不需要写关键字struct
struct Person
{
    string name;
    int age;
    void printPerson()
    {
        cout << "Name:" << name << " Age:" << age << endl;
    }
};
void test02()
{
    Person person;
    person.name = "Obama";
    person.age = 99;

    person.printPerson();
}

//3. 更严格的类型转换
//任何两个不一样的类型不能够直接赋值，必须显式的类型强转
void test03()
{
    char *p = (char *)malloc(sizeof(char) * 64);
}

//4. 函数加强
#if 0
func()
{
    return 10;
}
#endif

//5. 三目运算符加强
//C语言三目运算符返回的是值
//C++三目运算符返回的是变量本身
void test04()
{
    int a = 10;
    int b = 20;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    (a > b ? a : b) = 100;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

//5. 左值和右值的概念
void test05()
{
    //如果a放在等号左边，用的是a变量本身
    int a = 10;
    //如果a放在等号右面，用的是a的值
    int b = a;
}

int main() {
    //test01();
    //test02();
    test04();

    system("pause");
    return EXIT_SUCCESS;
}