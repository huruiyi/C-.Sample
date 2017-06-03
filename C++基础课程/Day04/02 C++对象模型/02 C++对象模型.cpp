#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
    //静态成员和非静态成员函数最大的区别：
    //非静态成员函数有this指针
    //静态成员函数没有this指针
    void showPerson()
    {
        cout << this->mAge << endl;
    }

    //静态成员函数不能使用非静态成员变量
    static void printPerson()
    {
        //mAge;
    }
public:
    int mAge;
};

#if 0
struct Person
{
    int mAge;
};

void showPerson(Person *this)
{
    cout << this->mAge << endl;
}
#endif

//静态成员和非静态成员函数都不占用对象大小
//静态成员变量也不占用对象大小
void test01()
{
    Person p1, p2; // struct Person p1,p2;
    p1.mAge;
    p2.mAge;

    p1.showPerson(); //showPerson(&p1);
    p2.showPerson(); //showPerson(&p2);

    cout << sizeof Person << endl;
}

int main() {
    test01();

    system("pause");
    return EXIT_SUCCESS;
}