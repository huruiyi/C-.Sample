#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <stdexcept>

using namespace std;

void test01()
{
    string str1{ "123456789" };
    string str2;
    str2.assign(str1, 3, 5);
    cout << str2 << endl;
}

void tet02()
{
    string str1{ "123456789" };
    for (int i = 0; i < str1.size(); i++)
    {
        //cout << str1[i] << endl;
        cout << str1.at(i) << endl;
    }
    /*
     [] 访问挂掉
     at: 抛异常
     **/
    try
    {
        cout << str1.at(100) << endl;
    }
    catch (out_of_range & ex)
    {
        cout << ex.what() << endl;
    }
    catch (...)
    {
        cout << "其他异常。。。" << endl;
    }
}

void test03()
{
    string str = { "hello@163.com" };
    int pos = str.find("@");
    cout << str.substr(0, pos) << endl;

    cout << str.substr(pos) << endl;
}

int main()
{
    system("pause");
    return 0;
}