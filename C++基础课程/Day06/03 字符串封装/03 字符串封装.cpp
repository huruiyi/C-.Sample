#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"MyString.h"

void test()
{
    MyString s1 = "aaa";
    MyString s2 = "bbb";
    MyString s3 = s1 + s2;
    s1 += s2;

    cout << "s1:" << s1 << endl;
    cout << "s2:" << s2 << endl;
    cout << "s3:" << s3 << endl;

    //cin标准输入流对象
    cout << "-----------" << endl;
    cin >> s1;
    cout << "s1:" << s1 << endl;

    s1 += " hello world!";
    cout << "s1:" << s1 << endl;
    MyString s4 = s1 + " ppppp";
    cout << "s4:" << s4 << endl;

    if (s1 == "hello world")
    {
        cout << "相等!" << endl;
    }
    else
    {
        cout << "不相等!" << endl;
    }

    for (int i = 0; i < s4.size(); ++i)
    {
        cout << s4[i] << " ";
    }
    cout << endl;
}

int main() {
    test();

    system("pause");
    return EXIT_SUCCESS;
}