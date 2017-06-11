#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
using namespace std;

//1. 成员函数

void test00()
{
    int number = 666;

    cout.width(10);
    cout.fill('*');
    cout.setf(ios::left);   //666*******
    //cout.setf(ios::right); //*******666
    cout << number << endl;
}
void test01()
{
    int number = 666;
    // 默认是十进制（ios::oct），必须先卸载，才能启用其他进制
    //卸载十进制
    cout.unsetf(ios::dec);
    //设置十六进制
    cout.setf(ios::hex);
    //cout.unsetf(ios::hex);
    //cout.setf(ios::oct);

    cout.setf(ios::showbase);
    cout << number << endl;
}

//2. 控制符
void test02()
{
    int number = 666;

    cout << setw(10)
        << setfill('*')
        << setiosflags(ios::left)
        << setiosflags(ios::showbase)
        << hex
        << number
        << endl;
}

int main1() {
    test01();
    //test02();

    system("pause");
    return EXIT_SUCCESS;
}